#ifndef LOX_H
#define LOX_H
#include <string>

#if defined(_WIN32)
#define EXIT_MSG "Press Ctrl + Z to Exit"
#else
#define EXIT_MSG "Press Ctrl + D to Exit"
#endif

#define PROMPT_WELCOME_MSG "Lox Prompt Ver 0.1"

class Lox {
	static bool hadError;
	static void run(std::string src);
	static void report(size_t line, std::string where, std::string msg);
public:
	static void runFile(const char* path);
	static void runPrompt(void);
	static void error(size_t line, std::string msg);
};

#endif