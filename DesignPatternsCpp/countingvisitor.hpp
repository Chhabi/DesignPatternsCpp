#pragma once

#include "shapevisitor.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "compositeshape.hpp"

namespace visitors
{
	class CountingVisitor : public shapes::ShapeVisitor
	{
	public:
		size_t circles;
		size_t rectangles;
		size_t compositeShapes;

		CountingVisitor()
			: circles(0), rectangles(0), compositeShapes(0)
		{
		}

		virtual void visitCircle(shapes::Circle& circle)
		{ 
			circles++; 
		}

		virtual void visitRectangle(shapes::Rectangle& rectangle)
		{
			rectangles++;
		}

		virtual void visitCompositeShape(shapes::CompositeShape& compositeShape)
		{
			compositeShapes++;
			for (auto& s : compositeShape.getShapes())
			{
				s->accept(*this);
			}
		}
	};
}