/****************************************************
         ❤ Bsmellah El Rahman El Rahim ❤
****************************************************/

#include <bits/stdc++.h>
using namespace std;


struct Vertex {
  char val;
  vector<Vertex *> children;
  bool isWord;
  Vertex(char c) : val(c), isWord(0) { children.assign(60, NULL); }
  ~Vertex() {
    auto cur = this;
    for (const auto &x : cur->children) {
      if (x) {
        delete x;
      }
    }
  }
};

class Trie {
  Vertex *root;

public:
  Trie():root(new Vertex('!')) { }
  void insert(string word) {
    auto cur = root;
    for (int i = 0; i < word.size(); ++i) {
      int ind = word[i] - 'A';
      if (!cur->children[ind])
        cur->children[ind] = new Vertex(word[i]);
      cur = cur->children[ind];
    }
    cur->isWord = 1;
  }
  bool contains(string word) {
    auto cur = root;
    for (int i = 0; i < word.size(); ++i) { // O(String SZ)
      int ind = word[i] - 'A';
      if (!cur->children[ind])
        return false;
      cur = cur->children[ind];
    }
    return cur->isWord;
  }
  bool startsWith(string word) {         // Search for Prefix
    auto cur = root;
    for (int i = 0; i < word.size(); ++i) {
      int ind = word[i] - 'A';
      if (!cur->children[ind])
        return false;
      cur = cur->children[ind];
    }
    return true;
  }
};

signed main() {
  Trie t;
  t.insert("Ahmed");
  cout << t.contains("AHmed") << '\n';
  cout << t.startsWith("A");
  cout << '\n';
}
