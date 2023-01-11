/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:42:28 by mmardi            #+#    #+#             */
/*   Updated: 2023/01/11 17:12:11 by mmardi           ###   ########.fr       */
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
  Node<int> *a = new Node<int>(10);
  Node<int> *b = new Node<int>(11);
  Node<int> *c = new Node<int>(9);
  Node<int> *d = new Node<int>(9);
  Node<int> *e = new Node<int>(12);
  Node<int> *f = new Node<int>(10);
  Node<int> *g = new Node<int>(10);
  RedBlackTree<int> tree;
  tree.insert(a);
  tree.insert(b);
  tree.insert(c);
  tree.insert(d);
  tree.insert(e);
  tree.insert(f);
  tree.insert(g);
  tree.deleteNode(e);
  std::cout << tree.root->data << " color :" << tree.root->color << std::endl;
  std::cout << tree.root->right->data << " color :" << tree.root->right->color << std::endl;
  std::cout << tree.root->right->right->data << " color :" << tree.root->right->right->color << std::endl;
  std::cout << tree.root->right->left->data << " color :" << tree.root->right->left->color << std::endl;
  std::cout << tree.root->right->left->right->data << " color :" << tree.root->right->left->right->color << std::endl;
}