#include <catch2/catch.hpp>
#include <uni/result.hpp>

using Value = int;

enum class Error {
  Negative,
};

using Result = uni::Result<Value, Error>;

TEST_CASE("Result: conversion ctor") {
  auto s0 = Result{1};
  Result s1 = 1;
  REQUIRE(s0.value() == s1.value());

  auto e0 = Result{Error::Negative};
  Result e1 = Error::Negative;
  REQUIRE(e0.error() == e1.error());
}

TEST_CASE("Result: success") {
  auto s = Result{12};
  REQUIRE(s.has_value());
  REQUIRE(bool{s});
  REQUIRE(s);

  REQUIRE(s.value() == 12);
  REQUIRE(*s == 12);

  REQUIRE_FALSE(s.has_error());
  REQUIRE_THROWS_AS(s.error(), uni::BadResultAccess);
}

TEST_CASE("Result: error") {
  auto s = Result{Error::Negative};
  REQUIRE(s.has_error());
  REQUIRE(!bool{s});
  REQUIRE(!s);

  REQUIRE(s.error() == Error::Negative);

  REQUIRE_FALSE(s.has_value());
  REQUIRE_THROWS_AS(s.value(), uni::BadResultAccess);
  REQUIRE_THROWS_AS(*s, uni::BadResultAccess);
}
