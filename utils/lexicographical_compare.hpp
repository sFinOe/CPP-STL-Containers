#ifndef LEXICOGRAPHICAL_COMPARE_HPP
# define LEXICOGRAPHICAL_COMPARE_HPP
# include <common.hpp>

/*
	compares two ranges of elements lexicographically (i.e., based on their spelling).
	The function compares the elements in the ranges using the specified comparison function,
	and returns true if the first range is lexicographically less than the second, and false otherwise.
*/

namespace ft
{
	template <typename Input1, typename last_Input1, typename Input2 , typename last_Input2>
	bool lexicographical_compare(Input1 first1, last_Input1 last1, Input2 first2, last_Input2 last2)
	{
		while (first1 != last1 && first2 != last2)
		{
			if (*first1 < *first2)
				return true;
			else if (*first2 < *first1)
				return false;
			++first1;
			++first2;
		}
		return (first1 == last1 && first2 != last2);
	}
}

#endif