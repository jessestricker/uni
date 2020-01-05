#ifndef UNI_CODE_POINT_HPP
#define UNI_CODE_POINT_HPP

#include <cstdint>
#include <iosfwd>
#include <string>

namespace uni {
  class CodePoint {
  public:
    using Value = std::uint_least32_t;

    static constexpr CodePoint min() noexcept;
    static constexpr CodePoint max() noexcept;

    constexpr explicit CodePoint(Value value = 0x0000) noexcept;
    constexpr explicit operator Value() const noexcept;

    [[nodiscard]] constexpr bool valid() const noexcept;
    [[nodiscard]] std::string to_string() const;

  private:
    Value value_;
  };

  std::ostream& operator<<(std::ostream& os, const CodePoint& cp);

  constexpr bool operator==(const CodePoint& lhs, const CodePoint& rhs) noexcept;
  constexpr bool operator<(const CodePoint& lhs, const CodePoint& rhs) noexcept;
  constexpr bool operator!=(const CodePoint& lhs, const CodePoint& rhs) noexcept;
  constexpr bool operator>(const CodePoint& lhs, const CodePoint& rhs) noexcept;
  constexpr bool operator<=(const CodePoint& lhs, const CodePoint& rhs) noexcept;
  constexpr bool operator>=(const CodePoint& lhs, const CodePoint& rhs) noexcept;

  // ---------------------------------------------------------------------------

  constexpr CodePoint CodePoint::min() noexcept {
    return CodePoint{};
  }

  constexpr CodePoint CodePoint::max() noexcept {
    return CodePoint{0x10ffff};
  }

  constexpr CodePoint::CodePoint(Value value) noexcept
      : value_{value} {
  }

  constexpr CodePoint::operator Value() const noexcept {
    return value_;
  }

  constexpr bool CodePoint::valid() const noexcept {
    return (min() <= *this) && (*this <= max());
  }

  constexpr bool operator==(const CodePoint& lhs, const CodePoint& rhs) noexcept {
    return CodePoint::Value{lhs} == CodePoint::Value{rhs};
  }

  constexpr bool operator<(const CodePoint& lhs, const CodePoint& rhs) noexcept {
    return CodePoint::Value{lhs} < CodePoint::Value{rhs};
  }

  constexpr bool operator!=(const CodePoint& lhs, const CodePoint& rhs) noexcept {
    return !(lhs == rhs);
  }

  constexpr bool operator>(const CodePoint& lhs, const CodePoint& rhs) noexcept {
    return rhs < lhs;
  }

  constexpr bool operator<=(const CodePoint& lhs, const CodePoint& rhs) noexcept {
    return !(rhs < lhs);
  }

  constexpr bool operator>=(const CodePoint& lhs, const CodePoint& rhs) noexcept {
    return !(lhs < rhs);
  }
}

#endif //UNI_CODE_POINT_HPP
