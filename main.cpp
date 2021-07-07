#include <iostream>
#include <string>
#include <bitset>


bool isNumber(std::string number) {
	bool isNumber = true;
	int index = 0;
	while (index < number.length() && isNumber != false) {
		if (std::isdigit(number[index]) != 0) {
			index++;
		}
		else {
			isNumber = false;
		}
	}
	
	return isNumber;
}

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
	*number01 = stoi(temporalNumber01);
	*number02 = stoi(temporalNumber02);
}

int main(void) {
	int number01 = 0;
	int number02 = 0;
	int result = 0;
	std::string operation = "";
	int validOperation = 0;
	std::string notNumber;
	std::string binary;
	std::cout << "This is a 32 bit boolean calculator\nChoose what operation you want to do:\n";
	do {
		std::cout << "1.AND\n2.OR\n3.NOT\n4.XOR\n5.EXIT" << std::endl;
		std::cin >> operation;
		while (!isNumber(operation)) {
			std::cout<<"Introduce a valid operation!!!\n";
			std::cout << "1.AND\n2.OR\n3.NOT\n4.XOR\n5.EXIT" << std::endl;
			std::cin >> operation;
		}
		validOperation = stoi(operation);
		switch (validOperation) {
			case 1:
				askForNumbers(&number01, &number02);
				_asm {
					MOV EAX, number01
					MOV EBX, number02
					AND EAX,EBX
					MOV result,EAX
				}
				std::cout << "The decimal result is : "<< result << std::endl;
				binary = std::bitset<32>(result).to_string();
				std::cout << "The binary result is : " << binary << std::endl;
				break;
			case 2:
				askForNumbers(&number01, &number02);
				_asm {
					MOV EAX, number01
					MOV EBX, number02
					OR EAX, EBX
					MOV result, EAX
				}
				std::cout << "The decimal result is : " << result << std::endl;
				binary = std::bitset<32>(result).to_string();
				std::cout << "The binary result is : " << binary << std::endl;
				break;
			case 3:
				std::cout << "Introduce the number: ";
				std::cin >> notNumber;
				while (!isNumber(notNumber)) {
					std::cout << "Introduce a valid number!!!\n";
					std::cout << "Introduce the number: ";
					std::cin >> notNumber;
				}
				number01 = stoi(notNumber);
				_asm {
					MOV EAX, number01
					NOT EAX
					MOV result, EAX
				}
				std::cout << "The decimal result is : " << result << std::endl;
				binary = std::bitset<32>(result).to_string();
				std::cout << "The binary result is : " << binary << std::endl;
				break;
			case 4:
				askForNumbers(&number01, &number02);
				_asm {
					MOV EAX, number01
					MOV EBX, number02
					XOR EAX, EBX
					MOV result, EAX
				}
				std::cout << "The decimal result is : " << result << std::endl;
				binary = std::bitset<32>(result).to_string();
				std::cout << "The binary result is : " << binary << std::endl;
				break;
		}
	} while (validOperation != 5);
	std::cout << "Program close...";
	return 0;
}