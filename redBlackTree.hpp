/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:37:28 by mmardi            #+#    #+#             */
/*   Updated: 2023/01/05 22:50:56 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RDB_HPP
#define RDB_HPP

template<class T>
struct Node {
  T data;
  Node *parent;
  Node *left;
  Node *right;
  int color;
  Node() :  parent(NULL) ,left(NULL) ,right(NULL),  color(1) {}
  Node(const T &val) : data(val), parent(NULL) ,left(NULL) ,right(NULL),  color(1) {}
};


template <class T>
class RedBlackTree {
  public:
    typedef Node<T>* _Node;
  private:
    _Node root;
    _Node _null;
  public:
    RedBlackTree() : root(NULL) , _null(NULL) {}
    void insert(_Node _newNode) {
      _Node x = this->root;
      if (root == NULL) {
        // std::cout << "root: " << _newNode->data << std::endl;
        _newNode->color = 0;
        root = _newNode;
      }
      else {
        while(x != _null) {
          if (_newNode->data >= x->data) {
            std::cout << "toright: " << _newNode->data << std::endl;
            x = x->right;
          }
          else {
            std::cout << "toleft: " << _newNode->data << std::endl;
            x = x->left;
          }
        }
        x = _newNode;
      }
    }
};

#endif