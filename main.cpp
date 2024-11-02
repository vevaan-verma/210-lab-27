// COMSC-210 | Lab 27 | Vevaan Verma
using namespace std;
#include <iostream>
#include <map>
#include <tuple>
#include <string>

/* FUNCTION PROTOTYPES */
int getMenuChoice();
int getValidatedChoice(int min, int max);

// main() is the entry point of the program and drives the program
// arguments: none
// returns: int - the exit code of the program
int main() {

	// parameters: friendship level (0 - 10), species, catchphrase
	map<string, tuple<int, string, string>> villagerColors;

	int userChoice = getMenuChoice();
	cout << endl; // output blank line for formatting

	while (userChoice != 6) { // loop while the user does not choose to exit

		userChoice = getMenuChoice(); // get the user's choice

	}

	return 0;

}

// getMenuChoice() displays the menu and gets the user's choice
// arguments: none
// returns: int - the user's choice
int getMenuChoice() {

	cout << "1. Add Villager" << endl;
	cout << "2. Delete Villager" << endl;
	cout << "3. Increase Friendship" << endl;
	cout << "4. Decrease Friendship" << endl;
	cout << "5. Search for Villager" << endl;
	cout << "6. Exit" << endl;

	cout << "Enter your choice: ";
	return getValidatedChoice(1, 6);

}

// getValidatedChoice() gets a validated integer choice from the user (between min and max inclusive)
// arguments: int min - the minimum value, int max - the maximum value
// returns: int - the validated integer choice
int getValidatedChoice(int min, int max) {

	int inputInt; // variable to store the input (of type int)

	while (!(cin >> inputInt) || inputInt < min || inputInt > max) { // while the input is not an integer or is not between the min and max

		cin.clear(); // clear the input stream
		cin.ignore(INT_MAX, '\n'); // ignore the invalid input
		cout << "Invalid input. Please enter a valid integer: "; // prompt the user to enter an integer

	}

	return inputInt;

}