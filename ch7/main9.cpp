#include <iostream>
#include <memory>
#include "Simple.hpp"

void useResource(std::weak_ptr<Simple>& weakSimple) {
    auto resource = weakSimple.lock();
    if (resource) {
        std::cout << "Resource still alive and the use count is " << resource.use_count() << std::endl;
    } else {
        std::cout << "Resource has been freed" << std::endl;
    }
}

int main() {
    auto sharedSimple{std::make_shared<Simple>()};
    std::weak_ptr<Simple> weakSimple{sharedSimple};

    std::cout << "Before calling the useResource 1st time, the use count is " << sharedSimple.use_count() << std::endl;
    // Try to use the weak_ptr
    useResource(weakSimple);
    std::cout << "After calling the useResource 1st time, the use count is " << sharedSimple.use_count() << std::endl;

    // Reset the shared_ptr
    // Since there is only 1 shared_ptr to the Simple resource, this will
    // free the resource, even though there is still a weak_ptr alive
    sharedSimple.reset();

    // Try to use the weak_ptr again
    useResource(weakSimple);
    return 0;
}