#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include <cstdlib>
#include <random>
#include <cctype>

using namespace std;

struct Player{
	
	string name;
	string killedBy;

	int lives; // after death lives--
	
	int level;
	int currentXP;
	int lvlupXP;
	int lvlupReward; // coins for now...
	
	int health; // current health
	int maxHealth; // max health
	
	int balance;
	
	int damage;
	
	int playerPosition;
	
	int winCount;
	int lossCount;
	
	bool isVictorious;
	bool isAlive;
};
struct Enemy{
	
	string name;
	
	int health; // used for health variation
	int maxhealth; // used as given enemy's max health
	
	int damage; // enemy's damage
	int fdamage; // damage when fleeing from an enemy
	int dropCoins;
	int dropXP;
};

enum itemTypes{
	
	CONSUMABLE,
	WEAPON
};
struct Items{
	
	string name;
	
	int price;
	int quantity;
	int bonusdamage;
	
	bool isEquipped;
	
	itemTypes type;
};

void mainArea(Player &player, Enemy &caveRat, Enemy &overgrownSpider, vector<Items> &inventory, vector<Items> &shopitems, int &eraseIndex);
void choosePlayerName(Player &player);

void checkInventory(Player &player, vector<Items> &inventory, vector<Items> &shopitems, int &eraseIndex);
void inventoryInteraction(Player &player, vector<Items> &inventory, vector<Items> &shopitems, Items &inventorySlot, int &eraseIndex);
void itemEquipment(Player &player, vector<Items> &inventory, vector<Items> &shopitems, Items &inventorySlot, int &eraseIndex);
void itemConsumption(Player &player, vector<Items> &inventory, vector<Items> &shopitems, Items &inventorySlot, int &eraseIndex);

void shopArea(Player &player, vector<Items> &inventory, vector<Items> &shopitems);
void voidedValidation(vector<Items> &inventory, string &itemName, bool &alreadyPuchased);
void buyEquippable(Player &player, vector<Items> &inventory, vector<Items> &shopitems, bool &alreadyPurchased, Items &item);

void mainCaveArea(Player &player, Enemy &caveRat, Enemy &overgrownSpider, vector<Items> &inventory, vector<Items> &shopitems, int &eraseIndex);
void clayCaveArea(Player &player, Enemy &caveRat, Enemy &overgrownSpider, vector<Items> &inventory, vector<Items> &shopitems, int &eraseIndex);
void enemyFight(Player &player, Enemy &enemy, vector<Items> &inventory, vector<Items> &shopitems, int &eraseIndex, bool &continueLoop);
void chestFound(Player &player, Enemy &caveRat, Enemy &overgrownSpider, vector<Items> &inventory, vector<Items> &shopitems, int &eraseIndex, char &chestOption, int foundCoins);
void playerDeath(Player &player, bool &continueLoop);
void playerStateValidation(Player &player);

void checkStats(Player &player, vector<Items> &inventory);
void levelingSystem(Player &player);

float roll(); // Random number function

#endif