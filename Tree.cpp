//
//  Tree.cpp
//  BinaryTree2
//
//  Created by Евгений Киримов on 22.08.2018.
//  Copyright © 2018 Евгений Киримов. All rights reserved.
//

#include "Tree.hpp"

void Tree::insert(int key){
    Node* newNode = new Node();
    newNode->setData(key);
    if(root == NULL){
        root = newNode;
    }else{
        Node* current = root;
        Node* parent = current;
        
        while(current!=NULL){
            parent = current;
            if(key<current->getData()){
                current = current->getLeft();
                if(current==NULL){
                    parent->setLeft(newNode);
                    return;
                }
            }else{
                current = current->getRight();
                if(current == NULL){
                    parent->setRight(newNode);
                    return;
                }
            }
        }
    }
}

void Tree::inOrder(Node* node){
    if(node!=NULL){
        inOrder(node->getLeft());
        std::cout << node->getData() << " ";
        inOrder(node->getRight());
    }
    
    
}

bool Tree::find(int key){
    Node* current = root;
    while(current->getData()!=key){
        if(key<current->getData())
            current = current->getLeft();
        else
            current = current->getRight();
        if(current == NULL) return false;
    }
    return true;
}

Node* Tree::getSuccesser(Node* node){
    Node* current = node->getRight();
    Node* successorParent = node;
    Node* successor = node->getRight();
    
    while(current!=NULL){
        successorParent = successor;
        successor = current;
        current =  current->getLeft();
    }
    
    if(successor != node->getRight()){
        successorParent->setLeft(successor->getRight());
        successor->setRight(node->getRight());
    }
    return successor;
    
}

bool Tree::del(int key){
    Node* current = root;
    Node* parent = current;
    bool isLeft = false;
    
    while(current->getData()!=key){
        if(key<current->getData()){
            isLeft = true;
            parent = current;
            current = current->getLeft();
        }
        else{
            isLeft = false;
            parent = current;
            current = current->getRight();
        }
        if(current == NULL) return false;
    }
    
    if(current->getLeft() == NULL && current->getRight() == NULL){
        if(current == root){
            root = NULL;
        }
        
        else{
            if(isLeft){
                delete parent->getLeft();
                parent->setLeft(NULL);
            }else{
                parent->setRight(NULL);
                delete parent->getRight();
            }
        }
        
    }else if(current->getLeft()==NULL){
        if(current == root)
            root = current->getRight();
        else{
            if(isLeft)
                parent->setLeft(current->getRight());
            else
                parent->setRight(current->getRight());
        }
    }else if(current->getRight() == NULL){
        if(current == root)
            root = current->getLeft();
        else{
            if(isLeft){
                parent->setLeft(current->getLeft());
            }else{
                parent->setRight(current->getLeft());
            }
        }
    }else{
        Node* successor = getSuccesser(current);
        if(current == root){
            root = successor;
        }
        else{
            if(isLeft){
                parent->setLeft(successor);
            }else{
                parent->setRight(successor);
            }
        }
        successor->setLeft(current->getLeft());
    }
    return true;
    
}

Node* Tree::minimum(){
    Node* current = root;
    Node* last = current;
    while(current!=NULL){
        last = current;
        current = current->getLeft();
    }
    return last;
}

Node* Tree::maximum(){
    Node* current = root;
    Node* last = current;
    while(current!=NULL){
        last = current;
        current = current->getRight();
    }
    return last;
}

Node* Tree::getRoot(){
    if(root)
        return root;
    else{
        std::cout << "root is NULL" << std::endl;
        return NULL;
    }
}
