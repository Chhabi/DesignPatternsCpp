
#pragma once
 
#include "abstractbuilder.hpp"
#include <memory>
#include "shape.hpp"
#include "compositeshape.hpp"
#include "rectangle.hpp"

using ShapePtr = std::shared_ptr<shapes::Shape>;

namespace construction
{
	class HardCodedBuilder : public AbstractBuilder
	{
	public:
		virtual std::shared_ptr<shapes::Shape> construct(shapes::ShapeFactory &factory) override
		{
			using namespace std;
			using namespace shapes;
			auto rootShape = make_unique<CompositeShape>();

			rootShape->add(make_shared<Rectangle>(10.0, 30.0, 5.0, 4.0));
			rootShape->add(make_shared<Circle>(10.0, 3.0, 13.0));

			rootShape->add(make_shared<CompositeShape>(initializer_list<ShapePtr>({
				make_shared<Rectangle>(12.0, 14.0, 2.0, 2.0),
				make_shared<Circle>(15.0, 18.0, 2.0)
			})));

			return move(rootShape);
		}
	};
}