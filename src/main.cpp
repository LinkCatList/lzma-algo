#include <iostream>
#include "lz78.hpp"
#include "delta_filter.hpp"

int main() {

    int n;
    std::cin >> n;
    std::vector<std::string> input(n);
    
    for(int i = 0; i < n; i++) {
        std::cin >> input[i];
    }

    auto Encode_delta_filter = delta_filter(input);

    std::cout << Encode_delta_filter << "\n";

    auto Encode_lz78 = lz78_Encode(Encode_delta_filter);

    std::cout << "ENCODE: \n";
    for (auto &i: Encode_lz78) {
        std::cout << std::get<0>(i) << " " << std::get<1>(i) << "\n"; 
    }

    std::vector<std::string> decode = lz78_Decode(Encode_lz78);
    std::cout << decode << "\n";
    std::cout << "DECODE: \n";
    std::cout << delta_Decode(decode) << "\n";
}