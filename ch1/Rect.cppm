export module Rectangle;
#include <cstdint>

export class Rect {
public:
    constexpr Rect(uint32_t width, uint32_t height);
    constexpr uint32_t getArea() const;
private:
    uint32_t mWidth;
    uint32_t mHeight;
};
