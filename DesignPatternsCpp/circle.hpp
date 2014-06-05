#pragma once

#include "shape.hpp"

class Circle : public Shape
{
	double centerX;
	double centerY;
	double radius;
public:
	Circle(double centerX, double centerY, double radius)
		: centerX(centerX), centerY(centerY), radius(radius)
	{}

	inline double getCenterX() { return this->centerX; }
	inline void setCenterX(double x) { this->centerX = x; }

	inline double getCenterY() { return this->centerY; }
	inline void setCenterY(double y) { this->centerY = y; }

	inline double getRadius() { return this->radius; }
	inline void setRadius(double r) { this->radius = r; }

	virtual double calcArea() const
	{
		return this->radius * this->radius * M_PI;
	}
};