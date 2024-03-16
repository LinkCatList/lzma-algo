#include <iostream>
#include <deque>

struct Node {
    Node *next[26];

    int id; // индекс строки в боре
    bool is_terminal;

    Node() {
        for (int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
        id = -1;
        is_terminal = false;
    }
};

Node *root = new Node();

void add_string(const std::string &s, int id) {
    Node *cur_v = root;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];

        if (cur_v -> next[c - 'a'] == nullptr) {
            cur_v -> next[c - 'a'] = new Node();
        }

        cur_v = cur_v -> next[c - 'a'];
    }

    cur_v -> id = id;
    cur_v -> is_terminal = true;
}

int has(const std::string &s) {
    Node *cur_v = root;

    bool was_terminal = false;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        
        was_terminal |= cur_v -> is_terminal;
        cur_v = cur_v -> next[c - 'a'];

        if (cur_v == nullptr) {
            return -1;
        }
    }

    if (cur_v -> is_terminal || was_terminal) {
        return cur_v -> id;
    }

    return -1;
}
