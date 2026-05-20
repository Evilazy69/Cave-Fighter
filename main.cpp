#include "game.h"  

int main(){
	Player player;
	player.health = 100;
	player.damage = 10;
	player.balance = 1000;
	player.playerPosition = 0;
	
	int eraseIndex; // inventory.cpp
	
	Items healthPotion;
	healthPotion.name = "Health Potion";
	healthPotion.price = 25;
	healthPotion.isEquipped = false;
	healthPotion.isConsumable = true;
	healthPotion.quantity = 0;
	
	Items bowieKnife;
	bowieKnife.name = "Bowie Knife";
	bowieKnife.price = 100;
	bowieKnife.isEquipped = false;
	bowieKnife.isConsumable = true;
	
	Items machete;
	machete.name = "Machete";
	machete.price = 250;
	machete.isEquipped = false;
	machete.isConsumable = true;
	
	Items sword;
	sword.name = "Sword";
	sword.price = 500;
	sword.isEquipped = false;
	sword.isConsumable = true;
	
	vector<Items> shopitems = {healthPotion, bowieKnife, machete, sword};
	vector<Items> inventory;
	
	
	

	char option;
	
	while(option != 'x'){	
		cout << '\n' << "....................................................." << "\n\n";
		
		cout << "Welcome to the Dungeon Crawler Game v0.14" << "\n\n";

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
					mainArea(player, inventory, shopitems, eraseIndex);
					break;
			case '2':
					break;
			default:
					break;
		}
	}
}
void mainArea(Player &player, vector<Items> &inventory, vector<Items> &shopitems, int &eraseIndex){
	
	char option;
	
	while (option != 'x'){
	
		cout << "..!..!!..!!!...!.!!.!!.!!!..!!!.!!!.!!!!.!!.!!.!!." << "\n\n";
		cout << "Health: " << player.health << '\n';
		cout << "Coins: " << player.balance << "\n\n";
		
		cout << "[1] Enter Shop" << '\n';
		cout << "[2] Enter Cave" << '\n';
		cout << "[3] Check stats" << '\n';
		cout << "[4] Inventory" << "\n\n";
		
		cout << "[x] Main menu" << "\n\n";
		
		cout << "..!..!!..!!!...!.!!.!!.!!!..!!!.!!!.!!!!.!!.!!.!!." << "\n\n";
		
		cin >> option;
		
		switch(option){
			case '1':
					shopArea(player, inventory, shopitems);
					break;
			case '2':
					cout << '\n' << "***... Entering the underground world ...***" << '\n';
					mainCaveArea(player, inventory, shopitems, eraseIndex);
					break;
			case '3':
					checkStats(player, inventory);
					break;
			case '4':
					checkInventory(player, inventory, shopitems, eraseIndex);
					break;
			default:
					break;
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

/*

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
	
	char option;
	
*/



			 // {Item healthPotion, Item BowieKnife, Item Machete, Item Sword};