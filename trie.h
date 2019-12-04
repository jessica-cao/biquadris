#ifndef TRIE_H
#define TRIE_H
#define CHAR_SIZE 128 // 128 usable ASCII characters
#include <iostream>
#include <vector>
#include <memory> // new
#include <stdexcept>

// A Trie is used for command parsing, so that incomplete but identifiable commands still work
class Trie {
	bool isLeaf;
	std::vector<std::unique_ptr<Trie>> character;
	const std::vector<std::string>commands = {"left", "right", "down", "clockwise", "counterclockwise", "drop", "levelup",
                "leveldown", "norandom", "random", "sequence", "restart", "I", "J", "L", "O",
                "S", "Z", "T"}; // ALL of the possible commands are in this vector; if you want to add or delete commands, DO IT HERE

    public:

	Trie(); // Constructor
	void insert(std::string); // insert a word into a new Trie
	void insertCommands(); // insert a whole list of commands into a new Trie
	std::string search(std::string); // searches and retrieves a command, else it throws an error
	int parsePrefix(std::string);

};


#endif
