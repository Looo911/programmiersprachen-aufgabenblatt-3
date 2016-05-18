#include <cstdlib>
#include <vector>
#include <list>
#include <set>
#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>

int main()
{	

	//3.2
	std::list <unsigned int> hundred(100);

	for (std::list<unsigned int>::iterator it=hundred.begin(); it!=hundred.end();++it)	
	{
    	*it=std::rand() % 100 + 0;
	} 
	/*std::copy(std::begin(hundred), std::end(hundred),
	  std::ostream_iterator<int>(std::cout, "\n"));
	*/
	std::vector<int> v(100);

	std::copy(std::begin(hundred), std::end(hundred), std::begin (v));

	//3.3
	std::cout << "Aufgabe 3.3:" << "\n";
	std::set<unsigned int> a (std::begin(v), std::end(v));
	std::cout << "Es sind " << a.size() << " gleiche Zahlen im Vektor" << "\n";
	for (int i = 0; i <= 100; ++i)
	{
		if(a.count(i) == 0)
		{
			std::cout << i << "\n";
		}
	}


	//3.4
	std::cout << "Aufgabe 3.4:" << "\n";

	std::map<int, int> map1;

	for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
	{	
		map1[*i] += 1;
	}
	
	for (auto i: map1)
	{
		std::cout << i.first << "  " << i.second << "\n";
	}
	

	return 0;


}