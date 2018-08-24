//
//  Tree.hpp
//  BinaryTree2
//
//  Created by Евгений Киримов on 22.08.2018.
//  Copyright © 2018 Евгений Киримов. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>
#include <iostream>

#include "Node.hpp"
class Tree{
private:
    Node* root;
public:
    void insert(int key);
    void inOrder(Node* node);
    bool find(int key);
    bool del(int key);
    Node* minimum();
    Node* maximum();
    Node* getRoot();
    Node* getSuccesser(Node* node);
};



#endif /* Tree_hpp */
