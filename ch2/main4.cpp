#include <iostream>
#include <cstdio>
#include <string>
#include <format>

#define STRING_EXAMPLE "1HA2HA3HA"

std::string_view extractExtension(std::string_view filename) {
    return filename.substr(filename.rfind('.'));
}

void handleExtension(const std::string& extension) {
    std::cout << "extension handling function" << std::endl;
}

int main() {
    std::string_view example{STRING_EXAMPLE};
    printf("The string is %s and size is %d\n", example.data(), static_cast<int32_t>(example.size()));
    example.remove_prefix(2);
    printf("After remove prefix of 2, the string is %s and size is %d\n", example.data(), static_cast<int32_t>(example.size()));

    std::string filename { R"(c:\temp\my file.txt)"};
    std::cout << std::format("C++ string: {}", extractExtension(filename)) << std::endl;

    const char* cString { R"(c:\temp\my file.ext)" };
    std::cout << std::format("C string: {}", extractExtension(cString)) << std::endl;

    std::cout << std::format("literal: {}", extractExtension(R"(c:\temp\my file.ext)")) << std::endl;

    const char* raw { R"(Xiaohuang Zhu . txt file)" };
    std::size_t length { std::strlen(raw) };
    std::cout << std::format("raw: {}", extractExtension({raw, length})) << std::endl;
    std::cout << std::format("raw: {}", extractExtension(std::string_view{raw, length})) << std::endl;

    // cannot directly construct std::string from std::string_view
    // use std::string_view.data() or explicitly construct the std::string from std::string_view
    handleExtension(extractExtension("my filename.txt").data());    // data() method
    handleExtension(std::string{extractExtension("my filename.txt")});  // explicit construct

    // cannot connect std::string and std::string_view directly
    std::string str{"Hello"};
    std::string_view sv{" World"};
    auto result {str + sv.data()};  // use data() method
    std::string result2 {str};
    result2.append(sv.data(), sv.size());
    std::cout << "The result1 is " << result << std::endl;
    std::cout << "The result2 is " << result2 << std::endl;

    // !!! WARNING !!!
    // Do not use std::string_view to save a temporary
#if 0
    std::string s {"Hello"};
    std::string_view sv2 { s + "World"};    // After construct the sv2, the temporary string is destroyed, but std::string_view still points to this string (dangling pointer)
    std::cout << sv2 << std::endl;  // On MSVC, this prints " ello World"
#endif

    {
        using namespace std::literals::string_view_literals;
        std::string_view sv3 {"My string_view"sv};
        std::cout << std::format("sv3 is {}", sv3) << std::endl;
    }
    return 0;
}