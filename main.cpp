/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:42:28 by mmardi            #+#    #+#             */
/*   Updated: 2023/01/04 02:20:25 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "reverse_iterator.hpp"
#include <vector>
# include <cstdlib>
#include <memory>
#include <iterator> // std::iterator, std::input_iterator_tag
#include <iostream>
#include <vector>
# include "stack.hpp"
#include <map>
# include <algorithm>
#include <stack>
# include "enable_if.hpp"
# include "pair.hpp"

int main()
{
  ft::pair<std::string, int> planet, homeplanet;

  planet = ft::make_pair("Earth", 6371);

  homeplanet = planet;

  std::cout << "Home planet: " << homeplanet.first << '\n';
  std::cout << "Planet size: " << homeplanet.second << '\n';
  return 0;
}