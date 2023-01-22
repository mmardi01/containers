/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:54:22 by mmardi            #+#    #+#             */
/*   Updated: 2023/01/18 14:57:52 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef VITERATOR_CPP
#define VITERATOR_CPP

# include <iostream>
# include <iterator>
#include <cstddef>

namespace ft
{
	template <class T>
	class vectorIterator : public std::iterator<std::random_access_iterator_tag, T>
	{
		private:
			T* ptr;
		public:
			typedef	std::random_access_iterator_tag 	iterator_category;
			typedef T									value_type;
			typedef std::ptrdiff_t 						difference_type;
			typedef T*									pointer;
			typedef T& 									reference;

			// _________________/ Constructors \_________________ //
			vectorIterator(T *s = NULL) { ptr = s; };

			vectorIterator(const vectorIterator& x) { ptr = x.ptr; };

			vectorIterator& operator = (const vectorIterator& x) { ptr = x.ptr; return *this; };

			// _________________/ Destructor \_________________ //
			~vectorIterator() { ptr = NULL; };

			// _________________/ Operation \_________________ //
			bool operator == (const vectorIterator& x) const
					{ return (ptr == x.ptr); };

			bool operator != (const vectorIterator& x) const
					{ return  (ptr != x.ptr); };

			reference operator * () const 
					{ return *ptr; }

			pointer operator->() const 
					{ return &ptr; }

			vectorIterator& operator ++ () 
					{ ptr++; return *this; }

			vectorIterator operator++(int) 
					{ vectorIterator tmp = *this; ptr++; return tmp; }

			vectorIterator &operator--() 
					{ ptr--; return *this; }

			vectorIterator operator--(int) 
					{ vectorIterator tmp = *this; ptr--; return tmp; }

			vectorIterator operator + (difference_type a) const
					{ vectorIterator tmp = *this; tmp.ptr += a; return tmp; }

			vectorIterator operator-(difference_type a) const 
					{ vectorIterator tmp = *this; tmp.ptr -= a; return tmp; }

			difference_type operator - (const vectorIterator& x) const 
					{ return (ptr - x.ptr); }

			bool operator < (const vectorIterator& x) const
					{ return (ptr < x.ptr); }

			bool operator > (const vectorIterator &x) const 
					{ return (ptr > x.ptr); }

			bool operator <= (const vectorIterator &x) const 
					{ return (ptr <= x.ptr); }

			bool operator >= (const vectorIterator &x) const 
					{ return (ptr >= x.ptr); }

			void operator += (difference_type a) 
					{ ptr += a; }

			void operator -= (difference_type a) 
					{ ptr -= a; }

			reference operator[](difference_type i) const 
					{ return ptr[i]; }
	};
	template <class T>
	vectorIterator<T> operator+(
		typename vectorIterator<T>::difference_type n, const vectorIterator<T> &x) {

		return (vectorIterator<T>(x + n));
	}
} 


# endif