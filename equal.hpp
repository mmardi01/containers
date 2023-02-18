/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:05:25 by mmardi            #+#    #+#             */
/*   Updated: 2023/02/18 19:21:09 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef EQUAL_HPP
# define EQUAL_HPP

namespace ft
{
  

template <class InputIterator1, class InputIterator2>
bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
{
  while (first1!=last1) {
    if (!(*first1 == *first2))
      return false;
    ++first1; ++first2;
  }
  return true;
}


template <class InputIterator1, class InputIterator2, class BinaryPredicate>  
bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred) {

    while (first1!=last1) {
    if (!(pred(*first1,*first2)))
      return false;
    first1++; 
    first2++;
  }
  return true;
    
}

template <class InputIterator1, class InputIterator2>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,InputIterator2 first2, InputIterator2 last2)
{
  while (first1!=last1)
  {
    if (first2==last2 || *first2<*first1) 
      return false;
    else if (*first1<*first2) 
      return true;
    first1++; 
    first2++;
  }
  return (first2 != last2);
}

} // namespace ft
# endif