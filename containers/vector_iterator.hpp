#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include <common.hpp>


namespace ft
{
	template <typename T>
	class vector_iterator
	{
		public :

			typedef typename ft::iterator_traits<T*>::value_type value_type;
			typedef typename ft::iterator_traits<T*>::difference_type difference_type;
			typedef typename ft::iterator_traits<T*>::pointer pointer;
			typedef typename ft::iterator_traits<T*>::reference reference;
			typedef pointer iterator_type;
			typedef std::random_access_iterator_tag iterator_category;

		protected :
		
			pointer _ptr;

		public :

			vector_iterator() : _ptr(NULL) {}
			explicit vector_iterator(pointer x) : _ptr(x) {}
			vector_iterator(const vector_iterator &other) : _ptr(other._ptr) {}
			~vector_iterator() {}

			operator vector_iterator<const T>() const {
        	    return (vector_iterator<const T>(this->_ptr));
        	}

        vector_iterator &operator=(const vector_iterator &rhs)
        {
            if (this == &rhs)
                return (*this);
            this->_ptr = rhs._ptr;
            return (*this);
        }

			iterator_type base() const {
                return _ptr;
            }
			reference operator*() {
                return *_ptr;
            }
			reference operator*() const {
                return *_ptr;
            }
			pointer operator->() const {
                return _ptr;
            }
			
			vector_iterator &operator++()
			{
				++_ptr;
				return *this;
			}
			vector_iterator operator++(int)
			{
				vector_iterator tmp = *this;
				++_ptr;
				return tmp;
			}
			vector_iterator &operator+=(difference_type n)
			{
				_ptr += n;
				return *this;
			}
			vector_iterator operator+(difference_type n) const {
				 return vector_iterator(_ptr + n);
			}
			vector_iterator &operator--()
			{
				--_ptr;
				return *this;
			}
			vector_iterator operator--(int)
			{
				vector_iterator tmp = *this;
				--_ptr;
				return tmp;
			}
			vector_iterator &operator-=(difference_type n)
			{
				_ptr -= n;
				return *this;
			}
			vector_iterator operator-(difference_type n) const {
				 return vector_iterator(_ptr - n);
			}
			reference operator[](difference_type n) const { return _ptr[n]; }

	};


    template <typename Iterator1, typename Iterator2>
    bool operator==(const ft::vector_iterator<Iterator1> &lhs, const ft::vector_iterator<Iterator2> &rhs)
    {
        return (lhs.base() == rhs.base());
    }

    template <typename Iterator1, typename Iterator2>
    bool operator!=(const ft::vector_iterator<Iterator1> &lhs, const ft::vector_iterator<Iterator2> &rhs)
    {
        return (lhs.base() != rhs.base());
    }

    template <typename Iterator1, typename Iterator2>
    bool operator>(const ft::vector_iterator<Iterator1> &lhs, const ft::vector_iterator<Iterator2> &rhs)
    {
        return (lhs.base() > rhs.base());
    }

    template <typename Iterator1, typename Iterator2>
    bool operator<(const ft::vector_iterator<Iterator1> &lhs, const ft::vector_iterator<Iterator2> &rhs)
    {
        return (lhs.base() < rhs.base());
    }

    template <typename Iterator1, typename Iterator2>
    bool operator<=(const ft::vector_iterator<Iterator1> &lhs, const ft::vector_iterator<Iterator2> &rhs)
    {
        return (lhs.base() <= rhs.base());
    }

    template <typename Iterator1, typename Iterator2>
    bool operator>=(const ft::vector_iterator<Iterator1> &lhs, const ft::vector_iterator<Iterator2> &rhs)
    {
        return (lhs.base() >= rhs.base());
    }

    // *(3 + it)
    template <typename Iterator1, typename Iterator2>
    ft::vector_iterator<Iterator1> operator+(const typename ft::vector_iterator<Iterator1>::difference_type &a, const ft::vector_iterator<Iterator2> &iter)
    {
        return (iter - a);
    }

	template <typename Iterator1>
    ft::vector_iterator<Iterator1> operator+(const typename ft::vector_iterator<Iterator1>::difference_type &a, const ft::vector_iterator<Iterator1> &iter)
    {
        return (iter - a);
    }

    // iterator - iterator2
    template <typename Iterator1, typename Iterator2>
    typename ft::vector_iterator<Iterator1>::difference_type operator-(const ft::vector_iterator<Iterator1> lhs, const ft::vector_iterator<Iterator2> rhs)
    {
        return (lhs.base() - rhs.base());
    }

}


#endif