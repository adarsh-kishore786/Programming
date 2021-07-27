/*
	card_game.cpp

	This program creates a card game
	of 52 cards.
*/

#include <iostream>
#include <array>
#include <algorithm>
#include <chrono>
#include <random>

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

constexpr int dealerLimit = 17;
constexpr int bustLimit = 21;

constexpr int aceVal1 = 1;
constexpr int aceVal2 = 11;

enum class Rank
{
	Rank_2,
	Rank_3,
	Rank_4,
	Rank_5,
	Rank_6,
	Rank_7,
	Rank_8,
	Rank_9,
	Rank_10,
	Rank_Jack,
	Rank_Queen,
	Rank_King,
	Rank_Ace,

	Max_Rank
};

enum class Suit
{
	Suit_Club,
	Suit_Diamond,
	Suit_Heart,
	Suit_Spade,

	Max_Suits 	
};

struct Card
{
	Rank rank {};
	Suit suit {};
};

using deck_type = std::array<Card, 52>;
using index_type = deck_type::size_type;

void printCard(const Card& card)
{
	switch(card.rank)
	{
		case Rank::Rank_2: std::cout << "2";
							break;

		case Rank::Rank_3: std::cout << "3";
							break;

		case Rank::Rank_4: std::cout << "4";
							break;

		case Rank::Rank_5: std::cout << "5";
							break;

		case Rank::Rank_6: std::cout << "6";
							break;

		case Rank::Rank_7: std::cout << "7";
							break;

		case Rank::Rank_8: std::cout << "8";
							break;

		case Rank::Rank_9: std::cout << "9";
							break;

		case Rank::Rank_10: std::cout << "T";
							 break;

		case Rank::Rank_Jack: std::cout << "J";
							   break;

		case Rank::Rank_Queen: std::cout << "Q";
								break;

		case Rank::Rank_King: std::cout << "K";
							   break;

		case Rank::Rank_Ace: std::cout << "A";
							 break; 
		default: std::cout << "?";
	}

	switch (card.suit)
	{
		case Suit::Suit_Spade: std::cout << "S";
							   break;

		case Suit::Suit_Diamond: std::cout << "D";
								 break;

		case Suit::Suit_Heart: std::cout << "H";
							   break;

		case Suit::Suit_Club: std::cout << "C";
							  break;
		default: std::cout << "?";
	}
	std::cout << "\n";
}

deck_type createDeck()
{
	deck_type deck {};

	index_type card = 0;
	for (int suit = 0; suit < static_cast<int>(Suit::Max_Suits); suit++)
		for (int rank = 0; rank < static_cast<int>(Rank::Max_Rank); rank++)
		{
			deck.at(card).rank = static_cast<Rank>(rank);
			deck.at(card).suit = static_cast<Suit>(suit);
			card++;
		}
	return deck;
}

void printDeck(deck_type& deck)
{
	for (const auto& card : deck)
	{
		printCard(card);
		std::cout << " ";
	}
	std::cout << "\n";
}

void shuffleDeck(deck_type& deck)
{
	std::shuffle(deck.begin(), deck.end(), std::default_random_engine(seed));
}

int getCardValue(Card& card)
{
	if (card.rank <= Rank::Rank_10)
		return (static_cast<int>(card.rank) + 2);

	switch (card.rank)
	{
		case Rank::Rank_10:
		case Rank::Rank_Jack:
		case Rank::Rank_Queen:
		case Rank::Rank_King: return 10;

		case Rank::Rank_Ace: return 11;
		default: return 0;
	}
}

void displayScores(const int& playerScore, const int& dealerScore)
{
	std::cout << "Player Score: " << playerScore << "\n";
	std::cout << "Dealer Score: " << dealerScore << "\n\n";
}

bool aceValWin(int& score, int& cardIndex, deck_type& deck)
{
	if (deck[cardIndex].rank == Rank::Rank_Ace)
	{
		score -= getCardValue(deck[cardIndex++]);
		if (score + aceVal1 <= bustLimit)
		{
			score += aceVal1;
			return true;
		}
		else
			return false;
	}
	return false;
}

bool playerLost(int& playerScore, int& cardIndex, deck_type& deck)
{
	char ch {};

	std::cout << "Would you like to hit or stand? \n"
				  << "1. H/h for hit\n"
				  << "2. S/s for stand\n";
	std::cin >> ch;

	if (ch == 'H' || ch == 'h')
	{
		std::cout << "\nThe card you got: ";
		printCard(deck[cardIndex]);
		playerScore += getCardValue(deck[cardIndex]);
		
		if (playerScore > bustLimit)
		{
			if (aceValWin(playerScore, cardIndex, deck))
				return false;
			else
				return true;
		}
	}
	return false;
}

bool dealerLost(int& dealerScore, int& cardIndex, deck_type& deck)
{
	std::cout << "Dealer's card: ";
	printCard(deck[cardIndex]);
	std::cout << "\n";
	
	dealerScore += getCardValue(deck[cardIndex]);

	if (dealerScore > bustLimit)
	{
		if (aceValWin(dealerScore, cardIndex, deck))
			return false;
		else
			return true;
	}
	return false;
}

bool playBlackjack(deck_type& deck)
{
	int cardIndex {0};
	int playerScore {getCardValue(deck[cardIndex++]) + getCardValue(deck[cardIndex++])};
	int dealerScore { getCardValue(deck[cardIndex++]) };

	while (dealerScore < dealerLimit && cardIndex < deck.size())
	{
		displayScores(playerScore, dealerScore);

		if (playerLost(playerScore, cardIndex, deck))
		{
			displayScores(playerScore, dealerScore);
			return false;
		}

		if (dealerLost(dealerScore, cardIndex, deck))
		{
			displayScores(playerScore, dealerScore);
			return true;
		}
	}

	if (playerScore > dealerScore)
	{
		displayScores(playerScore, dealerScore);
		return true;
	}

	displayScores(playerScore, dealerScore);
	return false;
}

int main()
{
	auto deck { createDeck() };
	
	shuffleDeck(deck);

	if (playBlackjack(deck))
		std::cout << "Congratulations! You won.\n";
	else
		std::cout << "Sorry, you lost.\n";
}