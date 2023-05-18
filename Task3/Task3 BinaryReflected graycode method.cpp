#include<iostream>
#include <bitset>

using namespace std;

int generateGraycode(int num) {
    return num ^ (num >> 1);
}

int main() {
    int i = 0;
    int z=0;
    int counter = 0;
    int gray = 0;
    int n = 5;

    const int MAX_SIZE = 100; // Maximum size of the array
    bitset<5> grayCodes[MAX_SIZE]; // Array to store the bitsets

    while (gray < (1 << n) - 1) {
        gray = generateGraycode(counter);

        grayCodes[i]=bitset<5>(gray); // Store the bitset in the array

        counter++;
        i++;
    }


    for (int j = i - 1; j >= 0; j--) {
        cout << z << " : " << grayCodes[j] << endl;
        z++;
    }
    cout<<" the number of switches is:"<<z-1;
    return 0;
}
