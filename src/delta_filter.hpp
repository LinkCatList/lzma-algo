#include <iostream>
#include <vector>

template <typename T>
std::ostream &operator <<(std::ostream &stream, const std::vector<T> &v){
    for (const auto &i : v){
        stream << i << " ";
    }
    return stream;
}

std::pair<char, std::vector<int> > delta_filter(std::vector<char> &input) {
    std::vector<int> code_input;

    for (int i = 1; i < input.size(); i++) {
        code_input.push_back((input[i] - '0') - (input[i - 1] - '0'));
    }

    return {input[0], code_input};
}

std::pair<int, std::vector<int> > delta_filter(std::vector<int> &input) {
    std::vector<int> code_input;

    for (int i = 1; i < input.size(); i++) {
        code_input.push_back(input[i] - input[i - 1]);
    }

    return {input[0], code_input};
}

std::vector<int> delta_Decode(std::pair<int, std::vector<int> > &encode) {
    std::vector<int> decode = {encode.first};

    std::vector<int> encode_vec = encode.second;
    for (int i = 0; i < encode_vec.size(); i++) {
        decode.push_back(decode.back() + encode_vec[i]);
    }

    return decode;
}
