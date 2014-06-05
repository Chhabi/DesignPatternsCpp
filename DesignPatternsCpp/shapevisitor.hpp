
#pragma once

namespace shapes
{
	class Circle;
	class Rectangle;
	class CompositeShape;

	class ShapeVisitor
	{
	public:
		virtual void visitCircle(Circle& circle) = 0;
		virtual void visitRectangle(Rectangle& rectangle) = 0;
		virtual void visitCompositeShape(CompositeShape& compositeShape) = 0;
	};
}
