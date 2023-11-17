#include <iostream>
#include<conio.h>
#include <string>

using namespace std;

string name, address, toppings_want;
string size_pizza[6];
int toppings[10];
int phone, amount_of_pizzas;
bool delivery;
string total_cost_pizza = "0";
double total_cost = 0;



void Customer_details() {
	cout << "What your name\n";
	getline(cin, name);
	cout << "\nWhats your address\n";
	getline(cin, address);
	cout << "\nWhat your phone number\n";
	cin >> phone;
}

void pizza_details() {
	cout << "\nHow many pizzas do you want\n";
	cin >> amount_of_pizzas;
	if (amount_of_pizzas > 6 or amount_of_pizzas < 1) {
		cout << "You can only order max 6 pizzas\n";
		cin >> amount_of_pizzas;
	}
	for (int i = 0; i < amount_of_pizzas; i++) {
		cout << "\nWhat size do you what pizza " << i << "\n";
		string x = "";
		cin >> x;
		size_pizza[i] = x;
	}
	cout << "\nDo you what topping on any of your pizzas yes or no\n";

	cin >> toppings_want;
	if (toppings_want == "yes") {
		for (int i = 0; i < amount_of_pizzas; i++) {
			cout << "\nHow many toppings do you what on pizza \n" << i;
			int amount_of_toppings;
			cin >> amount_of_toppings;
			toppings[i] = amount_of_toppings;
		}


	}

}


void delivery_system() {
	cout << "\ndo you what delivery yes or no\n";
	string delivery_want;
	cin >> delivery_want;
	if (delivery_want == "yes") {
		delivery = true;
	}
	else {
		delivery = false;
	}

}


double toppings_cost(int i) {
	if (toppings[i] == 1) {
		return 0.75;
	}
	else if (toppings[i] == 2) {
		return 1.35;
	}
	else if (toppings[i] == 3) {
		return 2.00;
	}
	else if (toppings[i] >= 4) {
		return 2.50;
	}
	else {
		return 0.00;
	}
}

void pizza_size_cost() {

	for (int i = 0; i < amount_of_pizzas; i++) {
		if (size_pizza[i] == "small") {
			cout << "\nPizza " << i << " costs " << char(156) << toppings_cost(i) + 3.25;
		}
		else if (size_pizza[i] == "median") {
			cout << "\nPizza " << i << " costs " << char(156) << toppings_cost(i) + 5.50;
		}
		else if (size_pizza[i] == "large") {
			cout << "\nPizza " << i << " costs " << char(156) << toppings_cost(i) + 7.15;
		}
	}


}

void total_cost_of_pizza() {
	for (int i = 0; i < amount_of_pizzas; i++) {
		if (size_pizza[i] == "small") {
			total_cost = total_cost + (toppings_cost(i) + 3.25);
		}
		else if (size_pizza[i] == "median") {
			total_cost = total_cost + (toppings_cost(i) + 5.50);
		}
		else if (size_pizza[i] == "large") {
			total_cost = total_cost + (toppings_cost(i) + 7.15);
		}
	}



}




void bill() {
	cout << "\nName: " << name << "\nAddress: " << address << "\nPhone Number: " << phone;
	pizza_size_cost();
	cout << "Total cost: " << char(156) << total_cost;






}





int main() {
	Customer_details();
	pizza_details();
	delivery_system();
	bill();
	return 0;
}