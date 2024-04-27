#include "Database.h"

Database::Database()
{
  keyCount = 0;
  keys = new string[64];
  values = new int[64];
}

Database::~Database()
{
  delete [] keys;
  delete [] values;
}

void Database::LoadFromFile()
{
// Opens the file
  ifstream inputFile;
  inputFile.open("database_input.txt");

  // Adds an item for each line until EOF or error
  string line;
  getline(inputFile, line);
  while (!inputFile.fail())
  {
    AddItem(line);
    getline(inputFile, line);
  }
  // Releases the file
  inputFile.close();
  // Back up the data
  backupData();
}

// Returns true if the key is in the database
bool Database::HasKey(string key)
{
  return getKeyIndex(key) != -1;
}

// Adds the item to an existing key or creates a new key if it doesn't exist
void Database::AddItem(string key)
{
  if (HasKey(key))
  {
    int index = getKeyIndex(key);
    values[index] += 1;
  }
  else
  {
    keys[keyCount] = key;
    values[keyCount] = 1;
    keyCount += 1;
  }
}

// Gets number of an item or 0 if there is none
int Database::GetItemCount(string key)
{
  if (HasKey(key))
  {
    int index = getKeyIndex(key);
    return values[index];
  }
  return 0;
}

int Database::GetKeyCount()
{
  return keyCount;
}

string Database::GetKeyFromIndex(int index)
{
  return keys[index];
}

int Database::GetValueFromIndex(int index)
{
  return values[index];
}

// Goes through each key to return which index it is located at. -1 if it doesn't find it
int Database::getKeyIndex(string key)
{
  int index = -1;
  for (int i = 0; i < keyCount; i++)
  {
    if (keys[i].compare(key) == 0)
    {
      index = i;
      break;
    }
  }
  return index;
}

void Database::backupData()
{
  ofstream backupFile;
  backupFile.open("frequency.dat");
  for (int i = 0; i < GetKeyCount(); i++)
  {
    string keyName = GetKeyFromIndex(i);
    backupFile << keyName << " " << GetValueFromIndex(i) << endl;
  }
  backupFile.close();

}
