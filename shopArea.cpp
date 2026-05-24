#include "game.h"

void shopArea(Player &player, vector<Items> &inventory, vector<Items> &shopitems){
	bool alreadyPurchased = false;
	
	cout << "(----------------------------------------------------------)" << "\n\n";
	
	cout << "Trader: Welcome to my shop, stranger! What can I do for you?" << "\n\n";
	
	cout << "(----------------------------------------------------------)" << "\n\n";
	
	char option;
	
	while (option != 'x'){
	alreadyPurchased = false; // each loop iteration, the bool sets to false, so we can buy something else
			
		cout << "|-------------------------------------------|" << "\n\n";
		
		cout << "Coins: " << player.balance << "\n\n";
		
		cout << "[1]" << shopitems.at(0).name << '\n';
		cout << "[2]" << shopitems.at(1).name << '\n';
		cout << "[3]" << shopitems.at(2).name << '\n';
		cout << "[4]" << shopitems.at(3).name << "\n\n";
		
		cout << "[x] Go back to Main Area" << "\n\n";
		
		cout << "|-------------------------------------------|" << "\n\n";
		cin >> option;

		switch(option){
			case '1':
					if (shopitems.at(0).quantity == 5){
						cout << "You can carry maximum 5 health potions at once" << '\n';
						continue;
					}
					if (player.balance >= 25){
						player.balance -= 25;
						shopitems.at(0).quantity += 1;
						cout << '\n' << "You purchased one health potion!" << '\n';
						
						if (shopitems.at(0).quantity > 1){
							continue;
						}
						inventory.push_back(shopitems.at(0));
					}
					else{
						cout << '\n' << "You don't have enough gold" << "\n\n";
					}
					break;
			case '2':
					voidedValidation(inventory, shopitems.at(1).name, alreadyPurchased);
					if (alreadyPurchased){
						continue;
					}
					if (player.balance >= 50){
						player.balance -= 50;
						inventory.push_back(shopitems.at(1));
						cout << '\n' << "You purchased a " << shopitems.at(1).name << '\n';
					}
					else{
						cout << '\n' << "You don't have enough gold" << '\n';
					}
					break;
			case '3':
					voidedValidation(inventory, shopitems.at(2).name, alreadyPurchased);
					if (alreadyPurchased){
						continue;
					}
					if (player.balance >= 100){
						player.balance -= 100;
						inventory.push_back(shopitems.at(2));
						cout << '\n' << "You purchased a " << shopitems.at(2).name << '\n';
					}
					else{
						cout << '\n' << "You don't have enough gold" << '\n';
					}
					break;
			case '4':
					voidedValidation(inventory, shopitems.at(3).name, alreadyPurchased);
					if (alreadyPurchased){
						continue;
					}
					if (player.balance >= 250){
						player.balance -= 250;
						inventory.push_back(shopitems.at(3));
						cout << '\n' << "You purchased a " << shopitems.at(3).name << '\n';
					}
					else{
						cout << '\n' << "You don't have enough gold" << '\n';
					}
					break;
			default:
					break;
		}		
	}
}
void voidedValidation(vector<Items> &inventory, string &itemName, bool &alreadyPurchased){
	auto iterator = find_if(inventory.begin(), inventory.end(),
		[itemName](const Items &i){
			return i.name == itemName;
		}
	);

	if (iterator != inventory.end()){										// l1 if iterator didn't make it to the end of inventory
	cout << "You already purchased that item!" << '\n';						// l2 it means that an element of shopitems is already in inventory
	alreadyPurchased = true;
	}
}





















