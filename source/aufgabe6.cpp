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

	auto lol = v0;

	std::sort(std::begin(v0), std::end(v0));

	
	REQUIRE(std::is_sorted(v0.begin(), v0.end()));	

	swaps(a, b);
	REQUIRE(b.radius()== 3.0f);

	std::sort(lol.begin(), lol.end(), [](Circle a, Circle b) 
		{ return a.radius() < b.radius(); } );
	
	REQUIRE(std::is_sorted(lol.begin(), lol.end()));

	
	//3.10
	std::vector<int>v1{1,2,3,4,5,6,7,8,9};
	std::vector<int>v2{9,8,7,6,5,4,3,2,1};
	std::vector<int>v3(9);

	std::transform(std::begin(v1), std::end(v1), std::begin(v2), std::begin(v3), 
	    [] (int const& v1, int const& v2) {
	      return v1 + v2;
	    });

  	REQUIRE (std::all_of(std::begin(v3), std::end(v3), []
    	(int const& v3) { return v3==10;}) == true);


  	
}



int main(int argc, char* argv[])
{	
	return Catch::Session().run(argc, argv);
}
