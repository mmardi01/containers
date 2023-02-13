/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:42:28 by mmardi            #+#    #+#             */
/*   Updated: 2023/02/13 20:56:17 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "vector.hpp"
#include <map>
# include "map.hpp"
# include "redBlackTree.hpp"
#include <algorithm>

int main ()
{
  ft::map<int,int> mp;
 std::vector<int> v;

    int ratio = 10000;
    for (int i = 0, j = 10; i < 30 * ratio; ++i, ++j) {
        mp.insert(ft::make_pair(i, j));
    }
    ft::map<int, int> mp2(mp.begin(), mp.end());
    ft::map<int, int>::iterator it = mp2.begin();
    for (int i = 0; i < 30 * ratio; ++i, it++) {
        v.push_back(it->first);
        v.push_back(it->second);
    }
    std::cout << v.size() << std::endl;
}
