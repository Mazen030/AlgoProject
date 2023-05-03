#include <iostream>
using namespace std;
int main() 
{
	int n;
	int counter = 0;
	cout << "ENTER THE NUMBER OF HIDING SPOTS: ";
	cin >> n;
	cout << "\n";
	
	cout << "ENTER THE TARGET START POS:";
	int start;
	cin >> start;

	int dead = 0;
	string movement;
	cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n";
	for (int i = 2;i <=n-1;i++)
	{
		cout << "THE SHOOTER NOW AT POSITION " << i << "\n";
		if (i == start )
		{
			cout << "TARGET IS HIT AT POS " <<i<<"!!!!\n";
			counter++;
			dead = 1;
		}
		else
		{
			if (dead == 0)
			{
				cout << "ENTER WHETHER THE TARGET WILL MOVE (LEFT) OR (RIGHT) : ";
				counter++;
				cin >> movement;
				cout << "\n";
			}
			cout << "THE SHOOTER HIT POS " << i;
			if (dead == 0)
			{
				cout << " AND NOW THE TARGET BECAME AT POSITION ";
				if (movement == "RIGHT")start++;
				else start--;
				cout << start << "\n";
			}
			else cout << " AND THE TARGET IS NOW DEAD\n";

			cout << "-------------------------------\n";
		}
	}
	for (int i = n-1;i >= 2;i--)
	{
		cout << "THE SHOOTER NOW AT POSITION " << i << "\n";
		if (i == start && dead==0)
		{
			cout << "TARGET IS HIT AT POSITION " << i << "!!!!\n";
			counter++;
			dead = 1;
		}
		else
		{
			if (dead == 0)
			{
				cout << "ENTER WHETHER THE TARGET WILL MOVE (LEFT) OR (RIGHT) : ";
				cin >> movement;
				counter++;
				cout << "\n";
			}
			cout << "THE SHOOTER HIT POS " << i;
			if (dead == 0)
			{
				cout << " AND NOW THE TARGET BECAME AT POS ";
				if (movement == "RIGHT")start++;
				else start--;
				cout << start << "\n";
			}
			else cout << " AND THE TARGET IS NOW DEAD\n";

			cout << "-------------------------------\n";
		}
	}

	cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n";
	if (counter == 1) cout << "**********THE TARGET IS HIT FROM THE FIRST SHOT***************";
	else 
	{
		cout << "**********THE TARGET IS HIT AFTER " << counter << " SHOOTS OF THE SHOOTER***********";
	}
}
