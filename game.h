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

void choosePlayerName(Player &player);
void mainArea(Player &player, vector<string> &itemlist, vector<string> &shopitems, vector<bool> &isEquipped);
void checkStats(Player &player, vector<string> &itemlist);
void checkInventory(Player &player, vector<string> &itemlist, vector<string> &shopitems, vector<bool> &isEquipped);
void shopArea(Player &player, vector<string> &itemlist, vector<string> &shopitems);
void voidedValidation(vector<string> &itemlist, string &itemName, bool &alreadyPuchased);
void mainCaveArea(Player &player, vector<string> &itemlist, vector<string> &shopitems, vector<bool> &isEquipped);
void clayCaveArea(Player &player, vector<string> &itemlist, vector<string> &shopitems); // coming soon

#endif