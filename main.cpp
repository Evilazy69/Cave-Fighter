#include "game.h"  

mt19937 rng(random_device{}());

float roll(){
	uniform_real_distribution<float> dist(0.0f, 1.0f);
	return dist(rng);
}

int main(){
	
	Player player;
	player.lives = 3;
	player.health = 50;
	player.balance = 1000;
	player.maxHealth = 100;
	player.level = 1;
	player.currentXP = 0;
	player.lvlupXP = 100;
	player.lvlupReward = 100;
	player.damage = 10;
	player.playerPosition = 0;
	player.winCount = 0;
	player.lossCount = 0;
	player.isVictorious = false;
	player.isAlive = true;
	player.killedBy = " ";
	
	Enemy caveRat;
	caveRat.name = "Cave Rat";
	caveRat.health = 15;
	caveRat.maxhealth = 15;
	caveRat.damage = 10;
	caveRat.fdamage = 15;
	caveRat.dropCoins = 20;
	caveRat.dropXP = 5;
	
	Enemy overgrownSpider;
	overgrownSpider.name = "Overgrown Spider";
	overgrownSpider.health = 25;
	overgrownSpider.maxhealth = 25;
	overgrownSpider.damage = 15;
	overgrownSpider.fdamage = 25;
	overgrownSpider.dropCoins = 50;
	overgrownSpider.dropXP = 10;
	
	Items healthPotion;
	healthPotion.name = "Health Potion";
	healthPotion.price = 25;
	healthPotion.quantity = 0;
	healthPotion.isEquipped = false;
	healthPotion.type = CONSUMABLE;
	
	Items bowieKnife;
	bowieKnife.name = "Bowie Knife";
	bowieKnife.price = 100;
	bowieKnife.bonusdamage = 5;
	bowieKnife.isEquipped = false;
	bowieKnife.type = WEAPON;
	
	Items machete;
	machete.name = "Machete";
	machete.price = 250;
	machete.bonusdamage = 10;
	machete.isEquipped = false;
	machete.type = WEAPON;
	
	Items sword;
	sword.name = "Sword";
	sword.price = 500;
	sword.bonusdamage = 15;
	sword.isEquipped = false;
	sword.type = WEAPON;
	
	vector<Items> shopitems = {healthPotion, bowieKnife, machete, sword};
	vector<Items> inventory;
	
	int eraseIndex; // inventory.cpp
	

	char option = ' ';
	
	while(option != 'x'){	
		cout << '\n' << "....................................................." << "\n\n";
		cout << "Welcome to the Dungeon Fighter Game v0.21" << "\n\n";		

		cout << "~~~ Main menu ~~~" << "\n\n";

		cout << "[1] Play" << '\n';
		cout << "[2] Settings" << "\n\n";

		cout << "[x] Quit" << '\n';
			
		cout << '\n' << "....................................................." << "\n\n";
		
		cin >> option;
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
		
		switch(option){
			case '1':
					//if (!player.name.empty()){
					//	mainArea(player, caveRat, overgrownSpider, inventory, shopitems, eraseIndex);
					//	break;
					//}
					//choosePlayerName(player);
					mainArea(player, caveRat, overgrownSpider, inventory, shopitems, eraseIndex);
					break;
			case '2':
					break;
			default:
					break;
		}
	}
}
void mainArea(Player &player, Enemy &caveRat, Enemy &overgrownSpider, vector<Items> &inventory, vector<Items> &shopitems, int &eraseIndex){
	
	char option = ' ';
	
	while (option != 'x'){
		
		if (player.isAlive == false){
			player.lives--;
			player.health = 100;
			player.isAlive = true; // resurrection
		}
	
		cout << "..!..!!..!!!...!.!!.!!.!!!..!!!.!!!.!!!!.!!.!!.!!." << "\n\n";
		cout << "Health: " << '[' << player.health << '/' << player.maxHealth << ']' << '\n';
		cout << "XP: " << '[' << player.currentXP << '/' << player.lvlupXP << ']' << '\n';
		cout << "Level: " << player.level << "\n\n";
		
		cout << "Coins: " << player.balance << "\n\n";
		
		cout << "[1] Enter Shop" << '\n';
		cout << "[2] Enter Cave" << '\n';
		cout << "[3] Check Stats" << '\n';
		cout << "[4] Inventory" << "\n\n";
		
		cout << "[x] Main menu" << "\n\n";
		
		cout << "..!..!!..!!!...!.!!.!!.!!!..!!!.!!!.!!!!.!!.!!.!!." << '\n';
		
		cin >> option;
		
		switch(option){
			case '1':
					shopArea(player, inventory, shopitems);
					break;
			case '2':
					cout << '\n' << "***... Entering the underground world ...***" << '\n';
					mainCaveArea(player, caveRat, overgrownSpider, inventory, shopitems, eraseIndex);
					break;
			case '3':
					checkStats(player, inventory);
					break;
			case '4':
					checkInventory(player, inventory, shopitems, eraseIndex);
					break;
			default:
					break;
		}
	}
}
void choosePlayerName(Player &player){
	
	cout << '\n' << "~ Choose a name for your character ~" << "\n\n";

	string name;
	while (name.empty()){
		getline(cin, name);
		if (name.empty()){
			cout << "Empty name doesn't count!" << '\n';
		}
	}
	
	player.name = name;
	
	cout << '\n' << ".........................................." << "\n\n";
	
	cout << "Welcome to the Undefined World, " << player.name << '\n';
	cout << "Press enter to teleport to the main area" << '\n';
	
	cout << '\n' << ".........................................." << "\n\n";

	cin.get();
	
	cout << "Teleporting to the main area..." << "\n\n";
}