#include "game.h"

void checkStats(Player &player, vector<Items> &inventory){
	
	cout << '\n' << "|-------------------------------------------|" << "\n\n";
	cout << player.name << "'s statistics" << "\n\n";
	
	cout << "Lives: " << "\t\t" << '{' << player.lives << '}' << "\n\n";
	
	cout << "Level: " << "\t\t" << '[' << player.level << '/' << player.maxLevel << ']' << '\n';
	cout << "Experience: " << '\t' << '[' << player.currentXP << '/' << player.lvlupXP << ']' << "\n\n";
	
	cout << "Health: " << '\t' << '[' << player.health << '/' << player.maxHealth << ']' << '\n';
	
	cout << "Coins: " << '\t' << '\t' << player.balance << '\n';
	cout << "Damage: " << '\t' << player.damage << '\n';
	cout << '\n' << "|-------------------------------------------|" << "\n\n";
	
	char option = ' ';
	
	while (option != 'x'){
		cout << '\n' << "[x] - Back to Main Area" << '\n';
		cin >> option;
	}
}
void levelingSystem(Player &player){
	if (player.level < 10){
		if (player.currentXP >= player.lvlupXP){
			player.currentXP = 0; // resets XP to 0 after lvlup (to be changed)
			
			player.balance += player.lvlupReward;
			player.level++;
			
			cout << "Congratulations you are now Level " << player.level << "\n\n";
			
			cout << "Rewards: " << "\n\n";
			
			cout << "- " << player.lvlupReward << " coins" << '\n';
			
			player.lvlupReward += 50; // When prises are given, augmenting them for next lvl
			player.lvlupXP += 25;
		}
	}
	else{
		if (player.currentXP > player.lvlupXP){
			player.currentXP = player.lvlupXP;
		}
	}
}
void upgradeMenu(Player &player, Upgrades &upgrDamage, Upgrades &upgrMaxHealth){
	
	cout << fixed << setprecision(1);
	
	bool continueLoop = false;
	char option = ' ';
	
	while (option != 'x'){
		continueLoop = false;
		
		cout << "\n\n";
		cout << "(----------------------------------------------------------)" << "\n\n";
		
		cout << "[1] Damage: " << "\t\t" << '{' << player.damage << '}' << '\t' << "[ +2.5 | +" << 2.5f*upgrDamage.currentUpgrade << " | " << upgrDamage.currentPrice << " | " << '(' << upgrDamage.currentUpgrade << '/' << upgrDamage.maxUpgrade << ") ]" << '\n';
		cout << "[2] Max health: " << '\t' << '{' << player.maxHealth << '}' << '\t' << "[ +5.0 | +" << 5.0*upgrMaxHealth.currentUpgrade << " | " << upgrMaxHealth.currentPrice << " | " << '(' << upgrMaxHealth.currentUpgrade << '/' << upgrMaxHealth.maxUpgrade << ") ]" << "\n\n";
		
		cout << "[x] Back to Main Menu" << "\n\n";
		
		cout << "(----------------------------------------------------------)" << '\n';
		
		cin >> option;
		
		switch(option){
			case '1':
					continueLoop = upgradeStat(player, upgrDamage, player.damage);
					if (continueLoop) continue;
					break;
			case '2':
					continueLoop = upgradeStat(player, upgrMaxHealth, player.maxHealth);
					if (continueLoop) continue;
					break;
			case 'x':
					break;
			default:
					break;
		}
	}
}
bool upgradeStat(Player &player, Upgrades &upgrade, int &playerStat){
	
	if (upgrade.currentUpgrade >= upgrade.maxUpgrade){
		cout << "Damage is fully upgraded" << '\n';
		return true;
	}
	if (player.balance >= upgrade.currentPrice){
		player.balance -= upgrade.currentPrice;
		
		upgrade.currentPrice += upgrade.initialPrice;
		upgrade.currentUpgrade++;
		playerStat += upgrade.upgradeValue;
		cout << "Damage upgraded from level " << upgrade.currentUpgrade-1 << " to " << upgrade.currentUpgrade << '\n';
	}
	else{
		cout << "Insufficient funds!" << '\n';
	}
	return false;
}
bool upgradeStat(Player &player, Upgrades &upgrade, float &playerStat){
	
	if (upgrade.currentUpgrade >= upgrade.maxUpgrade){
		cout << "Damage is fully upgraded" << '\n';
		return true;
	}
	if (player.balance >= upgrade.currentPrice){
		player.balance -= upgrade.currentPrice;
		
		upgrade.currentPrice += upgrade.initialPrice;
		upgrade.currentUpgrade++;
		playerStat += upgrade.upgradeValue;
		cout << "Damage upgraded from level " << upgrade.currentUpgrade-1 << " to " << upgrade.currentUpgrade << '\n';
	}
	else{
		cout << "Insufficient funds!" << '\n';
	}
	return false;
}