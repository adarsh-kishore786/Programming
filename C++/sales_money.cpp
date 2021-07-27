/*
	sales_money.cpp
*/

#include <iostream>

struct Advertisement
{
	int num_ads{};
	double percent_clicked{};
	double adv_money{};
};

Advertisement getDetails()
{
	std::cout << "Enter the total number of ads: ";
	int num_ads {};
	std::cin >> num_ads;

	std::cout << "Enter percent of ads clicked: ";
	double percent_clicked {};
	std::cin >> percent_clicked;

	std::cout << "Enter average money earned per advertisement: ";
	double adv_money {};
	std::cin >> adv_money;

	return {num_ads, percent_clicked, adv_money};
}

void printDetails(Advertisement a)
{
	std::cout << "Number of ads         : " << a.num_ads << std::endl;
	std::cout << "Percent of ads clicked: " << a.percent_clicked << "%\n";
	std::cout << "Average money earned  : " << a.adv_money << std::endl;

	double total = a.num_ads * a.percent_clicked * a.adv_money / 100;
	std::cout << "Total money earned    : " << total << std::endl; 
}

int main()
{
	Advertisement a { getDetails() };
	printDetails(a);
}