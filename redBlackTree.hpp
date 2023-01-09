/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:37:28 by mmardi            #+#    #+#             */
/*   Updated: 2023/01/09 03:26:32 by mmardi           ###   ########.fr       */
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

    _Node minimum(_Node x) {
      _Node node = x;
      while (node->left != _null)
        node = node->left;
      return node;
        
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

   void deleteFixer(_Node x) {
      _Node s;
      while (x != root && x->color == 0)
      {
        if (x == x->parent->left)
        {
            s = x->parent->right;
            if (s->color == 1)
            {
              s->color = 0;
              x->parent->color = 1;
              leftRotate(x->parent);
              s = x->parent->right;
            }

            if (s->left->color == 0 && s->right->color == 0)
            {
              s->color = 1;
              x = x->parent;
            }
            else
            {
              if (s->right->color == 0)
              {
                s->left->color = 0;
                s->color = 1;
                rightRotate(s);
                s = x->parent->right;
              }

              s->color = x->parent->color;
              x->parent->color = 0;
              s->right->color = 0;
              leftRotate(x->parent);
              x = root;
            }
        }
        else
        {
            s = x->parent->left;
            if (s->color == 1)
            {
              s->color = 0;
              x->parent->color = 1;
              rightRotate(x->parent);
              s = x->parent->left;
            }

            if (s->right->color == 0 && s->right->color == 0)
            {
              s->color = 1;
              x = x->parent;
            }
            else
            {
              if (s->left->color == 0)
              {
                s->right->color = 0;
                s->color = 1;
                leftRotate(s);
                s = x->parent->left;
              }

              s->color = x->parent->color;
              x->parent->color = 0;
              s->left->color = 0;
              rightRotate(x->parent);
              x = root;
            }
        }
      }
      x->color = 0;
   }

   
  void transplant(_Node u, _Node v) {
      if (u->parent == _null)
      {
        root = v;
      }
      else if (u == u->parent->left)
      {
        u->parent->left = v;
      }
      else
      {
        u->parent->right = v;
      }

    v->parent = u->parent;
  }

  public:
    RedBlackTree() : root(NULL)  {
    _null = new Node<T>;
    _null->color = 0;
    _null->left = nullptr;
    _null->right = nullptr;
    }
    void insert(_Node _newNode) {
    _newNode->left = _null;
    _newNode->right = _null;
    _Node x = this->root;
    _Node y = _null;
    if (root == NULL)
    {
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

    void deleteNode(_Node d_node) {
      _Node x = this->root;
      _Node y;

      while(x != d_node) {
        if (d_node->data >= x->data)
          x =  x->right;
        else 
          x = x->left;
        if (x == _null) {
          std::cout << "node not found\n";
          return;
        }
      }
      int o_color = x->color;
      if (x->left == _null) {
        y = x->right;
        transplant(x, x->right);
      }
      else if (x->right == _null)
      {
        y = x->left;
        transplant(x, x->left);
      }
      else {
        _Node min = minimum(x->right);
        o_color = min->color;
        y = min->right;
        if (min->parent == x){
          y->parent =  min;}
        else{
          transplant(min, min->right);
          min->right = x->right;
          min->right->parent = min;
        }
        transplant(x,min);
        min->left = x->left;
        min->left->parent = y;
        min->color = o_color;
      }
      delete x;
      if (o_color == 0) {
        deleteFixer(y);
      }
    }
};

#endif