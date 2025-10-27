#include <string>
#include <iostream>
#include <vector>

template <class T>
constexpr
std::string_view
type_name()
{
    using namespace std;
#ifdef __clang__
    string_view p = __PRETTY_FUNCTION__;
    return string_view(p.data() + 34, p.size() - 34 - 1);
#elif defined(__GNUC__)
    string_view p = __PRETTY_FUNCTION__;
#  if __cplusplus < 201402
    return string_view(p.data() + 36, p.size() - 36 - 1);
#  else
    return string_view(p.data() + 49, p.find(';', 49) - 49);
#  endif
#elif defined(_MSC_VER)
    string_view p = __FUNCSIG__;
    return string_view(p.data() + 84, p.size() - 84 - 7);
#endif
}

using namespace std::literals::string_literals;
int main() {
    auto string1 = {"Hello World"};
    auto string2 = "Hello World"s;
    std::cout << "Hello World!\n";

    // std::vector 支持类模板参数推导(CTAD)
    // 对字符串vector使用CTAD必须小心
    // 下面类型是std::vector<char const*>, 而不是std::vector<std::string>
    std::vector names {"Jone", "Sam"};
    std::cout << "type of names is " << type_name<decltype(names)>() << "\n";

    // 如果需要std::vector<std::string>
    // 可以使用std::string字面量
    std::vector namesString {"Jone"s, "Sam"s};
    std::cout << "type of namesString is " << type_name<decltype(namesString)>() << "\n";
    return 0;
}