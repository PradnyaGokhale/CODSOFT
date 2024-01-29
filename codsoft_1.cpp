#include <iostream>
#include <time.h> 
using namespace std;

int main()
{
    srand(time(0)); 
    int secretNum = rand()%100;
    int guess;
    int guessCount = 0;
    bool correctGuess = false;

    cout<<"\t\t\t\t\t\tGuess the number between 0 to 100. "<<endl;
    cout<<"\t\t\t\t\t\t\t   Good luck!!"<<endl;

    while(!correctGuess) {
        if(secretNum!=guess) {
            cout<<"\nEnter Your Guess: ";
            cin>>guess;
            guessCount++;
            if(guess>secretNum) {
                cout<<"Try a lower number."<<endl;
            }
            if(guess<secretNum) {
                cout<<"Try a higher number."<<endl;
            }
        }
        else {
            correctGuess = true;
        }
    }

    if(correctGuess) {
        cout<<endl;
        cout<<"\t\t\t\t\t\tYou Win!!";
        cout<<" The Number is "<<secretNum<<"."<<endl;
        cout<<"\t\t\t\t\t     And you guessed it in "<<guessCount<<" guesses.";
    }

    return 0;
}

