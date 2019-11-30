#ifndef TRIE_H
#define TRIE_H
#define CHAR_SIZE 128 // 128 usable ASCII characters
#include <iostream>
#include <vector>
#include <stdexcept>


// A Trie is used for command parsing, so that incomplete but identifiable commands still work
class Trie {
    public:
    bool isLeaf;
	Trie* character[CHAR_SIZE];
	const std::vector<std::string>commands = {"left", "right", "down", "clockwise", "counterclockwise", "drop", "levelup",
                "leveldown", "norandom", "random", "sequence", "restart", "I", "J", "L", "O",
                "S", "Z", "T"}; // ALL of the possible commands are in this vector; if you want to add or delete commands, DO IT HERE


	Trie(); // Constructor
    ~Trie(); // Destructor
	void insert(std::string); // insert a word into a new Trie
	void insertCommands(); // insert a whole list of commands into a new Trie
	std::string search(std::string); // searches and retrieves a command, else it throws an error

};


#endif
