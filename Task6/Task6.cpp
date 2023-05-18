#include <cstdlib>
#include <iostream>
using namespace std;


int coins[14];
int no_of_moves = 0;

int sum(int arr[], int start, int end) {

	int sum = 0;

	for (int i = start; i <= end; i++)
		sum += arr[i];

	return sum;

}



void fakeCoin(int arr[], int size, int start, int end, int original_size) {


	int mid = (size%2 ==0)? (start + end) / 2 : mid = (start + end - 1) / 2;
	int endf = (size % 2 == 0) ? end : end - 1;
	int leftBalance;
	int rightBalance;
	bool is_fake_left = false;
	bool is_fake_right = false;
	leftBalance = sum(arr, start, mid);
	rightBalance = sum(arr, mid + 1, endf);

	no_of_moves += 1;
	

	if (leftBalance == rightBalance) {
		//cout << "Im balanced";

		for (int i = start; i < end; i++)
			coins[i] = 0;

		if (size % 2 != 0) {

			no_of_moves += 1;
			if (arr[end] == arr[rand() % ((end - 1) - start) + start]) {
				arr[end] = 0;
				if (size == original_size) {
					cout << "No fake Coin";
					cout << "The number of weighings is : " << no_of_moves << endl;
					return;

				}
				else return;

			}


			else {
				cout << "The fake coin is " << end + 1 << endl;
				cout << (arr[end] > arr[start]) ? "Heavier" : "Lighter";
				cout << endl;
				cout << "The number of weighings is : " << no_of_moves << endl;
				return;
			}
		}

		else if (size == original_size) {

			cout << "No Fake Coin";
			cout << "The number of weighings is : " << no_of_moves << endl;
			return;

		}

		else return;



	}

	else if (leftBalance < rightBalance) {

		

		//cout << "Im left";

		if (coins[mid] == -1) {

			is_fake_left = true;

			for (int i = mid + 1; i < end; i++)
				coins[i] = 0;

			if (size % 2 == 0)
				coins[end] = 0;

		}

		else if (coins[mid+1] == 1) {

			is_fake_right = true;

			for (int i = start; i <= mid; i++)
				coins[i] = 0;
		}



		else {

			for (int i = start; i <= mid; i++)
				coins[i] = -1;

			for (int i = mid + 1; i < end; i++)
				coins[i] = 1;

			if (size % 2 == 0)
				coins[end] = 1;

		}







	}

	else {

		//cout << "I'm right";

		if (coins[mid+1] == -1) {

			is_fake_right = true;

			for (int i = start; i <= mid; i++)
				coins[i] = 0;
		}


		else if (coins[mid] == 1) {

			is_fake_left = true;

			for (int i = mid + 1; i < end; i++)
				coins[i] = 0;

			if (size % 2 == 0)
				coins[end] = 0;


		}

		else {

			for (int i = start; i <= mid; i++)
				coins[i] = 1;

			for (int i = mid + 1; i < end; i++)
				coins[i] = -1;

			if (size % 2 == 0)
				coins[end] = -1;



		}


	}


	if (start == mid) {

		cout << "The number of weighings is : " << no_of_moves << endl;
	
		if (coins[mid] == -1) {
			
			cout << "The Fake Coin is " << start + 1 << endl;
			cout << "Lighter" << endl;;
			return;
		
		}

		else if (coins[mid + 1] == -1) {
		
			cout << "The Fake Coin is " << mid + 2 << endl;
			cout << "Lighter"<<endl;
			return;
		
		}

		else if (coins[start] == 1) {

			cout << "The Fake Coin is " << start + 1 << endl;
			cout << "Heavier"<<endl;
			return;

		}

		else if (coins[mid + 1] == 1) {

			cout << "The Fake Coin is " << mid + 2 << endl;
			cout << "Heavier"<<endl;
			return;

		}
	
	}



	if (is_fake_left == false && is_fake_right == false) {
		fakeCoin(arr, size / 2, start, mid, original_size);
		fakeCoin(arr, size / 2, mid + 1, endf, original_size);
	}

	else if (is_fake_left)
		fakeCoin(arr, size / 2, start, mid, original_size);

	else if(is_fake_right)
		fakeCoin(arr, size / 2, mid+1, endf, original_size);
}
		


int main() { 

	
	srand(time(0));

	int weight = rand() % 5 + 1;
	int fakeweight = rand() % 5 + 1;
	int fakeindex = rand() % 12;

	cout << "The original coins weight: " << weight << endl;
	cout << "The fake coin weight: " << fakeweight << endl;
	cout << "The fake coin :" << fakeindex + 1<<endl;

	int weights[14] ;


	for (int i = 0; i < 14; i++)
		weights[i] = weight;

       weights[fakeindex] = fakeweight;


	   for (int i = 0; i < 14; i++)
		   coins[i] = -2;


	   /*for (int i = 0; i < 14; i++) {
			
		   cout << weights[i] << endl;
	   }
	   */


	   fakeCoin(weights, 14, 0, 13, 14);


	  /* for (int i = 0; i < 14; i++)
		   cout << coins[i]; */


	  
	   for (int i = 0; i < 14; i++)
		   cout<<coins[i];
	  



}
