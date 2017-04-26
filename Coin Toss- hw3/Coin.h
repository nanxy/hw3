#ifndef COIN_H
#define COIN_H

#include <string>
#include <cstdlib>
#include <ctime>// to use time function

using namespace std;


class Coin
{
        private:
        string sideUp;


    public:
        Coin();
        {
            srand (time(0));
        }
        virtual ~Coin(){}

        string GetsideUp()
        {
            return sideUp;
        }

        void toss(string val) //setSideUp mutator
        {
            string heads,tails;
            int tossing;
            tossing= rand() % 100+1
            if(tossing%1){

                sideUp==heads;
            }
            else
                sideUp==tails;
            cout<< "The coin is facing "<<sideUp<< " side up!"<< endl;

        }
};


#endif // COIN_H
