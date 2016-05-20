#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include "vec2.hpp"
#include "circle.hpp"
#include <cstdlib>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>

template <class T> void swaps (T& a, T& b)
{
	T c(std::move(a)); a=std::move(b); b=std::move(c);
} 




TEST_CASE("describe_factorial", "[aufgabe3]")
{
	std::vector<Circle> v0(6);

	Circle a(Vec2(0.0f, 0.0f), 3.0f);
	Circle b(Vec2(0.0f, 0.0f), 2.0f);
	
	Circle c(Vec2(0.0f, 0.0f), 1.2f);
	
	Circle d(Vec2(0.0f, 0.0f), 7.2f);
	
	Circle e(Vec2(0.0f, 0.0f), 11.3f);

	Circle f(Vec2(0.0f, 0.0f), 50000.4f);


	v0.push_back(a);
	v0.push_back(b);
	v0.push_back(c);
	v0.push_back(d);
	v0.push_back(e);
	v0.push_back(f);

	auto v1 = v0;

	std::sort(std::begin(v0), std::end(v0));

	
	REQUIRE(std::is_sorted(v0.begin(), v0.end()));	

	swaps(a, b);
	REQUIRE(b.radius()== 3.0f);

	std::sort(v1.begin(), v1.end(), [](Circle a, Circle b) { return a.radius() < b.radius(); } );
	
	REQUIRE(std::is_sorted(v1.begin(), v1.end()));


}



int main(int argc, char* argv[])
{	
	return Catch::Session().run(argc, argv);
}
