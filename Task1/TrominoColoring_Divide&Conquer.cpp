#include <iostream>
using namespace std;

int size_of_grid, b, a, counter = 0;
char arr[128][128];


int tile(int n, int x, int y,string location)
{
    int r, c;
    if (n == 2) {
        counter++;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[x + i][y + j] == 0) {

                    if (location =="up right"|| location=="down left")
                    arr[x + i][y + j] = 'w';
                    else if (location == "down right"||location== "up left")
                        arr[x + i][y + j] = 'b';

                }
            }
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

    // If missing tile is up right
    if (r < x + n / 2 && c < y + n / 2)
    {
        counter++;
        arr[x + n / 2][y + (n / 2) - 1] = 'g';
        arr[x + n / 2][y + n / 2] = 'g';
        arr[x + n / 2 - 1][y + n / 2] = 'g';

    }
    // If missing Tile is in down left
    else if (r >= x + n / 2 && c < y + n / 2)
    {
        counter++;
        arr[x + (n / 2) - 1][y + (n / 2)] = 'g';
        arr[x + (n / 2)][y + n / 2] = 'g';
        arr[x + (n / 2) - 1][y + (n / 2) - 1] = 'g';


    }

    // If missing Tile is in up left
    else if (r < x + n / 2 && c >= y + n / 2)
    {
        counter++;
        arr[x + n / 2][y + (n / 2) - 1] = 'g';
        arr[x + n / 2][y + n / 2] = 'g';
        arr[x + (n / 2) - 1][y + (n / 2) - 1] = 'g';

    }
    // If missing Tile is in down right
    else if (r >= x + n / 2 && c >= y + n / 2)
    {

        counter++;
        arr[x + (n / 2) - 1][y + (n / 2)] = 'g';
        arr[x + n / 2][y + (n / 2) - 1] = 'g';
        arr[x + (n / 2) - 1][y + (n / 2) - 1] = 'g';
    }


    // dividing it again in 4 quadrants
    tile(n / 2, x, y + n / 2,"down left");
    tile(n / 2, x, y,"down right");
    tile(n / 2, x + n / 2, y,"up right");
    tile(n / 2, x + n / 2, y + n / 2,"up left");

    return 0;
}

int main()
{
    cout << "enter size of grid as n *n ";
    cin >> size_of_grid;
    memset(arr, 0, sizeof(arr));

    a = 0, b = 0;
    // defected tile
    arr[a][b] = 'x';
    tile(size_of_grid, 0, 0,"up right");
 
    for (int i = 0; i < size_of_grid; i++) {
        for (int j = 0; j < size_of_grid; j++) {
            
                cout << arr[i][j]<<" ";
        }
        cout << "\n";

    }

    system("pause");
}
