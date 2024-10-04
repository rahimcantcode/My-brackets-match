#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "Checker.h"  // Include the Checker class header

TEST_CASE("Check that Checker works", "[Checker]") {
    // Testing the array-based stack checker
    SECTION("Checking the array stack checker") {
        Checker checker;  // Instantiate a Checker object

        // Test various files and expect specific outcomes (1 for mismatch, 0 for no mismatch)
        REQUIRE(checker.checkWithArray("./test_data/DSVector_bad.h") == 1);  // Expect a mismatch
        REQUIRE(checker.checkWithArray("./test_data/DSVector_good.h") == 0);  // Expect no mismatch
        REQUIRE(checker.checkWithArray("./test_data/DSVector_difficult.h") == 0);  // Expect no mismatch
        REQUIRE(checker.checkWithArray("./test_data/Closing.h") == 1);  // Expect a mismatch
        REQUIRE(checker.checkWithArray("./test_data/Mismatch.h") == 1);  // Expect a mismatch
        REQUIRE(checker.checkWithArray("./test_data/Opening.h") == 1);  // Expect a mismatch
        REQUIRE(checker.checkWithArray("./test_data/OK.h") == 0);  // Expect no mismatch
    }

    // Testing the list-based stack checker
    SECTION("Checking the list stack checker") {
        Checker checker;  // Instantiate a Checker object for list-based checking

        // Test various files and expect specific outcomes (1 for mismatch, 0 for no mismatch)
        REQUIRE(checker.checkWithList("./test_data/DSVector_bad.h") == 1);  // Expect a mismatch
        REQUIRE(checker.checkWithList("./test_data/DSVector_good.h") == 0);  // Expect no mismatch
        REQUIRE(checker.checkWithList("./test_data/DSVector_difficult.h") == 0);  // Expect no mismatch
        REQUIRE(checker.checkWithList("./test_data/Closing.h") == 1);
        REQUIRE(checker.checkWithList("./test_data/Mismatch.h") == 1);  // Expect a mismatch
        REQUIRE(checker.checkWithList("./test_data/Opening.h") == 1);  // Expect a mismatch
        REQUIRE(checker.checkWithList("./test_data/OK.h") == 0);  // Expect no mismatch
    }
}
