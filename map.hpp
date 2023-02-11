/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:21:15 by mmardi            #+#    #+#             */
/*   Updated: 2023/02/11 19:12:57 by mmardi           ###   ########.fr       */
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
            typedef Compare                                                 key_compare;
            typedef Alloc  
                                                             allocator_type;
            class value_compare : std::binary_function<value_type,value_type,bool>{
                friend class map;
                Compare comp;
                public:
                    value_compare() {}
                    bool operator() (const value_type& x, const value_type& y) const {
                        return comp(x.first, y.first);
                    }    
            };
            
            typedef ft::RedBlackTree<value_type,value_compare>              rbt_tree; 
            typedef typename allocator_type::reference                      reference;
            typedef typename allocator_type::const_pointer                  const_pointer;
            typedef typename rbt_tree::iterator                             iterator;
            typedef typename rbt_tree::const_iterator                       const_iterator;
            typedef ft::reverse_iterator<iterator>                          reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>                    const_reverse_iterator;
            typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
            typedef  size_t                                                 size_type;
            
        private:
            rbt_tree tree;
            size_type _size;
            allocator_type _alloc;
            key_compare _comp;
        public:
        // _________________/ Constructors \_________________ //
            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {
                _alloc = alloc;
                _comp = comp;
                _size = 0;
            }

            template <class InputIterator>  
            map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),  const allocator_type& alloc = allocator_type()) {
                _alloc = alloc;
                _comp = comp;
                while(first != last) {
                    tree.insert(*first++);
                    _size++;
                }
            }
            
            map (const map& x);
            ~map() {}
        // _________________/ Modifiers \_________________ //
        ft::pair<iterator,bool> insert (const value_type& val) {
            ft::pair<iterator,bool> b = tree.insert(val);
            if (b.second)
                _size++;
            return b;
        }
        // _________________/ Iterator \_________________ //
         iterator begin() {
            return tree.begin();
         }
         const_iterator begin() const {
            return const_iterator(tree.begin());
         }
         iterator end() {
            return tree.end();
         }

          const_iterator end() const {
            return const_iterator(tree.end());
         }

        reverse_iterator rbegin() {
            reverse_iterator(end());
        }

        const_reverse_iterator rend() const {
            return const_reverse_iterator(end());
        }
        // _________________/ Element Access \_________________ //
        mapped_type& operator[] (const key_type& k) {
            ft::pair<iterator,bool> b = tree.insert(ft::make_pair(k,mapped_type()));
            if (b.second)
                _size++;
            return b.first->second;
        }
        
        // _________________/ Capacity: \_________________ //
        bool empty() const {
            return _size == 0;
        }
        size_type size() const {
            return _size;
        }
    };
} // namespace ft



#endif