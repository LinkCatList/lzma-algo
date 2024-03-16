#include <iostream>
#include <deque>
#include "trie.hpp"

int main() { 
    std::deque<char> s1 = {'a', 'b', 'a', 'c', 'a', 'b', 'a'};
    std::deque<char> s2 = {'a', 'b'};
    std::deque<char> s3 = {' '};

    add_string(s1, 0);
    std::cout << has(s1) << " " << has(s2) << " " << has(s3) << "\n";

    return 0;
}