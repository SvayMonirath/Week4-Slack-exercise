#include <iostream>
#include <cassert>
#include "stack.cpp"

int main() {
    Stack stack(100);

    // Tests from main.cpp
    assert(stack.isBalanced("({[{}]})") && "Test 1 failed: ({[{}]}) should be balanced");
    assert(!stack.isBalanced("[][]{)") && "Test 2 failed: [][]{) should be unbalanced");
    assert(stack.isBalanced("if(a[0] == '{')") && "Test 3 failed: if(a[0] == '{') should be balanced");

    std::cout << "All tests passed\n";
    return 0;
}
