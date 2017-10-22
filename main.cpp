#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

using namespace std;

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
    // evenly distribute the random number across our range
    return min + static_cast<int>((max - min + 1) * (rand() * fraction));
}

int getUserInput(int guessNumber)
{
    cout << "Guess #" << guessNumber << ": ";

    int x;

    cin >> x;

    return x;
}

void startGame()
{

    int targetMin = 1, targetMax = 100, maxGuesses = 7, currentGuess = 1;
    int target = getRandomNumber(targetMin, targetMax);
    bool gameWon = false;
    // cout << "I have picked a number (HINT: it's " << target << ").  You have " << maxGuesses << " guesses." << endl;
    cout << "I have picked a number.  You have " << maxGuesses << " guesses." << endl;

    while(currentGuess <= maxGuesses && !gameWon)
    {
        int guess = getUserInput(currentGuess);

        if (guess == target)
        {
            cout << "You win!" << endl;
            gameWon = true;
        }
        else
        {
            if (guess < target)
            {
                cout << "Your guess is too low." << endl;
            }
            else
            {
                cout << "Your guess is too high" << endl;
            }
            currentGuess++;
        }

        if (currentGuess > maxGuesses)
        {
            cout << "You've reached the maximum number of guesses. The number was " << target << ". You lose." << endl;
        }
    }

}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    while(true)
    {
        startGame();


        cout << "Would you like to play again? (Answer Y for yes, N for no) ";

        char answer;

        cin >> answer;

        if (answer != 'Y')
        {
            cout << "Thank you for playing!";
            break;
        }
    }
    return 0;
}
