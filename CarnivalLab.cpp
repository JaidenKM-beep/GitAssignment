// Jaiden Monet CS179
// Carnival Mystery Code Lab
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
using namespace std;

class Location {
private:
	string name;
	string description;
public:
	void setName(string place) {
		name = place;
	}
	string getName() const {
		return name;
	}
};

class GameBooth : public Location {
	// code here
private:
	int tokens; 
	string prize;
};
class FoodStand : public Location {
	// code here
private:
	string foodName;
	double price;
};

class Ride : public Location {
public:
	int cost;
};

class Player {
public:
	string name;
	int tokensCollected;
	int cluesFound;
	
	
};
int main() {
	int choice;
	bool gameOver = false;
	srand(time(0));

	Location carnivalEntrance;
	carnivalEntrance.setName("Carnival Entrance");

	GameBooth ringToss; // Initialize location at carnival to look for clues
	GameBooth balloonDarts;

	FoodStand popcornStand; 
	FoodStand icecreamStand;

	Ride ferrisWheel;
	Ride merryGoround;
	
	ringToss.setName("Toss a Ring Booth");
	balloonDarts.setName("Pop The Balloon Stand");
	popcornStand.setName("Popcorn Stand");
	icecreamStand.setName("Willie's IceCream");
	merryGoround.setName("Merry Go Round");
	
	ferrisWheel.setName("Ferris Wheel");
	ferrisWheel.cost = 1;

	Player player1;
	player1.name = "Unknown"; // enter input for name later
	player1.tokensCollected = 0;
	player1.cluesFound = 0;

	vector<string> clues;
	map<string, string> rideClues;

	rideClues["Ferris Wheel"] = "Someone was seen near the prize tent";
	rideClues["Merry Go Round"] = "Hand prints were seen on the outskirts of the tents";

	map<string, string> rideContacts;
	rideContacts["Ferris Wheel"] = "Marco";
	rideContacts["Merry Go Round"] = "Lena";


	Location* playerLocation;
	playerLocation = &carnivalEntrance;

	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
	cout << "-----------You are a visitor at the carnival who decides to help find it.---------------------------------------" << endl;
	cout << "-----------You will be visiting different game booths and food stands,------------------------------------------" << endl;
	cout << "-----------In order to collect clues to figure out who took the ring and where they could be----------------------" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
	
	cout << "Please enter your name: " << endl;
	getline(cin, player1.name);
	cout << "-----------------------------------------------------------------------------------------------------------------------";
	cout << "\n Hello " << player1.name << ", someone has stolen the carnival owners lucky gold ring." << endl;
	cout << " A small piece of cloth from a costume was found near the ring toss booth." << endl;

	cout << " Player: " << player1.name << endl << " Current Location: "
		<< playerLocation->getName()
		<< endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	
	while (gameOver == false) {
		
		cout << "\n1. Ring Toss Booth\n";
		cout << "2. Popcorn Stand\n";
		cout << "3. Pop The Balloon Stand\n";
		cout << "4. Ice Cream Stand\n";
		cout << "5. Ferris Wheel\n";
		cout << "6. Merry Go Round\n";
		cout << "7. Quit\n";
		cout << "Enter choice: ";

		cin >> choice;

		if (cin.fail()) {
			cout << "Invalid input." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}

		if (choice == 1) {
			playerLocation = &ringToss;
			cout << "\nYou go to the " << playerLocation->getName() << "." << endl;
			cout << "You try the ring toss game..." << endl;

			int result = rand() % 2; // randomized for game attempt

			if (result == 1) {
				cout << "Congrats you won the game" << endl;
				cout << "2 tokens found nearby" << endl;
				clues.push_back(" Striped cloth near ring toss");
				player1.tokensCollected += 2;
				
				cout << "Clue: You notice a torn piece of red and white striped cloth nearby." << endl;
				player1.cluesFound++;
			}
			else {
				cout << "You missed..." << endl;
				cout << "Better luck next time" << endl;
			}
		}
		
		else if (choice == 2) {
			playerLocation = &popcornStand;
			cout << "\nYou go to the " << playerLocation->getName() << "." << endl;
			if (player1.tokensCollected >= 2) {
				cout << "You buy popcorn for 2 tokens." << endl;
				clues.push_back("Stranger with torn pants");
				player1.tokensCollected -= 2;

				cout << "You overhear A group of workers discussing a strange man walking around the area with torn pants." << endl;
				cout << "One worker also says, \"If the Ferris Wheel breaks down, yell for Marco. He runs that ride.\"" << endl;
				player1.cluesFound++;
			}
			else {
				cout << "Not enough tokens." << endl;
				cout << "Maybe try looking around a little bit more" << endl;
			}
		}
		else if (choice == 3) {
			playerLocation = &balloonDarts;
			cout << "\nYou go to the " << playerLocation->getName() << "." << endl;

			cout << "You try the pop the balloon game..." << endl;
			int result = rand() % 2;// Randomize for game attempt 

			if (result == 1) {
				cout << "Congrats you won the game" << endl;
				clues.push_back("Footsteps behind tent");
				player1.tokensCollected += 1;

				cout << "Clue: You notice some footsteps leading behind the tent." << endl;
				player1.cluesFound++;
			}
			else {
				cout << "You missed..." << endl;
			}

		}
		else if (choice == 4) {
			playerLocation = &icecreamStand;
			cout << "\nYou go to the " << playerLocation->getName() << "." << endl;
			if (player1.tokensCollected >= 3) {
				cout << "You buy ice cream for 3 tokens." << endl;
				clues.push_back("Dirt on tents");
				player1.tokensCollected -= 3;

				cout << "You overhear about dirty handprints found around the tents." << endl;
				cout << "The worker says, \"If the Merry Go Round stops, yell for Lena. She knows how to fix it.\"" << endl;
				player1.cluesFound++;
			}
			else {
				cout << "Not enough tokens." << endl;
			}
		}
		else if (choice == 5) {
			playerLocation = &ferrisWheel;
			cout << "\nYou go to the " << playerLocation->getName() << endl;

			if (player1.tokensCollected >= ferrisWheel.cost) {
				player1.tokensCollected -= ferrisWheel.cost;

				cout << "You ride the Ferris Wheel." << endl;
				int breakdown = rand() % 2;

				if (breakdown == 1) {
					string workerName;

					cout << "The Ferris Wheel suddenly stops in the air!" << endl;
					cout << "You remember that a worker at the popcorn stand mentioned someone who runs this ride." << endl;
					cout << "Who do you yell for? ";
					cin >> workerName;

					if (workerName == rideContacts["Ferris Wheel"] || workerName == "marco") {
						cout << "Marco hears you from below and runs to the control booth." << endl;
						cout << "He fixes the ride and safely brings you back down." << endl;
						cout << "While coming down, you notice something important." << endl;
						cout << "Clue: " << rideClues["Ferris Wheel"] << endl;

						clues.push_back(rideClues["Ferris Wheel"]);
						player1.cluesFound++;
					}
					else {
						cout << "No one responds to that name." << endl;
						cout << "You are stuck for a while before another worker finally helps." << endl;
					}
				}
				else {
					cout << "The ride goes smoothly." << endl;
					cout << "Clue: " << rideClues["Ferris Wheel"] << endl;

					clues.push_back(rideClues["Ferris Wheel"]);
					player1.cluesFound++;
				}
			}
			else {
				cout << "Not enough tokens." << endl;
			}
		}

		else if (choice == 6) {
			playerLocation = &merryGoround;
			cout << "\nYou go to the " << playerLocation->getName() << endl;

			cout << "You ride the Merry Go Round." << endl;
			int breakdown = rand() % 2;

			if (breakdown == 1) {
				string workerName;

				cout << "The Merry Go Round suddenly stops spinning!" << endl;
				cout << "You remember that someone at the ice cream stand mentioned a worker for this ride." << endl;
				cout << "Who do you yell for? ";
				cin >> workerName;

				if (workerName == rideContacts["Merry Go Round"] || workerName == "lena") {
					cout << "Lena hears you and rushes over to fix the ride." << endl;
					cout << "While waiting, you notice something suspicious near the ride." << endl;
					cout << "Clue: " << rideClues["Merry Go Round"] << endl;

					clues.push_back(rideClues["Merry Go Round"]);
					player1.cluesFound++;
				}
				else {
					cout << "No one responds to that name." << endl;
					cout << "You have to wait until another worker notices the ride stopped." << endl;
				}
			}
			else {
				cout << "The ride goes smoothly." << endl;
				cout << "Clue: " << rideClues["Merry Go Round"] << endl;

				clues.push_back(rideClues["Merry Go Round"]);
				player1.cluesFound++;
			}
			}
		else if (choice == 7) {
			gameOver = true;
		}
		else {
			cout << "Invalid Response" << endl;
		}

		// Show clues
		cout << "\nClues collected:\n";
		for (int i = 0; i < clues.size(); i++) {
			cout << "- " << clues[i] << endl;
		}

		// Win condition
		if (player1.cluesFound >= 3) {
			cout << "\nYou solved the mystery!" << endl;
			cout << "Using your clues you went to the most likely area of the thief and found a imposter clown." << endl;
			cout << "You call the security and recover the golden ring!";

			 // improve with more interaction of final scene 
			gameOver = true;
		}
	}

	cout << "\nGame Over." << endl;
	return 0;
	}
	
	

