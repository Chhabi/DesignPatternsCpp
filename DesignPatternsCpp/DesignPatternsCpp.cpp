// DesignPatternsCpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "circle.hpp"
#include "rectangle.hpp"
#include "compositeshape.hpp"
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

class Shape;
using ShapePtr = std::shared_ptr<Shape>;

int main(int argc, char** argv)
{
	auto rootShape = make_unique<CompositeShape>();

	rootShape->add(make_shared<Rectangle>(10.0, 30.0, 5.0, 4.0));
	rootShape->add(make_shared<Circle>(10.0, 3.0, 13.0));

	rootShape->add(make_shared<CompositeShape>(initializer_list<ShapePtr>({
		make_shared<Rectangle>(12.0, 14.0, 2.0, 2.0),
		make_shared<Circle>(15.0, 18.0, 2.0)
	})));

	auto totalArea = rootShape->calcArea();

	cout << "total area:" << totalArea << endl;
	return 0;
}
