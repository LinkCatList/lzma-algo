#include <iostream>
#include <deque>
#include "trie.hpp"

int main() { 
    std::string s1 = "abacaba";
    std::string s2 = "ab";
    std::string s3 = "";

    add_string(s1, 0);
    std::cout << has(s1) << " " << has(s2) << " " << has(s3) << "\n";

    return 0;
}