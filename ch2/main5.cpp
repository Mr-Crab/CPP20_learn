#include <iostream>
#include <format>
#include <string>

int main() {
    auto n = 3;
    auto s1 { std::format("Read {} bytes from {}", n, "file1.txt") };
    auto s2 { std::format("Read {0} bytes from {1}", n, "file2.txt") };
    std::cout << "s1 is " << s1 << std::endl;
    std::cout << "s2 is " << s2 << std::endl;

    auto s3 { std::format(L" ??{1}?ж??{0}?????", n, L"file3.txt") };
    std::wcout << "s3 is " << s3 << std::endl;

    // format: width
    int i{42};
    std::cout << std::format("|{:5}|", i) << std::endl;
    std::cout << std::format("|{:{}}|", i, 10) << std::endl;
    std::cout << std::endl;

    // format: [fill]align
    std::cout << std::format("|{:7}|", i) << std::endl;
    std::cout << std::format("|{:<7}|", i) << std::endl;
    std::cout << std::format("|{:_>7}|", i) << std::endl;
    std::cout << std::format("|{:_^7}|", i) << std::endl;
    std::cout << std::endl;

    // format: sign
    std::cout << std::format("|{:<5}|", i) << std::endl;
    std::cout << std::format("|{:<+5}|", i) << std::endl;
    std::cout << std::format("|{:< 5}|", i) << std::endl;
    std::cout << std::format("|{:< 5}|", -i) << std::endl;
    std::cout << std::endl;

    // format: # (alternate formatting)
    std::cout << std::format("|{:10d}|", i) << std::endl;
    std::cout << std::format("|{:10b}|", i) << std::endl;
    std::cout << std::format("|{:#10b}|", i) << std::endl;
    std::cout << std::format("|{:10X}|", i) << std::endl;
    std::cout << std::format("|{:#10X}|", i) << std::endl;
    std::string s {"ProCPP"};
    std::cout << std::format("|{:_^10}|", s) << std::endl;
    std::cout << std::endl;

    // format: precision
    double d {3.1415 / 2.3};
    std::cout << std::format("|{:12g}|", d) << std::endl;
    std::cout << std::format("|{:12.2}|", d) << std::endl;
    std::cout << std::format("|{:12e}|", d) << std::endl;

    int width{12};
    int precision{3};
    std::cout << std::format("|{2:{0}}.{1}f|", width, precision, d) << std::endl;
    std::cout << std::endl;

    // format: 0
    int idx{42};
    std::cout << std::format("|{:06d}|", idx) << std::endl;
    std::cout << std::format("|{:+06d}|", idx) << std::endl;
    std::cout << std::format("|{:06X}|", idx) << std::endl;
    std::cout << std::format("|{:#06X}|", idx) << std::endl;
    std::cout << std::endl;

    // format exception catch
    try {
        std::cout << std::format("An integer: {:}", 5);
    } catch (const std::format_error& caught_exception) {
        std::cout << caught_exception.what();
    }
    return 0;
}