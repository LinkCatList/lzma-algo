#include <iostream>
#include <vector>
#include "delta_filter.hpp"

int main(){
    int n;
    std::cin >> n;
    std::vector<std::string> v(n);

    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    auto encode = delta_filter(v);

    std::cout << "ENCODE:\n";
    std::cout << encode << "\n";

    std::cout << "DECODE:\n";
    std::cout << delta_Decode(encode) << "\n";

    return 0;
}