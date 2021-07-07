#include <iostream>
#include <string>
#include <bitset>

/*
* Checks wether a string is a number or not, recieves the string as a parameter.
* Returns a boolean true if the string is a number, false if not.
*/ 
bool isNumber(std::string number) {
	bool isNumber = true;
	size_t index = 0;
	while (index < number.size() && isNumber != false) {
		if (std::isdigit(number[index]) != 0) {
			index++;
		}
		else {
			isNumber = false;
		}
	}	
	return isNumber;
}

/*
* Returns the given number transformed into its binary representation as string
*/
std::string toBinary(int number) {
	return std::bitset<32>(number).to_string();
}

/*
* Asks the user to enter two numbers into the standard input
*/
void askForNumbers(int* number01, int* number02) {

	std::string temporalNumber01 = "";
	std::string temporalNumber02 = "";
	std::cout << "Introduce the first number: ";
	std::cin >> temporalNumber01;
	while (!isNumber(temporalNumber01)) {
		std::cout << "Introduce a number!!!\n";
		std::cout << "Introduce the first number: ";
		std::cin >> temporalNumber01;
	}
	std::cout << "Introduce the second number: ";
	std::cin >> temporalNumber02;
	while (!isNumber(temporalNumber02)) {
		std::cout << "Introduce a number!!!\n";
		std::cout << "Introduce the first number: ";
		std::cin >> temporalNumber02;
	}
	std::cout << "First number in binary:  " << toBinary(stoi(temporalNumber01)) << std::endl;
	std::cout << "second number in binary: " << toBinary(stoi(temporalNumber02)) << std::endl;
	*number01 = stoi(temporalNumber01);
	*number02 = stoi(temporalNumber02);
}

/*
* Asks the user to introduce the number of operation wanted
*/
int askForOperation() {
	std::string operation = "";
	std::cout << "Choose what operation you want to do:" << std::endl;
	std::cout << "1.AND\n2.OR\n3.NOT\n4.XOR\n5.EXIT\nIntroduce the number of operation:";
	std::cin >> operation;
	while (!isNumber(operation)) {
		std::cout << "Introduce a valid operation!!!\n";
		std::cout << "Choose what operation you want to do:" << std::endl;
		std::cout << "1.AND\n2.OR\n3.NOT\n4.XOR\n5.EXIT\nIntroduce the number of operation:";
		std::cin >> operation;
	}
	return stoi(operation);
}

/*
* Performs the AND operation with the help of assembly language
*/
void andOperation(int number01, int number02, int result) {
	std::cout << "\nOperation: AND" << std::endl;
	askForNumbers(&number01, &number02);
	_asm {
		MOV EAX, number01
		MOV EBX, number02
		AND EAX, EBX
		MOV result, EAX
	}
	std::cout << "The binary result is:    " << toBinary(result) << std::endl;
	std::cout << "The decimal result is:   " << result << std::endl << std::endl;
}

/*
* Performs the OR operation with the help of assembly language
*/
void orOperation(int number01, int number02, int result) {
	std::cout << "\nOperation: OR" << std::endl;
	askForNumbers(&number01, &number02);
	_asm {
		MOV EAX, number01
		MOV EBX, number02
		OR EAX, EBX
		MOV result, EAX
	}
	std::cout << "The binary result is:    " << toBinary(result) << std::endl;
	std::cout << "The decimal result is:   " << result << std::endl << std::endl;
}

/*
* Performs the NOT operation with the help of assembly language
*/
void notOperation(int number01, int result) {
	std::string notNumber;
	std::cout << "\nOperation: NOT" << std::endl;
	std::cout << "Introduce the number: ";
	std::cin >> notNumber;
	while (!isNumber(notNumber)) {
		std::cout << "Introduce a valid number!!!\n";
		std::cout << "Introduce the number: ";
		std::cin >> notNumber;
	}
	number01 = stoi(notNumber);
	std::cout << "The number in binary:    " << toBinary(number01) << std::endl;
	_asm {
		MOV EAX, number01
		NOT EAX
		MOV result, EAX
	}
	std::cout << "The binary result is:    " << toBinary(result) << std::endl;
	std::cout << "The decimal result is:  " << result << std::endl << std::endl;
}

/*
* Performs the XOR operation with the help of assembly language
*/
void xorOperation(int number01, int number02, int result) {
	std::cout << "\nOperation: XOR" << std::endl;
	askForNumbers(&number01, &number02);
	_asm {
		MOV EAX, number01 
		MOV EBX, number02
		XOR EAX, EBX
		MOV result, EAX
	}
	std::cout << "The binary result is:    " << toBinary(result) << std::endl;
	std::cout << "The decimal result is:   " << result << std::endl << std::endl;
}

/*
* Performs all the operations
*/
void booleanCalculator() {
	int number01 = 0;
	int number02 = 0;
	int result = 0;
	int validOperation = 0;
	std::cout << "This is a 32 bit boolean calculator" << std::endl;
	do {
		validOperation = askForOperation();
		switch (validOperation) {
		case 1:
			andOperation(number01,number02,result);
			break;
		case 2:
			orOperation(number01, number02, result);
			break;
		case 3:
			notOperation(number01, result);
			break;
		case 4:
			xorOperation(number01, number02, result);
			break;
		}
	} while (validOperation != 5);
	std::cout << "Program close...";
}

int main(void) {
	booleanCalculator();
	return 0;
}
