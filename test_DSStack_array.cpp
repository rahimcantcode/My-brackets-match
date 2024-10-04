#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "DSStack_array.h"  // Include the DSStack_array class header

TEST_CASE("Check that DSStack_array works", "[DSStack_array]") {
    // Tests for push, pop, and getSize functions
    SECTION("Testing push, pop, and getSize") {
        DSStack_array<int> stack;
        stack.push(1);
        stack.push(2);
        stack.push(3);

        REQUIRE(stack.getSize() == 3);
        REQUIRE(stack.pop() == 3);
        REQUIRE(stack.getSize() == 2);
        REQUIRE(stack.pop() == 2);
        REQUIRE(stack.getSize() == 1);
    }

    // Tests for the copy constructor
    SECTION("Testing copy constructor") {
        DSStack_array<int> originalStack;
        originalStack.push(1);
        originalStack.push(2);
        originalStack.push(3);

        DSStack_array<int> copiedStack = DSStack_array<int>(originalStack);
        REQUIRE(copiedStack.getSize() == 3);
        REQUIRE(copiedStack.peek() == 3);
    }

    // Tests for the assignment operator
    SECTION("Testing assignment operator") {
        DSStack_array<int> sourceStack;
        sourceStack.push(1);
        sourceStack.push(2);
        sourceStack.push(3);

        DSStack_array<int> assignedStack;
        assignedStack = sourceStack;
        REQUIRE(assignedStack.getSize() == 3);
        REQUIRE(assignedStack.peek() == 3);
    }

    // Tests for the clear and isEmpty functions
    SECTION("Testing clear and isEmpty functions") {
        DSStack_array<int> stack;
        stack.push(1);
        stack.push(2);
        stack.push(3);

        REQUIRE(!stack.isEmpty());
        stack.clear();
        REQUIRE(stack.getSize() == 0);
        REQUIRE(stack.isEmpty());
    }

    // Tests for the find function
   SECTION("Testing find function") {
        DSStack_array<int> stack;
        stack.push(1);
        stack.push(2);
        stack.push(3);

        // Expect the find method to return the index from the bottom of the stack
        REQUIRE(stack.find(1) == 0); // 1 is at the bottom of the stack
        REQUIRE(stack.find(2) == 1); // 2 is in the middle
        REQUIRE(stack.find(3) == 2); // 3 is at the top of the stack
    }
}
