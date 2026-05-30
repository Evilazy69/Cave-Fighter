#include "game.h"

void shopArea(Player &player, vector<Items> &inventory, vector<Items> &shopitems, int &eraseIndex){
	
	player.atLocation = "shopArea";
	
	bool continueLoop = false;
	char option = ' ';
	char buyOption = ' ';
	
	while (option != 'x'){
		cout << "(----------------------------------------------------------)" << "\n\n";
		
		cout << "Trader: Welcome to my shop, stranger! What can I do for you?" << "\n\n";
		
		cout << "[1] Buy items" << '\n';
		cout << "[2] Sell items" << "\n\n";
		
		cout << "[x] Back to Main Area" << "\n\n";
		
		cout << "(----------------------------------------------------------)" << '\n';
		
		cin >> option;
		
		switch(option){
			case '1':
					option = ' ';
					while (buyOption != 'x'){
						
						bool alreadyPurchased = false;
						alreadyPurchased = false; // each loop iteration, the bool sets to false, so we can buy something else
						continueLoop = false;
						
						cout << "|-------------------------------------------|" << "\n\n";
						
						cout << "Coins: " << player.balance << "\n\n";
						
						cout << "[1] " << shopitems.at(0).name << "\t\t" << shopitems.at(0).price << " coins" << '\n';
						cout << "[2] " << shopitems.at(1).name << "\t\t\t" << shopitems.at(1).price << " coins" << "\n\n";
						
						cout << "[3] " << shopitems.at(2).name << "\t\t\t" << shopitems.at(2).price << " coins" << '\n';
						cout << "[4] " << shopitems.at(3).name << "\t\t\t" << shopitems.at(3).price << " coins" << '\n';
						cout << "[5] " << shopitems.at(4).name << "\t\t\t" << shopitems.at(4).price << " coins" << "\n\n";
						
						cout << "[x] Back" << "\n\n";
						
						cout << "|-------------------------------------------|" << "\n\n";
						
						cin >> buyOption;

						switch(buyOption){
							case '1':
									continueLoop = buyConsumable(player, inventory, shopitems, shopitems.at(0));
									if (continueLoop) continue;
									break;
							case '2':
									continueLoop = buyConsumable(player, inventory, shopitems, shopitems.at(1));
									if (continueLoop) continue;
									break;
							case '3':
									voidedValidation(inventory, shopitems.at(2).name, alreadyPurchased);
									if (alreadyPurchased) continue;
									buyEquippable(player, inventory, shopitems, alreadyPurchased, shopitems.at(2));
									break;
							case '4':
									voidedValidation(inventory, shopitems.at(3).name, alreadyPurchased);
									if (alreadyPurchased) continue;
									buyEquippable(player, inventory, shopitems, alreadyPurchased, shopitems.at(3));
									break;
							case '5':
									voidedValidation(inventory, shopitems.at(4).name, alreadyPurchased);
									if (alreadyPurchased) continue;
									buyEquippable(player, inventory, shopitems, alreadyPurchased, shopitems.at(4));
									break;
							case 'x':
									break;
							default:
									break;
						}
					}
					buyOption = ' '; // reset buyOption from 'x' to ' ' to prevent perpetual loop break
					break;
			case '2':
					checkInventory(player, inventory, shopitems, eraseIndex);
					break;
			case 'x':
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
bool buyConsumable(Player &player, vector<Items> &inventory, vector<Items> &shopitems, Items &item){
	
	if (item.quantity >= item.maxQuantity){
		cout << "You can carry maximum " << item.maxQuantity << ' ' << item.name << 's' << '\n';
		return true;
	}
	if (player.balance >= item.price){
		player.balance -= item.price;
		item.quantity += 1;
		cout << '\n' << "You purchased one " << item.name << '\n';
		
		if (item.quantity > 1){
			return true;
		}
		inventory.push_back(item);
	}
	else{
		cout << '\n' << "You can't afford this!" << "\n\n";
	}
	return false;
}
void sellItems(Player &player, vector<Items> &inventory, vector<Items> &shopitems, Items &inventorySlot, int &eraseIndex){
	
	auto it = find_if(shopitems.begin(), shopitems.end(), // Since inventorySlot items aren't a reference but a copy of shopitems, I couldn't modify inventory items quantity by using inventorySlot.quantity
		[inventorySlot](const Items &item){				  // Therefore I made a lambda function that compares actual items to their respective copy and when values match it returns the correct value.
			return item.name == inventorySlot.name;		  // To access the correct value, I need to dereference the iterator and extract item's member from it
		}
	);
	
	if (inventorySlot.name == inventory.at(eraseIndex).name){
		if (!inventory.empty() && it->quantity <= 1){
				cout << "You sold " << inventory.at(eraseIndex).name << " for " << inventory.at(eraseIndex).sellPrice << " coins" << '\n';
				inventory.erase(inventory.begin() + eraseIndex);
				player.balance += inventorySlot.sellPrice;
		}
		else if (!inventory.empty() && it->quantity > 1){
			it->quantity--;
			cout << "You sold " << inventory.at(eraseIndex).name << " for " << inventory.at(eraseIndex).sellPrice << " coins" << '\n';
			player.balance += inventorySlot.sellPrice;
		}
	}
}