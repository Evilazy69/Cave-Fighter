#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Player{
	
	string name;

	int health;
	int balance;
	int damage;
};

void choosePlayerName(Player &player);
void mainArea(Player &player, vector<string> &itemlist);
void checkStats(Player &player, vector<string> &itemlist);
void checkInventory(Player &player, vector<string> &itemlist);
void shopArea(Player &player, vector<string> &itemlist);
void voidedValidation(vector<string> &itemlist, string &itemName, bool &alreadyPuchased);
void caveArea(Player &player, vector<string> &itemlist);


int main(){
	Player player;
	player.health = 100;
	player.damage = 10;
	player.balance = 150;
	
	vector<string> itemlist;

	char option;

	while(option != 'x'){	
		cout << '\n' << "....................................................." << "\n\n";
		
		cout << "Welcome to the Dungeon Crawler Game" << "\n\n";

		cout << "~~~ Main menu ~~~" << "\n\n";

		cout << "[1] Play" << '\n';
		cout << "[2] Settings" << "\n\n";

		cout << "[x] Quit" << '\n';
			
		cout << '\n' << "....................................................." << "\n\n";
		
		cin >> option;		 
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
		
		switch(option){
			case '1':
					choosePlayerName(player);
					mainArea(player, itemlist);
					break;
			case '2': 
					break;
			default:
					cout << "Invalid option\n";
		}
	}
}


void choosePlayerName(Player &player){
	
	cout << '\n' << "~ Choose a name for your character ~" << "\n\n";

	string name;
	while (name.empty()){
		getline(cin, name);
		if (name.empty()){
			cout << "Empty name doesn't count!" << '\n';
		}
	}
	
	player.name = name;
	
	cout << '\n' << ".........................................." << "\n\n";
	
	cout << "Welcome to the Undefined World, " << player.name << '\n';
	cout << "Press enter to teleport to the main area" << '\n';
	
	cout << '\n' << ".........................................." << "\n\n";

	cin.get();
	
	cout << "Teleporting to the main area..." << "\n\n";
}
void mainArea(Player &player, vector<string> &itemlist){
	string area = " -- Lobby sobby --";
	
	char option;
	
	while (option != 'x'){
	
		cout << "..!..!!..!!!...!.!!.!!.!!!..!!!.!!!.!!!!.!!.!!.!!." << "\n\n";
		cout << "Health: " << player.health << '\n';
		cout << "Gold: " << player.balance << "\n\n";
		
		cout << "[1] Enter Shop" << '\n';
		cout << "[2] Enter Cave" << '\n';
		cout << "[3] Check stats" << '\n';
		cout << "[4] Inventory" << "\n\n";
		
		cout << "[x] Main menu" << "\n\n";
		
		cout << "..!..!!..!!!...!.!!.!!.!!!..!!!.!!!.!!!!.!!.!!.!!." << "\n\n";
		
		cin >> option;
		
		switch(option){
			case '1':
					shopArea(player, itemlist);
					break;
			case '2':
					cout << '\n' << "***... Entering the darkest caves ...***" << '\n';
					caveArea(player, itemlist);
					break;
			case '3':
					checkStats(player, itemlist);
					break;
			case '4':
					checkInventory(player, itemlist);
					break;
			default:
					break;
		}
	}
}
void checkStats(Player &player, vector<string> &itemlist){
	cout << '\n' << "|-------------------------------------------|" << "\n\n";
	cout << player.name << "'s statistics" << "\n\n";
	
	cout << "Health: " << player.health << '\n';
	cout << "Gold: " << player.balance << '\n';
	cout << "Damage: " << player.damage << '\n';
	cout << '\n' << "|-------------------------------------------|" << "\n\n";
	
	char option;
	
	while (option != 'x'){
		cout << '\n' << "[x] - Back to Lobby sobby" << '\n';
		cin >> option;
	}

}
void checkInventory(Player &player, vector<string> &itemlist){
	cout << '\n' << "|-------------------------------------------|" << "\n\n";
	cout << player.name << "'s inventory" << "\n\n";
	
	if (itemlist.empty()){
		cout << "Inventory is empty :(" << '\n';
	}
	
	for (unsigned int i = 0; i < itemlist.size(); i++){
		cout << "- " << itemlist.at(i) << '\n';
	}
	cout << '\n' << "|-------------------------------------------|" << "\n\n";

	
	char option;
	
	while (option != 'x'){
		cout << '\n' << "[x] - Back to Lobby sobby" << '\n';
		cin >> option;
	}
}
void shopArea(Player &player, vector<string> &itemlist){
	vector<string> shopitems = {"Health potion", "Steel knife", "Sharp stainless steel knife", "Oversharpened high carbon stainless steel knife"};
	bool alreadyPurchased = false;
	
	cout << "(----------------------------------------------------------)" << "\n\n";
	
	cout << "Trader: Welcome to my shop, stranger! What can I do for you?" << "\n\n";
	
	cout << "(----------------------------------------------------------)" << "\n\n";
	
	char option;
	
	while (option != 'x'){
	alreadyPurchased = false; // each loop iteration, the bool sets to false, so we can buy something else
			
		cout << "|-------------------------------------------|" << "\n\n";
		
		cout << "[1]" << shopitems.at(0) << '\n';
		cout << "[2]" << shopitems.at(1) << '\n';
		cout << "[3]" << shopitems.at(2) << '\n';
		cout << "[4]" << shopitems.at(3) << "\n\n";
		
		cout << "[x] Go back to Main Area" << "\n\n";
		
		cout << "|-------------------------------------------|" << "\n\n";
		cin >> option;

		switch(option){
			case '1':
					if (player.balance >= 25){
						player.balance -= 25;
						itemlist.push_back("Health potion");
						cout << '\n' << "You purchased one health potion!" << '\n';
					}
					else{
						cout << '\n' << "You don't have enough gold" << "\n\n";
					}
					break;
			case '2':
					voidedValidation(itemlist, shopitems.at(1), alreadyPurchased);
					if (alreadyPurchased){
						continue;
					}
					if (player.balance >= 50){
						player.balance -= 50;
						itemlist.push_back("Steel knife");
						player.damage += 2;
						cout << '\n' << "You purchased a steel knife!" << '\n';
					}
					else{
						cout << '\n' << "You don't have enough gold" << '\n';
					}
					break;
			case '3':
					voidedValidation(itemlist, shopitems.at(2), alreadyPurchased);
					if (alreadyPurchased){
						continue;
					}
					if (player.balance >= 100){
						player.balance -= 100;
						itemlist.push_back("Sharp stainless steel knife");
						player.damage += 5;
						cout << '\n' << "You purchased a sharp stainless steel knife!" << '\n';
					}
					else{
						cout << '\n' << "You don't have enough gold" << '\n';
					}
					break;
			case '4':
					voidedValidation(itemlist, shopitems.at(3), alreadyPurchased);
					if (alreadyPurchased){
						continue;
					}
					if (player.balance >= 250){
						player.balance -= 250;
						itemlist.push_back("Oversharpened high carbon stainless steel knife");
						player.damage += 15;
						cout << '\n' << "You purchased an oversharpened high carbon stainless steel knife!!!" << '\n';
					}
					else{
						cout << '\n' << "You don't have enough gold" << '\n';
					}
					break;
		
		}		
	}
}
void caveArea(Player &player, vector<string> &itemlist){
	srand(time(NULL));
	
	vector<string> passlist;
	int hiddenPassCount = rand() % 2 + 1; 
	
	cout << "000ooo000o0o0o0ooo0ooo0oooo00000ooo000oooo000ooo0000ooo000" << '\n';
	
	if (hiddenPassCount == 1){
		cout << '\n' << "You stumbled upon " << hiddenPassCount << " hidden cave entry!" << '\n';
		passlist.push_back("Dark passage");
	}
	else{
		cout << '\n' << "You stumbled upon " << hiddenPassCount << " hidden cave entries!" << '\n';
		for (int i = 1; i <= 2; i++){
			passlist.push_back("Dark passage " + to_string(i));
		}
	}
	
	cout << '\n' << "Where do you want to go?" << "\n\n";
	
	for (unsigned int i = 0; i < passlist.size(); i++){
		cout << "[" << i+1 << "]" << ' ' << passlist.at(i) << '\n';
	}
	cout << '\n' << "000ooo000o0o0o0ooo0ooo0oooo00000ooo000oooo000ooo0000ooo000" << '\n';
	
	char option;
	
	while (option != 'x'){
		cout << '\n' << "[x] - Back to Lobby sobby" << '\n';
		cin >> option;
	}
}
void voidedValidation(vector<string> &itemlist, string &itemName, bool &alreadyPurchased){
	auto iterator = find(itemlist.begin(), itemlist.end(), string(itemName));

	if (iterator != itemlist.end()){										// l1 if iterator didn't make it to the end of itemlist
	cout << "You already purchased that item!" << '\n';						// l2 it means that an element of shopitems is already in itemlist
	alreadyPurchased = true;
	}
}