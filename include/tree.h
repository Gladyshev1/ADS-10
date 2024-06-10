// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <iostream>
#include <vector>

struct Node {
    std::vector<Node*> vecch;
    char data;
};

class MYtree {
 public:

     void add(std::vector<char>, Node*);
     explicit MYtree(std::vector<char>);
    Node* root;

 private:
    int size;


};

inline void MYtree::add(std::vector<char> nach, Node* root) {
    for (int i = 0; i < nach.size(); i++) {
        Node* node = new Node;
        node->data = nach[i];
        root->vecch.push_back(node);
        std::vector<char> vecEnd = nach;
        vecEnd.erase(vecEnd.begin() + i);
        add(vecEnd, node);
    }
}
inline MYtree::MYtree(std::vector<char> nach) {
    root = new Node;
    add(nach, root);
}

#endif  // INCLUDE_TREE_H_
