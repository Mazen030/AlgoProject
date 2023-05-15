#include <iostream>
#include<vector>
using namespace std;

int size_of_grid, b, a, cnt = 0;
int arr[128][128];

// Placing tile at the given coordinates
void place(int x1, int y1, int x2,
	int y2, int x3, int y3)
{
	cnt++;
	arr[x1][y1] = cnt;
	arr[x2][y2] = cnt;
	arr[x3][y3] = cnt;
}
// Quadrant names
// 1 2
// 3 4

// Function based on divide and conquer
int tile(int n, int x, int y)
{
	size_of_grid = 16;
	int r, c;
	vector <vector<int>> indices;
	indices.resize(3);
	int k = 0;
	if (n == 2) {
		cnt++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[x + i][y + j] == 0) {
					arr[x + i][y + j] = cnt;
					cout << "cnt " << cnt << endl;
					indices[k] = { x + i,y + j };
					k++;

				}
			}
		}
		
		for (int i = 0; i < indices.size(); i++) {
			for (int j = 0; j < indices[i].size(); j++) {
			cout <<" indices[i][j] "<< indices[i][j] << " ";
			}
		} 
		
		
		cout << "----------"<<endl;


		//w -> -20
		//black ->-19
		//gray -> 30
		int whitecnt = 0;
		int blackcnt = 0;
		int anycounter = 0;
		cout << "size of grid" << size_of_grid << endl;
		for (int i = 0; i < 3; i++) {
			if ((arr[indices[i][0] - 1][indices[i][1]] != cnt) && ((indices[i][0] - 1) < size_of_grid) && ((indices[i][1]) < size_of_grid) && ((indices[i][0] - 1) >= 0) && (indices[i][1] >= 0))
			{
				cout << "indices[i][0] - 1: " << indices[i][0] - 1 << " indices[i][1]: " << indices[i][1] << endl;
				if (arr[indices[i][0] - 1][indices[i][1]] ==- 20)
					whitecnt++;
				else if (arr[indices[i][0] + 1][indices[i][1]] == -19)
					blackcnt++;
				else {
					anycounter++;
				}
			}
			if ((arr[indices[i][0]][indices[i][1] + 1] != cnt) && (indices[i][0] < size_of_grid) && (indices[i][1] + 1 < size_of_grid) && (indices[i][0] >= 0) && (indices[i][1] + 1 >= 0)) {
				cout << "indices[i][0] : " << indices[i][0] << " indices[i][1]+1: " << indices[i][1] + 1 << endl;

				if (arr[indices[i][0]][indices[i][1] + 1] == -20)
					whitecnt++;

				else if (arr[indices[i][0] + 1][indices[i][1]] ==- 19)
					blackcnt++;
				else {
					anycounter++;
				}


			}
			if ((arr[indices[i][0] + 1][indices[i][1]] != cnt) && (indices[i][0] + 1 < size_of_grid) && (indices[i][1] < size_of_grid) && (indices[i][0] + 1 >= 0) && (indices[i][1] >= 0)) {
				cout << "indices[i][0] +1: " << indices[i][0] + 1 << " indices[i][1]: " << indices[i][1] << endl;

				if (arr[indices[i][0] + 1][indices[i][1]] == -20)
					whitecnt++;

				else if (arr[indices[i][0] + 1][indices[i][1]] == -19)
					blackcnt++;

				else {
					anycounter++;
				}
			}

			if ((arr[indices[i][0]][indices[i][1] - 1] != cnt) && (indices[i][0] < size_of_grid) && (indices[i][1] - 1 < size_of_grid) && (indices[i][0] >= 0) && (indices[i][1] - 1 >= 0))
			{
				cout << "indices[i][0]: " << indices[i][0] << " indices[i][1]-1: " << indices[i][1] - 1 << endl;

				if (arr[indices[i][0]][indices[i][1] - 1] == -20)
					whitecnt++;

				else if (arr[indices[i][0] + 1][indices[i][1]] == -19)
					blackcnt++;
				else {
					anycounter++;
				}

			}
			
		}
		cout << "black cnt " << blackcnt << endl;
		cout << "white cnt " << whitecnt << endl;

		if (blackcnt>whitecnt) {
			arr[indices[0][0]][indices[0][1]]=-20;
			arr[indices[1][0]][indices[1][1]]=-20;
			arr[indices[2][0]][indices[2][1]]=-20;
		}
		else if (whitecnt>blackcnt) {
			arr[indices[0][0]][indices[0][1]] =- 19;
			arr[indices[1][0]][indices[1][1]] = -19;
			arr[indices[2][0]][indices[2][1]] = -19;
		}
		else{
			arr[indices[0][0]][indices[0][1]] =- 20;
			arr[indices[1][0]][indices[1][1]] =-20;
			arr[indices[2][0]][indices[2][1]] =- 20;
		}

		return 0;
	}
	// finding hole location
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (arr[i][j] != 0)
				r = i, c = j;
		}
	}

	// If missing tile is 1st quadrant
	if (r < x + n / 2 && c < y + n / 2)
	{
		arr[x + n / 2][y + (n / 2) - 1] = 30; //right
		arr[x + n / 2][y + n / 2] = 30; //left
		arr[x + (n / 2) - 1][y + n / 2] = 30; //up 
	}
	// If missing Tile is in 3rd quadrant
	else if (r >= x + n / 2 && c < y + n / 2)
	{
		arr[x + (n / 2) - 1][y + (n / 2)] = 30; //left
		arr[x + (n / 2)][y + n / 2] = 30; // up
		arr[x + (n / 2) - 1][y + (n / 2) - 1] = 30; //right
	}

	// If missing Tile is in 2nd quadrant
	else if (r < x + n / 2 && c >= y + n / 2) {
		arr[x + n / 2][y + (n / 2) - 1] = 30; //right
		arr[x + n / 2][y + n / 2] = 30; //left
		arr[x + (n / 2) - 1][y + (n / 2) - 1] = 30; //up 
	}
	// If missing Tile is in 4th quadrant
	else if (r >= x + n / 2 && c >= y + n / 2) {
		arr[x + (n / 2) - 1][y + (n / 2)] = 30; //right
		arr[x + n / 2][y + (n / 2) - 1] = 30; //up
		arr[x + (n / 2) - 1][y + (n / 2) - 1] = 30; //left
	}

	// dividing it again in 4 quadrants
	tile(n / 2, x, y + n / 2);  //down left
	tile(n / 2, x, y);  //down right
	tile(n / 2, x + n / 2, y);  //up right 
	tile(n / 2, x + n / 2, y + n / 2); // up left

	return 0;
}
// Driver program to test above function
int main()
{    
	// size of box
	int size_of_grid;
	cout << "enter size of grid as n *n ";
	cin >> size_of_grid;
	memset(arr, 0, sizeof(arr));
	// Coordinates which will be marked
	a = 6, b = 7;
	// Here tile can not be placed
	arr[a][b] = -1;
	tile(size_of_grid, 0, 0);
	char arr2[128][128];
	// The grid is
	for (int i = 0; i < size_of_grid; i++) {
		for (int j = 0; j < size_of_grid; j++)
		{
			if (arr[i][j] ==- 20) 
				{		arr2[i][j] = 'w';
				}
			else if (arr[i][j] == -1)
			{
				arr2[i][j] = 'x';
			}
			else if (arr[i][j]==30)
				arr2[i][j] = 'g';
			
			else if (arr[i][j]==-19) {
				arr2[i][j] = 'b';
			}
			cout << arr2[i][j]<<" ";
			}
		cout << "\n";
	}
	system("pause");
}
