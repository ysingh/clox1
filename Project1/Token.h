#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include "TokenType.h"

class Token {
public:
	const TokenType type;
	const std::string lexeme;
	const void* literal;
	const int line;

	Token(TokenType typ, std::string lex, void* lit, int ln);
	std::string toString();
};

#endif