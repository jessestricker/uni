#include "code_point.hpp"

#include <iomanip>
#include <sstream>

namespace uni {
  std::string CodePoint::to_string() const {
    auto oss = std::ostringstream{};
    oss << "U+";
    oss << std::hex << std::uppercase;
    oss << std::setw(4) << std::setfill('0');
    oss << value_;
    return oss.str();
  }

  std::ostream& operator<<(std::ostream& os, const CodePoint& cp) {
    return os << cp.to_string();
  }
}
