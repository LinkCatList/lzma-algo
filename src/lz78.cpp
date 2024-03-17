#include <iostream>
#include "lz78.hpp"

template <typename T>
std::ostream &operator <<(std::ostream &stream, const std::vector<T> &v){
    for (const auto &i : v){
        stream << i;
    }
    return stream;
}

int main() {

    std::string input;
    std::cin >> input;

    std::vector<std::string> s;

    for (int i = 0; i < input.size(); i++) {
        std::string tmp = {input[i]};
        s.push_back(tmp);
    }

    auto encode = lz78_Encode(s);

    std::cout << "ENCODE:\n";
    for (auto &i: encode) {
        std::cout << std::get<0>(i) << " " << std::get<1>(i) << "\n"; 
    }

    std::vector<std::string> decode = lz78_Decode(encode);

    std::cout << "DECODE:\n";
    std::cout << decode << "\n";

    return 0;
}