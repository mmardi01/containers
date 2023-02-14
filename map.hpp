/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:21:15 by mmardi            #+#    #+#             */
/*   Updated: 2023/02/14 20:15:44 by mmardi           ###   ########.fr       */
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
            typedef typename rbt_tree::reverse_iterator                          reverse_iterator;
            typedef typename rbt_tree::const_reverse_iterator                     const_reverse_iterator;
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
                _size = 0;
                if (first != last)
                    insert(first,last);
            }
            
            map (const map& x) {
                _alloc = x._alloc;
                _comp = x._comp;
                _size = 0;
                if (x.size() > 0)
                    insert(x.begin(),x.end());
            };

            map& operator= (const map& x) {
                _alloc = x._alloc;
                _comp = x._comp;
                clear();
                if (x.size() > 0) {

                    insert(x.begin(),x.end());
                }
                return *this;
            }
            ~map() {
                clear();
            }
        // _________________/ Modifiers \_________________ //
        ft::pair<iterator,bool> insert (const value_type& val) {

            ft::pair<iterator,bool> b = tree.insert(val);
            
            if (b.second)
                _size++;
            return b;
        }

        template <class InputIterator>  
        void insert (InputIterator first, InputIterator last){

             while(first != last) {
                if (tree.insert(*first++).second)
                    _size++;
            }
        }
        iterator insert (iterator position, const value_type& val) {
            (void)position;
            insert(val);
        }
        void erase (iterator position) {
            iterator it = begin();
            while (it != position) it++;
            typename rbt_tree::_Node node = tree.findNode(*position);
            tree.deleteNode(node);
            _size--;
        }
        size_type erase (const key_type& k) {
            if (_size) {
            iterator it = begin();
            while(it != end() && it->first != k) it++;
            if (it != end()) {
                erase(it);
                return 1;
            }
            }
            return 0;
        }
        void erase (iterator first, iterator last) {
            if (_size > 0) {
            iterator tmp = first;
            tmp++;
            while (first != last) {
                erase(first);
                first = tmp;
                if (tmp != last)
                    tmp++;
            }
            }
        }

        void swap (map& x) {
            
          ft::map<key_type,mapped_type> tmp;
          tmp = *this;
          *this = x;
          x = tmp;
        }
        void clear() {
            if (_size > 0)
                erase(begin(),end());
            _size = 0;
        }
        // _________________/ Operations: \_________________ //
        iterator find (const key_type& k) {
            iterator it = begin();
            while (it != end() && it->first != k) it++;
            return it;        
        }
        const_iterator find (const key_type& k) const {
            iterator it = begin();
            while (it != end()) it++;
            return it;  
        }

        size_type count (const key_type& k) const {
            if (_size > 0 && tree.findNode(ft::make_pair(k,mapped_type())))
                return 1;
            return 0;
        }
        // _________________/ Iterator \_________________ //
         iterator begin() {
            return tree.begin();
         }
         const_iterator begin() const {
            return tree.begin();
         }
         iterator end() {
           
            return tree.end();
         }

          const_iterator end() const {
            return const_iterator(tree.end());
         }

        reverse_iterator rbegin() {
            return reverse_iterator(end());
        }

        reverse_iterator rend(){
            return reverse_iterator(begin());
        }    
        const_reverse_iterator rend() const {
            return const_reverse_iterator(begin());
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
        // _________________/ Observers: \_________________ //
        key_compare key_comp() const { return _comp(); }
        value_compare value_comp() const { return  value_comp(); }
    };
} // namespace ft



#endif