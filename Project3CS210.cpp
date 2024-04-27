
// Project3CS210.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Database.h"

// Prints menu options
void displayMenu()
{
  cout << "[1] Get Item Frequency" << endl;
  cout << "[2] List All Items" << endl;
  cout << "[3] Graphs All Items" << endl;
  cout << "[4] Exit" << endl << endl;
}

// Asks user to specify a specific item to print the frequency of
void getItemFrequency(Database& database)
{
  string key;
  cout << "Input item name: " << endl;
  cin >> key;
  cout << key << ": " << database.GetItemCount(key) << endl << endl;
}
// Prints the frequency of all items
void getAllItemsFrequency(Database& database)
{
  for (int i = 0; i < database.GetKeyCount(); i++)
  {
    string keyName = database.GetKeyFromIndex(i);
    // Adds padding so the print looks neat 
    for (int j = 0; j < (11 - keyName.length()); j++)
    {
      cout << " ";
    }
    cout << keyName << ": " << database.GetValueFromIndex(i) << endl;
  }
  cout << endl;
}

// Prints all items like a histogram
void getAllItemsFrequencyGraphed(Database& database)
{
  for (int i = 0; i < database.GetKeyCount(); i++)
  {
    string keyName = database.GetKeyFromIndex(i);
    // Adds padding so the graph looks neat 
    for (int j = 0; j < (11 - keyName.length()); j++)
    {
      cout << " ";
    }
    cout << keyName << ": ";
    for (int j = 0; j < database.GetValueFromIndex(i); j++)
    {
      cout << "#";
    }
    cout << endl;
  }
  cout << endl;
}
int main()
{
  // Creates the database and loads it from the file
  Database database;
  database.LoadFromFile();
  
  // Loop that displays the menu and responds to user input
  while (true)
  {
    displayMenu();
    int selection;
    cin >> selection;

    // Delegates each menu function to the proper function
    switch (selection)
    {
    case 1:
      getItemFrequency(database);
      break;
    case 2:
      getAllItemsFrequency(database);
      break;
    case 3:
      getAllItemsFrequencyGraphed(database);
      break;
    case 4:
      exit(0);
      break;
    }
  }

}