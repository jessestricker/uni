#include <catch2/catch.hpp>
#include <uni/code_point.hpp>

using namespace uni;

TEST_CASE("CodePoint: ctor and conversion op") {
  REQUIRE(CodePoint::Value{CodePoint{}} == 0x0000);
  REQUIRE(CodePoint::Value{CodePoint{0x1234}} == 0x1234);
}

TEST_CASE("CodePoint: min and max") {
  REQUIRE(CodePoint::min() == CodePoint{0x0000});
  REQUIRE(CodePoint::max() == CodePoint{0x10ffff});
}

TEST_CASE("CodePoint: eq and rel ops") {
  REQUIRE(CodePoint{0} == CodePoint{0});
  REQUIRE(CodePoint{0} != CodePoint{1});

  REQUIRE(CodePoint{0} < CodePoint{1});
  REQUIRE(CodePoint{1} > CodePoint{0});

  REQUIRE(CodePoint{0} <= CodePoint{0});
  REQUIRE(CodePoint{0} <= CodePoint{1});

  REQUIRE(CodePoint{0} >= CodePoint{0});
  REQUIRE(CodePoint{1} >= CodePoint{1});
}

TEST_CASE("CodePoint: valid") {
  REQUIRE(CodePoint::min().valid());
  REQUIRE(CodePoint{0x0001}.valid());
  REQUIRE(CodePoint::max().valid());

  auto invalid0 = CodePoint{CodePoint::Value{CodePoint::min()} - 1};
  auto invalid1 = CodePoint{CodePoint::Value{CodePoint::max()} + 1};
  REQUIRE(!invalid0.valid());
  REQUIRE(!invalid1.valid());
}

TEST_CASE("CodePoint: to_string") {
  REQUIRE(CodePoint{0x0001}.to_string() == "U+0001");
  REQUIRE(CodePoint{0x0010}.to_string() == "U+0010");
  REQUIRE(CodePoint{0x0100}.to_string() == "U+0100");
  REQUIRE(CodePoint{0x1000}.to_string() == "U+1000");
  REQUIRE(CodePoint{0x10000}.to_string() == "U+10000");
  REQUIRE(CodePoint{0x100000}.to_string() == "U+100000");

  REQUIRE(CodePoint{0x12ab}.to_string() == "U+12AB");
}
