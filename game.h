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

	int lives;
	int health;
	int balance;
	
	int damage;
	
	int playerPosition;
};
struct Enemy{
	
	string name;
	
	int health; // used for health variation
	int maxhealth; // used as given enemy's max health
	
	int damage; // enemy's damage
	int fdamage; // damage when fleeing from an enemy
	int drop;
};
struct Items{
	
	string name;
	
	int price;
	int quantity;
	
	bool isEquipped;
	bool isConsumable;
};

void mainArea(Player &player, Enemy &caveRat, Enemy &overgrownSpider, vector<Items> &inventory, vector<Items> &shopitems, int &eraseIndex);
void choosePlayerName(Player &player);

void checkInventory(Player &player, vector<Items> &inventory, vector<Items> &shopitems, int &eraseIndex);
void inventoryInteraction(Player &player, vector<Items> &inventory, vector<Items> &shopitems, Items &inventorySlot, int &eraseIndex);

void shopArea(Player &player, vector<Items> &inventory, vector<Items> &shopitems);
void voidedValidation(vector<Items> &inventory, string &itemName, bool &alreadyPuchased);

void mainCaveArea(Player &player, Enemy &caveRat, Enemy &overgrownSpider, vector<Items> &inventory, vector<Items> &shopitems, int &eraseIndex);
void clayCaveArea(Player &player, Enemy &caveRat, Enemy &overgrownSpider, vector<Items> &inventory, vector<Items> &shopitems, int &eraseIndex);
void enemyFight(Player &player, Enemy &enemy, vector<Items> &inventory, vector<Items> &shopitems, int &eraseIndex, bool &breakLoop, bool &continueLoop);

void checkStats(Player &player, vector<Items> &inventory);

float roll(); // Random number function

#endif