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
            if (root -> isleaf) root -> insertInNode(data);
          }
          if ( (root -> numberkeys) == degree - 1)  {
            Node<T> *newNode = new Node<T>(root -> size, false);
            newNode -> child[0] = root; 
            newNode -> splitChildNode(0, root); 
            int temp = 0; 
            if ( newNode -> keys[0] < data) temp++; 
            newNode -> childs[temp] -> insertInNode(data); 
            root = newNode; 
          }  
        }

        bool remove(int k) {
          if (!search) return false;
        }

        void print() {
            if (!root) cout << "There are not elements in the Btree" << endl;
            root -> TraverseToPrint();

        }

        ~BTree()  {

        }
};

#endif