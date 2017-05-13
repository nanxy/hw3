//============================================================================
// Name        : hw3.cpp
// Author      : Nancy Zhou
// Version     : ver 1.2- added cash out case option.
//               ver 1- omitted switch statement and replaced it with if
//               statements for each type of coin to run at the same time.
//
// Copyright   : dfasdfasdfas stealing is bad plz respek
// Description : This is a coin toss game where the player is heads and the
//               bot is tails. The player tosses a nickel, dime, and quarter
//               The player needs exactly $1.00 to win, or they can csh out
//               before they reach $1.00.
/*INSTRUCTIONS:
For this assignment, you will create a game program using the Coin class from
Programming Challenge 12. The program should have three instances of the Coin
class: one representing a quarter, one representing a dime, and one
representing a nickel. When the game begins, your starting balance is $0.
During each round of the game, the program will toss the simulated coins.
When a coin is tossed, the value of the coin is added to your balance if
it lands heads-up. For example, if the quarter lands heads-up, 25 cents is
added to your balance. Nothing is added to your balance for coins that land
tails-up. The game is over when your balance reaches $1 or more. If your
balance is exactly $1, you win the game. You lose if your balance exceeds $1.*/
//============================================================================


#include <iostream>
#include <string>
#include <iomanip>// for setpresicion
#include "Coin.h"
using namespace std;

/**==============================================================
                    Main
==============================================================**/
int main()
{
    char choice;
    double score=0.00;
    Coin dime,nickel,quarter;
    //Coin dime;
    //Coin quarter;
    cout<< "This is a game where you toss a nickel, dime, and quarter and if the coins are head side up, you get that amount."<<endl;
    cout<<" If you reach exactly $1.00, you win! But if you go over, then I win. Ready?"<<endl;
    cout<<" You may quit any time by inputting '#'"<<endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    //end of the welcome screen message
    do
    {
        cout<<" Would you like to flip the coins? Input 'y' if you would like to continue, 'n' if you want to cash out."<< endl;
        cin>>choice;// holds the user input


        if (score<1.0)
        {
            switch (choice)
            {
            case'y':
            {
                nickel.GetsideUp();
                if ( nickel.toss("val"))
                {
                    score+=0.05;
                    cout<< "The nickel is heads. +$0.05"<<endl;
                    //cout<<"------------------------------------------------------------"<<endl;
                }
                else
                    cout<<"Tails for the nickel."<<endl<<" oops, sorry! "<<endl;
                //cout<<"------------------------------------------------------------"<<endl;

                dime.GetsideUp();
                if (dime.toss("val"))
                {
                    score+=0.10;
                    cout<< "The dime is heads. +$0.10"<<endl;
                    //cout<<"------------------------------------------------------------"<<endl;
                }
                else
                    cout<<"Tails for the dime."<<endl<<" Oops,try again " <<endl;

                quarter.GetsideUp();

                if ( quarter.toss("val"))
                {
                    score+=.25;
                    cout<< "The quarter is heads. +$0.25"<<endl;
                }
                else
                    cout<<"Tails for the quarter."<<endl<<" uh oh, no dice."<<endl;

                cout<<"------------------------------------------------------------"<<endl;
                cout.precision(2);
                cout<< "The current amount is $"<<score<<fixed<<endl;
                cout<<"====================================================================="<<endl;
                break;
            }
            case'n':
            {
                cout.precision(2);
                cout<<"Thank you for playing, you have received $"<<fixed<<score<<endl;
                cout<<"====================================================================="<<endl;;
                cout<<"Would you like to play again?Press any key to play again,'#' to quit"<<endl;
                cin>>choice;
                break;//stop flipping and cash out.
            }
            default :
                cout<<"Invalid choice, input 'y' if you would like to continue, 'n' if you want to cash out."<< endl;
                cout<<"------------------------------------------------------------"<<endl;
                break;//this case prints when the user inputs an invalid coin.
            }


        }//this if statement runs when the score is still under $1.00
        if(score==1.0)
        {
            cout<<"====================================================================="<<endl;
            cout<<"___________________________________"<<endl;
            cout<<"|#######====================#######|"<<endl;
            cout<<"|#(1)*UNITED STATES OF AMERICA*(1)#|"<<endl;
            cout<<"|#*****      #/===\#   ********  **#|"<<endl;
            cout<<"|#* {G}      |(._.)|             *#|"<<endl;
            cout<<"|#*  ****** |  /v\  |    O N E   **#|"<<endl;
            cout<<"|#(1)        #\===/#           (1)*#|"<<endl;
            cout<<"|##=========ONE DOLLAR===========##|"<<endl;
            cout<<"------------------------------------"<<endl;
            cout<<"You win!"<<endl<<"Press any key to play again,'#' to quit"<<endl;
            cout<<"====================================================================="<<endl;
            score=0;
            cin>> choice;
        }//this statement prints a cute congrats screen
        if (score>1.0)
        {
            cout<<"====================================================================="<<endl;
            cout<<" Sorry! you lost!"<<endl;
            score-=1;
            cout<< "Your balance went $"<<score<<setprecision (4)<<" over."<<endl;
            cout<<"====================================================================="<<endl;
            score=0;
            cout<< "Would you like to play again? Press any key to play again,'#' to quit"<<endl;
            cin>>choice;

        }//this statement takes the difference of the score and 1 and displays the amount over the player went.

    }
    while (choice!='#');
    cout<< "Thanks for playing";
    return 0;
}
/*================================================================================================
           OUTPUT
/*================================================================================================
            ver 1.2
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

This is a game where you toss a nickel, dime, and quarter and if the coins are head side up, you get that amount.
 If you reach exactly $1.00, you win! But if you go over, then I win. Ready?
 You may quit any time by inputting '#'
-------------------------------------------------------------------------------
 Would you like to flip the coins? Input 'y' if you would like to continue, 'n' if you want to cash out.
y
Tails for the nickel.
 oops, sorry!
The dime is heads. +$0.10
The quarter is heads. +$0.25
------------------------------------------------------------
The current amount is $0.35
=====================================================================
 Would you like to flip the coins? Input 'y' if you would like to continue, 'n' if you want to cash out.

y
Tails for the nickel.
 oops, sorry!
Tails for the dime.
 Oops,try again
Tails for the quarter.
 uh oh, no dice.
------------------------------------------------------------
The current amount is $0.35
=====================================================================
 Would you like to flip the coins? Input 'y' if you would like to continue, 'n' if you want to cash out.
y
Tails for the nickel.
 oops, sorry!
Tails for the dime.
 Oops,try again
The quarter is heads. +$0.25
------------------------------------------------------------
The current amount is $0.60
=====================================================================
 Would you like to flip the coins? Input 'y' if you would like to continue, 'n' if you want to cash out.
y
The nickel is heads. +$0.05
The dime is heads. +$0.10
Tails for the quarter.
 uh oh, no dice.
------------------------------------------------------------
The current amount is $0.75
=====================================================================
 Would you like to flip the coins? Input 'y' if you would like to continue, 'n' if you want to cash out.
y
The nickel is heads. +$0.05
The dime is heads. +$0.10
The quarter is heads. +$0.25
------------------------------------------------------------
The current amount is $1.15
=====================================================================
=====================================================================
 Sorry! you lost!
Your balance went $0.15 over.
=====================================================================
Would you like to play again? Press any key to play again,'#' to quit
q
 Would you like to flip the coins? Input 'y' if you would like to continue, 'n' if you want to cash out.
q
Invalid choice, input 'y' if you would like to continue, 'n' if you want to cash out.
------------------------------------------------------------
 Would you like to flip the coins? Input 'y' if you would like to continue, 'n' if you want to cash out.
y
Tails for the nickel.
 oops, sorry!
The dime is heads. +$0.10
Tails for the quarter.
 uh oh, no dice.
------------------------------------------------------------
The current amount is $0.10
=====================================================================
 Would you like to flip the coins? Input 'y' if you would like to continue, 'n' if you want to cash out.
y
The nickel is heads. +$0.05
The dime is heads. +$0.10
Tails for the quarter.
 uh oh, no dice.
------------------------------------------------------------
The current amount is $0.25
=====================================================================
 Would you like to flip the coins? Input 'y' if you would like to continue, 'n' if you want to cash out.
y
Tails for the nickel.
 oops, sorry!
Tails for the dime.
 Oops,try again
Tails for the quarter.
 uh oh, no dice.
------------------------------------------------------------
The current amount is $0.25
=====================================================================
 Would you like to flip the coins? Input 'y' if you would like to continue, 'n' if you want to cash out.
y
Tails for the nickel.
 oops, sorry!
The dime is heads. +$0.10
Tails for the quarter.
 uh oh, no dice.
------------------------------------------------------------
The current amount is $0.35
=====================================================================
 Would you like to flip the coins? Input 'y' if you would like to continue, 'n' if you want to cash out.
y
Tails for the nickel.
 oops, sorry!
Tails for the dime.
 Oops,try again
The quarter is heads. +$0.25
------------------------------------------------------------
The current amount is $0.60
=====================================================================
 Would you like to flip the coins? Input 'y' if you would like to continue, 'n' if you want to cash out.
y
The nickel is heads. +$0.05
Tails for the dime.
 Oops,try again
The quarter is heads. +$0.25
------------------------------------------------------------
The current amount is $0.90
=====================================================================
 Would you like to flip the coins? Input 'y' if you would like to continue, 'n' if you want to cash out.
y
Tails for the nickel.
 oops, sorry!
The dime is heads. +$0.10
Tails for the quarter.
 uh oh, no dice.
------------------------------------------------------------
The current amount is $1.00
=====================================================================
=====================================================================
___________________________________
|#######====================#######|
|#(1)*UNITED STATES OF AMERICA*(1)#|
|#*****      #/===#   ********  **#|
|#* {G}      |(._.)|             *#|
|#*  ****** |  /v  |    O N E   **#|
|#(1)        #===/#           (1)*#|
|##=========ONE DOLLAR===========##|
------------------------------------
You win!
Press any key to play again,'#' to quit
=====================================================================
y
 Would you like to flip the coins? Input 'y' if you would like to continue, 'n' if you want to cash out.
y
The nickel is heads. +$0.05
The dime is heads. +$0.10
Tails for the quarter.
 uh oh, no dice.
------------------------------------------------------------
The current amount is $0.15
=====================================================================
 Would you like to flip the coins? Input 'y' if you would like to continue, 'n' if you want to cash out.
y
The nickel is heads. +$0.05
Tails for the dime.
 Oops,try again
Tails for the quarter.
 uh oh, no dice.
------------------------------------------------------------
The current amount is $0.20
=====================================================================
 Would you like to flip the coins? Input 'y' if you would like to continue, 'n' if you want to cash out.
y
Tails for the nickel.
 oops, sorry!
Tails for the dime.
 Oops,try again
The quarter is heads. +$0.25
------------------------------------------------------------
The current amount is $0.45
=====================================================================
 Would you like to flip the coins? Input 'y' if you would like to continue, 'n' if you want to cash out.
y
Tails for the nickel.
 oops, sorry!
The dime is heads. +$0.10
The quarter is heads. +$0.25
------------------------------------------------------------
The current amount is $0.80
=====================================================================
 Would you like to flip the coins? Input 'y' if you would like to continue, 'n' if you want to cash out.
n
Thank you for playing, you have received $0.80
=====================================================================
Would you like to play again?Press any key to play again,'#' to quit
#
Thanks for playing
Process returned 0 (0x0)   execution time : 47.875 s
Press any key to continue.
*/
