#include <iostream>
#include <vector>
#include <deque>
#include "trie.hpp"

template <typename T>
std::ostream &operator <<(std::ostream &stream, const std::deque<T> &v){
    for (const auto &i : v){
        stream << i << " ";
    }
    return stream;
}

std::vector<std::tuple<int, char> > lz78(std::string &input) {

    std::vector<std::tuple<int, char> >ans;
    std::string s = "";
    int prev = -1;
    int cnt = 0;

    for (int i = 0; i < input.size(); i++) {
        s.push_back(input[i]);
        int index = has(s); 

        if (index != -1) {
            prev = index;
        }
        else {
            add_string(s, cnt++);
            ans.push_back({prev + 1, input[i]});
            s = "";
            prev = -1;
        }
    }
    
    return ans;
}