#include "stack.h"
#include <iostream>
#include <string>

int postfix(char input);	// Postfix Expression Evaluation
void convert(char input);	// Converts Infix to postfix (First link in citation)
int prec(char input);		// Finds operator precendce (Modified code from geeksforgeeks.org)

int main() {

	std::string equ;	// Equation
	std::cout << "Enter mathematical expression: " << std::endl;
	std::getline(std::cin, equ);

	for (int i = 0; i < equ.length(); i++)	// For as long as the string. from geeksforgeeks.org
	{
		char c1;
		c1 = equ[i];
		convert(c1);
	}
	return 0;
}