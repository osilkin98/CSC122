#include <iostream>
#include <iomanip>
#include <climits>
#include <cctype>
#include <sstream>

#define MAX_TABLE_SIZE 50

using namespace std;

void print_menu() {
  cout << "Table menu\n\n1) Addition table\n"
       << "2) Multiplication table\n3) Subtraction table\n"
       << "4) Division table\n5) Remainder table\n6) Quit"
       << endl;
}

// 'operator' was already a keyword so I have to change to 'op'
float table_operation(int a, int b, char op) {
  if(op == '+') {
    return a + b;
  } else if(op == '-') {
    return a - b;
  } else if(op == '*') {
    return a * b;
  } else if(op == '/') {
    return (float)a / (float)b;
  }
  return a % b;
}

void construct_table(int table_size, char op) {
  ostringstream oss;
  int prec = op == '/' ? 2 : 0;
  int width = op == '/' ? prec+3: 4;
  int mult = (table_size + 2) * width;
  oss << setw(width) << left << op << setw(width) << "|";
  for(int i = 1; i <= table_size; ++i) {
    oss << setw(width) << i;
  }
  oss << "\n";
  for(int i = 1; i <= mult; ++i) {
    if(i == width+1) {
      oss << "+";
      continue;
    }
    oss << "-";
  }
  oss << "\n";
  for(int k = 1; k <= table_size; ++k) {
    oss << setw(width) << k << setw(width) << "|";
    for(int i = 1; i <= table_size; ++i) {
      oss << setw(width) << fixed << setprecision(prec)  << table_operation(i, k, op);
    }
    oss << "\n";
  }
  cout << oss.str() << endl;
}

// table selection function to refrain from writing functions
// within each if statement
// the select argument is actually representative of a single-digit number
// from 1-5, as the char built-in data type uses the least # of bytes
// it was the most sensible choice.
void table_select(char select) {
  int size_selection;
  cout << "\nEnter a table size: " << flush;
  cin >> size_selection;
  cin.clear();
  cin.ignore(INT_MAX, '\n');
  // if the user is trying to insert some garbage
  while(size_selection < 0 || size_selection > MAX_TABLE_SIZE) {
    cout << "\nERROR: Invalid Table Size, please enter a value between "
	 << "0 and " << MAX_TABLE_SIZE << "\nEnter a table size: " << flush;
    cin >> size_selection;
    cin.ignore(INT_MAX, '\n');
  }
  switch(select) {
  
  case 1: // addition
    construct_table(size_selection, '+');
    break;
  case 2: // multiplication
    construct_table(size_selection, '*');
    break;
  case 3: // subtraction
    construct_table(size_selection, '-');
    break;
  case 4: // division
    construct_table(size_selection, '/');
    break;
  case 5: // modulus
    construct_table(size_selection, '%');
    break;
  default:
    cerr << "some freaky error occurred and somehow the program ended up"
	 << " in the default case\n";
    break;
  }
  
  
}

bool is_valid(char c) {
  return ('1' <= c && c <= '6') ||
    tolower(c) == 'a' || tolower(c) == 'm' || tolower(c) == 's' ||
    tolower(c) == 'd' || tolower(c) == 'r' || tolower(c) == 'q';
}

int main() {
  // initialize the program
  cout << "\t\tWelcome to the Math Table Program!!!\n" << endl;
  char selec = '0';

  while(tolower(selec) != 'q' && tolower(selec) != '6') {
    print_menu();
    cout << "\nChoice: " << flush;
    cin >> selec;
    cin.ignore(INT_MAX, '\n');
    // checking for validation of enetered character makes more sense
    // prior to checking for specifics at the U 
    while(!is_valid(selec)) {
      cout << "Sorry, that choice isn't valid, please try again.\n"
	   << "Choice: " << flush;
      cin >> selec;
      cin.ignore(INT_MAX, '\n');
    }
    if(selec == '1' || tolower(selec) == 'a') {
      // addition table
      table_select(1);
    } else if(selec == '2' || tolower(selec) == 'm') {
      // multiplication table
      table_select(2);
    } else if(selec == '3' || tolower(selec) == 's') {
      // subtraction table
      table_select(3);
    } else if(selec == '4' || tolower(selec) == 'd') {
      // division table
      table_select(4);
    } else if(selec == '5' || tolower(selec) == 'r') {
      // remainder table
      table_select(5);
    }
    
    
  }
  
  return 0;
}
