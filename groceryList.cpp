#include <iostream>
#include <fstream>
#include <map>

using namespace std;

void diplayItems(map<string, int> &items) {
  for (auto it = items.begin(); it != items.end(); it++){
    cout << it -> first << " (" << it->second << ")" << endl;
  }
}

void addItem(map<string, int> &items){
  string item;
  int quantity;

  cout << " Enter the product name: ";
  cin >> item;
  cout << " Enter the quantity of the product: ";
  cin >> quantity;

  if (items.count(item) > 0){
    items.at(item) += quantity;
    cout << "The quantity of " << item << " has been updated." << endl;
  } else {
     items.emplace(item, quantity);
     cout << "Product added" << endl;
  }
}


void saveListToFile(map<string, int> &items) {
  ofstream groceryListFile;
  groceryListFile.open("groceryList.txt");

  for (auto it = items.begin(); it != items.end(); it++){
    groceryListFile << it -> first << " (" << it -> second << ")" << endl;
  }

  groceryListFile.close();
}

int main() {
  map<string, int> items;
  items.emplace("Eggs", 4);

  int option = -1;

  while (option != 0){
    cout << endl;
    cout << "0.End of the program" << endl;
    cout << "1. View products" << endl;
    cout << "2. Add a product" << endl;
    cout << "3. Save the grocery list to a file " << endl;
    cout << "Choose an option: ";

    cin >> option;

    if (option == 1){
      diplayItems(items);
    } else if (option == 2){
      addItem(items);
    } else if (option == 3){
      saveListToFile(items);
    }
  }
  
}
 


