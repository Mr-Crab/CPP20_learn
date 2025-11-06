#include <iostream>
#include <memory>

class Foo {
public:
    Foo(int value) : mData(value) {
        std::cout << "Construct the Foo instance" << std::endl;
    }

    ~Foo() {
        std::cout << "Destroy the Foo instance" << std::endl;
    }

    int mData;
};

int main() {
    std::cout << "Main: before make shared of Foo\n";
    auto foo {std::make_shared<Foo>(42)};
    std::cout << "Main: after make shared of Foo, before aliasing, the use count of foo is " << foo.use_count() << "\n";
    auto aliasing{std::shared_ptr<int>{foo, &foo->mData}};
    std::cout << "Main: after make aliasing of Foo, the use count of foo is " << foo.use_count() << " The use count of aliasing is " << aliasing.use_count() << "\n";
    return 0;
}