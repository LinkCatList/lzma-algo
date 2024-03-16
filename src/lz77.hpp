#include <iostream>
#include <vector>
#include <deque>
#include "trie.hpp"

std::vector<std::tuple<int, int, char> > lz77(std::string &input) {

    for (int i = 0; i < input.size(); i++) {

        std::deque<char> s;
        for(int j = i; j < input.size(); j++) {
            s.push_back(input[j]);
        }
        
        if (!has(s)) {
            add_string(s, i);
        }

    }

    std::vector<std::tuple<int, int, char> >ans;
    std::deque<char> d;
    for (int i = 0; i < input.size(); i++) {
        d.push_back(input[i]);

        while (has(d) == -1 && !d.empty()) {
            d.pop_front();
        }

        ans.push_back({has(d), d.size(), input[i+1]});
    }
    
    return ans;
}