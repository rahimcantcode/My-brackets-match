#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "DSList.h"  // Include the DSList class header

// Test suite for the DSList class functionality
TEST_CASE("Check that DSList works", "[DSList]") {
    // Testing push, pop, and peek functions
    SECTION("Checking push and pop operations") {
        DSList<int> integerList;
        integerList.push_back(1);
        integerList.push_back(2);
        integerList.push_back(3);
        integerList.push_back(4);

        // Verify size and end elements after push operations
        REQUIRE(integerList.size() == 4);
        REQUIRE(integerList.peek_back() == 4);
        REQUIRE(integerList.peek_front() == 1);

        // Test pop operations and verify remaining elements and list size
        REQUIRE(integerList.pop_back() == 4);
        REQUIRE(integerList.pop_front() == 1);
        REQUIRE(integerList.size() == 2);
        REQUIRE(integerList.peek_back() == 3);
        REQUIRE(integerList.peek_front() == 2);

        // Test pushing to the front and popping from the front
        integerList.push_front(10);
        REQUIRE(integerList.pop_front() == 10);
    }

    // Testing the copy constructor
    SECTION("Checking the copy constructor") {
        DSList<int> originalList;
        originalList.push_back(1);
        originalList.push_back(2);
        originalList.push_back(3);
        originalList.push_back(4);

        // Create a new list from the existing one and test the copied values
        DSList<int> copiedList = DSList<int>(originalList);
        REQUIRE(copiedList.size() == 4);
        REQUIRE(copiedList.pop_back() == 4);
        REQUIRE(copiedList.pop_front() == 1);
    }

    // Testing the assignment operator
    SECTION("Checking the assignment operator") {
        DSList<int> sourceList;
        sourceList.push_back(1);
        sourceList.push_back(2);
        sourceList.push_back(3);
        sourceList.push_back(4);

        DSList<int> assignedList;
        assignedList = sourceList;

        // Check that the assigned list has the same elements and behaviors
        REQUIRE(assignedList.size() == 4);
        REQUIRE(assignedList.pop_back() == 4);
        REQUIRE(assignedList.pop_front() == 1);
    }

    // Testing the find function
    SECTION("Checking the find function") {
        DSList<int> searchableList;
        searchableList.push_back(1);
        searchableList.push_back(2);
        searchableList.push_back(3);
        searchableList.push_back(4);

        // Verify that elements are found at the correct positions
        REQUIRE(searchableList.find(4) == 3);
        REQUIRE(searchableList.find(2) == 1);
        REQUIRE(searchableList.find(1) == 0);
    }

    // Testing the clear and isEmpty functions
    SECTION("Checking clear and isEmpty functions") {
        DSList<int> testList;
        testList.push_back(1);
        testList.push_back(2);
        testList.push_back(3);
        testList.push_back(4);

        // Verify that the list is not empty, then clear it and check again
        REQUIRE(!testList.isEmpty());
        testList.clear();
        REQUIRE(testList.isEmpty());
    }
}
