#include <iostream>
#include "ChessB.h"
#include <time.h>
#include "Constant.h"
using namespace std;
int main() {
    srand(time(NULL));
    while(true){
        ChessB x(0,0);
        x.addNexts();
        x.choosePathKWarnsdorff();
        //x.choosePathKBacktracking();
        cout << x.cnt << endl;
        if (x.cnt == N*N  && x.pathK[0]->isNeighbour(x.pathK[N*N-1]) == true) {
            for(int i=0;i<N*N;i++){
                if(i%8==0)
                    cout<<endl;
                cout<<x.pathK[i]->r<<","<<x.pathK[i]->c<<"   ";
            }
            break;
        }
    }
}
