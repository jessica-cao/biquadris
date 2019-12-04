#include "trie.h"

// Constructor
Trie::Trie() {
    this->isLeaf = false; // empty retrieval tree is not a leaf

    for (int i = 0; i < CHAR_SIZE; ++i) {
        //this->character[i] = nullptr;
		this->character.push_back(nullptr);
    }
};

// Insert a new key in the Trie.
void Trie::insert(std::string key) {
    const int KEYLEN = key.length();
    
	// start from root node
	Trie* curr = this;
	for (int i = 0; i < KEYLEN; i++) {
		// create a new node if path doesn't exists
		if (curr->character[(int) key[i]] == nullptr) {
			curr->character[(int) key[i]] = std::make_unique<Trie>();
			//curr->character[(int)key[i]] = new Trie();
		}

		// go to the next node
		curr = curr->character[(int) key[i]].get();
	}

	// mark current node as leaf
	curr->isLeaf = true;
}

// Using the insert method above, insert a vector of command names in a Trie.

void Trie::insertCommands() {
    const int COMMLEN = this->commands.size();
    
    for (int i = 0; i < COMMLEN; ++i) {
        this->insert(this->commands[i]);
    }
}

// Search for a key in Trie. It returns the whole name of the corresponding command if the key is found,
// else it returns an empty string. Maybe this should be called search and retrieve?
std::string Trie::search(std::string key) {
    const int KEYLEN = key.length();
    const int COMMLEN = this->commands.size();

    std::string foundComm;
    
	// return false if Trie is empty cuz it's obviously not there
	if (this == nullptr) {
	    throw std::logic_error {"\"" + key + "\" is not a valid command. Please input a valid command.."};
	}

	Trie* curr = this;
	for (int i = 0; i < KEYLEN; i++) {
		// go to next node
		curr = curr->character[(int) key[i]].get();

		// if string is invalid (reached end of path in Trie)
		if (curr == nullptr) {
			throw std::logic_error {"\"" + key + "\" is not a valid command. Please input a valid command."};
		}
	}
	
	// if we're here, it means that congrats, this string is a valid command
	
	for (int i = 0; i < COMMLEN; ++i) {
	    if (this->commands[i][0] == key[0] && this->commands[i].find(key) != std::string::npos) {
	        foundComm = this->commands[i];
	    }
	}
	
	return foundComm;
}

int Trie::parsePrefix(std::string cmd) {
	const int CMDLEN = cmd.length();
    std::string pref = "0";
    for (int i = 0; i < CMDLEN; ++i) {
        if ('0' <= cmd[i] && cmd[i] <= '9') {
            pref += cmd[i];
        }
    }
    
    return std::stoi(pref);
}
