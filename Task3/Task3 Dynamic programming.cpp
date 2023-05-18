#include <iostream>
#include<vector>
#include<string>
#include<string.h>
using namespace std;
int continuelast;
int flagsarray[100] = { 1,1,1,1 };
/* Here intially flags of switches number 0, 1, 2, 3 are = 1 as thoses swithces are already intialized with
their toggles in our code as stopping condition(Base cases) thats  why their flags are equal to 1 from the start
other than those switches any n number of switch that get called in generate_matrix function after we put their toggles
in array called togglesArray we rise the flag of switch number n =1 which means that the n switch has been called and
its toggle tranisiton value was stored in our togglesArray so,on further calls to this switch numbered n it wont be executed
instead it will get its values from Togglesarray which executes approach of dynamic Programming
*/

/* Putting Toggle Transitions for n = 2 and n = 3 as they are base conditions for our recurisve calls and
 Toggles for n=1 and n=0 are of no benefit here just to make Transitions for number of switches of n to be
 saved in row number n in 2D array Toggle array which will make it easier for us in our implementation
 PleaseNote:2d dynamic array cannot be used here as in c++ it is not allowed to make 2D Array with out knowing
 number of columns which will be here no of switches
 */

string toggleArray[1000][1000]= {
        {"0"},
        {"1","0"},
        {"11","01","00"},
        {"111","110","010","011","001","000"}

};

int returnrows(int n) {
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    if (n == 3)
        return 5;
    if (n > 3) {

        int rows = returnrows(n - 1) + 2 * returnrows(n - 2) + 1;

        return rows;
    }
}

void generate_Transitions(int n) {
    /* This if condition demonstrates that if flag of  of switch number n is equal to 1 this means that it has already been called before
     and that its toggles are included in the array Called   which means that there is no point to call value of n again
     so function will return
    */
    if (flagsarray[n] == 1)
        return;

    if (n == 2)
        return;
    if (n == 3)
        return;
    int helpervariable;
    int r3 = returnrows(2);

    int continevariable;

    if (n > 3) {
        generate_Transitions(n - 1);
        generate_Transitions(n - 2);

        int x = returnrows(n); //no of toggles needed for n switches to be turned off
        int y,z;
        y = returnrows(n - 2); //2
        z = returnrows(n - 1); //5

        //first part of sequence
        for (int i = 0; i <= y+1; i++)
        { //
            toggleArray[n][i] = "11" + toggleArray[n - 2][i];  //here we will use arr[n-2]
            continevariable = i;

        }

        for (int i = y; i > 0; i--)
        {

            //
            toggleArray[n][continevariable] = "01" + toggleArray[n - 2][i];  //here will arr[n-2]
            continevariable++;
            //variable to be used in next for loop
        }

        int helpervar = 0;
        int r2 = returnrows(n);

        for (int m =continevariable ; m <= r2; m++)
        {
            toggleArray[n][continevariable] = "0" + toggleArray[n-1][helpervar];
            helpervar++;
            continevariable++;
        }
    }

    flagsarray[n] = 1;
    /* Flag of switch number n will be rasied which means that toggles needed to switch it off is
     saved in toggleArray

    */


}

void  printtransitions(int n)
{
    int notoggles = 0;
    generate_Transitions(n);
    for (int i = 0; i <=returnrows(n); i++)
    {

        cout << toggleArray[n][i] << endl;
        notoggles++;

    }
    cout << "Minmum number of toggles :" << notoggles-1 << endl;
    /*Note that we subtracted one from notoggles as the intial condition which has all
    switches with 1's is not considered toggle */



}

int main()
{


    int noSwitches;
    cout << "Please Enter Number of Switches to be Turned Off :" ;
    cin >> noSwitches;


    printtransitions(noSwitches);
    system("pause");



}
