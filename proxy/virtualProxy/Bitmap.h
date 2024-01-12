#ifndef BITMAP_H
#define BITMAP_H

#include "iostream"
#include "string"

struct Image{
	virtual void draw() = 0;
	virtual ~Image() = default;
};


struct Bitmap: Image {
	std::string filename;

	Bitmap(const std::string& filename):filename{filename} {
		std::cout << "Loading image from: " << filename << std::endl;
	}	

	virtual ~Bitmap() = default ;

	void draw() override {
		std::cout << "draw Image..." << filename << std::endl;
	}
};

// allow to build the Bitmap only when the object is called
// using the LazyBitmap act as a (virtual)proxy for the Bitmap
struct LazyBitmap: Image {
	
	LazyBitmap(const std::string& filename):filename{filename} {};
	virtual ~LazyBitmap(){ delete bmp; };
	void draw() override {
		if(!bmp)
			bmp = new Bitmap(filename);
		bmp->draw();
	};

private:
	Bitmap *bmp;
	std::string filename;
};

inline void drawImage(Image& image) {
	image.draw();
};













#endif
