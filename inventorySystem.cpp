
// Inventory

/*

void checkInventory(Player &player, vector<string> &itemlist, vector<string> &shopitems, vector<bool> &isEquipped){
	char option;
	
	while (option != 'x'){
		cout << '\n' << "|-------------------------------------------|" << "\n\n";
		cout << player.name << "'s inventory" << "\n\n";
		
		if (itemlist.empty()){
			cout << "Inventory is empty :(" << '\n';
		}
		
		for (unsigned int i = 0; i < itemlist.size(); i++){
			cout << '[' << i+1 << "] " << itemlist.at(i) << '\n';
		}
		cout << '\n' << "|-------------------------------------------|" << "\n\n";

		cout << '\n' << "[x] - Close Inventory" << '\n';
		cin >> option;
		
		switch(option){
			case '1':
		}
	}
}

// Inventory Interaction 

void inventoryInteraction(Player &player, vector<string> &itemlist, vector<string> &shopitems, vector<bool> &isEquipped){
	
	if (itemlist.at(0) == shopitems.at(0)){
		if (!itemlist.empty()){
			itemlist.erase(itemlist.begin());
		}
		player.health += 25;
		cout << "You drank a health potion" << '\n';
	}
	else if (itemlist.at(0) == shopitems.at(1)){
		char option;
		
		while (option != 'x'){
			if (isEquipped.at(0) == false){
				cout << "- " << shopitems.at(1) << "\n\n";
				cout << "[1] Equip" << '\n';
				cout << "[x] Back" << '\n';
				
				cin >> option;
				
				switch(option){
					case '1':
							isEquipped.at(0) = true;
							player.damage += 15;
							break;
					case '2':
							break;
					default:
							break;
				}
			}
			else{
				cout << "- " << shopitems.at(1) << "\n\n";
				cout << "[1] Unquip" << '\n';
				cout << "[x] Back" << '\n';
				
				cin >> option;
				
				switch(option){
					case '1':
							isEquipped.at(0) = false;
							player.damage -= 15;
							break;
					case '2':
							break;
					default:
							break;
				}
			}
		}
	}
	else if (itemlist.at(0) == shopitems.at(2)){
		char option;
		
		while (option != 'x'){
			if (isEquipped.at(1) == false){
				cout << "- " << shopitems.at(2) << "\n\n";
				cout << "[1] Equip" << '\n';
				cout << "[x] Back" << '\n';
				
				cin >> option;
				
				switch(option){
					case '1':
							isEquipped.at(1) = true;
							player.damage += 15;
							break;
					case '2':
							break;
					default:
							break;
				}
			}
			else{
				cout << "- " << shopitems.at(2) << "\n\n";
				cout << "[1] Unquip" << '\n';
				cout << "[x] Back" << '\n';
				
				cin >> option;
				
				switch(option){
					case '1':
							isEquipped.at(1) = false;
							player.damage -= 15;
							break;
					case '2':
							break;
					default:
							break;
				}
			}
		}
	}
	else if (itemlist.at(0) == shopitems.at(3)){
		char option;
		
		while (option != 'x'){
			if (isEquipped.at(2) == false){
				cout << "- " << shopitems.at(3) << "\n\n";
				cout << "[1] Equip" << '\n';
				cout << "[x] Back" << '\n';
				
				cin >> option;
				
				switch(option){
					case '1':
							isEquipped.at(2) = true;
							player.damage += 15;
							break;
					case '2':
							break;
					default:
							break;
				}
			}
			else{
				cout << "- " << shopitems.at(3) << "\n\n";
				cout << "[1] Unquip" << '\n';
				cout << "[x] Back" << '\n';
				
				cin >> option;
				
				switch(option){
					case '1':
							isEquipped.at(0) = false;
							player.damage -= 15;
							break;
					case '2':
							break;
					default:
							break;
				}
			}
		}
	}
	else{
		cout << "You cannot equip something that doesn't exist :|" << '\n';
	}
	break;	
}

*/