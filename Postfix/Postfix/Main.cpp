#include <boost/algorithm/string.hpp>
#include <string>
#include <vector>
#include <iostream>
#include<math.h>
using namespace std;
void main() {
	vector<int> vStack;
	vector<string> tokens;
	int operand1, operand2;
	string inputExp = "";
	bool pfValid = true;
	//An interface with what the application can do
	cout << "*** Welcome to Postfix Calculation ***\n";
	cout << "*   This program only works on integer values\n";
	cout << "*   and accept + - * / % ^ as operators.\n";
	do {
		cout << "\nPlease enter a Postfix expression: (q to quit)\n";
		getline(cin, inputExp);
		// Use boost library function to tokenize input string
		boost::split(tokens, inputExp, boost::is_space());
		// Evaluate each token
		for (unsigned int i = 0; i < tokens.size() && pfValid == true; i++) {
			switch (tokens[i][0]) {
			//If the operator is for addition
			case '+':
				if (vStack.size() >= 2) {
					operand1 = vStack.back();
					vStack.pop_back();
					operand2 = vStack.back();
					vStack.pop_back();
					vStack.push_back(operand2 + operand1);
				}
				else {
					cout << "Invalid Postfix Expression at:  + \n";
					pfValid = false;
				}
				break;
			//If the operator is for subtraction
			case '-':
				if (vStack.size() >= 2) {
					operand1 = vStack.back();
					vStack.pop_back();
					operand2 = vStack.back();
					vStack.pop_back();
					vStack.push_back(operand2 - operand1);
				}
				else {
					cout << "Invalid Postfix Expression at:  - \n";
					pfValid = false;
				}
				break;
			//If the operator is for multiplication
			case '*':
				if (vStack.size() >= 2) {
					operand1 = vStack.back();
					vStack.pop_back();
					operand2 = vStack.back();
					vStack.pop_back();
					vStack.push_back(operand2 * operand1);
				}
				else {
					cout << "Invalid Postfix Expression at:  * \n";
					pfValid = false;
				}
				break;
			//If the operator is for division
			case '/':
				if (vStack.size() >= 2) {
					operand1 = vStack.back();
					vStack.pop_back();
					operand2 = vStack.back();
					vStack.pop_back();
					//Taking the bigger value out of the input given
					vStack.push_back(max(operand1, operand2) / min(operand1, operand2));
				}
				else {
					cout << "Invalid Postfix Expression at:  / \n";
					pfValid = false;
				}
				break;
			//If the operator needs to get the remainder of the input given
			case '%':
				if (vStack.size() >= 2) {
					operand1 = vStack.back();
					vStack.pop_back();
					operand2 = vStack.back();
					vStack.pop_back();
					vStack.push_back(operand2 % operand1);
				}
				else {
					cout << "Invalid Postfix Expression at:  % \n";
					pfValid = false;
				}
				break;
			//If the operator needs to multiple by the power of the input given
			case '^':
				if (vStack.size() >= 2) {
					operand1 = vStack.back();
					vStack.pop_back();
					operand2 = vStack.back();
					vStack.pop_back();
					vStack.push_back(pow(operand2, operand1));
				}
				else {
					cout << "Invalid Postfix Expression at:  ^ \n";
					pfValid = false;
				}
				break;
			default:
				if (all_of(tokens[i].begin(), tokens[i].end(), isdigit)) {
					vStack.push_back(stoi(tokens[i]));
				}
			}  // end of switch
		}  // end of FOR loop - Finish processing all tokens.
		// Output result
		if (inputExp[0] != 'q') {
			if (vStack.size() != 0 && pfValid == true) {
				cout << "\nYour Postfix Expression:  " << inputExp;
				cout << "\nResult:  " << vStack.back() << endl;
			}
			else {
				cout << "Invalid Postfix Expression:  " << inputExp <<
					endl;
			}
		}
		// reset for another Postfix expression
		tokens.clear();
		vStack.clear();
		pfValid = true;
	} while (inputExp[0] != 'q');
	cout << "\nThank you for using this program.\n";
	system("pause");
}
