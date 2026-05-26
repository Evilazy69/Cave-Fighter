#include "game.h"

void checkInventory(Player &player, vector<Items> &inventory, vector<Items> &shopitems, int &eraseIndex){
	string option = " ";
	
	while (true){
		cout << '\n' << "|-------------------------------------------|" << "\n\n";
		cout << player.name << "'s inventory" << "\n\n";
		
		if (inventory.empty()){
			cout << "Inventory is empty :(" << '\n';
		}
		
		for (unsigned int i = 0; i < inventory.size(); i++){
			if (inventory.at(i).type == CONSUMABLE && inventory.at(i).name == shopitems.at(0).name){
				cout << '[' << i+1 << "] " << inventory.at(i).name << " (" << shopitems.at(0).quantity << "/5)" << '\n';
			}
			else if(inventory.at(i).isEquipped == true){
				cout << '[' << i+1 << "] " << inventory.at(i).name << " (Equipped)" << '\n';
			}
			else if(inventory.at(i).isEquipped == false){
				cout << '[' << i+1 << "] " << inventory.at(i).name << " (Unequipped)" << '\n';
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
		
		inventoryInteraction(player, inventory, shopitems, inventory.at(opt-1), eraseIndex = opt-1);
	}
}
void inventoryInteraction(Player &player, vector<Items> &inventory, vector<Items> &shopitems, Items &inventorySlot, int &eraseIndex){
	
	if (inventorySlot.type == CONSUMABLE){	// inventorySlot string is created to represent each inventory item
		itemConsumption(player, inventory, shopitems, inventorySlot, eraseIndex);
	}
	else if (inventorySlot.type == WEAPON){
		itemEquipment(player, inventory, shopitems, inventorySlot, eraseIndex);
	}
	else{
		cout << "You cannot use/equip something that doesn't exist :|" << '\n';
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