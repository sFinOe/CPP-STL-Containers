#ifndef EQUAL_HPP
# define EQUAL_HPP
#include <common.hpp>


namespace ft
{
	template <typename Input1, typename Input2, typename Input3>
	bool equal(Input1 first1, Input2 last1, Input3 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}
}

#endif