#pragma once

#include "shape.hpp"
#include <vector>

namespace shapes
{
	class CompositeShape : public Shape
	{
		typedef std::shared_ptr<Shape> ShapePtr;
		std::vector<ShapePtr> shapes;
	public:
		CompositeShape()
		{}

		CompositeShape(std::vector<ShapePtr> shapes)
			: shapes(std::move(shapes))
		{}

		CompositeShape(const CompositeShape &) = delete; // for now, will implement with ProtoType

		std::vector<std::shared_ptr<Shape>>& getShapes()
		{
			return this->shapes;
		}

		const std::vector<std::shared_ptr<Shape>>& getShapes() const
		{
			return this->shapes;
		}

		double calcArea() const
		{
			return std::accumulate(begin(shapes), end(shapes), 0.0, [](double agg, const ShapePtr& s) { return agg + s->calcArea(); });
		}

		virtual void accept(ShapeVisitor &visitor) override
		{
			visitor.visitCompositeShape(*this);
		}

		void add(std::shared_ptr<Shape> shape)
		{
			this->shapes.push_back(shape);
		}

		bool remove(std::shared_ptr<Shape> shape)
		{
			auto position = find(begin(this->shapes), end(this->shapes), shape);
			if (position != end(this->shapes))
			{
				this->shapes.erase(position);
				return true;
			}

			return false;
		}
	};
}