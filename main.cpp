/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:42:28 by mmardi            #+#    #+#             */
/*   Updated: 2023/02/18 18:44:35 by mmardi           ###   ########.fr       */
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
  ft::map<int,int> a;
  a.insert(ft::make_pair(1,1));
  ft::map<int,int> b;
  if (a == b) {
    puts("S");
  }


  return 0;
}