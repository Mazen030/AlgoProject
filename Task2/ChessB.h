//
// Created by George Welson on 28-Nov-22.
//

#ifndef KNIGHT_PROJ_CHESSB_H
#define KNIGHT_PROJ_CHESSB_H
#include "Node.h"
#include "Constant.h"
class ChessB{
public:
    Node cb[N][N];
    Node* src;
    Node* current;
    Node* pathK[N*N];
    int cnt;
    ChessB(int x,int y);
    void addNexts();//creates pieces Nodes
    void addKnight(int i, int j);//creates Knight nodes
    void choosePathKWarnsdorff();
    void choosePathKBacktracking();
};
#endif
