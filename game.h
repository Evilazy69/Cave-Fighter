#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Player{
	
	string name;

	int health;
	int balance;
	int damage;
};

void mainArea(Player &player, vector<string> &itemlist, vector<string> &shopitems, vector<bool> &isEquipped, int &eraseIndex);
void choosePlayerName(Player &player);

void checkInventory(Player &player, vector<string> &itemlist, vector<string> &shopitems, vector<bool> &isEquipped, int &eraseIndex);
void inventoryInteraction(Player &player, vector<string> &itemlist, vector<string> &shopitems, vector<bool> &isEquipped, string &inventorySlot, int &eraseIndex);

void shopArea(Player &player, vector<string> &itemlist, vector<string> &shopitems, vector<bool> &isEquipped);
void voidedValidation(vector<string> &itemlist, string &itemName, bool &alreadyPuchased);

void mainCaveArea(Player &player, vector<string> &itemlist, vector<string> &shopitems, vector<bool> &isEquipped, int eraseIndex);
void clayCaveArea(Player &player, vector<string> &itemlist, vector<string> &shopitems); // coming soon

void checkStats(Player &player, vector<string> &itemlist);

#endif