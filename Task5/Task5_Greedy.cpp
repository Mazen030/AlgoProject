// Task5_greedy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
using namespace std;
int main()
{
	vector<vector<int>> coins;
	int n;
	cout << "enter number of coins";
	cin >> n;
	while (n % 4 != 0) {
		cout << "n not divisible by 4 , re-enter";
		cin >> n;

	}
	for (int i = 1; i <= n; i++)
	{
		//to make coins indexed by 1 not zero
		coins.push_back({ i ,0 });
	}
	int CoinsOnLHS, jumps, erasecounter, CoinsOnRHS, moves, erasecounter2;
	jumps = 1;
	erasecounter = erasecounter2 =0;
	moves = 0;
	CoinsOnRHS = 0;
	CoinsOnLHS = 0;
	// start with the rightmost coin , and count how many coins are on its left 
	for (int i = 1; i < n; i++) {
		CoinsOnLHS = n  - erasecounter2 - i;
		if (CoinsOnLHS != (n / 2) + 1)
		{
			jumps++;

			cout << "CoinsOnLHS " << CoinsOnLHS << endl;
			cout << "erasecounter " << erasecounter << endl;
			//jumps is the number of jumps
			coins[n - i - erasecounter2][1] = coins[coins[n - i - erasecounter2][0] - 1 - erasecounter - jumps][0];
			moves++;
			cout << "jumps1 " << jumps << endl;
			//erase coins that has jumped over a coin
			for (int j = 0; j < coins.size(); j++) {
				if (coins[j][0] == coins[coins[n - i - erasecounter2][0] - 1 - erasecounter - jumps][0]) {
					cout << "coin to be erased" << coins[coins[n - i - erasecounter2][0] - 1 - erasecounter - jumps][0] << endl;
					erasecounter = 1;
					erasecounter2++;
					coins.erase(coins.begin() + j);
					break;
				}

			}
		}
		else {

			//keep decreasing pointer till coinsOnRHS = n/2 +1 
			//don't count pairs
			//count coinsOnRhs Excluding Pairs at the end 
			break;

		}

	}

	for (auto p : coins) {
		cout << "(" << p[0] << "," << p[1] << ")" << endl;
	}
	int movesbefore = moves;

	for (int i = 0; i < n; i++)
	{

		for (int j = 1; j < coins.size() - movesbefore; j++)
		{

			if (coins[j][1] != 0)
			{
					//thus , the coin have a pair 
				CoinsOnRHS += 2;
			}
			else {
				CoinsOnRHS++;
			}
		}
		cout << "coinsRHS " << CoinsOnRHS << endl;

		if (CoinsOnRHS == (n / 2) + 1) {

			//pair from the left side
			CoinsOnRHS = 0;
			coins[(n / 4) + 1][1] = coins[0][0];
			moves++;
			//erase coins that has jumped over a coin
			for (int m = 0; m < coins.size(); m++) {

				if (coins[m][0] == coins[0][0]) {
					cout << "coin to be erased" << coins[0][0] << endl;
					coins.erase(coins.begin() + m);
					erasecounter2++;
					break;
				}
			}


		}

	}

	for (auto p : coins) {
		cout << "(" << p[0] << "," << p[1] << ")" << endl;
	}


	cout << "NUMBER OF MOVES = " << moves << endl;
	system("pause");

}

