// Copyright 2022 NNTU-CS
#include  "tree.h"


int factorial(int i) {
    int ret = 1;
    for (int Q = 1; Q <= i; Q++) {
        ret *= Q;
    }
    return ret;
}

std::vector<char> getPerm(const MYtree& tree, int X) {
    std::vector<char> vec;
    if (X <= factorial(tree.root->vecch.size())) {
        auto root = tree.root;
        int i = factorial(root->vecch.size()) / root->vecch.size();
        for (int Q = 0; Q < root->vecch.size(); Q++) {
            if (X > Q * 2 && X <= i * (Q + 1)) {
                root = root->vecch[Q];
                vec.push_back(root->data);
            }
        }
        if (X % 2 != 1) {
            root = root->vecch[1];
            vec.push_back(root->data);
           
        }
        else {
            root = root->vecch[0];
            vec.push_back(root->data);
        }
        root = root->vecch[0];
        vec.push_back(root->data);
    }
    return vec;
}
