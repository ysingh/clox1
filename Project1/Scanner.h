#ifndef SCANNER_H
#define SCANNER_H

#include <vector>
#include "Token.h"

class Scanner {
	const std::string source;
	int start{ 0 };
	int current{ 0 };
	int line{ 1 };
	bool isAtEnd();
	void scanToken(void);
public:
	std::vector<Token> scanTokens(void);
	Scanner(std::string src);
};

#endif
