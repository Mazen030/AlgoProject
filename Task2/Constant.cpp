//
// Created by George Welson on 15-May-23.
//
#include "Constant.h"
bool isValid(int r,int c) {
    if(r<0||r>N-1||c<0||c>N-1)
        return false;
    else
        return true;
}