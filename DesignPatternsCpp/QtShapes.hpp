#pragma once

#include <memory>
#include "circle.hpp"
#include "rectangle.hpp"
#include "compositeshape.hpp"
#include "shapefactory.hpp"

namespace shapes
{
	namespace qt
	{
		class QtRectangle : public Rectangle
		{
		public:
			QtRectangle(double x, double y, double w, double h)
				: Rectangle(x, y, w, h)
			{
			}
		};

		class QtCircle : public Circle
		{
		public:
			QtCircle(double x, double y, double r)
				: Circle(x, y, r)
			{
			}
		};

		class QtCompositeShape : public CompositeShape
		{
		public:
			QtCompositeShape(std::vector<std::shared_ptr<Shape>> shapes)
				: CompositeShape(shapes)
			{
			}
		};

		class QtShapeFactory : public ShapeFactory
		{
		public:
			virtual std::shared_ptr<Circle> CreateCircle(double x, double y, double r)
			{
				return std::make_shared<QtCircle>(x, y, r);
			}

			virtual std::shared_ptr<Rectangle> CreateRectangle(double x, double y, double w, double h)
			{
				return std::make_shared<QtRectangle>(x, y, w, h);
			}

			virtual std::shared_ptr<CompositeShape> CreateComposite(std::vector<std::shared_ptr<Shape>> shapes)
			{
				return std::make_shared<QtCompositeShape>(shapes);
			}
		};
	}
}