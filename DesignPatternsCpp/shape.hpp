
#pragma once

#include "shapevisitor.hpp"

namespace shapes
{
	class Shape
	{
	public:
		virtual double calcArea() const = 0;

		virtual void accept(ShapeVisitor &visitor) = 0;
	};
}