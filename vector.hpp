/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:42:08 by mmardi            #+#    #+#             */
/*   Updated: 2022/12/27 21:24:35 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HP

#include <iostream>

namespace ft
{
    template <class T, class Alloc = std::allocator<T> >
    class vector
    {
    private:
        T *tab;

    public:
        vector(){};
        vector(const vector &object)
        {
        }
        vector &operator=(const vector &object)
        {
        }
    };
}

#endif