#include "game.h"

void checkStats(Player &player, vector<Items> &inventory){
	
	cout << '\n' << "|-------------------------------------------|" << "\n\n";
	cout << player.name << "'s statistics" << "\n\n";
	
	cout << "Lives: " << '\t' << player.lives << "\n\n";
	
	cout << "Level: " << '\t' << player.level << '\n';
	cout << "Experience: " << '\t' << '[' << player.currentXP << " / " << player.lvlupXP << ']' << "\n\n";
	
	cout << "Health: " << '[' << player.health << '/' << player.maxHealth << ']' << '\n';
	
	cout << "Coins: " << '\t' << player.balance << '\n';
	cout << "Damage: " << player.damage << '\n';
	cout << '\n' << "|-------------------------------------------|" << "\n\n";
	
	char option = ' ';
	
	while (option != 'x'){
		cout << '\n' << "[x] - Back to Main Area" << '\n';
		cin >> option;
	}
}
void levelingSystem(Player &player){
	if (player.currentXP >= player.lvlupXP){
		player.currentXP = 0; // resets XP to 0 after lvlup (to be changed)
		
		player.maxHealth += 5;
		player.balance += player.lvlupReward;
		
		cout << "Congratulations you are now Level " << player.level << "\n\n";
		
		cout << "Rewards: " << "\n\n";
		
		cout << "- " << player.lvlupReward << " coins" << '\n';
		cout << "- " << "+5 to maximum health" << '\n';
		
		player.lvlupReward += 25; // When prises are given, augmenting them for next lvl
		player.lvlupXP += 25;
	}
}