//Andrew Willis
//11/6/2022
//Dr Lehr, CIS17A
//Midterm Project: Blackjack
//Purpose: To accurate play and report results after a game of blackjack
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <time.h>
#include <iomanip>
#include "Hand.h"
#include "Card.h"
#include "Bank.h"
#include "PlayerBank.h"
using namespace std;

enum menuChoice 
{
    play = 0,
    score = 1,
    leave = 2
};
template <typename T> T myMax(T x, T y)
 {
    return (x > y) ? x : y;
 }
struct playerScore 
{
    char firstI;
    char secondI;
    char thirdI;
    int score;
};
Card* fillDynamicDeck(Card*, int);
void printDeck(Hand);
Hand drawCard(Hand, Hand, int);
Hand resizeAfterDraw(Hand, int);
int randomizeCardIndex(int);
void destroy(Card*);
Hand removeCards(Hand);
int stringToInt(string);
int mainGame(int, Deck);
int adjustForAces(Hand);
void wrtTxt(fstream&, playerScore*);
void wrtBin(fstream&, playerScore*);
playerScore* readBin(fstream&, int);
void prntTxt(playerScore*);

int main(int argc, char** argv) {
    srand(time(NULL));
    playerScore* newPlayer; //player score struct to be handled by the files
    string writtenChoice; //User inputted choice
    int comparedChoice = -1; //choice to compare again enums
    string textFileName = "Results.txt"; //file name for outputting results
    string binFileName = "Results.bin";
    fstream textFile; //file to output results
    fstream binFile;
    menuChoice playerChoice;
    char initials[4];
    ifstream deckOfCards;
    const int totalCards = 52;
    string deckFile = "DeckOfCards.txt";
    Card    AceOfHearts, AceOfSpades, AceOfClubs, AceOfDiamonds,
            TwoOfHearts, TwoOfSpades, TwoOfClubs, TwoOfDiamonds,
            ThreeOfHearts, ThreeOfSpades, ThreeOfClubes, ThreeOfDiamonds,
            FourOfHearts, FourOfSpades, FourOfClubs, FourOfDiamonds,
            FiveOfHearts, FiveOfSpades, FiveOfClubs, FiveOfDiamonds,
            SixOfHearts, SixOfSpades, SixOfClubs, SixOfDiamonds,
            SevenOfHearts, SevenOfSpades, SevenOfClubs, SevenOfDiamonds,
            EightOfHearts, EightOfSpades, EightOfClubs, EightOfDiamonds,
            NineOfHearts, NineOfSpades, NineOfClubs, NineOfDiamonds,
            TenOfHearts, TenOfSpades, TenOfClubs, TenOfDiamonds,
            JackOfHearts, JackOfSpades, JackOfClubs, JackOfDiamonds,
            QueenOfHearts, QueenOfSpades, QueenOfClubs, QueenOfDiamonds,
            KingOfHearts, KingOfSpades, KingOfClubs, KingOfDiamonds;
    Card fullDeck[totalCards] = {AceOfHearts, AceOfSpades, AceOfClubs, AceOfDiamonds, TwoOfHearts, TwoOfSpades, TwoOfClubs, TwoOfDiamonds, ThreeOfHearts, ThreeOfSpades, ThreeOfClubes, ThreeOfDiamonds, FourOfHearts, FourOfSpades, FourOfClubs, FourOfDiamonds, FiveOfHearts, FiveOfSpades, FiveOfClubs, FiveOfDiamonds, SixOfHearts, SixOfSpades, SixOfClubs, SixOfDiamonds, SevenOfHearts, SevenOfSpades, SevenOfClubs, SevenOfDiamonds, EightOfHearts, EightOfSpades, EightOfClubs, EightOfDiamonds, NineOfHearts, NineOfSpades, NineOfClubs, NineOfDiamonds, TenOfHearts, TenOfSpades, TenOfClubs, TenOfDiamonds,
        JackOfHearts, JackOfSpades, JackOfClubs, JackOfDiamonds, QueenOfHearts, QueenOfSpades, QueenOfClubs, QueenOfDiamonds, KingOfHearts, KingOfSpades, KingOfClubs, KingOfDiamonds};
    //Declare Deck Object
    Deck deck("Full Deck");
    deckOfCards.open(deckFile, ios::in);
    //Fills up the card structs from a file
    if (deckOfCards.is_open()) {
        string fileLine;
        int newValue;
        for (int i = 0; i < totalCards; i++) {
            int counter = 0;
            while (getline(deckOfCards, fileLine) && counter < 3) {
                if (counter == 0) {
                    fullDeck[i].setName(fileLine);
                    counter += 1;
                } else
                    if (counter == 1) {
                    newValue = stringToInt(fileLine);
                    fullDeck[i].setValue(newValue);
                    counter += 1;
                } else
                    if (counter == 2) {
                    fullDeck[i].setSuit(fileLine);
                    counter += 1;
                } else
                    if (counter >= 3) {
                    break;
                }
            }
        }
        deckOfCards.close();
    }
    deck.setCardsInHand(fillDynamicDeck(fullDeck,totalCards));
    cout << "Please enter your three initials." << endl;
    cin >> initials;
    while (strlen(initials) != 3) {
        cout << "Please enter your three initials." << endl;
        cin >> initials;
    }
    cout << "Welcome to Andrew's Blackjack!  Here are the table rules: " << endl;
    cout << "1.  Splitting is allowed.\n2.  Insurance and Doubling Down are not available at this time.\n3.  Aces are both high and low and adjust as needed automatically.\n" << endl;
    cin.ignore();

    do //Checks for input from the menu
    {
        cout << "Would you like to 'play',search for a player's 'score' by index, or 'leave' the game?" << endl;
        comparedChoice = -1;
        cin >> writtenChoice;
        if (writtenChoice == "play") {
            comparedChoice = 0;
        } else if (writtenChoice == "score") {
            comparedChoice = 1;
        } else if (writtenChoice == "leave") {
            comparedChoice = 2;
        } else {
            comparedChoice = -1;
        }
        if (comparedChoice == play) //Set up the game to hold results and run properly,
        {
            newPlayer = new playerScore;
            textFile.open(textFileName, ios::out | ios::app); //Opens the text file for editing
            newPlayer->firstI = initials[0];
            newPlayer->secondI = initials[1];
            newPlayer->thirdI = initials[2];
            newPlayer->score = mainGame(totalCards, deck); //plays the game and saves the final money amount
            cout << "Thanks for playing!  Check the " << textFileName << " file for your history!  You ended the game with: $" << newPlayer->score << " left!" << endl;
            binFile.open(binFileName, ios::out | ios::app | ios::binary); //Opens the bin file for editing
            wrtTxt(textFile, newPlayer); //Writes record to a text file
            wrtBin(binFile, newPlayer); //Writes record to a bin file
            binFile.close();
            textFile.close();
            delete newPlayer;
            comparedChoice = -1;
        } else if (comparedChoice == score) //Search a file asked for initials input by the user
        {
            binFile.open(binFileName, ios::in | ios::app | ios::binary);
            int entryNum;
            cout << "Which entry would you like to look at?  Please enter an integer value." << endl;
            cin >> entryNum;
            playerScore* test = readBin(binFile, entryNum); //Reads in a bin file and number and retrieves that record
            prntTxt(test);
            binFile.close();
            delete test;
            comparedChoice = -1;
        } else if (comparedChoice == leave) //Player stops playing and the files are closed
        {
            cout << "Thanks for playing!" << endl;
        } else //Default
        {
            cout << "Please choose to either play, score, or leave!" << endl;
        }
    } while (comparedChoice == -1); //Sentinel

    return 0;

}

int stringToInt(string x) {
    //Changes chars to ints in order to be operated on.  Used for the values of cards read from a file.
    int returnInt = 0;
    if (x.length() - 1 == 2) {
        returnInt += (x[0] - '0') * 10;
        returnInt += (x[1] - '0');
    } else if (x.length() - 1 == 1) {
        returnInt += (x[0] - '0');
    }
    return returnInt;
}

Hand removeCards(Hand x) {
    Hand emptyHand; //New hand class
    emptyHand.setName(x.getName()); //Copies name
    emptyHand.setSize(0); //Sets size
    return emptyHand;
}

void destroy(Card* x) {
    //cleans up data
    delete[]x;
}

Hand resizeAfterDraw(Hand x, int y) {
    Hand newHand; //New class to adjust and return
    newHand.setName(x.getName()); //Copies the name of the one to copy
    Card* newCardsInHand = new Card[x.getSize() - 1]; //Sets the size to one less than the copied
    newHand.setCardsInHand(newCardsInHand); //Points
    newHand.setSize(x.getSize() - 1); //Adjusts the size var properly
    for (int i = 0; i < newHand.getSize() + 1; i++) {
        if (i < y) //Fills values before the index taken from normally
        {
            newHand.getCardsInHand()[i] = x.getCardsInHand()[i];
        } else if (i > y) //Any values after the index taken from are put one space behind their original to fill the gap
        {
            newHand.getCardsInHand()[i - 1] = x.getCardsInHand()[i];
        }
    }
    return newHand;
}

Card* fillDynamicDeck(Card* x, int y) {
    //Fills the dynamic array for the cards to be drawn from.
    Card* array = new Card[y];
    for (int i = 0; i < y; i++) {
        array[i] = x[i];
    }
    return array;
}

void printDeck(Hand x) {
    //Outputs info about a hand while adjusting for aces
    int total = 0;
    cout << "Cards in the " << x.getName() << ": " << endl;
    for (int i = 0; i < x.getSize(); i++) {
        cout << x.getCardsInHand()[i].getName() << endl;
        total += x.getCardsInHand()[i].getValue();
    }
    total = adjustForAces(x);
    cout << "Total of the " << x.getName() << " is: " << total << endl;
}

Hand drawCard(Hand from, Hand to, int index) {
    Hand toNew; //Creates a new hand to fill values from
    toNew.setName(to.getName()); //Copies the name
    Card* newCardsInHand = new Card[to.getSize() + 1]; //Sets the size to one more than the desired hand adjusted
    toNew.setCardsInHand(newCardsInHand); //Points to the new array
    if (to.getSize() == 0) //Fills up the initial index with the value if it was empty prior
    {
        toNew.getCardsInHand()[0] = from.getCardsInHand()[index];
    } else //Fills up the values of the new array with the old hands'
    {
        for (int i = 0; i < to.getSize(); i++) {
            toNew.getCardsInHand()[i] = to.getCardsInHand()[i];
        }
        toNew.getCardsInHand()[to.getSize()] = from.getCardsInHand()[index]; //Adds the drawn card's values to the end of the new struct's array
    }
    toNew.setSize(to.getSize()+1);
    return toNew;
}

int randomizeCardIndex(int x) {
    return rand() % x; //Chooses a random value for the deck to pull
}

int mainGame(int totalCards, Deck fullDeck) {
    //
    
    
    //CHANGE CURRENT TOTAL, DEAELER TOTAL TO BANK/PLAYER BANK OBJECTS!!!
    
    
    //
    int tempTotal = 0; //Used for the split hand's total
    bool canSplit = false; //Used to see if the player has met split criteria
    bool isSplit = false; //Used to see if the player has chosen to split
    float betValue = 0; //Value the player bets
    float startingMoney = 1000; //Original capital
    bool enterLoop = true; //Check if the player enters the main gameplay loop IE wins or loses in the first two cards
    Hand playerHand; //Hand the player's cards are in
    playerHand.setName("Player");
    Hand splitHand; //Hand the split cards are in
    splitHand.setName("Split Hand");
    Hand dealerHand; //Hand the dealers cards are in
    dealerHand.setName("Dealer");
    Hand unusedCards; //The deck of the cards
    unusedCards.setName("Deck");
    char choice = 'x'; //The choice the player makes during the main game loop
    //Totals to be used
    int currentTotal = 0; //Total of the player
    int dealerTotal = 0; //Total of the dealer
    int shownDealerTotal = 0; //Total shown to the player in the beginning
    int currentRandomIndex = 0; //Random value to draw from the deck
    //Sets the initial sizes
    unusedCards.setSize(0);
    playerHand.setSize(0);
    splitHand.setSize(0);
    dealerHand.setSize(0);
    //Fills up the unused cards deck
    unusedCards.setCardsInHand(fullDeck.getCardsInHand());
    unusedCards.setSize(totalCards);
    //Game Number Tracker
    int gameNumTracker = 0;
    //Leaving Game Tracker
    bool leavingGame = false;
    //Main Game!
    while (leavingGame == false) {
        gameNumTracker++;
        cout << "___________________________" << "GAME: " << gameNumTracker << "___________________________" << endl;
        cout << "Your starting money is: " << startingMoney << " dollars." << endl;
        cout << "How much would you like to bet?  Input -1 to quit." << endl;
        cin >> betValue;
        if (betValue == -1) {
            break;
        }
        while (betValue <= 0 || betValue > startingMoney) //Makes sure you can make the bet
        {
            cout << "How much would you like to bet?  Input -1 to quit." << endl;
            cin >> betValue;
        } 
        if(betValue>0 && betValue <= startingMoney)
        {
            cout << "You bet: " << betValue << endl;
            //Draws 2 cards
            currentRandomIndex = randomizeCardIndex(unusedCards.getSize()); //Random index
            playerHand = drawCard(unusedCards, playerHand, currentRandomIndex); //Draws a card to the players hand
            unusedCards = resizeAfterDraw(unusedCards, currentRandomIndex); //Resizes the deck


            currentRandomIndex = randomizeCardIndex(unusedCards.getSize());
            playerHand = drawCard(unusedCards, playerHand, currentRandomIndex);
            unusedCards = resizeAfterDraw(unusedCards, currentRandomIndex);

            //Dealer draw 2 cards
            currentRandomIndex = randomizeCardIndex(unusedCards.getSize());
            dealerHand = drawCard(unusedCards, dealerHand, currentRandomIndex); //Draws a card to the dealers hand
            unusedCards = resizeAfterDraw(unusedCards, currentRandomIndex);

            currentRandomIndex = randomizeCardIndex(unusedCards.getSize());
            dealerHand = drawCard(unusedCards, dealerHand, currentRandomIndex);
            unusedCards = resizeAfterDraw(unusedCards, currentRandomIndex);
            //Output the player's hand for viewing and add up the values
            for (int i = 0; i < playerHand.getSize(); i++) {
                currentTotal += playerHand.getCardsInHand()[i].getValue();
                currentTotal = adjustForAces(playerHand);
            }
            playerHand.printHand(currentTotal);
            int v;
            v = playerHand.getCardsInHand()[0]+playerHand.getCardsInHand()[1];
            cout << "The current total for your first two drawn cards is: " << v << endl;
            cout << "The higher of the two cards is: " << myMax(playerHand.getCardsInHand()[0].getValue(),playerHand.getCardsInHand()[1].getValue()) << endl;
            cout << endl;
            //Output the dealer's hand for viewing minus the hidden card
            for (int i = 0; i < dealerHand.getSize() - 1; i++) {
                shownDealerTotal += dealerHand.getCardsInHand()[i].getValue();
                cout << "Card shown: " << dealerHand.getCardsInHand()[i].getName() << endl;
            }
            for (int i = 0; i < dealerHand.getSize(); i++) {
                dealerTotal += dealerHand.getCardsInHand()[i].getValue();
            }
            //Output the total of the dealer's hand
            cout << "Viewed total in dealer hand: " << shownDealerTotal << endl;
            cout << endl;
            //Checks if there's any double blackjacks or if the game is already won
            if (currentTotal == 21 && dealerTotal != 21) //Player blackjacks
            {
                cout << "BLACKJACK!!!" << endl;
                enterLoop = false;
                startingMoney += betValue * 2;
                cout << "Your money is now: " << startingMoney << endl;
            }
            if (dealerTotal == 21 && currentTotal != 21) //Dealer blackjacks
            {
                dealerHand.printHand(dealerTotal);
                cout << "The dealer blackjacked..." << endl;
                enterLoop = false;
                startingMoney -= betValue;
                cout << "Your money is now: " << startingMoney << endl;
            }
            if (dealerTotal == currentTotal && dealerTotal == 21) //Both blackjack
            {
                dealerHand.printHand(dealerTotal);
                cout << "Both blackjack!  It's a push." << endl;
                enterLoop = false;
                cout << "Your money is now: " << startingMoney << endl;
            }
            //Main calculation loop
            while (currentTotal <= 21 && enterLoop == true) {
                if (playerHand.getSize() == 2) //As long as the player's hand size is 2 we can check if a split is possible.  
                {
                    if (playerHand.getCardsInHand()[0].getValue() != playerHand.getCardsInHand()[1].getValue() || startingMoney < betValue * 2 || isSplit == true) //Normal gameplay at the beginning if no split is possible
                    {
                        cout << "Would you like to hit (H) or stand (S)?" << endl;
                        cin >> choice;
                    } else 
                    {
                        canSplit = true;
                        cout << "Would you like to hit (H), stand (S), or split (X)?" << endl;
                        cin >> choice;
                    }
                } else //Normal gameplay choice
                {
                    cout << "Would you like to hit (H) or stand (S)?" << endl;
                    cin >> choice;
                }
                if (choice == 'X' && canSplit == true) //Checks if the player does split and is able to do so
                {
                    isSplit = true; //Indicates they are now in a split
                    Card* dummyCards = new Card[1];
                    splitHand.setCardsInHand(dummyCards); //Initializes the split hand.
                    splitHand.getCardsInHand()[0] = playerHand.getCardsInHand()[1]; //Adds the second card to the split hand
                    splitHand.setSize(1);
                    currentTotal -= playerHand.getCardsInHand()[1].getValue(); //Removes the split card from the total
                    tempTotal = currentTotal; //Saves the total for after the split is played
                    playerHand = resizeAfterDraw(playerHand, 1);
                    currentTotal = splitHand.getCardsInHand()[0].getValue(); //Starts playing the split hand
                    splitHand.printHand();
                }

                if (choice == 'H') //Checks if the player hits
                {
                    currentRandomIndex = randomizeCardIndex(unusedCards.getSize());
                    if (isSplit) //If the player is playing the split hand
                    {
                        splitHand = drawCard(unusedCards, splitHand, currentRandomIndex);
                        unusedCards = resizeAfterDraw(unusedCards, currentRandomIndex);
                        currentTotal += splitHand.getCardsInHand()[splitHand.getSize() - 1].getValue();
                        splitHand.printHand();
                        if (currentTotal > 21) //Checks for a bust in the split hand
                        {
                            currentTotal = adjustForAces(splitHand); //Adjusts for aces in case
                            if (currentTotal > 21) //If the aces cant fix it, you bust
                            {
                                destroy(splitHand.getCardsInHand());
                                startingMoney -= betValue;
                                cout << "Lost the split hand...recovering original.  \nYour money is now " << startingMoney << endl << endl << endl;
                                ;
                                splitHand.printHand();
                                currentTotal = tempTotal; //Starts up the player's hand run
                                isSplit = false;
                                canSplit = false;
                            }

                        }
                    } else {
                        //Normal run for the player's hand
                        playerHand = drawCard(unusedCards, playerHand, currentRandomIndex);
                        unusedCards = resizeAfterDraw(unusedCards, currentRandomIndex);
                        currentTotal += playerHand.getCardsInHand()[playerHand.getSize() - 1].getValue();
                        currentTotal = adjustForAces(playerHand);
                        playerHand.printHand(currentTotal);
                    }

                } else if (choice == 'S') {
                    while (dealerTotal < 17) //If the dealer is not at 17 or more they have to draw a card
                    {
                        currentRandomIndex = randomizeCardIndex(unusedCards.getSize());
                        dealerHand = drawCard(unusedCards, dealerHand, currentRandomIndex);
                        unusedCards = resizeAfterDraw(unusedCards, currentRandomIndex);
                        dealerTotal += dealerHand.getCardsInHand()[dealerHand.getSize() - 1].getValue();
                        if (dealerTotal > 21) //Makes sure the dealer can have aces be 11 or 1
                        {
                            dealerTotal = adjustForAces(dealerHand);
                        }
                    }
                    dealerHand.printHand(dealerTotal);
                    if (dealerTotal > 21) //Checks if the dealer busts
                    {
                        cout << "Busted the dealer!" << endl;
                        startingMoney += betValue;
                        cout << "Your money is now: " << startingMoney << endl;
                        if (isSplit) //Reverts back to the main hand if the player was in a split
                        {
                            cout << "Back to the main hand." << endl;
                            currentTotal = tempTotal;
                            canSplit = false;
                            isSplit = false;
                            destroy(splitHand.getCardsInHand());
                            playerHand.printHand(currentTotal);
                        } else
                            break; //Or ends the round if not.
                    } else
                        if (currentTotal > dealerTotal) //Checks if the player beats the dealer
                    {
                        cout << "Win!" << endl;
                        startingMoney += betValue;
                        cout << "Your money is now: " << startingMoney << endl;
                        if (isSplit) //Returns to the main hand if the player was in a split
                        {
                            cout << "Back to the main hand." << endl;
                            currentTotal = tempTotal;
                            canSplit = false;
                            isSplit = false;
                            destroy(splitHand.getCardsInHand());
                            playerHand.printHand(currentTotal);
                        } else
                            break;
                    } else
                        if (currentTotal < dealerTotal) //Checks if the player loses to the dealer
                    {
                        cout << "Lose!" << endl;
                        startingMoney -= betValue;
                        cout << "Your money is now: " << startingMoney << endl;
                        if (isSplit)//Returns to the main hand if the player was in a split
                        {
                            cout << "Back to the main hand." << endl;
                            currentTotal = tempTotal;
                            canSplit = false;
                            isSplit = false;
                            destroy(splitHand.getCardsInHand());
                            playerHand.printHand(currentTotal);
                        } else
                            break;
                    } else //Checks if the dealer and player tie
                    {
                        cout << "Push!" << endl;
                        cout << "Your money is now: " << startingMoney << endl;
                        if (isSplit) {
                            cout << "Back to the main hand." << endl; //Returns to the main hand if the player was in a split
                            currentTotal = tempTotal;
                            canSplit = false;
                            isSplit = false;
                            destroy(splitHand.getCardsInHand());
                            playerHand.printHand(currentTotal);
                        } else
                            break;
                    }
                }
            }
            if (currentTotal > 21) //If the loop ends somehow, the player must have busted.  This checks that and shows it.
            {
                cout << "Busted yourself..." << endl;
                startingMoney -= betValue;
                cout << "Your money is now: " << startingMoney << endl;
            }
            cout << endl;
            //Reset Values for infinite draws
            isSplit = false;
            canSplit = false;
            tempTotal = 0;
            currentTotal = 0;
            dealerTotal = 0;
            shownDealerTotal = 0;
            enterLoop = true;
            playerHand = removeCards(playerHand);
            dealerHand = removeCards(dealerHand);
            unusedCards.setCardsInHand(fullDeck.getCardsInHand());
            unusedCards.setSize(totalCards);
            if (startingMoney <= 0) //Ends the game if the player has no money to spend.
            {
                cout << "Looks like you're out of money.  Better luck next time!" << endl;
                break;
            }
        }
    }
    return startingMoney;
}

int adjustForAces(Hand x) {
    int total = 0;
    int numAces = 0;
    for (int i = 0; i < x.getSize(); i++) {
        total += x.getCardsInHand()[i].getValue();
        if (x.getCardsInHand()[i].getValue() == 11) {
            numAces += 1; //Counts the number of aces present
        }
    }
    while (total > 21 && numAces > 0) //Takes the amount of aces and makes their value 1 if needed.  Only does this to get below 21.
    {
        total -= 10;
        numAces--;
    }
    return total;
}

playerScore* readBin(fstream& in, int record) { //Reads and fills a struct with a file's contents
    //Declare and initialize variables
    long cursor = 0L; //Where to place the cursor
    playerScore* a = new playerScore; //Declare the array to return

    //Find the record
    cursor = record * sizeof (playerScore);

    //Fill the structure
    in.seekg(cursor, ios::beg);
    in.read(reinterpret_cast<char*> (a), sizeof (playerScore));
    return a;
}

void wrtBin(fstream& out, playerScore* a) { //Writes data from a struct to a bin file
    out.write(reinterpret_cast<char*> (a), sizeof (playerScore));
}

void wrtTxt(fstream& out, playerScore* a) { //Writes the values from a struct to a file
    out << endl;
    out << setw(4) << a->firstI << a->secondI << a->thirdI << endl;
    out << setw(6) << a->score << endl;
    out << endl;
}

void prntTxt(playerScore* a) { //Prints values from a struct to the console
    cout << endl;
    cout << "Game Results " << endl;
    cout << setw(4) << a->firstI << a->secondI << a->thirdI << endl;
    cout << setw(6) << a->score << endl;
    cout << endl;
}