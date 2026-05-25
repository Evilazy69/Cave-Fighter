#include "game.h"

void checkStats(Player &player, vector<Items> &inventory){
	cout << '\n' << "|-------------------------------------------|" << "\n\n";
	cout << player.name << "'s statistics" << "\n\n";
	
	cout << "Lives: " << player.lives << '\n';
	cout << "Health: " << player.health << "\n\n";
	
	cout << "Gold: " << player.balance << '\n';
	cout << "Damage: " << player.damage << '\n';
	cout << '\n' << "|-------------------------------------------|" << "\n\n";
	
	char option = ' ';
	
	while (option != 'x'){
		cout << '\n' << "[x] - Back to Main Area" << '\n';
		cin >> option;
	}
}