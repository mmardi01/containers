/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:42:28 by mmardi            #+#    #+#             */
/*   Updated: 2023/02/14 20:15:55 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "vector.hpp"
#include <map>
# include "map.hpp"
# include "redBlackTree.hpp"
#include <algorithm>

void fd() 
{
    
    ft::map<int,int> mp;
    for (int i = 0, j = 0; i < 10; ++i, ++j)
        mp.insert(ft::make_pair(i, j));
}
int main ()
{
   fd();
    // ft::map<int,int> mp2;
    // for (int i = 25 * 10000, j = 0; i < 35 * 10000; ++i, --j)
    //     mp.insert(ft::make_pair(i, j));
    // long *adr1 = reinterpret_cast<long *>(&mp);
    // long *adr2 = reinterpret_cast<long *>(&mp2);
    // mp.swap(mp2);
    // if (reinterpret_cast<long *>(&mp) == adr1 && reinterpret_cast<long *>(&mp2) == adr2)
    // 	v.push_back(1);
    // v.push_back(mp2.size());
    // typename ft::map<int,int>::iterator it = mp2.begin();
    // for (; it != mp2.end(); ++it) {
    //     v.push_back(it->first);
    //     v.push_back(it->second);
    // }
    // std::swap(mp, mp2);
    // typename ft::map<int,int>::iterator it2 = mp2.begin();
    // for (; it2 != mp2.end(); ++it2) {
    //     v.push_back(it2->first);
    //     v.push_back(it2->second);
    // }
    system("leaks containers");
}