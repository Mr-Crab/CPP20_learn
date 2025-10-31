#ifndef CPP20_KEYVALUE_HPP
#define CPP20_KEYVALUE_HPP
#include <string>
#include <format>

class KeyValue {
public:
    KeyValue(std::string_view key, int value)
        : mKey(key), mValue(value) {}
    const std::string& getKey() const {return mKey;}
    int getValue() const {return mValue;}
private:
    std::string mKey;
    int mValue;
};

template<>
class std::formatter<KeyValue> {
    public:
    constexpr auto parse(auto& context) {
        auto iter {context.begin()};
        const auto end {context.end()};
        if (iter == end || *iter == '}') {
            mOutputType = OutputType::KeyAndValue;
            return iter;
        }

        switch (*iter) {
            case 'a':
                mOutputType = OutputType::KeyOnly;
                break;
            case 'b':
                mOutputType = OutputType::ValueOnly;
                break;
            case 'c':
                mOutputType = OutputType::KeyAndValue;
                break;
            defaut:
                throw std::format_error("Invalid KeyValue format specifier");
        }

        ++iter;
        if (iter != end && *iter != '}') {
            throw std::format_error("Invalid KeyValue format specifier");
        }
        return iter;
    }

    auto format(const KeyValue& kv, auto& context) const {
        switch (mOutputType) {
            using enum OutputType;
            case KeyOnly:
                return std::format_to(context.out(), "{}", kv.getKey());
            case ValueOnly:
                return std::format_to(context.out(), "{}", kv.getValue());
            default:
                return std::format_to(context.out(), "{} - {}", kv.getKey(), kv.getValue());
        }
    }

private:
    enum class OutputType {KeyOnly, ValueOnly, KeyAndValue};
    OutputType mOutputType {OutputType::KeyAndValue};
};

#endif //CPP20_KEYVALUE_HPP