
#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;
    while(n % 4 != 0){
        cout << "no solution " << endl << "re-enter :  ";
        cin >> n;
    }
    int arr[n];
    bool flag = false;
    bool used[n];
    int pairs[n];
    for(int i = 0 ; i < n ; i++){
        arr[i] = 1;
        used[i] = false;
    }
    int movee = 1;
    int temp = 0;
    int min_moves  = 0;
    int j = 0;
    int ind = 1;
    int constt = 1;
    int a = 0;
    while(a != ((n/4) - 1)){
        if(arr[j] == 1){
            constt = movee;
            ind = j;
            while(constt != -1){
                j++;
                constt -= arr[j];
            }
            pairs[ind] = j;
            pairs[j] = ind;
            arr[ind] = 0;
            arr[j] = 0;
            movee++;
            a++;
           // cout << ind << " " << j << endl;
            j = ind;
        }
        j++;
    }
    int newi;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] == 1){
            newi = i;
            break;}
    }
 //   cout << newi << " " << movee;
    int left_temp = movee;
    int k = 0;
    for(int i = newi ; i < n ; i++){
        if(arr[i] == 1){
            left_temp = movee;
            k = i;
            while(left_temp != -1){
                left_temp -= arr[k];
                k++;
            }
            arr[k] = 2;
            arr[i] = 0;
            movee++;
            pairs[i] = k;
            pairs[k] = i;
        }
    }
    int index = 1;
    int result = 0;
    for(int i = 0 ; i < n ; i++){
        if(!used[i] && !used[pairs[i]]){
            cout <<"The "<< index << " pair is : " <<  i << " with " <<  pairs[i] << endl;
            used[i] = true;
            used[pairs[i]] = true;
            index++;
            result++;
        }

    }
    cout << "The total number of moves  = " << result << endl;


}
