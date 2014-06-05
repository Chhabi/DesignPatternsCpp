#pragma once

#include "shape.hpp"

class CompositeShape : public Shape
{
	typedef std::shared_ptr<Shape> ShapePtr;
	std::vector<ShapePtr> shapes;
public:
	CompositeShape()
	{}

	CompositeShape(std::initializer_list<ShapePtr> list)
		: shapes(list)
	{}

	CompositeShape(const CompositeShape &) = delete; // for now, will implement with ProtoType


	const std::vector<std::shared_ptr<Shape>> getShapes() const
	{
		return this->shapes;
	}

	double calcArea() const
	{
		return std::accumulate(begin(shapes), end(shapes), 0.0, [](double agg, const ShapePtr& s) { return agg + s->calcArea(); });
	}

	void add(std::shared_ptr<Shape> shape)
	{
		this->shapes.push_back(shape);
	}

	bool remove(std::shared_ptr<Shape> shape)
	{
		auto currentEnd = end(this->shapes);
		auto newEnd = std::remove(begin(this->shapes), currentEnd, shape);
		this->shapes.erase(newEnd, currentEnd);
		return newEnd != currentEnd;
	}
};