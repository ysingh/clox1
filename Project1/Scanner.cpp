#include "Scanner.h";

Scanner::Scanner(std::string src) : source{ src } {}

std::vector<Token> Scanner::scanTokens(void) {
	std::vector<Token> tokens{};
	while (!isAtEnd) {
		start = current;
		scanToken();

	}
	tokens.push_back(Token(_EOF, "", NULL, line));
}

bool Scanner::isAtEnd(void) {
	return current >= source.length();
}

void Scanner::scanToken(void) {

}

