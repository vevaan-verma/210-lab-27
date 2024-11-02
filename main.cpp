// COMSC-210 | Lab 27 | Vevaan Verma
using namespace std;
#include <iostream>
#include <map>
#include <tuple>
#include <string>

/* FUNCTION PROTOTYPES */
int getMenuChoice();
void addVillager(map<string, tuple<int, string, string>>& villagerColors);
void deleteVillager(map<string, tuple<int, string, string>>& villagerColors);
void increaseFriendship(map<string, tuple<int, string, string>>& villagerColors);
void decreaseFriendship(map<string, tuple<int, string, string>>& villagerColors);
void searchVillager(map<string, tuple<int, string, string>>& villagerColors);
void outputVillagers(map<string, tuple<int, string, string>>& villagerColors);
int getValidatedChoice(int min, int max);

// main() is the entry point of the program and drives the program
// arguments: none
// returns: int - the exit code of the program
int main() {

	// parameters: friendship level (0 - 10), species, catchphrase
	map<string, tuple<int, string, string>> villagerColors;

	int userChoice = getMenuChoice();

	while (userChoice != 6) { // loop while the user does not choose to exit

		switch (userChoice) { // switch on the user's choice

		case 1: // if the user chooses to add a villager

			addVillager(villagerColors); // add a villager
			break;

		case 2: // if the user chooses to delete a villager

			deleteVillager(villagerColors); // delete a villager
			break;

		case 3: // if the user chooses to increase the friendship level of a villager

			increaseFriendship(villagerColors); // increase the friendship level of a villager
			break;

		case 4: // if the user chooses to decrease the friendship level of a villager

			decreaseFriendship(villagerColors); // decrease the friendship level of a villager
			break;

		case 5: // if the user chooses to search for a villager

			searchVillager(villagerColors); // search for a villager
			break;

		}

		outputVillagers(villagerColors); // output the villagers in the map
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

// addVillager() adds a villager to the map
// arguments: map<string, tuple<int, string, string>& villagerColors - the map of villagers
// returns: void
void addVillager(map<string, tuple<int, string, string>>& villagerColors) {

	string name; // variable to store the name of the villager
	int friendship; // variable to store the friendship level of the villager
	string species; // variable to store the species of the villager
	string catchphrase; // variable to store the catchphrase of the villager

	cout << "Villager Name: ";
	cin >> name; // get the name of the villager

	cout << "Friendship Level (0 - 10): ";
	friendship = getValidatedChoice(0, 10); // get the friendship level of the villager

	cout << "Species: ";
	cin >> species; // get the species of the villager

	cout << "Catchphrase: ";
	getline(cin, catchphrase); // get the catchphrase of the villager

	villagerColors.insert({ name, { friendship, species, catchphrase } }); // insert the villager into the map

}

// getValidatedChoice() gets a validated integer choice from the user (between min and max inclusive)
// arguments: int min - the minimum value, int max - the maximum value
// returns: int - the validated integer choice
int getValidatedChoice(int min, int max) {

	int inputInt; // variable to store the input (of type int)

	while (!(cin >> inputInt) || inputInt < min || inputInt > max) { // while the input is not an integer or is not between the min and max

		cin.clear(); // clear the input stream
		cout << "Invalid input. Please enter a valid integer: "; // prompt the user to enter an integer

	}

	return inputInt;

}