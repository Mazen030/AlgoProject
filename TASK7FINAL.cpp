#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
int main()
{
	int target, shots,hidingspots;
	cout << "Enter the number of hiding spots : ";
	cin >> hidingspots;
	cout << "Enter the target start position :";
    cin >> target;
	int shotsPerTime = 0,totalshots=0;
	string s;
	int shooterpos = 1;
	int invalid = 0;
	cout << "**************************************************\n";
	while (shooterpos<=hidingspots)
	{
		while (shotsPerTime <= hidingspots)
		{

			if (target == 0 || target == hidingspots + 1)
			{
				cout << "*****************INVALID POSITION**************\n";
				invalid = 1;
				break;
			}
			cout << "The target  is now at position " << target << "\n";

			cout << "The shooter is now at position " << shooterpos << "\n";

			cout << "The shooter hit the hiding spot at position " << shooterpos << "\n";

			shotsPerTime++;
			if (target == shooterpos)break;
			else
			{
				cout << "Enter the next movement of the target whether (right) OR (left) : ";
				cin >> s;
				if (s == "right")target++;

				else target--;

			}
		}
		totalshots += shotsPerTime;
		if (target == shooterpos)break;
		shotsPerTime = 0;
		shooterpos++;
		
		cout << "**************************************************\n";
	}
	cout << "                                             \n";
	if(!invalid)cout << "the target is hit at pos " << shooterpos << " and after " << totalshots << " shots\n\n ";

}
