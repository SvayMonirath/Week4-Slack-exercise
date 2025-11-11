#include <iostream>
#include "stack.cpp"

using namespace std;
int main(void) {
    Stack stack(100);
    cout << stack.isBalanced("({[{}]})") << endl ;
    cout << stack.isBalanced("[][]{)") << endl ;
    cout << stack.isBalanced("if(a[0] == '{')") << endl ;
    return 0;
}
