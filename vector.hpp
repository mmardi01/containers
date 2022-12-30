/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:42:08 by mmardi            #+#    #+#             */
/*   Updated: 2022/12/30 01:46:34 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HP
#include<stdio.h>
#include <iostream>
#include "vectorIterator.hpp"


namespace ft
{
    template <class T, class Alloc = std::allocator<T> >
    class vector
    {
    private:
        T *arr;
        size_t __size;
        size_t __capacity;
        Alloc _allocator;
        
    public:
        typedef Alloc                                    allocator_type;
        typedef T                                        value_type;
        typedef typename allocator_type::reference       reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer         pointer;
        typedef typename allocator_type::const_pointer   const_pointer;
        typedef vectorIterator<T>                        iterator;
        typedef const vectorIterator<T>                  const_iterator;
        typedef size_t                                   size_type;

        // _________________/ Constructors \_________________ //
        vector(const allocator_type &alloc = allocator_type())
        {
            __size = 0;
            arr = NULL;
            _allocator = alloc;
            __capacity = 0;
        };
        vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
        {
            _allocator = alloc;
            __capacity = n;
            __size = n;
            arr = _allocator.allocate(n);
            for (size_t i = 0; i < n; i++)
            {
                this->arr[i] =  val;
            }
        };
        vector(const vector& x)
        {
            _allocator = x.get_allocator();
            __size = x.size();
            __capacity = x.size();
            arr = _allocator.allocate(__capacity);
            for (size_t i = 0; i < __size; i++)
            {
                arr[i] = x.arr[i];
            }
            
        };
        vector& operator = (const vector& x) {
            __size = x.size();
            _allocator = x.get_allocator();
            if (__capacity < x.capacity()) {
                _allocator.deallocate(arr, __capacity);
                __capacity = x.capacity();
                arr = _allocator.allocate(__capacity);
            }
            for (size_t i = 0; i < __size; i++)
            {
                arr[i] = x.arr[i];
            }
            return *this;
        };


        // _________________/ Destructor \_________________ //

        ~vector() {
            __size = 0;
            _allocator.deallocate(arr,__capacity);
            __capacity = 0;
        };
        
        // _________________/ Iterators \_________________ //

        iterator begin() {
            
            return iterator(&arr[0]);
        }
        
        const_iterator begin() const
        {

            return const_iterator(&arr[0]);
        }

        iterator end()
        {

            return iterator(&arr[__size]);
        }

        const_iterator end() const
        {

            return const_iterator(&arr[__size]);
        }
        
        const_iterator cbegin() const throw() {

            return const_iterator(&arr[0]);
        }

        const_iterator cend() const throw()
        {

            return const_iterator(&arr[__size]);
        }

        // _________________/ Capacity \_________________ //
        
        size_type size() const {
            return __size;
        };

        size_type capacity() const {
            
            return __capacity;
        };
        
        // _________________/ Element access \_________________ //

        reference operator[](size_type n) {
            
            return arr[n];
        };

        const_reference operator[](size_type n) const {
            
            return arr[n];
        };

        reference at(size_type n) {
            
            return arr[n];
        };

        const_reference at(size_type n) const {

            return arr[n];
        };

        reference front() {
            
            return arr[0];
        };
        
        const_reference front() const {
            
            return arr[0];
        };

        reference back() {
            
            return arr[__size - 1];
        };

        const_reference back() const {

            return arr[__size - 1];
        };

        value_type* data() throw() {

            return &arr[0];
        };

        const value_type* data() const throw() {

            return &arr[0];
        };

        // _________________/ Modifiers \_________________ //
        
        void assign (size_type n, const value_type& val) {

           __size = n;
           if (__capacity < n) {
                _allocator.deallocate(arr, __capacity);
                arr = _allocator.allocate(n);
                __capacity = n;
           }
           for (size_t i = 0; i < __size; i++)
           {
                arr[i] = val;
           }
           
        } 
        
        void push_back (const value_type& val) {
            ft::vector<value_type> tmp;
            if (__size == __capacity) {
                tmp = *this;
                _allocator.deallocate(arr, __capacity);
                __capacity *= 2;
                arr = _allocator.allocate(__capacity);
                *this = tmp;
            }
            if (__capacity == 0) 
                __capacity++;
            arr[__size] = val;
            __size++;
        }

        void pop_back() {
            __size--;
        }

        void clear() {

            __size = 0;
        }

        void swap(vector &x) {
            value_type tmpSize = __size;
            value_type tmpCapacity = __capacity;
            Alloc tmpAllocator = _allocator;
            T* tmpArr = arr;
            
            __size = x.size();
            __capacity = x.capacity();
            arr = x.arr;
            _allocator = x.get_allocator();
            
            x.__size = tmpSize;
            x.__capacity = tmpCapacity;
            x._allocator = tmpAllocator;
            x.arr = tmpArr;
        }

        // _________________/ Allocator \_________________ //

        allocator_type get_allocator() const {

            return _allocator;
        };
    };
}

#endif