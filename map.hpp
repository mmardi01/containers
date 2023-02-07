/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:21:15 by mmardi            #+#    #+#             */
/*   Updated: 2023/02/07 18:55:06 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef _MAP_HPP_
#define _MAP_HPP_

# include "redBlackTree.hpp"
# include <memory>
# include "pair.hpp"
# include "reverse_iterator.hpp"
#include "iterator_traits.hpp"
#include <iostream>


namespace ft
{
    template < class Key,class T,class Compare = std::less<Key>,class Alloc = std::allocator<ft::pair<const Key,T> > > 
    class map {
        public:
            typedef Key                                                     key_type;   
            typedef T                                                       mapped_type; 
            typedef ft::pair<const key_type,mapped_type>                    value_type; 
            typedef ft::RedBlackTree<value_type >                           rbt_tree;
            typedef Compare                                                 key_compare;
            typedef Alloc                                                   allocator_type;
            typedef typename allocator_type::reference                      reference;
            typedef typename allocator_type::const_pointer                  const_pointer;
            typedef typename ft::RedBlackTree<value_type>::iterator         iterator;
            typedef typename ft::RedBlackTree<value_type>::const_iterator   const_iterator;
            typedef ft::reverse_iterator<iterator>                          reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>                    const_reverse_iterator;
            typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
            typedef  size_t                                                 size_type;
            
        private:
            rbt_tree tree;
        public:
            map() {}
            ~map() {}
    };
} // namespace ft



#endif