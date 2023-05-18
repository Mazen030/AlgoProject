//
// Created by George Welson on 28-Nov-22.
//
#include "Node.h"

/*
 this function initialize the nexts pointers of the node to null
 */


Node::Node(int r, int c):  visited(false), deg(0), corner(false), nextPossibleMove(0),r(r),c(c){
    //constructing a square
    for(int i=0;i<8;i++)
        this->nextK[i]=NULL;
    if((this->r==0 && this->c==0)||(this->r==0 && this->c==N-1)||(this->r==N-1 && this->c==0)||(this->r==N-1 && this->c==N-1)){
        this->corner = true;
    }
}
Node* Node::getLowestNext() {
    //returns next possible move with minimum degree that has not been visited before
    int min_deg=9;
    int min_deg_idx=-1;
    int start=rand()%8;
    for(int count = 0; count < 8; ++count){
        int i = (start + count)%8;
        if(this->nextK[i]==NULL)
            continue;
        if(this->nextK[i]->visited == false){
            if (this->nextK[i]->corner == true) {
                return this->nextK[i];
            }
            if (this->nextK[i]->deg < min_deg) {
                min_deg = this->nextK[i]->deg;
                min_deg_idx = i;
            }
        }
    }
    if(min_deg_idx==-1){
        return NULL;
    }
    return this->nextK[min_deg_idx];
}
void Node::visit() {
    this->visited=true;
    Node* tmp= this->nextK[0];
    int i;
    for(i=0;(tmp!= NULL)&&(i<8);i++){
        tmp->deg--;
        tmp=this->nextK[i+1];
    }
}

// Copy assignment operator
Node& Node::operator=(const Node& other)  {
    if (this != &other) {
        // Perform deep copy of data
    this->deg=other.deg;
    this->r=other.r;
    this->c=other.c;
    this->visited=other.visited;
    this->corner=other.corner;
    this->nextPossibleMove=other.nextPossibleMove;
    for(int i=0;i<8;i++){
        this->nextK[i]=other.nextK[i];
    }
    }
    return *this;
}
Node::Node(){

}
/*
This function formats the printing of the nodes
 */
void Node::display(ostream &out) const {
    out<<"Node Position: "<<this->r<<","<<this->c<<endl;
    out<<"Next Nodes for Knight:\n";
    for(int i=0;i<8;i++){
        if(this->nextK[i] == NULL)
            continue;
        else
            out << this->nextK[i]->r<<","<< this->nextK[i]->c << endl;
    }
}

bool Node::isNeighbour(Node *n) {
    for(int i=0;i<8;i++){
        if(this->nextK[i]==NULL)
            break;
        if(n->r==this->nextK[i]->r &&n->c==this->nextK[i]->c)
            return true;
    }
    return false;
}




ostream & operator<< (ostream & out, const Node & aNode)
{
    aNode.display(out);
    return out;
}
