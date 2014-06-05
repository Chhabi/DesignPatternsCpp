#pragma once

#include "circle.hpp"
#include "rectangle.hpp"
#include "compositeshape.hpp"
#include "shapefactory.hpp"

namespace shapes
{
	namespace gl
	{
		class CircleGL : public Circle
		{
		public:
			CircleGL(double x, double y, double r)
				: Circle(x, y, r)
			{
			}
		};

		class RectangleGL : public Rectangle
		{
		public:
			RectangleGL(double x, double y, double w, double h)
				: Rectangle(x, y, w, h)
			{
			}
		};

		class CompositeShapeGL : public CompositeShape
		{
		public:
			CompositeShapeGL(std::vector<std::shared_ptr<Shape>> shapes)
				: CompositeShape(shapes)
			{
			}
		};

		class GLShapeFactory : public ShapeFactory
		{
		public:
			virtual std::shared_ptr<Circle> CreateCircle(double x, double y, double r) override
			{
				return std::make_shared<CircleGL>(x, y, r);
			}

			virtual std::shared_ptr<Rectangle> CreateRectangle(double x, double y, double w, double h) override
			{
				return std::make_shared<RectangleGL>(x, y, w, h);
			}

			virtual std::shared_ptr<CompositeShape> CreateComposite(std::vector<std::shared_ptr<Shape>> shapes) override
			{
				return std::make_shared<CompositeShapeGL>(shapes);
			}
		};
	}
}
