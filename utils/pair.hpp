#ifndef PAIR_HPP
#define PAIR_HPP
#include <common.hpp>


namespace ft
{
	// struct holding two objects of (possibly but not necessarily) diffrent types
	template<class T1, class T2>
	struct pair {
			typedef T1	first_type;
			typedef T2	second_type;

			T1 first;
			T2 second;

			pair() : first(), second(){}
			pair(T1 const &f, T2 const &s) : first(f), second(s){}
			// template copy constructor for pair class
			template<class U1, class U2>
			pair(pair<U1, U2> const &obj) : first(obj.first), second(obj.second){}
			pair& operator=( const pair& other ){
				first = other.first;
				second = other.second;
				return *this;
			}

	};
		// non-member functions

		template<class T1, class T2>
		pair<T1, T2> make_pair(T1 f, T2 s){
			return pair<T1, T2>(f, s);
		}

		template<class T1, class T2>
		bool	operator==(pair<T1, T2> const &first, pair<T1, T2> const &second){
			return (first.first == second.first && first.second == second.second);
		}

		template<class T1, class T2>
		bool	operator!=(pair<T1, T2> const &first, pair<T1, T2> const &second){
			return !(first == second);
		}

		template<class T1, class T2>
		bool	operator<(pair<T1, T2> const &first, pair<T1, T2> const &second){
			return ((first.first < second.first) || (!(second.first < first.first) && first.second < second.second));
		}

		template<class T1, class T2>
		bool	operator<=(pair<T1, T2> const &first, pair<T1, T2> const &second){
			return !(second < first);
		}

		template<class T1, class T2>
		bool	operator>(pair<T1, T2> const &first, pair<T1, T2> const &second){
			return second < first;
		}

		template<class T1, class T2>
		bool	operator>=(pair<T1, T2> const &first, pair<T1, T2> const &second){
			return !(first < second);
		}

} // namespace ft



#endif