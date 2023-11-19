#include <iostream>
#include<conio.h>
#include <string>
#include <cctype>

using namespace std;

string name, address, toppings_want, phone;
string size_pizza[6];
int toppings[10];
int amount_of_pizzas;
bool delivery;
string total_cost_pizza = "0";
double total_cost = 0;
int pizza_num = 1;
double total_cost_everything;


void total_cost_calc();
//ask for customer details and stores the infomation
void Customer_details() {
	cout << "What your name\n";
	getline(cin, name);
	cout << "\nWhats your address\n";
	getline(cin, address);
	cout << "\nWhat your phone number\n";
	cin >> phone;
	while (phone.size() > 11 or phone.size() < 10) {
		cout << "\nPhone Number to long or short ,try again\n";
		cin >> phone;
	 }
		
	
	
}
//get the details for the pizza and stores them
void pizza_details() {
	cout << "\nHow many pizzas do you want\n";
	cin >> amount_of_pizzas;
	if (amount_of_pizzas > 6 or amount_of_pizzas < 1) {
		cout << "You can only order max 6 pizzas\n";
		cin >> amount_of_pizzas;
	}
	int pizza_num = 1;
	for (int i = 0; i < amount_of_pizzas; i++) {
		cout << "\nWhat size do you what pizza " << pizza_num << "\n";
		string x = "";
		cin >> x;
		while (x != "small" && x != "median" && x != "large") {
			cout << "\nSmall ,Median and Large are the only options\n";
			cin >> x;
		}
		size_pizza[i] = x;
		pizza_num++;
		
	}
	cout << "\nDo you what topping on any of your pizzas yes or no\n";

	cin >> toppings_want;
	if (toppings_want == "yes") {
		pizza_num = 1;
		for (int i = 0; i < amount_of_pizzas; i++) {
			cout << "\nHow many toppings do you what on pizza " << pizza_num << "\n";
			int amount_of_toppings;
			cin >> amount_of_toppings;
			toppings[i] = amount_of_toppings;
			pizza_num++;
		}


	}

}

//see if the customer whats delivery 
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

//finds the costs of toppings and returns it for furcher use
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
//finds the cost of the pizza depending on the size and adds topping costs as well
void pizza_size_cost() {
	

	for (int i = 0; i < amount_of_pizzas; i++) {
		if (size_pizza[i] == "small") {
			cout << "\nPizza " << pizza_num << " costs " << char(156) << toppings_cost(i) + 3.25;
		}
		else if (size_pizza[i] == "median") {
			cout << "\nPizza " << pizza_num << " costs " << char(156) << toppings_cost(i) + 5.50;
		}
		else if (size_pizza[i] == "large") {
			cout << "\nPizza " << pizza_num << " costs " << char(156) << toppings_cost(i) + 7.15;
		}
		pizza_num++;
	}


}





//works out and displays the bill
void bill() {
	cout << "\nName: " << name << "\nAddress: " << address << "\nPhone Number: " << phone;
	pizza_size_cost();
	cout << "\nTotal cost: ";
	total_cost_calc();

}

void total_cost_calc() {
	for (int i = 0; i < amount_of_pizzas; i++) {
		if (size_pizza[i] == "small") {
			total_cost_everything = total_cost_everything + (toppings_cost(i) + 3.25);
		}
		else if (size_pizza[i] == "median") {
			total_cost_everything = total_cost_everything + (toppings_cost(i) + 5.50);
		}
		else if (size_pizza[i] == "large") {
			total_cost_everything = total_cost_everything + (toppings_cost(i) + 7.15);
		}
	}
	if (delivery == true) {
		total_cost_everything = total_cost_everything + 2.50;
	}
	
	if (total_cost_everything >= 20) {
		total_cost_everything = total_cost_everything * 0.9;
	}
	cout << char(156) << total_cost_everything;
}

//add the discount

//make phone number max lenght and min
//add inter check and letter check
//make it so which pizza does not say 0
//total cost


int main() {
	Customer_details();
	pizza_details();
	delivery_system();
	bill();
	_getch();
	return 0;
}
