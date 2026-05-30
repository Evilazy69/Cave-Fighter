#include "game.h"

void checkInventory(Player &player, vector<Items> &inventory, vector<Items> &shopitems, int &eraseIndex){
	
	string option = " ";
	
	while (true){
		cout << '\n' << "|-------------------------------------------|" << "\n\n";
		cout << player.name << "'s inventory" << "\n\n";
		
		if (inventory.empty()){
			cout << "Inventory is empty :(" << '\n';
		}
		
		if (player.atLocation != "shopArea"){
			for (unsigned int i = 0; i < inventory.size(); i++){
				
				auto it = find_if(shopitems.begin(), shopitems.end(), // comparing shopitems elements to inventory elements by name member
					[inventory, shopitems, i](const Items &item){	  // this prevents relying that the inventory and shopitems have the same order (which is not always the case)
						return item.name == inventory.at(i).name;	  // so we search what's is certainly matching and then only print the inventory
					}
				);
				
				if (inventory.at(i).type == CONSUMABLE){
					cout << '[' << i+1 << "] " << inventory.at(i).name << " (" << it->quantity << '/' << it->maxQuantity << ')' << '\n';
				}
				else if(inventory.at(i).isEquipped == true){
					cout << '[' << i+1 << "] " << inventory.at(i).name << " (Equipped)" << '\n';
				}
				else if(inventory.at(i).isEquipped == false){
					cout << '[' << i+1 << "] " << inventory.at(i).name << " (Unequipped)" << '\n';
				}
			}
		}
		else{
			for (unsigned int i = 0; i < inventory.size(); i++){
				
				auto it = find_if(shopitems.begin(), shopitems.end(),
					[inventory, shopitems, i](const Items &item){	  
						return item.name == inventory.at(i).name;	  
					}
				);
				
				if (inventory.at(i).type == CONSUMABLE){
					cout << '[' << i+1 << "] " << inventory.at(i).name << " (" << it->quantity << '/' << it->maxQuantity << ')' << '\n';
				}
				else if(inventory.at(i).type == WEAPON){
					cout << '[' << i+1 << "] " << inventory.at(i).name << '\n';
				}
			}
		}

		cout << '\n' << "|-------------------------------------------|" << "\n\n";

		cout << '\n' << "[x] - Close Inventory" << '\n';
		
		cin >> option;
		unsigned int opt = 0;
		
		if (option == "x") break;
		
		try{
			size_t pos;
			opt = stoi(option, &pos);
		}
		catch (...) {
			cout << "Inventory slot is a number" << '\n';
			continue;
		}
		
		
		if (opt > inventory.size() || opt == 0){
			if (inventory.empty()){
				cout << "You cannot chose a slot while inventory is empty" << '\n';
			}
			else{
				cout << "Chose a valid inventory slot" << '\n';
			}
			continue;
		}
		
		inventoryInteraction(player, inventory, shopitems, inventory.at(opt-1), eraseIndex = opt-1); // Inventory slot index interaction depends on what user enters as index
	}
}
void inventoryInteraction(Player &player, vector<Items> &inventory, vector<Items> &shopitems, Items &inventorySlot, int &eraseIndex){
	
	if (player.atLocation != "shopArea"){ // use/equip items
		if (inventorySlot.type == CONSUMABLE){
			itemConsumption(player, inventory, shopitems, inventorySlot, eraseIndex);
		}
		else if (inventorySlot.type == WEAPON){
			itemEquipment(player, inventory, shopitems, inventorySlot, eraseIndex);
		}
		else{
			cout << "You cannot use/equip something that doesn't exist :|" << '\n';
		}
	}
	else{ // sell items
		if (inventorySlot.type == CONSUMABLE || inventorySlot.type == WEAPON){
			sellItems(player, inventory, shopitems, inventorySlot, eraseIndex);
		}
		else{
			cout << "You cannot sell something that doesn't exist :|" << '\n';
		}
	}
}

void itemEquipment(Player &player, vector<Items> &inventory, vector<Items> &shopitems, Items &inventorySlot, int &eraseIndex){
	char option = ' ';
	
	while (option != 'x'){
		
		auto isEquippedTrueCount = count_if(inventory.begin(), inventory.end(),
			[shopitems](const Items &item){
				return item.isEquipped;
			}
		);
		
		if (inventorySlot.isEquipped == false){
			cout << "- " << inventorySlot.name << "\n\n";
			cout << "[1] Equip" << '\n';
			cout << "[x] Back" << '\n';
			
			cin >> option;
			
			switch(option){
				
				case '1':
						if (isEquippedTrueCount >= 1){
							cout << "You can carry only one weapon at a time" << '\n';
							break;
						}
						
						inventorySlot.isEquipped = true;
	
						if (inventorySlot.isEquipped == true){
							player.damage += inventorySlot.bonusdamage;
						}
						break;
				case '2':
						break;
				default:
						break;
			}
		}
		else{
			cout << "- " << inventorySlot.name << "\n\n";
			cout << "[1] Unquip" << '\n';
			cout << "[x] Back" << '\n';
			
			cin >> option;
			
			switch(option){
				case '1':
						inventorySlot.isEquipped = false;
						
						if (inventorySlot.isEquipped == false){
							player.damage -= inventorySlot.bonusdamage;
						}
						break;
				case '2':
						break;
				default:
						break;
			}
		}
	}
}
void itemConsumption(Player &player, vector<Items> &inventory, vector<Items> &shopitems, Items &inventorySlot, int &eraseIndex){
	if (inventorySlot.name == "Health Potion"){
		if (!inventory.empty() && shopitems.at(0).quantity <= 1){
			if (player.health < player.maxHealth){
				inventory.erase(inventory.begin() + eraseIndex);
			}
		}
		if (player.health >= player.maxHealth){
			cout << "You're already full hp!" << '\n';
			player.health = player.maxHealth;
		}
		else{
			if (player.health < player.maxHealth){
				player.health += 25;
				if (player.health >= player.maxHealth){
					player.health = player.maxHealth;
				}
				cout << "You drank a health potion and restored 25 hp" << '\n';
				shopitems.at(0).quantity--;
			}
		}
	}
	else if (inventorySlot.name == "Telecrystl"){
		if (player.atLocation == "clayCaveArea"){
			if (!inventory.empty() && shopitems.at(1).quantity <= 1){
				inventory.erase(inventory.begin() + eraseIndex);
			}
			shopitems.at(1).quantity--;
			player.playerPosition = 0;
			cout << "You absorbed telecrystl and were teleported to the origin..." << '\n';
		}
		else{
			cout << "DEBUG: player.atLocation value: " << player.atLocation << '\n';
			cout << "You can't use this item here" << '\n';
		}
	}
}
