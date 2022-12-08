#include <iostream>
#include <string>
#include "stack.h"

int prec(char input) {
	if (input == '/' || input == '*' || input == '%')
		return 2; // If input is /,*, or %, then return highest precedence
	else if (input == '+' || input == '-')
		return 1; // If input is + or -, then return 1 for precendce
	else 
		return -1;// Otherwise, return lowest precedence
}

void convert(char c) {
	Stack stack;
	std::string output;					// Postfix output

	if (c >= '0' && c <= '9')			// If the operand is valid
		output += c;					// Set it to output
	else if (c == '(')					// If char is left bracket
		stack.push('(');				// Put left bracket in stack
	else if (c == ')') {				// If the char is right bracket
		while (stack.Top() != '(') {	// and while the top of the stack is not the left bracket
			output += stack.Top();		// Set the output to whatever is the top of the stack
			stack.pop();				// and pop it from the stack
		}
		stack.pop();					// If the top of the stack IS '(' then pop it
	}
	else {
		// If the stack is not empty and while the stack precedence >= input precedence
		while (!stack.isEmpty() && prec(c) <= prec(stack.Top())) {
			output += stack.Top();		// Add the top of the stack to the output
			stack.pop();				// Pop the stack
		}
		stack.push(c);					// Push input on to stack
	}
	// While stack is not empty AND the top of the stack is not the left bracket
	if (!stack.isEmpty()) {
		while (stack.Top() != '(') {
			output += stack.Top();		// Set the output to whatever is the top of the stack
			stack.pop();				// and pop it from the stack
		}
	}
	if (stack.Top() == '(')				// If the top of the stack IS '('
		stack.pop();					// then pop it

	// Pop all the remaining elements from the stack and add it to output
	while (!stack.isEmpty())		// While the stack isn't empty
	{
		output += stack.Top();		// Add the stack to the output
		stack.pop();				// Pop remaining elements
	}
	std::cout << output << " ";
}