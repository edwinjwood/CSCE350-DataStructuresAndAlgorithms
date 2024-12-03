// LockerDoors_Wood_Edwin.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

// main function

int main()

{

    // variables

    int n, s, k, open_lockers = 0;    

    cout << "Enter the number of lockers:";

    // input the number of lockers

    cin >> n;

    cout << "Enter the number of students:";

    // input number of students

    cin >> s;

    // initialize all lockers with 0, 0 for closed and 1 for open

    int locker[n] = {};    

    //iterate through students
    
    for (int j = 1; j <= s; j++)
        
        //k = j;
        //cout << j << endl;
        //k = j;
        
        {
            for (int i = 0; i < n; i++)
            {
                k = j;

                // toggle the lockers
                // in each pass toggle every i'th lock
                // if open close it and vice versa
                
               // cout << k << endl;

                if (((i+1) % k) == 0)
                
                 //cout << (i) % (k) << endl;
                    
                {

                    if (locker[i] == 0)

                        locker[i] = 1;

                    else if (locker[i] == 1)

                        locker[i] = 0;

                }
                
            }

        }

    cout << "After last pass of all students:" << endl;

    // print the status of all lockers

    for (int x = 0; x < n; x++)

    {

        if (locker[x] == 0)

        {

            cout << "Locker " << x + 1 << " is closed." << endl;

        }

        else if (locker[x] == 1)

        {

            cout << "Locker " << x + 1 << " is open." << endl;

            // count the open lockers

            open_lockers++;            
           

        }

    }

    // print the open locks

    cout << "Total open lockers are :" << open_lockers << endl;

    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
