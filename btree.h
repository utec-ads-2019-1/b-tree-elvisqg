#ifndef BTREE_H
#define BTREE_H

#include "node.h"
#include <iostream>

using namespace std; 

template <typename T>
class BTree {
    private:
        Node<T>* root;
        unsigned int degree;

    public:
        BTree(unsigned int degree) : degree(degree), root(nullptr) {};

        Node<T>* search(int k) { 
          if (!root) {
            cout << "There are not elements in the Btree" << endl;
            return nullptr;
          }  
           return root -> searchElement(k);
        } 

        bool insert(int k, T data) {
          if (search(data))  return false;
          if (!root) {
            Node<T> newNode = new Node<T>(degree,true);
            newNode.keys.push_back(data);
            newNode.numberkeys += 1;
            root -> newNode;
          }
          if ( (root -> numberkeys) < degree - 1) {
            if (root -> isleaf) root -> keys.push_back(data);
            
          }
        }

        bool remove(int k) {
          if (!search) return false;
        }

        void print() {
            if (!root) cout << "There are not elements in the Btree" << endl;
            root -> TraverseToPrint();

        }

        ~BTree();
};

#endif