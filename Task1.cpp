//Number Guessing game

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    // seed the random number generator with current time.
    srand(time(0));
    //generate a random number in 1 to 100.
    int RandomNumber = rand() % 100 + 1;
    int guess = 0;

    cout<<"Welcome to the Guessing Game"<<"\n";
    cout<<"I have picked number between 1 to 100. Try to Guess it: "<<"\n";

    //infinite loop until the correct guess number found.
    while(true)
    {
        cout<<"Enter your Guess: ";
        cin>>guess;

        if(guess < RandomNumber)
        cout<<"Too low! Try again"<<"\n";
        else if(guess > RandomNumber)
        cout<<"Too high! Try again"<<"\n";
        else
        {
            cout<<"Congratulations you Guessed the correct number: "<<RandomNumber<<"\n";
            break; 
            //Exit the loops after guess number found.
        }
    }
    return 0;
}