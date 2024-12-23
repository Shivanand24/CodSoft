#include <iostream>

using namespace std;

int main() {
    int n = 2403; 
    int number_of_guesses = 1;
    int guess_number; 

    cout << "Number of guesses is limited to only 9 times: " << endl;

    while (number_of_guesses <= 9) {
        cout << "Guess the number: " << endl;
        cin >> guess_number;

        if (guess_number < 1202) {
            cout << "You entered a lesser number, please input a greater number." << endl;
        } else if (guess_number > 1202) {
            cout << "You entered a greater number, please input a smaller number." << endl;
        } else {
            cout << "You won!" << endl;
            cout << number_of_guesses << " number of guesses you took to finish." << endl;
            break; 
        }

        cout << (9 - number_of_guesses) << " guesses left." << endl;
        number_of_guesses++; 
    }

    if (number_of_guesses > 9) {
        cout << "Game Over" << endl;
    }

    return 0;
}