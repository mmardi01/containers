/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:42:28 by mmardi            #+#    #+#             */
/*   Updated: 2023/01/05 22:51:07 by mmardi           ###   ########.fr       */
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
# include "redBlackTree.hpp"

int main()
{
  Node<int> *a = new Node<int>(5);
  Node<int> *s = new Node<int>(9);
  Node<int> *bcmp = new Node<int>(4);
  Node<int> *bcmp2 = new Node<int>(3);
  RedBlackTree<int> b;
  b.insert(a);
  b.insert(bcmp);
  b.insert(bcmp2);
  b.insert(s);
  Node<int>* tmp = a;
  while(tmp) {
    std::cout << tmp->data << std::endl;
    tmp = tmp->left;
  }
  
}