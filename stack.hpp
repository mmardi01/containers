/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:39:13 by mmardi            #+#    #+#             */
/*   Updated: 2023/01/02 19:03:37 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

# include "vector.hpp"
# include <algorithm>

namespace ft {
    
    template <class T, class Container = ft::vector<T> >
    class stack {
        private:
            Container arr;
        public:
            typedef T                               value_type;
            typedef Container                       container_type;
            typedef typename Container::size_type   size_type;
            
        // _________________/ Constructors \_________________ //
        explicit stack (const container_type& ctnr = container_type()) { arr = ctnr; }
        
        // _________________/ Member functions \_________________ //
        bool empty() const { return arr.empty(); }
        
        size_type size() const { return arr.size(); }
        
        value_type& top() { return arr.back(); }

        const value_type& top() const { return arr.back(); }

        void push(const value_type& val) { arr.push_back(val); }
        
        void pop() { arr.pop_back(); }

        void swap (stack& x) throw() {  std::swap(*this, x); }
        
        template <class _T, class _Container>  friend bool operator== (const stack<_T,_Container>& lhs, const stack<_T,_Container>& rhs);

        template <class _T, class _Container>  friend bool operator!= (const stack<_T,_Container>& lhs, const stack<_T,_Container>& rhs);
    
        template <class _T, class _Container>  friend bool operator<  (const stack<_T,_Container>& lhs, const stack<_T,_Container>& rhs);
    
        template <class _T, class _Container>  friend bool operator<= (const stack<_T,_Container>& lhs, const stack<_T,_Container>& rhs);
    
        template <class _T, class _Container>  friend bool operator>  (const stack<_T,_Container>& lhs, const stack<_T,_Container>& rhs);
    
        template <class _T, class _Container>  friend bool operator>= (const stack<_T,_Container>& lhs, const stack<_T,_Container>& rhs);

    };
    template <class _T, class _Container> 
    bool operator== (const stack<_T,_Container>& lhs, const stack<_T,_Container>& rhs) { return (lhs.arr == rhs.arr); }


    template <class _T, class _Container> 
    bool operator != (const stack<_T,_Container>& lhs, const stack<_T,_Container>& rhs) { return (lhs.arr != rhs.arr); }

    template <class _T, class _Container> 
    bool operator < (const stack<_T,_Container>& lhs, const stack<_T,_Container>& rhs) { return lhs.arr < rhs.arr; }

    template <class _T, class _Container> 
    bool operator > (const stack<_T,_Container>& lhs, const stack<_T,_Container>& rhs) { return (lhs.arr > rhs.arr); }

    template <class _T, class _Container> 
    bool operator <= (const stack<_T,_Container>& lhs, const stack<_T,_Container>& rhs) { return (lhs.arr <= rhs.arr); }

    template <class _T, class _Container> 
    bool operator >= (const stack<_T,_Container>& lhs, const stack<_T,_Container>& rhs) { return (lhs.arr >= rhs.arr); }

    template <class T, class Container>  
    void swap (stack<T,Container>& x, stack<T,Container>& y) throw() { x.swap(y);   }
}
#endif