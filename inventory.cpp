#include "game.h"

void checkInventory(Player &player, vector<string> &itemlist, vector<string> &shopitems, vector<bool> &isEquipped, int &eraseIndex){
	char option;
	
	while (option != 'x'){
		cout << '\n' << "|-------------------------------------------|" << "\n\n";
		cout << player.name << "'s inventory" << "\n\n";
		
		if (itemlist.empty()){
			cout << "Inventory is empty :(" << '\n';
		}
		
		for (unsigned int i = 0; i < itemlist.size(); i++){ 
			if (itemlist.at(i) == shopitems.at(0)){
				cout << '[' << i+1 << "] " << itemlist.at(i) << '\n';
			}
			if (itemlist.at(i) == shopitems.at(1) || itemlist.at(i) == shopitems.at(2) || itemlist.at(i) == shopitems.at(3)){
				if (isEquipped.at(i) == true){
					cout << '[' << i+1 << "] " << itemlist.at(i) << " (Equipped)" << '\n';
				}
				else{
					cout << '[' << i+1 << "] " << itemlist.at(i) << " (Unequipped)" << '\n';
				}
			}
		}
		cout << '\n' << "|-------------------------------------------|" << "\n\n";

		cout << '\n' << "[x] - Close Inventory" << '\n';
		cin >> option;
		
		switch(option){
			case '1':
					inventoryInteraction(player, itemlist, shopitems, isEquipped, itemlist.at(0), eraseIndex = 0);
					break;
			case '2': 
					inventoryInteraction(player, itemlist, shopitems, isEquipped, itemlist.at(1), eraseIndex = 1);
					break;
			case '3': 
					inventoryInteraction(player, itemlist, shopitems, isEquipped, itemlist.at(2), eraseIndex = 2);
					break;
			case '4': 
					inventoryInteraction(player, itemlist, shopitems, isEquipped, itemlist.at(3), eraseIndex = 3);
					break;
			case '5': 
					inventoryInteraction(player, itemlist, shopitems, isEquipped, itemlist.at(4), eraseIndex = 4);
					break;
			case '6': 
					inventoryInteraction(player, itemlist, shopitems, isEquipped, itemlist.at(5), eraseIndex = 5);
					break;
			case '7': 
					inventoryInteraction(player, itemlist, shopitems, isEquipped, itemlist.at(6), eraseIndex = 6);
					break;
			case '8': 
					inventoryInteraction(player, itemlist, shopitems, isEquipped, itemlist.at(7), eraseIndex = 7);
					break;
			default:
					break;
					
		}
	}
}
void inventoryInteraction(Player &player, vector<string> &itemlist, vector<string> &shopitems, vector<bool> &isEquipped, string &inventorySlot, int &eraseIndex){

	
					if (inventorySlot == shopitems.at(0)){	// inventorySlot string is created to represent each itemlist vector element
						if (!itemlist.empty()){
							itemlist.erase(itemlist.begin() + eraseIndex);
						}
						player.health += 25;
						cout << "You drank a health potion" << '\n';
					}
					else if (inventorySlot == shopitems.at(1)){
						auto iterator = find(isEquipped.begin(), isEquipped.end(), true);
						char option;
						
						while (option != 'x'){
							if (isEquipped.at(0) == false){
								cout << "- " << shopitems.at(1) << "\n\n";
								cout << "[1] Equip" << '\n';
								cout << "[x] Back" << '\n';
								
								cin >> option;
								
								switch(option){
									
									case '1':
											if (iterator != isEquipped.end()){
												cout << '\n' << "You can only equip one weapon at a time" << '!' << "\n\n";
												continue;
											}
											
											isEquipped.at(0) = true;
											player.damage += 15;
											break;
									case '2':
											break;
									default:
											break;
								}
							}
							else{
								cout << "- " << shopitems.at(1) << "\n\n";
								cout << "[1] Unquip" << '\n';
								cout << "[x] Back" << '\n';
								
								cin >> option;
								
								switch(option){
									case '1':
											isEquipped.at(0) = false;
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
					else if (inventorySlot == shopitems.at(2)){
						auto iterator = find(isEquipped.begin(), isEquipped.end(), true);
						char option;
						
						while (option != 'x'){
							if (isEquipped.at(1) == false){
								cout << "- " << shopitems.at(2) << "\n\n";
								cout << "[1] Equip" << '\n';
								cout << "[x] Back" << '\n';
								
								cin >> option;
								
								switch(option){
									case '1':
											if (iterator != isEquipped.end()){
												cout << '\n' << "You can only equip one weapon at a time" << '!' << "\n\n";
												continue;
											}
											
											isEquipped.at(1) = true;
											player.damage += 15;
											break;
									case '2':
											break;
									default:
											break;
								}
							}
							else{
								cout << "- " << shopitems.at(2) << "\n\n";
								cout << "[1] Unquip" << '\n';
								cout << "[x] Back" << '\n';
								
								cin >> option;
								
								switch(option){
									case '1':
											isEquipped.at(1) = false;
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
					else if (inventorySlot == shopitems.at(3)){
						auto iterator = find(isEquipped.begin(), isEquipped.end(), true);
						char option;
						
						while (option != 'x'){
							if (isEquipped.at(2) == false){
								cout << "- " << shopitems.at(3) << "\n\n";
								cout << "[1] Equip" << '\n';
								cout << "[x] Back" << '\n';
								
								cin >> option;
								
								switch(option){
									case '1':
											if (iterator != isEquipped.end()){
												cout << '\n' << "You can only equip one weapon at a time" << '!' << "\n\n";
												continue;
											}
											
											isEquipped.at(2) = true;
											player.damage += 15;
											break;
									case '2':
											break;
									default:
											break;
								}
							}
							else{
								cout << "- " << shopitems.at(3) << "\n\n";
								cout << "[1] Unquip" << '\n';
								cout << "[x] Back" << '\n';
								
								cin >> option;
								
								switch(option){
									case '1':
											isEquipped.at(0) = false;
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