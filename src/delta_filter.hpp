#include <iostream>
#include <vector>

template <typename T>
std::ostream &operator <<(std::ostream &stream, const std::vector<T> &v){
    for (const auto &i : v){
        stream << i << " ";
    }
    return stream;
}

std::vector<std::string> delta_filter(std::vector<std::string> &input) {
    std::vector<std::string> code_input = {input[0]};

    for (int i = 1; i < input.size(); i++) {
        code_input.push_back(std::to_string(stoi(input[i]) - stoi(input[i - 1])));
    }

    return code_input;
}

// std::pair<int, std::vector<int> > delta_filter(std::vector<int> &input) {
//     std::vector<int> code_input;

//     for (int i = 1; i < input.size(); i++) {
//         code_input.push_back(input[i] - input[i - 1]);
//     }

//     return {input[0], code_input};
// }

std::vector<std::string> delta_Decode(std::vector<std::string>  &encode) {
    std::vector<std::string> decode = {encode[0]};

    std::vector<std::string> encode_vec = encode;
    for (int i = 1; i < encode_vec.size(); i++) {
        decode.push_back(std::to_string(std::stoi(decode.back()) + std::stoi(encode_vec[i])));
    }

    return decode;
}
