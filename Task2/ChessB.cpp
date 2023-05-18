//
// Created by George Welson on 28-Nov-22.
//
#include "ChessB.h"


/*
 * 1- This is the constructor of the chess game which builds the 8 x 8 chess board with the nodes
 * 2- A node represent a square in the board e.g. : a1 , h8 , etc.
 * 3- A vector is used to insert all nodes into it thus implementing the idea of "Graph"
 *   which makes it easy to traverse through the board
 * */

ChessB::ChessB(string src)
{
    string temp="a1";
    for(int i= 0; i<N;i++){
        for(int j=0;j<N;j++){
            temp[1] = '1'+i;
            temp[0] = 'a'+j;
            Node k(temp);
            cb[i][j]=k;
        }
    }
    for(int i=0;i<N*N;i++){
        this->pathK[i]=NULL;
    }
    cnt=0;
    this->src=&this->cb[src[1] - '1'][src[0] - 'a'];
    this->src->visited=true;
    this->current=this->src;
    this->pathK[cnt]=this->current;
    cnt++;
}


/*
 4-This function is implemented to avoid the chess pieces used (knight, pawn, bishop) to go
 out of the chess board (A chess piece can't go beyond A & H, and 1 & 8)
 */



/*
 5-This function is used to create the nodes available for the chess pieces used (knight, pawn, bishop)
 to move to, it also implements the isValid function to make sure that the pieces stays in board
*/

void ChessB::addNexts() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            addKnight(i, j);
        }
    }
}


/*
 addKnight is a function used to create the nodes available for the knights to move to
  it's implemented using the xMovesK and yMovesK which is the positions the knight can move to
 */
void ChessB::addKnight(int i, int j) {
    int y = 0;
    for (int k = 0; k < N; k++) {
        char temp[2];
        temp[0] = this->cb[i][j].pos[0] + xMovesK[k];
        temp[1] = this->cb[i][j].pos[1] + yMovesK[k];
        if (!(isValid(temp)))
            this->cb[i][j].nextK[y]=NULL;
        else {
            this->cb[i][j].nextK[y] = &this->cb[temp[1] - '1'][temp[0] - 'a'];
            this->cb[i][j].deg++;
            y++;
        }
    }
}

/*
 addPawn is a function used to create the nodes available for the pawn to move to
 it's implemented using the xMovesP and yMovesP which is the positions the pawn can move to
 */

/*
 addBishop is a function used to create the nodes available for the bishop to move to,
 it's implemented using the xMovesB and yMovesB which is the positions the bishop can move to
 */

void ChessB::choosePathKWarnsdorff() {
    Node* tmp= nullptr;
    for(int i=0;i<N*N-1;i++){
        tmp = this->current->getLowestNext();
        if (tmp == nullptr)
            break;
        else {
            this->current = tmp;
            this->current->visit();
            this->pathK[cnt]=tmp;
            cnt++;
        }
    }
}
void ChessB::choosePathKBacktracking() {
    Node* tmp= nullptr;

    for(int j=0;j<N*N;j++){
        //int trial=0;
        for(int i=0;(i<8);i++) {
            tmp = this->current->nextK[i];
            //trial++;
            if (tmp == nullptr||(tmp->visited == true && i>=7)) {//backtracking
                this->current->visited= false;
                cnt-=2;
                this->current = this->pathK[cnt];
                i=this->current->trav-1;
                cnt++;
                this->pathK[cnt]=NULL;
                j=cnt-1;
                continue;
            }
            else if (tmp->visited == true)
                continue;
            else {
                this->current->trav=i+1;
                this->current = tmp;
                this->current->visited=true;
                this->pathK[cnt] = tmp;
                cnt++;
                break;
            }
        }
    }
}