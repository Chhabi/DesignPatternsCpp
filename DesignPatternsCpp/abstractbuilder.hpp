#pragma once

#include <memory>

// forward declaration
namespace shapes
{
	class Shape;
}

namespace construction
{

	class AbstractBuilder
	{
	public:
		virtual std::shared_ptr<shapes::Shape> construct() = 0;
	};
}