#include "game.h"

void shopArea(Player &player, vector<Items> &inventory, vector<Items> &shopitems){
	bool alreadyPurchased = false;
	
	cout << "(----------------------------------------------------------)" << "\n\n";
	
	cout << "Trader: Welcome to my shop, stranger! What can I do for you?" << "\n\n";
	
	cout << "(----------------------------------------------------------)" << "\n\n";
	
	char option = ' ';
	
	while (option != 'x'){
	alreadyPurchased = false; // each loop iteration, the bool sets to false, so we can buy something else
			
		cout << "|-------------------------------------------|" << "\n\n";
		
		cout << "Coins: " << player.balance << "\n\n";
		
		cout << "[1] " << shopitems.at(0).name << "\t\t" << shopitems.at(0).price << " coins" << '\n';
		cout << "[2] " << shopitems.at(1).name << "\t\t\t" << shopitems.at(1).price << " coins" << '\n';
		cout << "[3] " << shopitems.at(2).name << "\t\t\t" << shopitems.at(2).price << " coins" << '\n';
		cout << "[4] " << shopitems.at(3).name << "\t\t\t" << shopitems.at(3).price << " coins" << "\n\n";
		
		cout << "[x] Go back to Main Area" << "\n\n";
		
		cout << "|-------------------------------------------|" << "\n\n";
		cin >> option;

		switch(option){
			case '1':
					if (shopitems.at(0).quantity >= 5){
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
					buyEquippable(player, inventory, shopitems, alreadyPurchased, shopitems.at(1));
					break;
			case '3':
					voidedValidation(inventory, shopitems.at(2).name, alreadyPurchased);
					if (alreadyPurchased){
						continue;
					}
					buyEquippable(player, inventory, shopitems, alreadyPurchased, shopitems.at(2));
					break;
			case '4':
					voidedValidation(inventory, shopitems.at(3).name, alreadyPurchased);
					if (alreadyPurchased){
						continue;
					}
					buyEquippable(player, inventory, shopitems, alreadyPurchased, shopitems.at(3));
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
void buyEquippable(Player &player, vector<Items> &inventory, vector<Items> &shopitems, bool &alreadyPurchased, Items &item){
	voidedValidation(inventory, shopitems.at(1).name, alreadyPurchased);
	if (player.balance >= item.price){
		player.balance -= item.price;
		inventory.push_back(item);
		cout << '\n' << "You purchased a " << item.name << '\n';
	}
	else{
		cout << '\n' << "You don't have enough gold" << '\n';
	}
}





















