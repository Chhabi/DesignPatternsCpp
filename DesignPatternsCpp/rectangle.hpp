
#pragma once

#include "shape.hpp"

class Rectangle : public Shape
{
	double x;
	double y;
	double width;
	double height;
public:
	Rectangle(double x, double y, double w, double h)
		: x(x), y(y), width(w), height(h)
	{
	}

};