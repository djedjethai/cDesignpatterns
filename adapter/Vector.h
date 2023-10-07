#include<iostream>
#include<vector>
#include<algorithm>


struct Point{
	int x, y;
};

struct Line{
	Point start, end;
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
