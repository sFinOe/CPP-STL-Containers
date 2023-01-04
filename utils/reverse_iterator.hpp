#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP
#include <common.hpp>

namespace ft
{
	template <typename Iterator>
	class reverse_iterator
	{

		public :
			typedef typename ft::iterator_traits<Iterator>::value_type value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer pointer;
			typedef typename ft::iterator_traits<Iterator>::reference reference;
			typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
			typedef Iterator iterator_type;

		protected :

			iterator_type _current;

		public :

			reverse_iterator() : _current(NULL) {}
			explicit reverse_iterator(iterator_type x) : _current(x) {}

			template <class Iter>
			reverse_iterator(const reverse_iterator<Iter> &other) : _current(other.base()) {}

			iterator_type base() const { return _current; }

			reference operator*() const{
				iterator_type tmp = _current;
				return *--tmp;
			}

			pointer operator->() const { return &(operator*()); }

			reverse_iterator &operator++() {
				--_current;
				return *this;
			}

			reverse_iterator operator++(int) {
				reverse_iterator tmp = *this;
				--_current;
				return tmp;
			}

			reverse_iterator &operator--() {
				++_current;
				return *this;
			}

			reverse_iterator operator--(int) {
				reverse_iterator tmp = *this;
				++_current;
				return tmp;
			}

			reverse_iterator operator+(difference_type n) const {
				return reverse_iterator(_current - n);
			}

			reverse_iterator &operator+=(difference_type n) {
				_current -= n;
				return *this;
			}

			reverse_iterator operator-(difference_type n) const {
				return reverse_iterator(_current + n);
			}

			reverse_iterator &operator-=(difference_type n) {
				_current += n;
				return *this;
			}

			reference operator[](difference_type n) const {
				return *(*this + n);
			}

	};

	/**********  Non-member functions  ********/


    template <typename Iterator1, typename Iterator2>
	bool operator==(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs) {
		return lhs.base() == rhs.base();
	}

    template <typename Iterator1, typename Iterator2>
	bool operator!=(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs) {
		return lhs.base() != rhs.base();
	}

    template <typename Iterator1, typename Iterator2>
	bool operator<(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs) {
		return lhs.base() > rhs.base();
	}

    template <typename Iterator1, typename Iterator2>
	bool operator<=(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs) {
		return lhs.base() >= rhs.base();
	}

    template <typename Iterator1, typename Iterator2>
	bool operator>(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs) {
		return lhs.base() < rhs.base();
	}

    template <typename Iterator1, typename Iterator2>
	bool operator>=(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs) {
		return lhs.base() <= rhs.base();
	}

    // *(3 + it)
    template <typename Iterator1, typename Iterator2>
    ft::reverse_iterator<Iterator1> operator+(const typename ft::reverse_iterator<Iterator1>::difference_type &a, const ft::reverse_iterator<Iterator2> &iter)
    {
        return (iter + a);
    }

    // iterator - iterator2
    template <typename Iterator1, typename Iterator2>
    typename ft::reverse_iterator<Iterator1>::difference_type operator-(const ft::reverse_iterator<Iterator1> lhs, const ft::reverse_iterator<Iterator2> rhs)
    {
        return -(lhs.base() - rhs.base());
    }

}

#endif