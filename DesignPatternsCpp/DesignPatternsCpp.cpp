// DesignPatternsCpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "circle.hpp"
#include "rectangle.hpp"
#include "compositeshape.hpp"
#include <algorithm>
#include <numeric>
#include <iostream>

#include "abstractbuilder.hpp"
#include "hardcodedbuilder.hpp"
#include "commandlinebuilder.hpp"

#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "compositeshape.hpp"
#include "shapefactory.hpp"
#include "GDIShapes.hpp"
#include "GLShapes.hpp"
#include "QtShapes.hpp"

#include "countingvisitor.hpp"

using namespace std;
using namespace construction;
using namespace shapes;

class Program
{
	unique_ptr<AbstractBuilder> builder;
	unique_ptr<ShapeFactory> shapeFactory;

public:
	Program(unique_ptr<AbstractBuilder> builder_, unique_ptr<ShapeFactory> shapeFactory)
		: builder(move(builder_)),
		shapeFactory(move(shapeFactory))
	{}

	void run()
	{
		auto rootShape = this->builder->construct(*shapeFactory);
		auto totalArea = rootShape->calcArea();
		cout << "total area:" << totalArea << endl;

		visitors::CountingVisitor counter;
		rootShape->accept(counter);

		cout << "circles: " << counter.circles << " rectangles: " << counter.rectangles << " composites: " << counter.compositeShapes << endl;
	}
};

int main(int argc, char** argv)
{
	Program p(make_unique<HardCodedBuilder>(), 
			make_unique<shapes::gdi::GDIShapeFactory>());

	p.run();
	return 0;
}
