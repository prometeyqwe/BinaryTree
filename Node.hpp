//
//  Node.hpp
//  BinaryTree2
//
//  Created by Евгений Киримов on 22.08.2018.
//  Copyright © 2018 Евгений Киримов. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>

class Node{
private:
    int data;
    Node* left;
    Node* right;
public:
    void setData(int x);
    int getData();
    
    void setLeft(Node* x);
    Node* getLeft();
    
    void setRight(Node* x);
    Node* getRight();
};


#endif /* Node_hpp */
