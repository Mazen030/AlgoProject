#include <iostream>
#include "ChessB.h"
#include <time.h>
#include "Constant.h"
using namespace std;
int main() {
    srand(time(NULL));
    while(true){
        ChessB x("h5");
        x.addNexts();
        x.choosePathKWarnsdorff();
        cout << x.cnt << endl;
        if (x.cnt == N*N  && x.pathK[0]->isNeighbour(x.pathK[N*N-1]) == true) {
            for(int i=0;i<N*N;i++){
                cout<<x.pathK[i]->pos<<endl;
            }
            break;
        }
    }
}
