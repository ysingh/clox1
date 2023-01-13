#include "Token.h";
#include <sstream>

Token::Token(TokenType typ, std::string lex, void* lit, int ln) : type{ typ }, lexeme{ lex }, literal{ lit }, line{ ln } {}

const char* TokenString[] = {
	"LEFT_PAREN",
	"RIGHT_PAREN",
	"LEFT_BRACE",
	"RIGHT_BRACE",
	"COMMA",
	"DOT",
	"MINUS",
	"PLUS",
	"SEMICOLON",
	"SLASH",
	"STAR",

	// One or Two Character Tokens
	"BANG",
	"BANG_EQUAL",

	"EQUAL",
	"EQUAL_EQUAL",

	"GREATER",
	"GREATER_EQUAL",

	"LESS",
	"LESS_EQUAL",

	// Literals
	"IDENTIFIER",
	"STRING",
	"NUMBER",

	// Keywords
	"AND",
	"CLASS",
	"ELSE",
	"FALSE",
	"FUN",
	"FOR",
	"IF",
	"NIL",
	"OR",
	"PRINT",
	"RETURN",
	"SUPER",
	"THIS",
	"TRUE",
	"VAR",
	"WHILE",

	"EOF"
};

std::string Token::toString() {
	std::ostringstream oss{};
	oss << TokenString[type] << " " << lexeme << " " << (char*)literal;
	return oss.str();
}