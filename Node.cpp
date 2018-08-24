//
//  Node.cpp
//  BinaryTree2
//
//  Created by Евгений Киримов on 22.08.2018.
//  Copyright © 2018 Евгений Киримов. All rights reserved.
//

#include "Node.hpp"

void Node::setData(int x){
    this->data = x;
}

int Node::getData(){
    return this->data;
}

void Node::setLeft(Node* x){
    this->left = x;
}

Node* Node::getLeft(){
    return this->left;
}

void Node::setRight(Node* x){
    this->right = x;
}

Node* Node::getRight(){
    return this->right;
}

