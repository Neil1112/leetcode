#include <iostream>
#include <string>
#include <stack>
using namespace std;

// function to check if the given string has valid parenthesis
bool isValid(string s) {
    stack<char> parenthesis_stack;
    for (char c : s) {
        if (c == ')' || c == '}' || c == ']') {
            // if stack empty - return false
            if (parenthesis_stack.empty())
                return false;
            
            // if not empty, then pop element and compare with current
            char popped_element = parenthesis_stack.top();
            parenthesis_stack.pop();
            if ((popped_element == '(' && c == ')') || (popped_element == '{' && c == '}') || (popped_element == '[' && c == ']'))
                continue;
            
            // else
            return false;
        }

        // push to stack
        if (c == '(' || c == '{' || c == '[')
            parenthesis_stack.push(c);
    }

    // if stack not empty after traversing the string - return false
    if (!parenthesis_stack.empty())
        return false;

    return true;
}


int main() {
    string s;

    // test case 1
    s = "()";
    cout << "Test case 1: " << endl;
    cout << "String: " << s << endl;
    cout << "Valid parenthesis: " << isValid(s) << endl;

    // test case 2
    cout << endl;
    s = "()[]{}";
    cout << "Test case 2: " << endl;
    cout << "String: " << s << endl;
    cout << "Valid parenthesis: " << isValid(s) << endl;

    // test case 3
    cout << endl;
    s = "(]";
    cout << "Test case 3: " << endl;
    cout << "String: " << s << endl;
    cout << "Valid parenthesis: " << isValid(s) << endl;

    // test case 4
    cout << endl;
    s = "[";
    cout << "Test case 4: " << endl;
    cout << "String: " << s << endl;
    cout << "Valid parenthesis: " << isValid(s) << endl;

    return 0;
}