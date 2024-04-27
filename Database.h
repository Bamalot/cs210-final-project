#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Database
{
public:
  Database();
  ~Database();
  void LoadFromFile();
  bool HasKey(string key);
  void AddItem(string key);
  int GetItemCount(string key);
  int GetKeyCount();
  string GetKeyFromIndex(int index);
  int GetValueFromIndex(int index);
private:

  int keyCount;
  string* keys;
  int* values;
  int getKeyIndex(string key);
  void backupData();
};

