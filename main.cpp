/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:42:28 by mmardi            #+#    #+#             */
/*   Updated: 2023/02/04 18:23:48 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "vector.hpp"
#include <map>
# include "pair.hpp"

int main() {
  std::map<int,int> a;
  a.insert(std::pair<int,int>(1,1));
  std::map<int,int>::iterator it = a.begin();
  (void)it;
  // *it = std::pair<int,int>(2,2);
  // std::cout << it->first << std::endl;
  
}
