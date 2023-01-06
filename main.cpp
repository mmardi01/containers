/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:42:28 by mmardi            #+#    #+#             */
/*   Updated: 2023/01/06 00:43:33 by mmardi           ###   ########.fr       */
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
  Node<int> *k = new Node<int>(2);
  Node<int> *d = new Node<int>(1);
  RedBlackTree<int> b;
  b.insert(a);
  b.insert(bcmp);
  b.insert(bcmp2);
  b.insert(s);
  b.insert(k);
  b.insert(d);
  Node<int>* tmp = a;
  while(tmp) {
    std::cout << tmp->data << std::endl;
    tmp = tmp->left;
  }
  
}