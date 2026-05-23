#include "game.h"

void checkInventory(Player &player, vector<Items> &inventory, vector<Items> &shopitems, int &eraseIndex){
	char option;
	
	while (option != 'x'){
		cout << '\n' << "|-------------------------------------------|" << "\n\n";
		cout << player.name << "'s inventory" << "\n\n";
		
		if (inventory.empty()){
			cout << "Inventory is empty :(" << '\n';
		}
		
		for (unsigned int i = 0; i < inventory.size(); i++){
			if (inventory.at(i).isConsumable == true && inventory.at(i).name == shopitems.at(0).name){
				cout << '[' << i+1 << "] " << inventory.at(i).name << " (" << shopitems.at(0).quantity << "/5)" << '\n';
			}
			else if(inventory.at(i).isEquipped == true){
				cout << '[' << i+1 << "] " << inventory.at(i).name << "(Equipped)" << '\n';
			}
			else if(inventory.at(i).isEquipped == false){
				cout << '[' << i+1 << "] " << inventory.at(i).name << "(Unequipped)" << '\n';
			}
		}

		cout << '\n' << "|-------------------------------------------|" << "\n\n";

		cout << '\n' << "[x] - Close Inventory" << '\n';
		cin >> option;
		
		switch(option){
			case '1':
					inventoryInteraction(player, inventory, shopitems, inventory.at(0), eraseIndex = 0);
					break;
			case '2': 
					inventoryInteraction(player, inventory, shopitems, inventory.at(1), eraseIndex = 1);
					break;
			case '3': 
					inventoryInteraction(player, inventory, shopitems, inventory.at(2), eraseIndex = 2);
					break;
			case '4': 
					inventoryInteraction(player, inventory, shopitems, inventory.at(3), eraseIndex = 3);
					break;
			case '5': 
					inventoryInteraction(player, inventory, shopitems, inventory.at(4), eraseIndex = 4);
					break;
			case '6': 
					inventoryInteraction(player, inventory, shopitems, inventory.at(5), eraseIndex = 5);
					break;
			case '7': 
					inventoryInteraction(player, inventory, shopitems, inventory.at(6), eraseIndex = 6);
					break;
			case '8': 
					inventoryInteraction(player, inventory, shopitems, inventory.at(7), eraseIndex = 7);
					break;
			default:
					break;
					
		}
	}
}
void inventoryInteraction(Player &player, vector<Items> &inventory, vector<Items> &shopitems, Items &inventorySlot, int &eraseIndex){
	
	if (inventorySlot.name == shopitems.at(0).name){	// inventorySlot string is created to represent each inventory item
		if (!inventory.empty() && shopitems.at(0).quantity <= 1){
			inventory.erase(inventory.begin() + eraseIndex);
		}
		else{
			shopitems.at(0).quantity -= 1;
		}

		if (player.health >= 100){
			player.health = 100;
			cout << "You're already full hp!" << '\n';
		}
		else{
			player.health += 25;
			cout << "You drank a health potion and restored 25 hp" << '\n';
		}
	}
	else if (inventorySlot.name == shopitems.at(1).name){
		char option = ' ';
		
		while (option != 'x'){
			if (inventorySlot.isEquipped == false){
				cout << "- " << shopitems.at(1).name << "\n\n";
				cout << "[1] Equip" << '\n';
				cout << "[x] Back" << '\n';
				
				cin >> option;
				
				switch(option){
					
					case '1':
							inventorySlot.isEquipped = true;
							player.damage += 15;
							break;
					case '2':
							break;
					default:
							break;
				}
			}
			else{
				cout << "- " << shopitems.at(1).name << "\n\n";
				cout << "[1] Unquip" << '\n';
				cout << "[x] Back" << '\n';
				
				cin >> option;
				
				switch(option){
					case '1':
							inventorySlot.isEquipped = false;
							player.damage -= 15;
							break;
					case '2':
							break;
					default:
							break;
				}
			}
		}
	}
	else if (inventorySlot.name == shopitems.at(2).name){
		char option = ' ';
		
		while (option != 'x'){
			if (inventorySlot.isEquipped == false){
				cout << "- " << shopitems.at(2).name << "\n\n";
				cout << "[1] Equip" << '\n';
				cout << "[x] Back" << '\n';
				
				cin >> option;
				
				switch(option){
					case '1':
							inventorySlot.isEquipped = true;
							player.damage += 15;
							break;
					case '2':
							break;
					default:
							break;
				}
			}
			else{
				cout << "- " << shopitems.at(2).name << "\n\n";
				cout << "[1] Unquip" << '\n';
				cout << "[x] Back" << '\n';
				
				cin >> option;
				
				switch(option){
					case '1':
							inventorySlot.isEquipped = false;
							player.damage -= 15;
							break;
					case '2':
							break;
					default:
							break;
				}
			}
		}
	}
	else if (inventorySlot.name == shopitems.at(3).name){
		char option = ' ';
		
		while (option != 'x'){
			if (inventorySlot.isEquipped == false){
				cout << "- " << shopitems.at(3).name << "\n\n";
				cout << "[1] Equip" << '\n';
				cout << "[x] Back" << '\n';
				
				cin >> option;
				
				switch(option){
					case '1':
							inventorySlot.isEquipped = true;
							player.damage += 15;
							break;
					case '2':
							break;
					default:
							break;
				}
			}
			else{
				cout << "- " << shopitems.at(3).name << "\n\n";
				cout << "[1] Unquip" << '\n';
				cout << "[x] Back" << '\n';
				
				cin >> option;
				
				switch(option){
					case '1':
							inventorySlot.isEquipped = false;
							player.damage -= 15;
							break;
					case '2':
							break;
					default:
							break;
				}
			}
		}
	}
	else{
		cout << "You cannot use/equip something that doesn't exist :|" << '\n';
	}
}