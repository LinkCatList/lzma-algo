#include <iostream>
#include <vector>
#include <deque>
#include "trie.hpp"

std::vector<std::tuple<int, std::string> > lz78_Encode(std::vector<std::string> &input) {

    std::vector<std::tuple<int, std::string> >ans;
    std::string s = "";
    int prev = -1;
    int cnt = 0;

    for (int i = 0; i < input.size(); i++) {
        s += input[i];
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
    if (prev != -1) {
        ans.push_back({0, input.back()});
    }  
    return ans;
}

std::vector<std::string> lz78_Decode(std::vector<std::tuple<int, std::string> > &input) {

    std::vector<std::string> words;
    for (int i = 0; i < input.size(); i++) {

        int link_ind = std::get<0>(input[i]);
        std::string cur_string = std::get<1>(input[i]);

        if (link_ind == 0) {
            words.push_back(cur_string);
        }
        else {
            words.push_back(words[link_ind - 1] + cur_string);
        }
    }

    std::vector<std::string> ans;
    for (auto &i: words) {
        for (auto &c: i){
            ans.push_back(std::to_string(c - '0'));
        }
    }

    return ans;
}