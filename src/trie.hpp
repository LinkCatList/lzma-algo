#include <iostream>
#include <deque>

struct Node {
    Node *next[26];

    int id_start; // индекс начала строки, которая заканчивается в этой вершине

    Node() {
        for (int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
        id_start = -1;
    }
};

Node *root = new Node();

void add_string(const std::deque<char> &s, int id_start) {
    Node *cur_v = root;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];

        if (cur_v -> next[c - 'a'] == nullptr) {
            cur_v -> next[c - 'a'] = new Node();
        }

        cur_v = cur_v -> next[c - 'a'];
    }

    cur_v -> id_start = id_start;
}

int has(const std::deque<char> &s) {
    Node *cur_v = root;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        
        cur_v = cur_v -> next[c - 'a'];

        if (cur_v == nullptr) {
            return -1;
        }
    }
    return cur_v -> id_start;
}
