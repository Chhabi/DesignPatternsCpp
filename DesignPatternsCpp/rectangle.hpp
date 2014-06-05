
#pragma once

#include "shape.hpp"

namespace shapes
{
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

		virtual double calcArea() const override
		{
			return this->width * this->height;
		}

		virtual void accept(ShapeVisitor &visitor) override
		{
			visitor.visitRectangle(*this);
		}
	};
}