/* Trie
 */
#include <iostream>
#include <vector>

#define ALPHABET 26

using namespace std;

struct TrieNode {
  // vector<TrieNode*> children(ALPHABET);
  bool is_end;
  TrieNode* children[ALPHABET];
};

TrieNode* make_node() {
  TrieNode* node = new TrieNode();
  for (auto trie_node_ptr : node->children) {
    trie_node_ptr = nullptr;
  }
  node->is_end = false;
  return node;
}

void insert(TrieNode* root, string word) {
  TrieNode* crawler_ptr = root;
  for (int i = 0; i < word.length(); ++i) {
    int index = word[i] - 'a';
    if (crawler_ptr->children[index] == nullptr) {
      crawler_ptr->children[index] = make_node();
    }
    crawler_ptr = crawler_ptr->children[index];
  }
  crawler_ptr->is_end = true;
}

bool search(TrieNode* root, string word) {
  TrieNode* crawler_ptr = root;
  for (int j = 0; j < word.length(); ++j) {
    int index = word[j] - 'a';
    if (crawler_ptr->children[index] == nullptr) return false;
    crawler_ptr = crawler_ptr->children[index];
  }
  return (crawler_ptr != nullptr && crawler_ptr->is_end == true);
}

int main() {
  vector<string> words = {"the", "a",  "there", "answer",
                          "any", "by", "bye",   "their"};

  TrieNode* root = make_node();

  for (auto word : words) {
    insert(root, word);
  }

  search(root, "the") ? cout << "\"the\" exists" << endl
                      : cout << "\"the\" does not exist" << endl;
  search(root, "these") ? cout << "\"theese\" exists" << endl
                        : cout << "\"these\" does not exist" << endl;
  search(root, "their") ? cout << "\"their\" exists" << endl
                        : cout << "\"their\" does not exist" << endl;
  search(root, "thaw") ? cout << "\"thaw\" exists" << endl
                       : cout << "\"thaw\" does not exist " << endl;

  return 0;
}
