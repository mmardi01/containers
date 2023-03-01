/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:16:20 by mmardi            #+#    #+#             */
/*   Updated: 2023/03/01 15:34:33 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "redBlackTree.hpp"
# include <memory>
# include "../utility/pair.hpp"
# include "../iterators/reverse_iterator.hpp"
#include "../iterators/iterator_traits.hpp"
#include <iostream>
#include "../utility/equal.hpp"
 
# ifndef _SET_HPP
#define _SET_HPP

namespace ft
{
    template <  class T,                        // set::key_type/value_type
                class Compare = std::less<T>,        // set::key_compare/value_compare
                class Alloc = std::allocator<T>      // set::allocator_type 
                > 
    class set {
        public:
            typedef T                                                       key_type;  
            typedef T                                                       value_type;
            typedef Compare                                                 key_compare;
            typedef key_compare                                             value_compare;
            typedef Alloc                                                   allocator_type;
            typedef typename allocator_type::reference                      reference;
            typedef typename allocator_type::const_reference                const_reference;
            typedef typename allocator_type::pointer                        pointer;
            typedef typename allocator_type::const_pointer                  const_pointer;
            typedef ft::RedBlackTree<value_type,key_compare,allocator_type> rb_tree;
            typedef typename rb_tree::iterator                              iterator;
            typedef typename rb_tree::const_iterator                        const_iterator;
            typedef typename rb_tree::reverse_iterator                      reverse_iterator;
            typedef typename rb_tree::const_reverse_iterator                const_reverse_iterator;
            typedef typename iterator_traits<iterator>::difference_type     difference_type;
            typedef size_t                                                  size_type;
        private:
            rb_tree tree;
            allocator_type _alloc;
            size_type _size;
            key_compare _comp;
        public:
        // _________________/ Constructors \_________________ //
            explicit set(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {
                _alloc = alloc;
                _comp = comp;
                _size = 0;
            }
            template <class InputIterator>  
            set(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),  const allocator_type& alloc = allocator_type()) {
                _alloc = alloc;
                _comp = comp;
                _size = 0;
                if (first != last)
                    insert(first,last);
            }

            set(const set& x) {
                _alloc = x._alloc;
                _comp = x._comp;
                _size = 0;
                if (x.size() > 0)
                    insert(x.begin(),x.end());
            };
             set& operator= (const set& x) {
                _alloc = x._alloc;
                _comp = x._comp;
                clear();
                if (x.size() > 0) {

                    insert(x.begin(),x.end());
                }
                return *this;
            }
            ~set() { clear(); };
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
            typename rb_tree::_Node node = tree.findNode(*position);
            tree.deleteNode(node);
            _size--;
        }
        size_type erase (const key_type& k) {
            if (_size) {
                iterator it = begin();
                while(it != end() && *it != k) it++;
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

        void swap (set& x) {
            
          ft::set<value_type,key_compare,allocator_type> tmp;
          tmp = *this;
          *this = x;
          x = tmp;
        }
        void clear() {

            if (_size > 0)
                erase(begin(),end());
            _size = 0;
        }

            // _________________/ Capacity: \_________________ //
        bool empty() const {
            return _size == 0;
        }
        size_type size() const {
            return _size;
        }
        size_type max_size() const {
            return   tree.maxSize();
        }

         // _________________/ Operations: \_________________ //
        iterator find (const key_type& k) {
            iterator it = begin();
            while (it != end() && *it != k) it++;
            return it;        
        }
        const_iterator find (const key_type& k) const {
            iterator it = begin();
            while (it != end() && *it != k) it++;
            return it;  
        }

        size_type count (const key_type& k) const {
            if (_size > 0 && tree.findNode(k))
                return 1;
            return 0;
        }
        
        iterator lower_bound(const key_type& k) {
            
            iterator it = begin();
            while (it != end() && _comp(*it, k)) it++;
            return it;
        }
        
        const_iterator lower_bound (const key_type& k) const {
            const_iterator it = begin();
            while (it != end() && _comp(*it, k)) it++;
            return it;
        }
        
        iterator upper_bound (const key_type& k) {
            iterator it = begin();
            while (it != end() && !_comp(k, *it)) it++;
            return it;
        }
        
        const_iterator upper_bound (const key_type& k) const{
            const_iterator it = begin();
            while (it != end() && !_comp(k, *it)) it++;
            return it;
        }

        ft::pair<const_iterator,const_iterator> equal_range(const key_type& k) const {
            
            return ft::make_pair(lower_bound(k),upper_bound(k));
        }
        ft::pair<iterator,iterator> equal_range(const key_type& k) {
            
            return ft::make_pair(lower_bound(k),upper_bound(k));
        }

         // _________________/ Observers: \_________________ //
        key_compare key_comp() const { return _comp; }
        value_compare value_comp() const { return  _comp; }
    };

    template <class T, class Compare, class Alloc>  
bool operator== ( const ft::set<T,Compare,Alloc>& lhs, const ft::set<T,Compare,Alloc>& rhs ) {
    if (lhs.size() != rhs.size())
        return false;
    return ft::equal(lhs.begin(),lhs.end(),rhs.begin());
}

template <class T, class Compare, class Alloc>  
bool operator != ( const ft::set<T,Compare,Alloc>& lhs, const ft::set<T,Compare,Alloc>& rhs ) {
    return !(lhs == rhs);
}


template <class T, class Compare, class Alloc>  
bool operator<( const ft:: set<T,Compare,Alloc>& lhs, const ft::set<T,Compare,Alloc>& rhs ) {
    return ft::lexicographical_compare(lhs.begin(),lhs.end(),rhs.begin(),rhs.end());
}

template <class T, class Compare, class Alloc>  
bool operator<=( const ft:: set<T,Compare,Alloc>& lhs, const ft::set<T,Compare,Alloc>& rhs ) {
    return lhs < rhs || lhs == rhs;
}

template <class T, class Compare, class Alloc>  
bool operator>( const ft:: set<T,Compare,Alloc>& lhs, const ft::set<T,Compare,Alloc>& rhs ) {
    return !(lhs < rhs) && !(lhs == rhs);
}

template <class T, class Compare, class Alloc>  
bool operator>=( const ft:: set<T,Compare,Alloc>& lhs, const ft::set<T,Compare,Alloc>& rhs ) {
    return lhs > rhs || lhs == rhs;
}

template <class T, class Compare, class Alloc>  
void swap(ft::set<T,Compare,Alloc>& x, ft::set<T,Compare,Alloc>& y) {
    x.swap(y);
}
} // namespace ft

#endif