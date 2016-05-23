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


template <typename conta, typename funct> 
conta filter (conta& a, funct& b)
{
	conta c;
	for (auto i : c)
	{
		if (b(i))
			{
				c.push_back(i);
			}
	}
	return c;
} 


bool is_even(int a)
{
	return (a % 2 == 0);
}

	
bool is_odd(int a)
{
	return (a % 2 != 0);
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


  	//3.11


  	std::vector<int>notalleven{1,2,3,4,5,6};


	std::vector<int>alleven=filter(notalleven,is_even);

	REQUIRE(std::all_of(alleven.begin(), alleven.end(), is_even));


	//3.13
/*
	std::vector<Circle>circles{{5.0f},{3.0f},{8.0f},{1.0f},{5.0f}};
	auto goil = std::copy_if (circles.begin(), circles.end(), [](Circle a){return (a.radius()<4.0f);} );
 */	



}



int main(int argc, char* argv[])
{	
	return Catch::Session().run(argc, argv);
}
