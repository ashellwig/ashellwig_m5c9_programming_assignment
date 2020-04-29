#include "../include/chapter9.hh"
#include <catch2/catch.hpp>

SCENARIO("Example", "[example]") {
  GIVEN("An example") {
    WHEN("We use it") {
      THEN("Our tests pass!") { REQUIRE(1 == 1); }
    }
  }
}
