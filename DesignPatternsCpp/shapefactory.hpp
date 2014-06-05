#pragma once

#include <memory>
#include <vector>
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "compositeshape.hpp"

namespace shapes
{
	class ShapeFactory
	{
	public:
		virtual std::shared_ptr<Circle> CreateCircle(double x, double y, double r) = 0;
		virtual std::shared_ptr<Rectangle> CreateRectangle(double x, double y, double w, double h) = 0;
		virtual std::shared_ptr<CompositeShape> CreateComposite(std::vector<std::shared_ptr<Shape>> shapes) = 0;
	};
}