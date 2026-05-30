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
#include <iomanip>

using namespace std;

struct Player {
	
	string name;
	string killedBy;
	string atLocation; // player localisation

	int lives; // after death lives--
	
	int level;
	int maxLevel;
	int currentXP;
	int lvlupXP;
	int lvlupReward; // coins for now...
	
	int health; // current health
	int maxHealth; // max health
	
	int balance;
	
	float damage;
	
	int playerPosition;
	
	int winCount;
	int lossCount;
	
	bool isVictorious;
	bool isAlive;
};
struct Upgrades {
	
	string name;
	
	int initialPrice;
	int currentPrice;
	
	float upgradeValue; // value of one upgrade step of whatever is affected by upgradeValue (Maxhealth, damage, etc.)
	int currentUpgrade;
	int maxUpgrade;
};
struct Enemy {
	
	string name;
	
	int health; // used for health variation
	int maxhealth; // used as given enemy's max health
	
	int damage; // enemy's damage
	int fdamage; // damage when fleeing from an enemy
	int dropCoins;
	int dropXP;
};

enum itemTypes {
	
	CONSUMABLE,
	WEAPON
};
struct Items {
	
	string name;
	
	int price;
	int sellPrice;
	
	int quantity;
	int maxQuantity;
	
	int bonusdamage;
	
	bool isEquipped;
	
	itemTypes type;
};

// main

void mainArea(Player &player, Enemy &caveRat, Enemy &overgrownSpider, vector<Items> &inventory, vector<Items> &shopitems, int &eraseIndex, Upgrades &upgrDamage, Upgrades &upgrMaxHealth);
void choosePlayerName(Player &player);

// inventory

void checkInventory(Player &player, vector<Items> &inventory, vector<Items> &shopitems, int &eraseIndex);
void inventoryInteraction(Player &player, vector<Items> &inventory, vector<Items> &shopitems, Items &inventorySlot, int &eraseIndex);
void itemEquipment(Player &player, vector<Items> &inventory, vector<Items> &shopitems, Items &inventorySlot, int &eraseIndex);
void itemConsumption(Player &player, vector<Items> &inventory, vector<Items> &shopitems, Items &inventorySlot, int &eraseIndex);

// shop

void shopArea(Player &player, vector<Items> &inventory, vector<Items> &shopitems, int &eraseIndex);
void voidedValidation(vector<Items> &inventory, string &itemName, bool &alreadyPuchased);
void buyEquippable(Player &player, vector<Items> &inventory, vector<Items> &shopitems, bool &alreadyPurchased, Items &item);
bool buyConsumable(Player &player, vector<Items> &inventory, vector<Items> &shopitems, Items &item);
void sellItems(Player &player, vector<Items> &inventory, vector<Items> &shopitems, Items &inventorySlot, int &eraseIndex);

// gameplay

void mainCaveArea(Player &player, Enemy &caveRat, Enemy &overgrownSpider, vector<Items> &inventory, vector<Items> &shopitems, int &eraseIndex);
void clayCaveArea(Player &player, Enemy &caveRat, Enemy &overgrownSpider, vector<Items> &inventory, vector<Items> &shopitems, int &eraseIndex);
void enemyFight(Player &player, Enemy &enemy, vector<Items> &inventory, vector<Items> &shopitems, int &eraseIndex, bool &continueLoop);
void chestFound(Player &player, Enemy &caveRat, Enemy &overgrownSpider, vector<Items> &inventory, vector<Items> &shopitems, int &eraseIndex, char &chestOption, int foundCoins);
void playerDeath(Player &player, bool &continueLoop);
void playerStateValidation(Player &player);

// stats

void checkStats(Player &player, vector<Items> &inventory);
void levelingSystem(Player &player);
void upgradeMenu(Player &player, Upgrades &upgrDamage, Upgrades &upgrMaxHealth);
bool upgradeStat(Player &player, Upgrades &upgrade, int &playerStat);  // overloaded functions for int and float cases
bool upgradeStat(Player &player, Upgrades &upgrade, float &playerStat);


float roll(); // Random number function

#endif