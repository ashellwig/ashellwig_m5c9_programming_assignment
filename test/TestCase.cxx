#include "../include/catch2/catch.hpp"
#include "../include/chapter9.hh"

SCENARIO("Example", "[example]") {
  GIVEN("An example") {
    WHEN("We use it") {
      THEN("Our tests pass!") { REQUIRE(1 == 1); }
    }
  }
}
