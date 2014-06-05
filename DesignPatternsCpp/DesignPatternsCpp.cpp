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

using namespace std;
using namespace construction;
using namespace shapes;

class Program
{
	unique_ptr<AbstractBuilder> builder;
public:
	Program(unique_ptr<AbstractBuilder> builder_)
		: builder(move(builder_))
	{}

	void run()
	{
		auto rootShape = this->builder->construct();
		auto totalArea = rootShape->calcArea();
		cout << "total area:" << totalArea << endl;
	}
};

int main(int argc, char** argv)
{
	Program p(make_unique<CommandlineBuilder>());
	p.run();
	return 0;
}
