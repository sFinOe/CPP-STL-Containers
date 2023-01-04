#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP
#include <common.hpp>

/*
	It allows you to access the characteristics of an iterator,
	such as its value type and difference type,
	without having to know the specific type of the iterator.
*/

namespace ft
{
	template <typename Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::iterator_category iterator_category;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
	};

	// partial specialization for pointer types
	template <typename T>
	struct iterator_traits<T *>
	{
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef T *pointer;
		typedef T &reference;
	};

	// partial specialization for const pointer types
	template <typename T>
	struct iterator_traits<const T *>
	{
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef const T *pointer;
		typedef const T &reference;
	};

}

#endif