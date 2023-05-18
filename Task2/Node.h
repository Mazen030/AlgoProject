//
// Created by George Welson on 28-Nov-22.
//

#ifndef KNIGHT_PROJ_NODE_H
#define KNIGHT_PROJ_NODE_H

#include <iostream>
#include <cstdlib>
#include <list>
#include <cstring>
#include <math.h>
#include "Constant.h"
using namespace std;
const int xMovesK[] = {1, 1, 2, 2, -1, -1, -2, -2};
const int yMovesK[] = {2, -2, 1, -1, 2, -2, 1, -1};


class Node{
public:
    typedef Node* NodePointer;
    bool visited;
    bool corner;
    int trav;
     string pos;
    int deg;
    NodePointer nextK[8];
    Node(string name);
    Node();
    Node(int x,int y);
    void display(ostream & out) const;
    void visit();
    Node* getLowestNext();
    Node& operator=(const Node& other);
    bool isNeighbour(Node* n);
};
ostream & operator<< (ostream & out, const Node & aNode);
#endif //KNIGHT_PROJ_NODE_H
