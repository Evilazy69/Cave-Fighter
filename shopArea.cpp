#include "game.h"

void shopArea(Player &player, vector<string> &itemlist, vector<string> &shopitems, vector<bool> &isEquipped){
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
						itemlist.push_back(shopitems.at(0));
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
						isEquipped.push_back(false);
						itemlist.push_back(shopitems.at(1));
						cout << '\n' << "You purchased a " << shopitems.at(1) << '\n';
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
						isEquipped.push_back(false);
						itemlist.push_back(shopitems.at(2));
						cout << '\n' << "You purchased a " << shopitems.at(2) << '\n';
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
						isEquipped.push_back(false);
						itemlist.push_back(shopitems.at(3));
						cout << '\n' << "You purchased a " << shopitems.at(3) << '\n';
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
void voidedValidation(vector<string> &itemlist, string &itemName, bool &alreadyPurchased){
	auto iterator = find(itemlist.begin(), itemlist.end(), string(itemName));

	if (iterator != itemlist.end()){										// l1 if iterator didn't make it to the end of itemlist
	cout << "You already purchased that item!" << '\n';						// l2 it means that an element of shopitems is already in itemlist
	alreadyPurchased = true;
	}
}