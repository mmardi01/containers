/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:39:22 by mmardi            #+#    #+#             */
/*   Updated: 2023/02/13 16:47:40 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR
#define REVERSE_ITERATOR

# include <iostream>
# include <iterator>
#include "iterator_traits.hpp"
#include "vectorIterator.hpp"

namespace ft
{
	
template <class Iterator>
class reverse_iterator : public std::iterator<
							 typename ft::iterator_traits<Iterator>::iterator_category,
							 typename ft::iterator_traits<Iterator>::value_type,
							 typename ft::iterator_traits<Iterator>::difference_type,
							 typename ft::iterator_traits<Iterator>::reference,
							 typename ft::iterator_traits<Iterator>::pointer>
{
	private:
		Iterator __it;
	public:
		typedef Iterator 													iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category 	iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type 			value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer 			pointer;
		typedef typename ft::iterator_traits<Iterator>::reference 			reference;

		// Construction
		reverse_iterator() { } //default

		reverse_iterator(iterator_type it) {
			__it = it;
		}

		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter> &rev_it) {

			__it = rev_it.__it;
		}

		template <class Iter>
		reverse_iterator &operator=(const reverse_iterator<Iter> &rev_it) {

			__it = rev_it.__it;
		}

			// Member functions

			iterator_type base() const
		{

			return __it;
		}

		reference operator*() const {
			iterator_type tmp = __it;
			tmp--;
			return *(tmp);
		}

		reverse_iterator operator+(difference_type n) const {

			return (reverse_iterator(__it - n));
		}

		reverse_iterator operator-(difference_type n) const
		{
			return (reverse_iterator(__it + n));
		}

		reverse_iterator &operator++() {
			__it--;
			return *this;
		}
		reverse_iterator operator++(int)
		{
			reverse_iterator temp = *this;
			++(*this);
			return temp;
		}

		reverse_iterator &operator--() {

			__it++;
			return *this;
		}

		reverse_iterator operator--(int)
		{
			reverse_iterator temp = *this;
			--(*this);
			return temp;
		}

		reverse_iterator &operator+=(difference_type n) {

			return (reverse_iterator(__it -= n));
		}
		reverse_iterator &operator-=(difference_type n)
		{

			return (reverse_iterator(__it += n));
		}

		pointer operator->() const
		{
			return &(operator*());
		}

		reference operator[](difference_type n) const {

			 return (__it[-n - 1]);
		}
};
	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {

		return lhs.base() == rhs.base();
	}

	template <class Iterator>
	bool operator != (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{

		return lhs.base() != rhs.base();
	}
	template <class Iterator>
	bool operator > (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{

		return lhs.base() < rhs.base();
	}
	template <class Iterator>
	bool operator < (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{

		return lhs.base() > rhs.base();
	}
	template <class Iterator>
	bool operator <= (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{

		return lhs.base() >= rhs.base();
	}
	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{

		return lhs.base() <= rhs.base();
	}

	template <class Iterator>
	reverse_iterator<Iterator> operator+(
		typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it) {

		return (reverse_iterator<Iterator>(rev_it + n));
	}
	template <class Iterator>  
	typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {


			return ( rhs.base() - lhs.base());
		}

} // namespace ft

#endif