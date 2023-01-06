/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:37:28 by mmardi            #+#    #+#             */
/*   Updated: 2023/01/06 15:07:41 by mmardi           ###   ########.fr       */
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
  Node() :  parent(nullptr) ,left(nullptr) ,right(nullptr),  color(1) {}
  Node(const T &val) : data(val), parent(nullptr) ,left(nullptr) ,right(nullptr),  color(1) {}
};


template <class T>
class RedBlackTree {
  public:
    typedef Node<T>* _Node;
    _Node root;
  private:
    _Node _null;

    // rotations
    void leftRotate(_Node node) {
      _Node x = node->right;
      node->left = x->left;
      if (x->left) {
        x->left->parent = node;
      }
      x->parent = node->parent;
      if (!node->parent)
        root = x;
      else if (node == node->parent->left) 
        node->parent->left = x;
      else
        node->parent->right = x;
      x->left = node;
      node->parent = x;
        
    }

     void rightRotate(_Node node) {
      _Node x = node->left;
      node->left = x->right;
      if (x->right) {
        x->right->parent = node;
      }
      x->parent = node->parent;
      if (!node->parent)
        root = x;
      else if (node == node->parent->right) 
        node->parent->right = x;
      else
        node->parent->left = x;
      x->right = node;
      node->parent = x;
    }



    
    // insert fixer
    void insertFixer(_Node node) {
      if (node->parent->color == 0) {
        
        return;
      }
      else {
        while (node->parent->color == 1) {

            if (node->parent->parent->left == node->parent) {
              if (node->parent->parent->right && node->parent->parent->right->color == 1) {
                node->parent->color = 0;
                node->parent->parent->right->color = 0;
                node->parent->parent->color = 1;
                node = node->parent->parent;
              }
              else {
                if (node == node->parent->right) {
                  node = node->parent;
                  leftRotate(node);
                }
                node->parent->color = 0;
                node->parent->parent->color = 1;
                rightRotate(node->parent->parent);
              }
            }
            else {
              if (node->parent->parent->left && node->parent->parent->left->color == 1) {
                node->parent->color = 0;
                node->parent->parent->left->color = 0;
                node->parent->parent->color = 1;
                node = node->parent->parent;
              }
              else {
                if (node == node->parent->left) {
                  node = node->parent;
                  rightRotate(node);
                }
                node->parent->color = 0;
                node->parent->parent->color = 1;
                leftRotate(node->parent->parent);
              }
            }
            if (node == this->root)
              break ;
        }
        root->color = 0;
      }
    }
   ////////////////insert fixer 
  public:
    RedBlackTree() : root(nullptr) , _null(nullptr) {}
    void insert(_Node _newNode) {
      _Node x = this->root;
      _Node y = _null;
      if (root == nullptr) {
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