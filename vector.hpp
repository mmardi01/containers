/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:42:08 by mmardi            #+#    #+#             */
/*   Updated: 2022/12/31 21:30:56 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include<stdio.h>
#include <iostream>
#include "vectorIterator.hpp"
#include "reverse_iterator.hpp"

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
        typedef Alloc                                               allocator_type;
        typedef T                                                   value_type;
        typedef typename allocator_type::reference                  reference;
        typedef typename allocator_type::const_reference            const_reference;
        typedef typename allocator_type::pointer                    pointer;
        typedef typename allocator_type::const_pointer              const_pointer;
        typedef vectorIterator<T>                                   iterator;
        typedef const vectorIterator<T>                             const_iterator;
        typedef ft::reverse_iterator<iterator>                      reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>                const_reverse_iterator;
        typedef typename iterator_traits<iterator>::difference_type difference_type;
        typedef size_t                                              size_type;

        // _________________/ Constructors \_________________ //
        explicit vector (const allocator_type &alloc = allocator_type())
        {
            __size = 0;
            arr = NULL;
            _allocator = alloc;
            __capacity = 0;
        };
        

        vector (size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
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
        
        template <class InputIterator> 
        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) {
            
            _allocator = alloc;
            difference_type n = last - first;
            arr = _allocator.allocate(n);
            __capacity = n;
            __size = n;
            for (size_t i = 0; first != last; first++)
            {
                arr[i] = *first;
                i++;
            }
            
        }
        
        vector (const vector& x)
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

        reverse_iterator rbegin(){

            return (reverse_iterator(this->end()));
        }

        const_reverse_iterator rbegin() const {

            return (reverse_iterator(this->end()));
        }

        reverse_iterator rend() {

            return (reverse_iterator(this->begin()));
        }

        const_reverse_iterator rend() const {

            return (reverse_iterator(this->begin()));
        }

        const_iterator cbegin() const throw() {

            return const_iterator(&arr[0]);
        }

        const_reverse_iterator crbegin() const  {
            
            return (const_reverse_iterator(this->end()));
        }

        const_reverse_iterator crend() const {

            return (const_reverse_iterator(this->begin()));
        }

            const_iterator cend() const throw()
        {

            return const_iterator(&arr[__size]);
        }

        // _________________/ Capacity \_________________ //
        
        size_type size() const {
            return __size;
        };

        size_type max_size() const {

            return (_allocator.max_size());
        }

        size_type capacity() const {
            
            return __capacity;
        };

        void resize(size_type n, value_type val = value_type()) {

            if (__size < n) {
                if (n <= __capacity) {
                    while (__size < n) {

                        arr[__size] = val;
                        __size++;
                    }
                }
                else {
                        value_type *tmp = _allocator.allocate(__capacity);
                        for (size_t i = 0; i < __capacity; i++)
                        {
                            tmp[i] = arr[i];
                        }
                        
                        _allocator.deallocate(arr,__capacity);
                        arr = _allocator.allocate(n);
                        for (size_t i = 0; i < __capacity; i++)
                        {
                            arr[i] = tmp[i];
                        }
                        _allocator.deallocate(tmp, __capacity);
                        __capacity =  n;
                        while(__size < n) {
                            
                            arr[__size] = val;
                            __size++;
                        } 
                    }
            }
            __size = n;
        }

        bool empty() const {

            return (__size == 0);
        }

        void reserve(size_type n) {

            if (n > __capacity) {
                value_type *tmp = _allocator.allocate(__capacity);
                for (size_t i = 0; i < __capacity; i++)
                {
                        tmp[i] = arr[i];
                }
                _allocator.deallocate(arr,__capacity);
                arr = _allocator.allocate(n);
                for (size_t i = 0; i < __size; i++)
                {
                    arr[i] = tmp[i];
                }
                _allocator.deallocate(tmp,__capacity);
                __capacity = n;
            }
        }

        void shrink_to_fit() {
            value_type *tmp = _allocator.allocate(__capacity);
            for (size_t i = 0; i < __capacity; i++)
            {
                tmp[i] = arr[i];
            }
            _allocator.deallocate(arr, __capacity);
            arr = _allocator.allocate(__size);
            for (size_t i = 0; i < __size; i++)
            {
                arr[i] = tmp[i];
            }
            _allocator.deallocate(tmp,__capacity);
            __capacity = __size;
        }
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
        
        template <class InputIterator>
        void assign (InputIterator first, InputIterator last) {
            difference_type n = last - first;
            __size = n;
            if (__size > __capacity) {
                _allocator.deallocate(arr,__capacity);
                arr = _allocator.allocate(n);
                __capacity = n;
            }
            for (size_t i = 0; i < __size; i++)
            {
                arr[i] = *first;
                first++;
            }
            
        }
        
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
            if (__capacity == 0) { 
                __capacity++;
                arr = _allocator.allocate(1);
            }
            else if (__size == __capacity) {
                tmp = *this;
            std::cout << __capacity;
                _allocator.deallocate(arr, __capacity);
                __capacity *= 2;
                arr = _allocator.allocate(__capacity);
                *this = tmp;
            }
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