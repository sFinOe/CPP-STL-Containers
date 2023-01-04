#include <ft_containers.hpp>

int main ()
{

	ft::vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	ft::vector<int>::iterator it = v.begin();
	ft::vector<int>::iterator ite = v.end();

	--ite;

	std::cout << "vector: ";

	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}

	std::cout << *it << std::endl;

	ft::stack<int> s(v);

	std::cout << "stack: ";

	while (!s.empty())
	{
		std::cout << s.top() << " ";
		s.pop();
	}

	std::cout << std::endl;

	ft::map<int, int> m;

	m.insert(ft::make_pair(1, 1));
	m.insert(ft::make_pair(2, 2));
	m.insert(ft::make_pair(3, 3));
	m.insert(ft::make_pair(4, 4));
	m.insert(ft::make_pair(5, 5));

	ft::map<int, int>::iterator it2 = m.begin();
	ft::map<int, int>::iterator ite2 = m.end();

	--ite2;

	std::cout << "map: ";

	while (it2 != ite2)
	{
		std::cout << it2->first << " ";
		++it2;
	}

	std::cout << it2->first << std::endl;

	ft::set<int> s2;

	s2.insert(1);
	s2.insert(2);
	s2.insert(3);
	s2.insert(4);
	s2.insert(5);

	ft::set<int>::iterator it3 = s2.begin();

	std::cout << "set: ";

	while (it3 != s2.end())
	{
		std::cout << *it3 << " ";
		++it3;
	}

	std::cout << std::endl;

	return 0;
}