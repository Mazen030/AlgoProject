//
// Created by George Welson on 15-May-23.
//
#include "Constant.h"
bool isValid(string str) {
    if(str[0]<'a'||str[0]>'h'||str[1]<'1'||str[1]>'8')
        return false;
    else
        return true;
}