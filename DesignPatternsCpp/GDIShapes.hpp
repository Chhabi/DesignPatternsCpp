#pragma once

#include "circle.hpp"
#include "rectangle.hpp"
#include "compositeshape.hpp"
#include "shapefactory.hpp"

namespace shapes
{
	namespace gdi
	{
		class CircleGDI : public Circle
		{
		public:
			CircleGDI(double x, double y, double r)
				: Circle(x, y, r)
			{
			}
		};

		class RectangleGDI : public Rectangle
		{
		public:
			RectangleGDI(double x, double y, double w, double h)
				: Rectangle(x, y, w, h)
			{
			}
		};

		class CompositeShapeGDI : public CompositeShape
		{
		public:
			CompositeShapeGDI(std::vector<std::shared_ptr<Shape>>& shapes)
				: CompositeShape(shapes)
			{
			}
		};

		class GDIShapeFactory : public ShapeFactory
		{
		public:
			virtual std::shared_ptr<Circle> CreateCircle(double x, double y, double r) override
			{
				return std::make_shared<CircleGDI>(x, y, r);
			}

			virtual std::shared_ptr<Rectangle> CreateRectangle(double x, double y, double w, double h) override
			{
				return std::make_shared<RectangleGDI>(x, y, w, h);
			}

			virtual std::shared_ptr<CompositeShape> CreateComposite(std::vector<std::shared_ptr<Shape>> shapes) override
			{
				return std::make_shared<CompositeShapeGDI>(shapes);
			}
		};

	}
}