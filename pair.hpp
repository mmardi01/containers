/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:24:36 by mmardi            #+#    #+#             */
/*   Updated: 2023/01/03 20:36:04 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{
    template <class _T1, class _T2> 
    class pair {
        
        private:
            _T1 __first;
            _T2 __second;
    } ;
} // namespace ft


#endif