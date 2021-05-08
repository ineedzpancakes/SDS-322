#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::string;
using std::vector;
using std::swap;
using std::cout;
using std::endl;

class Card {
  private:
    string name;
    string suit;
    int value;
    int alt_value;
  public:
    Card() {}
    Card (string pName, string pSuit, int pValue, int pAlt_Value) {
      name = pName;
      suit = pSuit;
      value = pValue;
      alt_value = pAlt_Value;
    }

    // Prints the name, suit, value, and alt value of a card.
    void print_card() {
      cout << name << " of " << suit << ", " << value << ", " << alt_value << endl;
    }

    // Compares card values based on card values and alt values. 
    int compare(Card c2) {
      if (value > c2.value) {
        return 1;
      }
      else if (value < c2.value) {
        return -1;
      }
      else {
        if (alt_value > c2.alt_value) {
          return 1;
        }
        else if (alt_value < c2.alt_value) {
          return -1;
        }
        return 0;
      }
    }

    // Returns which suit a card is using an integer.
    int suitValue () {
      if (suit.compare("Clubs") == 0) {
        return 1;
      }
      else if (suit.compare("Spades") == 0) {
        return 2;
      }
      else if (suit.compare("Hearts") == 0) {
        return 3;
      }
      else if (suit.compare("Diamonds") == 0) {
        return 4;
      }
      else {
        return 0;
      }
    }
};

class Deck {
  private:
    vector<Card> private_deck;
  public:
    Deck (vector<Card> addDeck) {
      private_deck = addDeck;
    }

    // Prints all the cards in the deck. 
    void print_deck() {
      for (auto card: private_deck) {
        card.print_card();
      }
    }

    // Adds a new card into the deck.
    void addCard (Card newCard) {
      private_deck.push_back(newCard);
    }

    // Returns a Deck object with n cards taken from the current instace of Deck.
    // The current Deck will lose those n cards.
    Deck deal(int number_of_cards) {
      vector<Card> newDeck;
      for (int i = 0 ; i < number_of_cards ; i++) {
        newDeck.push_back(private_deck.back());
        private_deck.pop_back();
      }
      return newDeck;
    }

    // Gets the vector of the Deck.
    vector<Card> getVector() {
      return private_deck;
    }


    void shuffleDeck (Deck d2) {
      // Shuffle d2.
      int d2size = d2.getVector().size();
      for (int i = 0 ; i < d2size ; i++) {
        int j = i + rand() % (d2size - i);
        swap(d2.getVector()[i], d2.getVector()[j]);
      }

      // Shuffle current instance.
      for (int i = 0 ; i < private_deck.size() ; i++) {
        int j = i + rand() % (private_deck.size() - i);
        swap(private_deck[i], private_deck[j]);
      }

      // Push d2 back into current instance.
      for (int i = 0 ; i < d2size ; i++) {
        private_deck.push_back(d2.getVector()[i]);
      }

      // Shuffle combined deck.
      for (int i = 0 ; i < private_deck.size() ; i++) {
        int j = i + rand() % (private_deck.size() - i);
        swap(private_deck[i], private_deck[j]);
      }
    }

    // Sorts all cards using Bubble Sort.
    // Sorts by value and suit. 
    void sort() {
      int size = private_deck.size();
      for (int i = 0 ; i < size ; i++) {
        for (int j = 0 ; j < size - i - 1 ; j++) {
          // Sort by value.
          if (private_deck[j].compare(private_deck[j + 1]) == 1) {
            Card temp = private_deck[j];
            private_deck[j] = private_deck[j + 1];
            private_deck[j + 1] = temp;
          }
          // Sort by suit.
          if (private_deck[j].suitValue() > private_deck[j + 1].suitValue()) {
            Card temp = private_deck[j];
            private_deck[j] = private_deck[j + 1];
            private_deck[j + 1] = temp;
          }
        }
      }
    }
};

int main() {
  vector<Card> myDeck;

  vector<string> CardNames = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
  vector<string> CardSuits = {"Clubs", "Spades", "Hearts", "Diamonds"};

  for (int i = 0 ; i < 4 ; i++) { // Suits of Cards
    for (int j = 0 ; j < 13 ; j++) { // Names of Cards
      if (j == 0) { // Ace has an alt value of 11.
        Card myCard(CardNames[j], CardSuits[i], j + 1, 11);
        myDeck.push_back(myCard);
      }
      else if (j >= 10) { // Jack, Queen, and King wiil all have alt values of 10.
        Card myCard(CardNames[j], CardSuits[i], j + 1, 10);
        myDeck.push_back(myCard);
      }
      else if (j != 0 && !(j >= 10)) { // All other cards will have the same value and alt value.
        Card myCard(CardNames[j], CardSuits[i], j + 1, j + 1);
        myDeck.push_back(myCard);
      }
    }
  }
  

  Deck cardDeck = myDeck;
  cout << "============== CURRENT DECK ==============" << endl;
  cardDeck.print_deck(); // Use of print_deck()

  cout << endl;

  Deck dealed = cardDeck.deal(26); // Use of deal(int number_of_cards)
  cout << "=============  DEALED DECK  ==============" << endl;
  dealed.print_deck();

  cout << endl;

  cardDeck.shuffleDeck(dealed); // Use of deckShuffle(Deck d2)
  cout << "============== SHUFFLED DECK =============" << endl;
  cardDeck.print_deck();

  cout << endl;

  cardDeck.sort(); // Use of sort()
  cout << "==============  SORTED DECK  ==============" << endl;
  cardDeck.print_deck();
  
}
