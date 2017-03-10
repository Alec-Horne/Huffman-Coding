// making a heap
#ifndef HEAP_HPP
#define HEAP_HPP

#include <cassert>
#include <iostream>
#include <vector>
#include "HNode.hpp"

class Heap {
protected:
  // holds the tree
  std::vector<HNode*> tree;

  // index of the last element added
  int position = 0;

public:
  Heap() { tree.resize(2); }
  virtual ~Heap() {}

  //Number of items in heap
  int count;

  // add an element to the tree
  void enqueue(HNode*);
  // fix the heap from a specific index up
  void fix_up(const int&);

  // remove the smallest element
  HNode* dequeue();
  // fix the tree after replacing the smallest element
  void fix_down(const int&);

  void swap(const int&, const int&);

  void display();

  void clear();

  void clear_recursively(HNode*);

};

void Heap::enqueue(HNode* node) {
  // check to see if we need to expand the vector
  if (position == tree.size() - 1)
    tree.resize(tree.size() * 2);

  // insert at the next position
  tree[++position] = node;

  // fix up to the root (or until we dont need to swap)
  fix_up(position);
  // done

  count += 1;
}

HNode* Heap::dequeue() {
  assert(position);

  HNode* ret = tree[1];
  swap(1, position--);
  fix_down(1);
  count -= 1;
  return ret;
}

void Heap::swap(const int& a, const int& b) {
  HNode* temp = tree[a];
  tree[a] = tree[b];
  tree[b] = temp;
}

void Heap::display() {
  for (int i = 1; i <= position; ++i)
    std::cout << "[" << tree[i]->weight << "]";
  std::cout << std::endl;
}

void Heap::fix_up(const int& t) {
  // at the top of the tree
  if (t == 1)
    return;

  // if current is < its parent
  if (*tree[t] < *tree[t/2]) {
    swap(t, t/2);
    fix_up(t/2);
  }
}

void Heap::fix_down(const int& t) {
  int left_index = t * 2;
  int right_index = (t * 2) + 1;

  // if two children
  if (right_index <= position) {
    // check for the smallest of the children and treat like one child but recurse
    if (*tree[left_index] < *tree[right_index]) {
      if (*tree[left_index] < *tree[t]) {
	swap(left_index, t);
	fix_down(left_index);
      }
    }
    else {
      if (*tree[right_index] < *tree[t]) {
	swap(right_index, t);
	fix_down(right_index);
      }
    }
  }
  // one  child
  else if (left_index <= position) {
    if (*tree[left_index] < *tree[t])
      swap(left_index, t);
  }
}

void Heap::clear(){
    if(tree[0] == nullptr)
       return;

    for(int x = 0; x <= tree.size() - 1; x++)
        dequeue();
}

#endif
