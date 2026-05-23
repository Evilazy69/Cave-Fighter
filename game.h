#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

struct Player{
	
	string name;

	int health;
	int balance;
	
	int damage;
	
	int playerPosition;
};
struct Enemy{
	
	string name;
	
	int health;
	int damage;
	int drop;
};
struct Items{
	
	string name;
	
	int price;
	int quantity;
	
	bool isEquipped;
	bool isConsumable;
};

void mainArea(Player &player, Enemy &caveRat, vector<Items> &inventory, vector<Items> &shopitems, int &eraseIndex);
void choosePlayerName(Player &player);

void checkInventory(Player &player, vector<Items> &inventory, vector<Items> &shopitems, int &eraseIndex);
void inventoryInteraction(Player &player, vector<Items> &inventory, vector<Items> &shopitems, Items &inventorySlot, int &eraseIndex);

void shopArea(Player &player, vector<Items> &inventory, vector<Items> &shopitems);
void voidedValidation(vector<Items> &inventory, string &itemName, bool &alreadyPuchased);

void mainCaveArea(Player &player, Enemy &caveRat, vector<Items> &inventory, vector<Items> &shopitems, int eraseIndex);
void clayCaveArea(Player &player, Enemy &caveRat, vector<Items> &inventory, vector<Items> &shopitems, int &eraseIndex); // coming soon

void checkStats(Player &player, vector<Items> &inventory);

float roll(); // Random number function

#endif