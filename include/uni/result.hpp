#ifndef UNI_RESULT_HPP
#define UNI_RESULT_HPP

#include <stdexcept>

namespace uni {
  class BadResultAccess : public std::logic_error {
  public:
    explicit BadResultAccess(const char* string)
        : logic_error{string} {
    }
  };

  template <class V, class E>
  class Result {
  public:
    using Value = V;
    using Error = E;

    Result(const Value& value) // NOLINT
        : has_value_{true}
        , value_{value} {
    }

    Result(const Error& error) // NOLINT
        : has_value_{false}
        , error_{error} {
    }

    [[nodiscard]] bool has_value() const noexcept {
      return has_value_;
    }

    [[nodiscard]] bool has_error() const noexcept {
      return !has_value();
    }

    const Value& value() const {
      if (has_value()) {
        return value_;
      }
      throw BadResultAccess{"no value"};
    }

    const Error& error() const {
      if (has_error()) {
        return error_;
      }
      throw BadResultAccess{"no error"};
    }

    operator bool() const noexcept { // NOLINT
      return has_value();
    }

    const Value& operator*() const {
      return value();
    }

  private:
    bool has_value_;
    union {
      Value value_;
      Error error_;
    };
  };
}

#endif //UNI_RESULT_HPP
