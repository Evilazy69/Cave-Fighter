#include "game.h"

void mainCaveArea(Player &player, vector<string> &itemlist, vector<string> &shopitems, vector<bool> &isEquipped, int eraseIndex){
	srand(time(NULL));
	char option;
	
	while (option != 'x'){
	
		cout << '\n' << "000ooo000o0o0o0ooo0ooo0oooo00000ooo000oooo000ooo0000ooo000" << '\n';
	
		cout << '\n' << "[1] Enter claystone cave" << '\n';
		cout << "[2] Inventory" << '\n';
		
		cout << '\n' << "[x] - Back to Main Area" << '\n';
	
		cout << '\n' << "000ooo000o0o0o0ooo0ooo0oooo00000ooo000oooo000ooo0000ooo000" << '\n';
		
		cin >> option;
		
		switch(option){
			case '1':
					break;
			case '2':
					checkInventory(player, itemlist, shopitems, isEquipped, eraseIndex);
					break;
			default:
					break;
		}
	}
}

// clayCaveArea coming soon...