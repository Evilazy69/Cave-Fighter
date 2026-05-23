#include "game.h"

void mainCaveArea(Player &player, Enemy &caveRat, vector<Items> &inventory, vector<Items> &shopitems, int eraseIndex){
	char option;
	
	while (option != 'x'){
		
		if (player.health <= 0){
			break;
		}
	
		cout << '\n' << "000ooo000o0o0o0ooo0ooo0oooo00000ooo000oooo000ooo0000ooo000" << "\n\n";
	
		cout << "[1] Enter Claystone Cave" << '\n';
		cout << "[2] Inventory" << '\n';
		
		cout << '\n' << "[x] Crawl back to the surface" << '\n';
	
		cout << '\n' << "000ooo000o0o0o0ooo0ooo0oooo00000ooo000oooo000ooo0000ooo000" << '\n';
		
		cin >> option;
		
		switch(option){
			case '1':
					cout << "***...Entering Claystone Cave...***" << '\n';
					clayCaveArea(player, caveRat, inventory, shopitems, eraseIndex);
					break;
			case '2':
					checkInventory(player, inventory, shopitems, eraseIndex);
					break;
			default:
					break;
		}
	}
}
void clayCaveArea(Player &player, Enemy &caveRat, vector<Items> &inventory, vector<Items> &shopitems, int &eraseIndex){
	
	player.playerPosition = 0;
	int prevPosition = player.playerPosition;
	
	bool continueLoop = false;
	bool breakLoop = false;
	char option = ' ';
	
	while (option != 'x'){

		if (player.health < 0){
			player.health = 0;
		}
		if (player.health == 0){
			cout << "/////////////////" << "\n\n";
			
			cout << "You died" << "\n\n";
			
			cout << "/////////////////" << "\n\n";
		
			cin.get();
			break;
		}
		
		continueLoop = false;
		breakLoop = false;
		float r = roll();
		
		
		if (player.playerPosition == 0){
			
			cout << '\n' << "000ooo000o0o0o0ooo0ooo0oooo00000ooo000oooo000ooo0000ooo000" << "\n\n";
			
			cout << "Health: " << player.health << "\n\n";
			
			cout << "[1] Advance" << '\n';
			cout << "[2] Step back" << "\n\n";
			
			cout << "[3] Inventory" << '\n';
			cout << "[4] Map" << "\n\n";
			
			cout << "[x] Crawl back to the Navigation Cave" << '\n';
			
			cout << '\n' << "000ooo000o0o0o0ooo0ooo0oooo00000ooo000oooo000ooo0000ooo000" << '\n';
		}
		else if (player.playerPosition >= 5 && player.playerPosition > prevPosition && r < 0.20){
			
			caveRat.health = 15;
			char encounterOption = ' ';
			while (encounterOption != '2'){
				
				cout << "!!!!!!!!!!!!!!!!!!!!!" << "\n\n";
				
				cout << "You encountered a " << caveRat.name << "\n\n";
				
				cout << "Health: " << player.health << "\n\n";
				
				cout << "[1] Start fighting" << '\n';
				cout << "[2] Try to flee (lose 20 health)" << "\n\n";
				
				cout << "[3] Inventory" << "\n\n";
				
				cout << "!!!!!!!!!!!!!!!!!!!!!" << "\n\n";
				
				cin >> encounterOption;
				switch(encounterOption){
					case '1':
							while (caveRat.health > 0){
								char fightOption = ' ';
								
								cout << caveRat.name << " health (" << caveRat.health << '/' << "15)" << "\n\n";
								
								cout << "Health: " << player.health << "\n\n";
								
								cout << "[1] Attack" << '\n';
								cout << "[2] Inventory" << '\n';

								cin >> fightOption;
							
								switch(fightOption){
									case '1':
											caveRat.health -= player.damage;
											cout << '\n' << "You dealt: " << player.damage << " damage" << '\n';
											
											player.health -= caveRat.damage;
											cout << "You received: " << caveRat.damage << " damage" << "\n\n";
											break;
									case '2':
											checkInventory(player, inventory, shopitems, eraseIndex);
											break;
								}
								
							}
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							player.balance += caveRat.drop;
							cout << "You beat " << caveRat.name << '\n';
							cout << "Looted: " << caveRat.drop << '\n';
							
							continueLoop = true; // After beating the rat, player goes back to the main loop instead of proceeding to main loop's movememnt switch
							breakLoop = true;
							
							encounterOption = '2'; // reassigning '2' to option so the outter loop will allow me to escape, since it's condition is while option != '2'
							break; // break from while (caveRat.health > 0) loop once the fight is done (won or lost)
					case '2':
							player.health -= 20;
							continueLoop = true; // After fleeing,  player goes back to the main loop instead of proceeding to main loop's movememnt switch
							breakLoop = true;
							break;
					case '3':
							checkInventory(player, inventory, shopitems, eraseIndex);
							break;
					default:
							break;
				}
				if (breakLoop) break;
			}
			if (continueLoop) continue;
		}
		else if (player.playerPosition >= 1){
			
			cout << '\n' << "000ooo000o0o0o0ooo0ooo0oooo00000ooo000oooo000ooo0000ooo000" << "\n\n";
			
			cout << "Health: " << player.health << "\n\n";
			
			cout << "[1] Advance" << '\n';
			cout << "[2] Step back" << "\n\n";
			
			cout << "[3] Inventory" << '\n';
			cout << "[4] Map" << "\n\n";
			
			cout << '\n' << "000ooo000o0o0o0ooo0ooo0oooo00000ooo000oooo000ooo0000ooo000" << '\n';
			
			if (player.playerPosition >= 10 && player.playerPosition > prevPosition && r < 0.30){ // 0.20 - 0.30 => 10% chance of finding chest on moving
				char chestOption = ' ';
			
			cout << "!!!!!!!!!!!!!!!!!!!!!" << "\n\n";
			
			cout << "You found a treasure chest!" << "\n\n";
			
			cout << "[1] Open chest" << '\n';
			cout << "[2] Dismiss" << "\n\n";
			
			cout << "!!!!!!!!!!!!!!!!!!!!!" << '\n';
				
				
				while (true){
					r = roll();
					cin >> chestOption;
				
					switch(chestOption){
						case '1':
								if (r < 0.57f){ // Cumulative thresholds -> 0.00 to 0.57 = 57% chance
									int coins = 50;
									chestOption = ' ';
									
									cout << "--------------" << "\n\n";
									
									cout << "Chest content:" << "\n\n";
									
									cout << "- " << coins << " coins" << "\n\n";
									
									cout << "--------------" << '\n';
									
									cout << "[1] Claim loot" << '\n';
									
									cin >> chestOption;
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									
									while(chestOption != '1'){
										cout << "Invalid input" << '\n';
										cin >> chestOption;
									}
									cout << "You claimed " << coins << " coins" << '\n';
									player.balance += coins;
								}
								else if(r < 0.82f){ // 0.57 to 0.82 = 25%
									int coins = 100;
									chestOption = ' ';
									
									cout << "--------------" << "\n\n";
									
									cout << "Chest content:" << "\n\n";
									
									cout << "- " << coins << " coins" << "\n\n";
									
									cout << "--------------" << '\n';
									
									cout << "[1] Take loot" << '\n';
									cout << "[2] Idgaf" << '\n';
									
									cin >> chestOption;
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									
									while(chestOption != '1'){
										cout << "Invalid input" << '\n';
										cin >> chestOption;
									}
									cout << "You claimed " << coins << " coins" << '\n';
									player.balance += coins;
								}
								else if(r < 0.92f){ // 0.82 to 0.92 = 10%
									int coins = 250;
									chestOption = ' ';
									
									cout << "--------------" << "\n\n";
									
									cout << "Chest content:" << "\n\n";
									
									cout << "- " << coins << " coins" << "\n\n";
									
									cout << "--------------" << '\n';
									
									cout << "[1] Take loot" << '\n';
									cout << "[2] Idgaf" << '\n';
									
									cin >> chestOption;
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									
									while(chestOption != '1'){
										cout << "Invalid input" << '\n';
										cin >> chestOption;
									}
									cout << "You claimed " << coins << " coins" << '\n';
									player.balance += coins;
								}
								else if(r < 0.97f){ // 0.92 to 0.97 = 5%
									int coins = 500;
									chestOption = ' ';
									
									cout << "--------------" << "\n\n";
									
									cout << "Chest content:" << "\n\n";
									
									cout << "- " << coins << " coins" << "\n\n";
									
									cout << "--------------" << '\n';
									
									cout << "[1] Take loot" << '\n';
									cout << "[2] Idgaf" << '\n';
									
									cin >> chestOption;
									cin.ignore(numeric_limits<streamsize>::max(), '\n');

									while(chestOption != '1'){
										cout << "Invalid input" << '\n';
										cin >> chestOption;
									}
									cout << "You claimed " << coins << " coins" << '\n';
									player.balance += coins;
								}
								else if(r < 0.99f){ // 0.97 to 0.99 = 2%
									int coins = 1000;
									chestOption = ' ';
									
									cout << "--------------" << "\n\n";
									
									cout << "Chest content:" << "\n\n";
									
									cout << "- " << coins << " coins" << "\n\n";
									
									cout << "--------------" << '\n';
									
									cout << "[1] Take loot" << '\n';
									cout << "[2] Idgaf" << '\n';
									
									cin >> chestOption;
									cin.ignore(numeric_limits<streamsize>::max(), '\n');

									while(chestOption != '1'){
										cout << "Invalid input" << '\n';
										cin >> chestOption;
									}
									cout << "You claimed " << coins << " coins" << '\n';
									player.balance += coins;
								}
								else if(r < 1.00f){ // 0.99 to 1.00 = 1%
	 
									int coins = 5000;
									chestOption = ' ';
									
									cout << "--------------" << "\n\n";
									
									cout << "Chest content:" << "\n\n";
									
									cout << "- " << coins << " coins" << "\n\n";
									
									cout << "--------------" << '\n';
									
									cout << "[1] Take loot" << '\n';
									cout << "[2] Idgaf" << '\n';
									
									cin >> chestOption;
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									
									while(chestOption != '1'){
										cout << "Invalid input" << '\n';
										cin >> chestOption;
									}
									cout << "You claimed " << coins << " coins" << '\n';
									player.balance += coins;
								}
								cout << "DEBUG: r: " << r << '\n';
								continueLoop = true;
								break;
						case '2':
								continueLoop = true;
								break;
						default:
								break;
					}
					break;
				}
			}
		}
		prevPosition = player.playerPosition; // prevPosition will take player.playerPosition values after each outer loop iteration (which means that prevPosition is always 1 step behind player.playerPosition)
		if (continueLoop) continue;
		
		cin >> option;
		
		switch(option){
			case '1':
					player.playerPosition += 1;
					break;
			case '2':
					if (player.playerPosition == 0){
						cout << "Unable to step back into position -1" << '\n';
						break;
					}
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
					break;
			default:
					break;
		}
	}
}

// clayCaveArea coming soon...