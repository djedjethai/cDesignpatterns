#include<boost/container_hash/hash.hpp>

#include <boost/container_hash/hash_fwd.hpp>
#include <cstddef>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<mutex>


struct Point{
	int x, y;

	friend std::size_t hash_value(const Point& obj){
		std::size_t seed = 0x725C686F;
		boost::hash_combine(seed, obj.x);
		boost::hash_combine(seed, obj.y);
		return seed;
	};
};

struct Line{
	Point start, end;

	friend std::size_t hash_value(const Line& obj){
		std::size_t seed = 0x719E6B16;
		boost::hash_combine(seed, obj.start);
		boost::hash_combine(seed, obj.end);
		return seed;
	};
};

struct VectorObject{
	virtual std::vector<Line>::iterator begin() = 0;
	virtual std::vector<Line>::iterator end() = 0;
};

struct VectorRectangle:  VectorObject {
	VectorRectangle(int x, int y, int width, int height){
		lines.emplace_back(Line{Point{x, y}, Point{x + width, y}});
		lines.emplace_back(Line{Point{x + width, y}, Point{x + width, y + height}});
		lines.emplace_back(Line{Point{x, y}, Point{x, y + height}});
		lines.emplace_back(Line{Point{x, y + height}, Point{x + width, y + height}});	
	};

	std::vector<Line>::iterator begin() override {
		return lines.begin();
	};

	std::vector<Line>::iterator end() override {
		return lines.end();
	}
private:
	std::vector<Line> lines;
};


// TODO add func DrawPoints()
void DrawPoints(std::vector<Point>::iterator start, std::vector<Point>::iterator end){
	for(auto i = start; i != end; ++i){
		std::cout << "$" << std::endl;
	}
}

struct LineToPointCachingAdapter{
	typedef std::vector<Point> Points;


	LineToPointCachingAdapter(Line& line){
		// !!! not thread save(static var should be protect by mutex)
		static boost::hash<Line> hash;
		line_hash = hash(line); //  note: line_hash is a field!

		// no thread-save protection
		// if(cache.find(line_hash) != cache.end())
		
		// ok, thread-save
		if(findInCache(line_hash) != cache.end())
			return;

		Points points;

		int left = std::min(line.start.x, line.end.x);
		int right = std::max(line.start.x, line.end.x);
		int top = std::min(line.start.y, line.end.y);
		int bottom = std::max(line.start.y, line.end.y);
		int dx = right - left;
		int dy = line.end.y - line.start.y;

		// only vertical or horizontal lines
		if(dx == 0){
			// vertical
			for(int y = top; y <= bottom; ++y )
				points.emplace_back(Point{left, y});
		} else if(dy == 0){
			for(int x = left; x <= right; ++x)
				points.emplace_back(Point{x, top});
		};

		cache[line_hash] = points;
	};


	virtual Points::iterator begin(){
		// To ensure proper unlocking, you should use std::lock_guard 
		// or std::unique_lock to manage the mutex automatically.
		std::lock_guard<std::mutex> lock(cacheMutex);
		return cache[line_hash].begin();
	};

	virtual Points::iterator end(){
		std::lock_guard<std::mutex> lock(cacheMutex);
		// return cache[line_hash].end();
		Points::iterator it = cache[line_hash].end();
		return it;
	};

	static std::map<std::size_t, Points>::iterator findInCache(std::size_t line_hash){
		cacheMutex.lock();
		auto it = cache.find(line_hash);
		cacheMutex.unlock();
		return it;
	};

private:
	// !!! not thread save(static var should be protect by mutex)
	static std::map<std::size_t, Points> cache;
	static std::mutex cacheMutex;
	
	std::size_t line_hash;
	Points points;
};

// In C++, static members of a class need to be defined and initialized outside 
// the class definition in one of your source files (typically a .cpp file).
// should define and initialize the LineToPointCachingAdapter::cache static member 
// in one of your source files. 
// then the linker should be able to find the definition of LineToPointCachingAdapter::cache,
std::map<std::size_t, LineToPointCachingAdapter::Points> LineToPointCachingAdapter::cache;
std::mutex LineToPointCachingAdapter::cacheMutex;

struct LineToPointAdapter {
	typedef std::vector<Point> Points; 

	LineToPointAdapter(Line& line){
		int left = std::min(line.start.x, line.end.x);
		int right = std::max(line.start.x, line.end.x);
		int top = std::min(line.start.y, line.end.y);
		int bottom = std::max(line.start.y, line.end.y);
		int dx = right - left;
		int dy = line.end.y - line.start.y;

		// only vertical or horizontal lines
		if(dx == 0){
			// vertical
			for(int y = top; y <= bottom; ++y )
				points.emplace_back(Point{left, y});
		} else if(dy == 0){
			for(int x = left; x <= right; ++x)
				points.emplace_back(Point{x, top});

		};
		
	};

	virtual Points::iterator begin() {
		return points.begin();
	};

	virtual Points::iterator end() {
		return points.end();
	};

private:
	Points points;
};
