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

        }
    friend class BTree; 
};

#endif