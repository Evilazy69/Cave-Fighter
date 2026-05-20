#include "game.h"

void mainCaveArea(Player &player, vector<Items> &inventory, vector<Items> &shopitems, int eraseIndex){
	srand(time(NULL));
	char option;
	
	while (option != 'x'){
	
		cout << '\n' << "000ooo000o0o0o0ooo0ooo0oooo00000ooo000oooo000ooo0000ooo000" << "\n\n";
	
		cout << "[1] Enter Claystone Cave" << '\n';
		cout << "[2] Inventory" << '\n';
		
		cout << '\n' << "[x] Crawl back to the surface" << '\n';
	
		cout << '\n' << "000ooo000o0o0o0ooo0ooo0oooo00000ooo000oooo000ooo0000ooo000" << '\n';
		
		cin >> option;
		
		switch(option){
			case '1':
					cout << "***...Entering Claystone Cave...***" << '\n';
					clayCaveArea(player, inventory, shopitems, eraseIndex);
					break;
			case '2':
					checkInventory(player, inventory, shopitems, eraseIndex);
					break;
			default:
					break;
		}
	}
}
void clayCaveArea(Player &player, vector<Items> &inventory, vector<Items> &shopitems, int &eraseIndex){
	
	srand(time(NULL));
	
	player.playerPosition = 0;
	bool exitLoop = false;
	bool continueLoop = false;
	char option = ' ';
	
	while (true){
		int r = rand() % 100 + 1;
		
		cout << '\n' << "000ooo000o0o0o0ooo0ooo0oooo00000ooo000oooo000ooo0000ooo000" << "\n\n";
		
		if (player.playerPosition == 0){
			cout << "[1] Advance" << '\n';
			cout << "[2] Step back" << "\n\n";
			
			cout << "[3] Inventory" << '\n';
			cout << "[4] Map" << "\n\n";
			
			cout << "[x] Crawl back to the Navigation Cave" << '\n';
		}
		else if (player.playerPosition >= 1){
			cout << "[1] Advance" << '\n';
			cout << "[2] Step back" << "\n\n";
			
			cout << "[3] Inventory" << '\n';
			cout << "[4] Map" << "\n\n";
		}
		if (player.playerPosition >= 1 && r % 2 == 0){ // 5% chance
			int s = rand() % 100 + 1;
			char option = ' ';
			
			cout << "!!!!!!!!!!!!!!!!!!!!!" << "\n\n";
			
			cout << "You found a treasure chest!" << "\n\n";
			
			cout << "[1] Open chest" << '\n';
			cout << "[2] Dismiss" << "\n\n";
			
			cout << "!!!!!!!!!!!!!!!!!!!!!" << '\n';
			
			while (option != '2'){
				cin >> option;
			
				switch(option){
					case '1':
							if (s % 10 == 0){ // 10% chance
								int coins = 50;
								char option = ' ';
								
								cout << "--------------" << "\n\n";
								
								cout << "Chest content:" << "\n\n";
								
								cout << "- " << coins << " coins" << "\n\n";
								
								cout << "--------------" << '\n';
								
								cout << "[1] Take loot" << '\n';
								cout << "[2] Idgaf" << '\n';
								
								cin >> option;
								
								if (option == '1'){
									player.balance += coins;
									cout << "You claimed " << coins << " coins" << '\n';
								}
								else if (option == '2'){
									cout << "Coins are left here forever..." << '\n';
								}
							}
							else if(s % 4 == 0){ // 25% chance
								int coins = 100;
								char option = ' ';
								
								cout << "--------------" << "\n\n";
								
								cout << "Chest content:" << "\n\n";
								
								cout << "- " << coins << " coins" << "\n\n";
								
								cout << "--------------" << '\n';
								
								cout << "[1] Take loot" << '\n';
								cout << "[2] Idgaf" << '\n';
								
								cin >> option;
								
								if (option == '1'){
									player.balance += coins;
									cout << "You claimed  " << coins << " coins" << '\n';
								}
								else if (option == '2'){
									cout << "Coins are left here forever..." << '\n';
								}
							}
							else if(s % 10 == 0){ // 10% chance
								int coins = 250;
								char option = ' ';
								
								cout << "--------------" << "\n\n";
								
								cout << "Chest content:" << "\n\n";
								
								cout << "- " << coins << " coins" << "\n\n";
								
								cout << "--------------" << '\n';
								
								cout << "[1] Take loot" << '\n';
								cout << "[2] Idgaf" << '\n';
								
								cin >> option;
								
								if (option == '1'){
									player.balance += coins;
									cout << "You claimed  " << coins << " coins" << '\n';
								}
								else if (option == '2'){
									cout << "Coins are left here forever..." << '\n';
								}
							}
							else if(s % 20 == 0){ // 5% chance
								int coins = 500;
								char option = ' ';
								
								cout << "--------------" << "\n\n";
								
								cout << "Chest content:" << "\n\n";
								
								cout << "- " << coins << " coins" << "\n\n";
								
								cout << "--------------" << '\n';
								
								cout << "[1] Take loot" << '\n';
								cout << "[2] Idgaf" << '\n';
								
								cin >> option;
								
								if (option == '1'){
									player.balance += coins;
									cout << "You claimed  " << coins << " coins" << '\n';
								}
								else if (option == '2'){
									cout << "Coins are left here forever..." << '\n';
								}
							}
							else if(s % 50 == 0){ // 2% chance
								int coins = 1000;
								char option = ' ';
								
								cout << "--------------" << "\n\n";
								
								cout << "Chest content:" << "\n\n";
								
								cout << "- " << coins << " coins" << "\n\n";
								
								cout << "--------------" << '\n';
								
								cout << "[1] Take loot" << '\n';
								cout << "[2] Idgaf" << '\n';
								
								cin >> option;
								
								if (option == '1'){
									player.balance += coins;
									cout << "You claimed  " << coins << " coins" << '\n';
								}
								else if (option == '2'){
									cout << "Coins are left here forever..." << '\n';
								}
							}
							else if(s == 69){ // 1% chance
 
								int coins = 999999999;
								char option = ' ';
								
								cout << "--------------" << "\n\n";
								
								cout << "Chest content:" << "\n\n";
								
								cout << "- " << coins << " coins" << "\n\n";
								
								cout << "--------------" << '\n';
								
								cout << "[1] Take loot" << '\n';
								cout << "[2] Idgaf" << '\n';
								
								cin >> option;
								
								if (option == '1'){
									player.balance += coins;
									cout << "You claimed  " << coins << " coins" << '\n';
								}
								else if (option == '2'){
									cout << "Coins are left here forever..." << '\n';
								}
							}
							break;
					case '2':
							cout << ":(" << '\n';
							continueLoop = true;
							break;
					default:
							break;
				}
			}
			if (continueLoop){
				continue;
			}
		}
		cout << '\n' << "000ooo000o0o0o0ooo0ooo0oooo00000ooo000oooo000ooo0000ooo000" << "\n\n";
		
		cin >> option;
		
		switch(option){
			case '1':
					player.playerPosition += 1;
					break;
			case '2':
					player.playerPosition -= 1;
					break;
			case '3':
					checkInventory(player, inventory, shopitems, eraseIndex);
					break;
			case '4':
					cout << "----- { MAP } -----" << "\n\n";
					
					cout << "Location: Claystone Cave" << '\n';
					cout << "Position: " << player.playerPosition << "\n\n";
					
					cout << "-------------------" << '\n';
					break;
			case 'x':
					if (player.playerPosition == 0){
						exitLoop = true;
						break;
					}
					else{
						break;
					}
			default:
					break;
		}
		if (exitLoop){
			break;
		}
	}
}

// clayCaveArea coming soon...