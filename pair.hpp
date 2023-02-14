/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:24:36 by mmardi            #+#    #+#             */
/*   Updated: 2023/02/14 13:20:41 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PAIR_HPP
#define _PAIR_HPP


# include <iostream>
# include <algorithm>


namespace ft
{
    template <class _T1, class _T2> 
   struct pair {
            typedef _T1 first_type;
            typedef _T2 second_type;

            first_type first;
            second_type second;
            pair() { }
            
            template <class U, class V>
            pair(const pair<U, V> &pr) : first(pr.first), second(pr.second) {
            }

            pair(const first_type &a, const second_type &b) : first(a), second(b)  {
                
            }

            pair &operator=(const pair &pr) {
                
                 first = pr.first; 
                 second = pr.second; 
                 return *this; 
            }
            void swap(pair &pr) throw() {

                 std::swap(first, pr.first);
                 std::swap(second, pr.second);
            }
    } ;

    template <class T1, class T2>
    bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
            return lhs.first == rhs.first && lhs.second == rhs.second;
    }

    template <class T1, class T2>
    bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
            return !(lhs == rhs);
    }

    template <class T1, class T2>
    bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
            return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
    }

    template <class T1, class T2>
    bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
            return !(rhs < lhs);
    }

    template <class T1, class T2>
    bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
            return rhs < lhs;
    }

    template <class T1, class T2>
    bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
            return !(lhs < rhs);
    }

    template <class T1, class T2>
    pair<T1, T2> make_pair(T1 x, T2 y)
    {
            return (pair<T1, T2>(x, y));
    }
} // namespace ft


#endif