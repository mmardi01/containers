/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:53:47 by mmardi            #+#    #+#             */
/*   Updated: 2023/03/01 15:34:52 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ENABLE_IF
#define ENABLE_IF
 
namespace ft
{
    template <bool Cond, class T = int> 
    struct enable_if {
        
    };
    
    template <class T> 
    struct enable_if<true,T> {
        typedef T type;
    };
} // namespace ft


# endif