#ifndef RENDERER_H
#define RENDERER_H

#include<iostream>


class Renderer{
public:
	virtual void renderCircle(float x, float y, float radius) = 0;
};

class VectorRenderer : public Renderer {
	void renderCircle(float x, float y, float radius) override {
		std::cout << "VectorRenderer render circle x: " << x << std::endl;
	};
};

class RasterRenderer : public Renderer {
	void renderCircle(float x, float y, float radius) override {
		std::cout << "RasterRenderer render circle x: " << x << std::endl;
	};
};

class Shape{
protected:
	Renderer& renderer;
	Shape(Renderer& r):renderer{r}{};
public:
	virtual void draw() = 0;
	virtual void resize(float factor) = 0;
};

class Circle : public Shape{
public:
	Circle(Renderer& r, float x, float y, float radius): Shape(r), x{x}, y{y}, radius{radius} {};

	float x, y, radius;
	void draw() override{
		renderer.renderCircle(x, y, radius);
	};

	void resize(float f) override{
		x *= f;
		y *= f;
		radius *= f;
	};
};






















#endif 
