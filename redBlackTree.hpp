/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:37:28 by mmardi            #+#    #+#             */
/*   Updated: 2023/01/06 02:56:55 by mmardi           ###   ########.fr       */
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
    
    void insertFixer(_Node node) {

      if (node->parent->color == 0)
        return;
      // else {
      //   while(node-parent->color == 1) {
      //     if (node->parent->parent->left-color == 1 && node->parent->right->color == 1) {
      //       node->parent->parent->left->color == 0;
      //       node->parent->parent->color == 1;
      //       node->parent->right->color == 0;
      //     }
      //     else {
      //       if (node == node->parent->parent->right->right)
      //     }
      //     node = node->parent;            
      //   }
      // }
    }
    
  public:
    RedBlackTree() : root(NULL) , _null(NULL) {}
    void insert(_Node _newNode) {
      _Node x = this->root;
      _Node y = _null;
      if (root == NULL) {
        _newNode->color = 0;
        root = _newNode;
      }
      else {
        while(x != _null) {
          y = x; 
          if (_newNode->data >= x->data) {
            x = x->right;
          }
          else {
            x = x->left;
          }
        }
        _newNode->parent = y;
        if (_newNode->data >= y->data)
          y->right = _newNode;
        else  
          y->left = _newNode;
        insertFixer(_newNode);
      }
    }
};

#endif