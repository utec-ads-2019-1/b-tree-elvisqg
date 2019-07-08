#ifndef NODE_H
#define NODE_H

#include <vector>
#include <set>
using namespace std;

template <typename T>
class Node {
    unsigned int size;
    unsigned int numkeys;
    vector<unsigned int> keys;
    vector<Node<T>*> childs;
    bool isLeaf;

    public: 
        Node(unsigned int size, bool isLeaf) : size(size), isLeaf(isLeaf) {
            keys.resize(size - 1);
            childs.resize(size);
            numkeys = 0;
        }

        Node<T>* searchElement(int k)  {
            unsigned int count = 0;
            while (count < numkeys && k >= keys[count]) count++;
            if (keys[count] == k) return this;
            if (isLeaf) return nullptr;
            return childs[count] ->searchElement(k);
            /*for (auto it : numkeys) {
              if (it < k) continue;
              if (it == k) return this;
              break;
            }*/
        }

        void TraverseToPrint() {
          if (!isLeaf) {
            for (int it = 0; it < numkeys; it++)  {
              childs[it] -> TraverseToPrint();
              cout << keys[it] << " ";
            }  
          }
          for (int it = 0; it < numkeys; it++)  {
            cout << keys[it] << " ";
          }
        }

        void insertInNode(T data) {
          unsigned int num = numkeys-1;
          if (isLeaf) {
            while ( num >= 0 && keys[num] > data) { 
              keys[num+1] = keys[num]; 
              num--; 
            }  
            keys[num+1] = data; 
            numkeys++;
            return;
          }
          while (num >= 0 && keys[num] > data) num--;       
          if (childs[num+1] -> numkeys < size-1) childs [num+1] -> insertInNode(data);
          splitChildNode(num+1, childs[num+1]);
        }

       void splitChildNode(unsigned int num, Node<T>* child) {
          Node<T> *newNode = new Node<T>(child -> size, child -> isLeaf);
          newNode -> numkeys = size - 1; 
          for (unsigned int it = 0; it < size-1; it++) {
              newNode -> keys[it] = child -> keys[it+size]; 
          }    
          if (!child -> isLeaf) { 
            for (unsigned int it = 0; it < size; it++) {
              newNode -> childs[it] = child -> childs[it+size]; 
            }
          } 
          child -> numkeys = size - 1; 
          for (int it = size; it >= num+1; it--) {
              childs[it+1] = childs[it]; 
          }     
          childs[num+1] = newNode; 
        
          // A key of y will move to this node. Find the location of 
          // new key and move all greater keys one space ahead 
          for (int it = size-1; it >= num; it--) 
              keys[it+1] = keys[it]; 
        
          // Copy the middle key of y to this node 
          keys[num] = child -> keys[numkeys-1]; 
        
          // Increment count of keys in this node 
          size++; 
        }
    friend class BTree; 
};

#endif