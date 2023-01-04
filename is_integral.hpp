/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:56:58 by mmardi            #+#    #+#             */
/*   Updated: 2023/01/04 00:38:21 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL
#define IS_INTEGRAL


namespace ft
{
    
    template <class T> 
    struct is_integral {
        
        static const bool value = false;
    };

    template <> 
    struct is_integral<bool> {
        
        static const bool value = true;
    };

    template <> 
    struct is_integral<char> {
        
        static const bool value = true;
    };

    //  template <> 
    // struct is_integral< char16_t > {
        
    //     static const bool value = true;
    // };

    //  template <> 
    // struct is_integral< char32_t > {
        
    //     static const bool value = true;
    // };

     template <> 
    struct is_integral<wchar_t> {
        
        static const bool value = true;
    };

     template <> 
    struct is_integral<signed char> {
        
        static const bool value = true;
    };

     template <> 
    struct is_integral<short int> {
        
        static const bool value = true;
    };

     template <> 
    struct is_integral<int> {
        
        static const bool value = true;
    };

     template <> 
    struct is_integral<long int> {
        
        static const bool value = true;
    };

     template <> 
    struct is_integral<long long int> {
        
        static const bool value = true;
    };

     template <> 
    struct is_integral<unsigned char> {
        
        static const bool value = true;
    };

     template <> 
    struct is_integral<unsigned short int> {
        
        static const bool value = true;
    };

     template <> 
    struct is_integral<unsigned int> {
        
        static const bool value = true;
    };

     template <> 
    struct is_integral<unsigned long int> {
        
        static const bool value = true;
    };

     template <> 
    struct is_integral<unsigned long long int> {
        
        static const bool value = true;
    };
} // namespace ft

#endif