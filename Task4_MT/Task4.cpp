#include <iostream>
#include <string>
#include <cmath>
using namespace std;
// Define Macro constants
#define N 1000
#define NUM_SLAVES 10

// Check is a helper function to check which slave drank the poison by releasing the range of barrels
int check(int persons[][1], int day) {
    int poisonIndex =-1;
    string poisonHint = "";

    for (int i = 0; i <NUM_SLAVES; i++) {
        if (persons[i][0] == 1) {
            poisonIndex = i;
            switch (day) {
                case 1:
                    if(NUM_SLAVES==8){
                        if(i>5) {
                            poisonIndex = poisonIndex + 2;
                        }
                        else{poisonIndex=poisonIndex+1;}
                    }
                    poisonHint = " which ranges from " + to_string(abs(i * N / NUM_SLAVES)) + "-" + to_string(abs(i * (N / NUM_SLAVES)) + (abs(N / NUM_SLAVES - 1)));
                    break;
                case 2:
                    poisonHint = " which contains in number in form of X" + to_string(abs(i)) + "X";
                    break;
                case 3:
                    poisonHint = " which contains in number in form of XX" + to_string(abs(i));
                    break;
                default:
                    break;
            }
            cout << "Person " << (i + 1) << " is the one that drank poison" << poisonHint << endl;
            break;
        }
    }

    return poisonIndex;
}
/*
this function takes an array that is all filled with 0 except for the poisoned index which is 1,
 start and end points and starts divide and conquering on them, using recursive method
it divide and conquer and returns 1 if it’s found otherwise 0
 */
int findPoison(int arr[], int start, int end) {
    if (start == end) {
        return arr[start];
    }
    int midValue = (start + end) / 2;
    int leftValues = findPoison(arr, start, midValue);
    int rightValues = findPoison(arr, midValue + 1, end);
    return leftValues || rightValues;
}


//this function is used to determine certain parts, such as which the start and end for the divide and conquer.
void slaveTesting() {

//We start by declaring two 2D Arrays(secondSlaveArray, thirdSlaveArray), and two 1D array (sD3Array, eArray)
    int secondSlaveArray[NUM_SLAVES][N/NUM_SLAVES];
    int thirdSlaveArray[NUM_SLAVES][N/NUM_SLAVES];
    int sD3Array[NUM_SLAVES];
    int eArray[NUM_SLAVES];

// Set initial values for sD3Array and eArray from 0 to NUM_Slaves
    for (int j=0;j<NUM_SLAVES;j++){
        sD3Array[j]=j;
        eArray[j] = j;
    }
//initializing array with 0, and filling 1 index with 1 which indicated the poisoned wine
    int arr[N];
    for(int i = 0; i < N; i++) {
        arr[i]=0;
    }
    int random = rand() % N;
    arr[random] = 1;

    /*
      This is a helper function that is used to fill the arrays secondSlaveArray,
      and thirdSlaveArray so that they
      undergo the approach of divide-and-conquer on the 1000 bottles for the different ranges provided */

    string strArray[N];
    for (int i = 0; i < N; i++) {
        strArray[i] = to_string(arr[i]);
        for (int j = 0; j < NUM_SLAVES; j++) {
            if (to_string(i).substr(1, 1) == to_string(j)) {
                secondSlaveArray[j][eArray[j]] = stoi(strArray[i]);
                eArray[j]=eArray[j]+1;
            }
            if (to_string(i).substr(to_string(i).length() - 1, 1) == to_string(j)) {
                thirdSlaveArray[j][sD3Array[j]] = stoi(strArray[i]);
                sD3Array[j]++;
            }
        }
    }
    //This arrays are declared so that they can be sent to the helper function “Check” to release a well describing output
    int end = (N / NUM_SLAVES) - 1;
    int firstDay[NUM_SLAVES][1];
    int secondDay[NUM_SLAVES][1];
    int thirdDay[NUM_SLAVES][1];

/* here we use secondSlaveArray and thirdSlaveArray and perform divide and conquer on every row
/ to find exactly which slave drank the poison and on which day
 (which can be determined by the arrays called firstDay, secondDay, thirdDay)*/
    for (int i = 0; i < NUM_SLAVES; i++) {
        int temp1 = findPoison(arr, i * (N / NUM_SLAVES), (i + 1) * (N / NUM_SLAVES) - 1);
        firstDay[i][0] = temp1;
        temp1 = findPoison(secondSlaveArray[i],i, end);
        secondDay[i][0] = temp1;
        temp1 = findPoison(thirdSlaveArray[i], i, end);
        thirdDay[i][0] = temp1;
    }

    /* here the helper function Check is used to check exactly which slave drank the poison on each day*/
    int day1 = check(firstDay, 1);
    cout << " in day 1" << endl;
    int day2 = check(secondDay, 2);
    cout << " in day 2" << endl;
    int day3 = check(thirdDay, 3);
    cout << " in day 3" << endl;

    cout<<"Therefore, the posioned bottle is: "<<day1<<day2<<day3;
}
int main() {
    srand(time(NULL));
    slaveTesting();

    return 0;
}