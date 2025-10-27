#include <charconv>
#include <iostream>
#include <string>

// transfer from number to string

int main() {
    const std::size_t BufferSize = 50;
    std::string out(BufferSize, ' ');
    auto result { std::to_chars(out.data(), out.data() + out.size(), 12345) };
    if (result.ec == std::errc{}) {
        std::cout << "out is " << out << std::endl;
    }

    // for constructal binding
    auto [ptr, error] { std::to_chars(out.data(), out.data() + out.size(), 454677) };
    if (error == std::errc{}) {
        std::cout << "constuctor binding out is " << out << std::endl;
    }

    // for float/double conversion
    double value {0.314};
    std::string out2 (BufferSize, ' ');
    auto [ptrF, errorF] { std::to_chars(out2.data(), out2.data() + out2.size(), value) };
    if (errorF == std::errc{}) {
        std::cout << "constructor binding of float out is " << out2 << std::endl;
    }

    // for error return, i.e. ptr
    double value2;
    out2 = std::string{"  Hi There!"};
    auto [ptr2, error2] { std::from_chars(out2.data(), out2.data() + out2.size(), value2) };
    if (error2 == std::errc{}) {
        if (value == value2) {
            std::cout << "Perfect round trip" << std::endl;
        } else {
            std::cout << "No perfect round trip" << std::endl;
        }
    } else if (error2 == std::errc::invalid_argument) {
        std::cout << "Invalid argument and the first non-number character is |" << ptr2 << "|" << std::endl;
    }
    return 0;
}