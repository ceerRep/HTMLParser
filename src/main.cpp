#include <iostream>
#include <typeinfo>

#include "HTMLParser/Parser.hpp"

int main(void)
{
    using namespace cowr;

    HTMLParser parser;

    char ch;

    while (std::cin.get(ch)) {
        parser << ch;
    }

    auto tokens = parser.lexOnly();

    for (auto& x : tokens) {
        auto& token = convertToReference(x.get());
        std::cout << token.toString() << std::endl;
    }
}
