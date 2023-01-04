#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP
#include <common.hpp>


namespace ft
{
	// enable_if is a metafunction that returns its second argument if its first argument is true, and does not participate in overload resolution otherwise.
	// The first argument is a compile-time constant expression that is either true or false.
	// The second argument is the type to be returned if the first argument is true.

	// bool B : the first argument is a compile-time constant expression that is either true or false. (is_integral<T>::value for example)
	// class T = void : if no second argument is passed, the default is void (the type to be returned if the first argument is true)
	template<bool B, class T = void>
	struct enable_if {};
	
	// if the first argument is true, the second argument is returned
	// enableif return type is T 
	template<class T>
	struct enable_if<true, T> { typedef T type; };
	
}

#endif