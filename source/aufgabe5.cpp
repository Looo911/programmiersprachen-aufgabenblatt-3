#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include <vector>


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
	std::vector<int> v0(100);

	for (std::vector<int>::iterator it=v0.begin(); it!=v0.end();++it)	
	{
    	*it=std::rand() % 100 + 0;
	}

	


	v0.erase(std::remove_if(v0.begin(), v0.end(), is_odd), v0.end());

	REQUIRE(std::all_of(v0.begin(), v0.end(), is_even));
}



int main(int argc, char* argv[])
{	
	return Catch::Session().run(argc, argv);
}

