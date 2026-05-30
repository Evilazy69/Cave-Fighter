#include "game.h"

void mainCaveArea(Player &player, Enemy &caveRat, Enemy &overgrownSpider, vector<Items> &inventory, vector<Items> &shopitems, int &eraseIndex){
	
	player.atLocation = "mainCaveArea"; // the location is set beyond while loop so it doesn't interfere when location changed to clayCaveArea which is inside mainCaveArea
	
	char option = ' ';
	
	while (option != 'x'){
		
		if (player.isAlive == false) break;
	
		cout << '\n' << "000ooo000o0o0o0ooo0ooo0oooo00000ooo000oooo000ooo0000ooo000" << "\n\n";
	
		cout << "[1] Enter Claystone Cave" << '\n';
		cout << "[2] Inventory" << '\n';
		
		cout << '\n' << "[x] Crawl back to the surface" << '\n';
	
		cout << '\n' << "000ooo000o0o0o0ooo0ooo0oooo00000ooo000oooo000ooo0000ooo000" << '\n';
		
		cin >> option;
		
		switch(option){
			case '1':
					cout << "***...Entering Claystone Cave...***" << '\n';
					clayCaveArea(player, caveRat, overgrownSpider, inventory, shopitems, eraseIndex);
					break;
			case '2':
					checkInventory(player, inventory, shopitems, eraseIndex);
					break;
			default:
					break;
		}
	}
}
void clayCaveArea(Player &player, Enemy &caveRat, Enemy &overgrownSpider, vector<Items> &inventory, vector<Items> &shopitems, int &eraseIndex){
	
	player.playerPosition = 0;
	int prevPosition = player.playerPosition;
	
	bool continueLoop = false;
	char option = ' ';
	
	while (option != 'x'){
	player.atLocation = "clayCaveArea";
		
		continueLoop = false;
		player.isVictorious = false;
		if (player.isAlive == false) break;
		
		float r = roll();
		
		
		if (player.playerPosition == 0){
			
			cout << '\n' << "000ooo000o0o0o0ooo0ooo0oooo00000ooo000oooo000ooo0000ooo000" << "\n\n";
			
			cout << "HP: " << '[' << player.health << '/' << player.maxHealth << ']' << '\n';
			cout << "XP: " << '[' << player.currentXP << '/' << player.lvlupXP << ']' << "\n\n";
			
			cout << "[1] Advance" << '\n';
			cout << "[2] Step back" << "\n\n";
			
			cout << "[3] Inventory" << '\n';
			cout << "[4] Map" << "\n\n";
			
			cout << "[i] About this location" << '\n';
			cout << "[x] Crawl back to the Navigation Cave" << '\n';
			
			cout << '\n' << "000ooo000o0o0o0ooo0ooo0oooo00000ooo000oooo000ooo0000ooo000" << '\n';
		}
		else if (player.playerPosition >= 5 && player.playerPosition > prevPosition && r < 0.20){ // 0.00 - 0.20 => 20% chance of stumble upon caveRat on moving forward
			
			enemyFight(player, caveRat, inventory, shopitems, eraseIndex, continueLoop);
			prevPosition = player.playerPosition; // when these values match, it will prevent successive stumbling upon enemies as fight ends
			if (continueLoop) continue;
		}
		else if (player.playerPosition >= 5 && player.playerPosition > prevPosition && r >= 0.20 && r < 0.30){ // 0.20 - 0.30 => 10% chance of finding chest on moving
			
			enemyFight(player, overgrownSpider, inventory, shopitems, eraseIndex, continueLoop);
			prevPosition = player.playerPosition;
			if (continueLoop) continue;
		}
		
		else if (player.playerPosition >= 1){
			
			cout << '\n' << "000ooo000o0o0o0ooo0ooo0oooo00000ooo000oooo000ooo0000ooo000" << "\n\n";
			
			cout << "HP: " << '[' << player.health << '/' << player.maxHealth << ']' << '\n';
			cout << "XP: " << '[' << player.currentXP << '/' << player.lvlupXP << ']' << '\n';
			cout << "LVL: " << player.level << "\n\n";
			
			cout << "[1] Advance" << '\n';
			cout << "[2] Step back" << "\n\n";
			
			cout << "[3] Inventory" << '\n';
			cout << "[4] Map" << "\n\n";
			
			cout << '\n' << "000ooo000o0o0o0ooo0ooo0oooo00000ooo000oooo000ooo0000ooo000" << '\n';
			
			if (player.playerPosition >= 10 && player.playerPosition > prevPosition && r < 0.35){ // 0.30 - 0.35 => 5% chance of finding chest on moving forward
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
									chestFound(player, caveRat, overgrownSpider, inventory, shopitems, eraseIndex, chestOption, 50);
								}
								else if(r < 0.82f){ // 0.57 to 0.82 = 25%
									chestFound(player, caveRat, overgrownSpider, inventory, shopitems, eraseIndex, chestOption, 100);
								}
								else if(r < 0.92f){ // 0.82 to 0.92 = 10%
									chestFound(player, caveRat, overgrownSpider, inventory, shopitems, eraseIndex, chestOption, 250);
								}
								else if(r < 0.97f){ // 0.92 to 0.97 = 5%
									chestFound(player, caveRat, overgrownSpider, inventory, shopitems, eraseIndex, chestOption, 500);
								}
								else if(r < 0.99f){ // 0.97 to 0.99 = 2%
									chestFound(player, caveRat, overgrownSpider, inventory, shopitems, eraseIndex, chestOption, 1000);
								}
								else if(r < 1.00f){ // 0.99 to 1.00 = 1%
									chestFound(player, caveRat, overgrownSpider, inventory, shopitems, eraseIndex, chestOption, 2500);
								}
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
					player.playerPosition++;
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
			case 'i':
					cout << "-------------------" << "\n\n";
					
					cout << "Encounterable enemies: " << "\n\n";
					
					cout << "- " << caveRat.name << " (Very light)" << '\n';
					cout << "- " << overgrownSpider.name << " (Light)" << "\n\n";
					
					cout << "-------------------" << '\n';
					break;
			case 'x':
					break;
			default:
					break;
		}
	}
}
void enemyFight(Player &player, Enemy &enemy, vector<Items> &inventory, vector<Items> &shopitems, int &eraseIndex, bool &continueLoop){
		
	enemy.health = enemy.maxhealth; // If an enemy was previously killed, this will reset its health to its maximum health
	char encounterOption = ' ';
	bool isFightActive = true;
	
	while (isFightActive){
		if (player.isAlive == false) break;
		
		cout << "!!!!!!!!!!!!!!!!!!!!!" << "\n\n";
		
		cout << "You encountered a " << enemy.name << "\n\n";
		
		cout << "Health: " << player.health << "\n\n";
		
		cout << "[1] Start fighting" << '\n';
		cout << "[2] Try to flee (lose " << enemy.fdamage << " hp)" << "\n\n";
		
		cout << "[3] Inventory" << "\n\n";
		
		cout << "!!!!!!!!!!!!!!!!!!!!!" << "\n\n";
		
		cin >> encounterOption;
		switch(encounterOption){
			case '1':
					while (enemy.health > 0){ // fighting loop
					
						playerStateValidation(player);
						if (player.isAlive == false){
							isFightActive = false;
							player.killedBy = enemy.name;
							playerDeath(player, continueLoop);
							break;
						}
						
						char fightOption = ' ';
						
						cout << enemy.name << " health (" << enemy.health << '/' << enemy.maxhealth << ')' << "\n\n";
						
						cout << "Health: " << '[' << player.health << '/' << player.maxHealth << ']' << '\n';
						
						cout << "[1] Attack" << '\n';
						cout << "[2] Inventory" << '\n';

						cin >> fightOption;
					
						switch(fightOption){
							case '1':
									enemy.health -= player.damage;
									cout << '\n' << "You dealt: " << player.damage << " damage" << '\n';
									
									if (enemy.health > 0){
										player.health -= enemy.damage;
										cout << "You received: " << enemy.damage << " damage" << "\n\n";
									}
									else{
										isFightActive = false;
										player.isVictorious = true;
									}
									break;
							case '2':
									checkInventory(player, inventory, shopitems, eraseIndex);
									break;
						}
					}
					
					if (player.isVictorious){
						
						player.balance += enemy.dropCoins;
						player.currentXP += enemy.dropXP;
						
						levelingSystem(player);
						
						cout << '\n';
						cout << ".........................." << "\n\n";
						
						cout << "You beat " << enemy.name << '!' << "\n\n";
						cout << "Looted: " << "\n\n";
						
						cout << "- " << enemy.dropCoins << " coins" << '\n';
						cout << "- " << enemy.dropXP << " XP" << '\n';
						
						cout << ".........................." << "\n\n";
						
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cin.get();
						
						continueLoop = true;
					}

					break; // break from while (enemy.health > 0) loop once the fight is done (won or lost)
			case '2':
					player.health -= enemy.fdamage;
					continueLoop = true; // After fleeing,  player goes back to the main loop instead of proceeding to main loop's movememnt switch
					return;
			case '3':
					checkInventory(player, inventory, shopitems, eraseIndex);
					break;
			default:
					break;
		}
	}
}
void chestFound(Player &player, Enemy &caveRat, Enemy &overgrownSpider, vector<Items> &inventory, vector<Items> &shopitems, int &eraseIndex, char &chestOption, int foundCoins){
	
	int coins = foundCoins;
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
void playerDeath(Player &player, bool &continueLoop){

	if (player.isAlive == false){
		if (player.lives <= 0){
			cout << "\n\n\n";
			
			
			cout << "Game Over :(" << '\n';
			
			
			cout << "\n\n\n";
			exit(0);
		}
		
		cout << "\n\n" << "/////////////////" << "\n\n";
		
		cout << "You died" << "\n\n";
		
		cout << "Death cause: Killed by " << player.killedBy << "\n\n";
		
		cout << player.lives-1 << " lives remain";
		
		cout << "\n\n" << "/////////////////" << "\n";
	
		continueLoop = true; // After win or loss, player goes back to the main loop instead of proceeding to main loop's movememnt switch
		
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.get();
	}
}
void playerStateValidation(Player &player){
	if (player.health < 0) player.health = 0;
	if (player.health == 0) player.isAlive = false;
}