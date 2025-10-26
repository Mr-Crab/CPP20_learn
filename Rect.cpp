module Rectangle;

constexpr Rect::Rect(uint32_t width, uint32_t height): mWidth(width), mHeight(height) {}

constexpr uint32_t Rect::getArea() const { return mWidth * mHeight; }