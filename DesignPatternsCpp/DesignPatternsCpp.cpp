// DesignPatternsCpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "circle.hpp"
#include "rectangle.hpp"
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

class Shape;
using ShapePtr = std::shared_ptr<Shape>;

int main(int argc, char** argv)
{
	vector<ShapePtr> shapes;

	shapes.push_back(make_shared<Rectangle>(10.0, 30.0, 5.0, 4.0));
	shapes.push_back(make_shared<Circle>(10.0, 3.0, 13.0));

	auto totalArea = std::accumulate(begin(shapes), end(shapes), 0.0, [](double agg, ShapePtr s) { return agg + s->calcArea(); });
	cout << "total area:" << totalArea << endl;
	return 0;
}
