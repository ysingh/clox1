#include <iostream>

#include "Lox.h";
#include "Scanner.h";

bool Lox::hadError{ false };

void Lox::runFile(const char* path) {
	std::cout << "Running File" << std::endl;
	
	std::FILE* sourceFile = std::fopen(path, "rb");
	
	if (!sourceFile) {
		std::cout << "Unable to open source File at: " << path << "Error: " << std::strerror(errno) << std::endl;
		return;
	}

	std::string sourceCodeBuf;
	std::fseek(sourceFile, 0, SEEK_END);
	sourceCodeBuf.resize(std::ftell(sourceFile));
	std::rewind(sourceFile);
	std::fread(&sourceCodeBuf[0], 1, sourceCodeBuf.size(), sourceFile);
	std::fclose(sourceFile);
	
	run(sourceCodeBuf);

	if (hadError) exit(65);
}

void Lox::runPrompt(void) {
	std::cout << PROMPT_WELCOME_MSG << std::endl;
	std::cout << EXIT_MSG << std::endl;
	std::cout << "> ";
	std::string line;
	do {
		if (!line.empty()) {
			run(line);
			hadError = false;
		}
		std::cout << "> ";
	} while (std::getline(std::cin, line));
}

void Lox::run(std::string src) {
	std::cout << src << std::endl;

	Scanner scanner(src);
	std::vector<Token> tokens = scanner.scanTokens();

	for (Token i : tokens) {
		std::cout << i.toString() << std::endl;
	}	
}

void Lox::report(size_t line, std::string where, std::string msg) {
	std::cerr << "\033[1;31m[line: " << line << "] Error " << where << ": " << msg << "\033[0m" << std::endl;
	hadError = true;
}

void Lox::error(size_t line, std::string msg) {
	report(line, "", msg);
}