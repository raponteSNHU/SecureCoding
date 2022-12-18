// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>

using namespace std;

//macro definition
#define MAX_VALUE_LEN 20

int main()
{
  std::cout << "Buffer Overflow Example" << std::endl;

  // TODO: The user can type more than 20 characters and overflow the buffer, resulting in account_number being replaced -
  //  even though it is a constant and the compiler buffer overflow checks are on.
  //  You need to modify this method to prevent buffer overflow without changing the account_order
  //  varaible, and its position in the declaration. It must always be directly before the variable used for input.

  const std::string account_number = "CharlieBrown42";
  char user_input[MAX_VALUE_LEN];

  while (1) {
	  cout << "Enter a value: ";

	  /*Using getline will discard input stream when it gets to a newline
	  because newline is the delimitation character.
	  Whole line will be read until max limit or newline is reached.
	  Program will output message if defined value limit is exceeded.*/
	  cin.getline(user_input, MAX_VALUE_LEN);

	  //Input validation to detect if user input fits defined variable
	  if (cin.fail()) {

		  //Reset the stream state, repairs instream
		  cin.clear();

		  //Clears the buffer
		  cin.ignore(numeric_limits<streamsize>::max(), '\n');

		  //Outputs message to try again
		  cout << "Character limit exceeded. Try again.\n" << endl;
	  }
	  else {
		  cout << "You entered: " << user_input << endl;
		  cout << "Account Number = " << account_number << endl;

		  //Exits the loop and the program
		  return 0;
	  }
  }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
