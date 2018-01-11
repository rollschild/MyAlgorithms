#include <iostream>

using namespace std;

#define SIZE 26

struct Trie {
    struct Trie* child[SIZE];
    bool leaf;
}

int charToInt(char c) {
    return c - 'A';
}

struct Trie* insert(char c) {
    
}
