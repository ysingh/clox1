#include <iostream>
#include "Lox.h";

int main(int argc, char* argv[]) {
	Lox lox;
	lox.runFile("Lox.cpp");
	lox.runPrompt();
	lox.error(100, "WWWWWWWWWWWWWWWWWWWWWWWWW");
	/*if (argc > 1) {
		std::cout << "Usage: clox1 [script]" << std::endl;
		exit(64);
	} else if (argc == 1) {
		lox.runFile(argv[0]);
	} else {
		lox.runPrompt();
	}*/

	return 0;
}