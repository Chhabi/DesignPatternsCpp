#pragma once

#include <memory>

// forward declaration
namespace shapes
{
	class Shape;
	class ShapeFactory;
}

namespace construction
{

	class AbstractBuilder
	{
	public:
		virtual std::shared_ptr<shapes::Shape> construct(shapes::ShapeFactory &factory) = 0;
	};
}