// Task5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<vector<int>> coins;
	int n;
	int erasecounter1 = 0;
	int erasecounter2 = 0;

	// variable to keep track of number of moves
	int moves = 0;
	int coinspassed = 1;
	cout << "enter number of coins";
	cin >> n;
	while (n % 4 != 0) {
		cout << "n not divisible by 4 , re-enter";
		cin >> n;

	}


	for (int i = 1; i <= n; i++) {
		//to make coins indexed by 1 not zero
		coins.push_back({ i ,0 });

	}
	

	for (int i = 1; i <= (n / 4) - 1; i++) 
	{
		//start from rightmost
		//{8,6}
		coinspassed++;
		//cout << "coinspassed: " << coinspassed << " coins[n - i-erasecounter][0] : " << coins[n - i - erasecounter2][0]<<" coins[coins[n - i-erasecounter][0] - 1 -erasecounter- coinspassed][0] : "<< coins[coins[n - i - erasecounter1][0] - 1 - erasecounter1 - coinspassed][0]<<endl;
		coins[n - i-erasecounter2][1] = coins[coins[n - i-erasecounter2][0] - 1 -erasecounter1- coinspassed][0];
		
		//cout << "[0]"<<coins[n - i-erasecounter][0] << endl;
		//cout <<"[1]"<<coins[n - i-erasecounter][1] << endl;
		moves++;

		for (int j = 0; j < coins.size(); j++) {
			if (coins[j][0] == coins[coins[n - i - erasecounter2][0] - 1 - erasecounter1 - coinspassed][0]) {
				cout << "coin to be erased" << coins[coins[n - i - erasecounter2][0] - 1 - erasecounter1 - coinspassed][0] << endl;
				erasecounter1 = 1;
				erasecounter2++;
				coins.erase(coins.begin() + j);
			
				break;
			}
			
		}
		
	
	}
	// print the pairs

	for (auto p : coins) {
		cout << "(" << p[0] << "," << p[1] << ")" << endl;
	}
	cout << endl;


	for (int i = (n / 4); i <= (n / 2); i++) {
		//start from leftmost
	
		coins[(n/4) + 1][1] = coins[0][0];
		moves++;
		for (int j = 0; j < coins.size(); j++) {
			if (coins[j][0] == coins[0][0]) {
				coins.erase(coins.begin() + j);
				break;
			}
		}
	}

	for (auto p : coins) {
		cout << "(" << p[0] << "," << p[1] << ")" << endl;
	}


	cout << "NUMBER OF MOVES = " << moves << endl;
	system("pause");
}


