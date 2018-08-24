//
//  main.cpp
//  BinaryTree2
//
//  Created by Евгений Киримов on 22.08.2018.
//  Copyright © 2018 Евгений Киримов. All rights reserved.
//

#include <iostream>
#include "Tree.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    Tree *tree = new Tree();
    tree->insert(50);
    tree->insert(75);
    tree->insert(62);
    tree->insert(87);
    tree->insert(77);
    tree->insert(79);
    tree->insert(93);
    tree->del(75);
    std::cout << "Hello, World!\n";
    return 0;
}
