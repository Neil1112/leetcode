#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

// funciton that calculates the longest unique substring
// using sliding window method to keep track of the longest string
// returns - length of the longest unique substring
int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int leftIndex = 0;
    int rightIndex = 0;
    int maxLength = 0;
    unordered_set<char> uniqueChars;

    while (rightIndex < n) {
        // if the character is not in the set, add it to the set
        if (uniqueChars.find(s[rightIndex]) == uniqueChars.end()) {
            uniqueChars.insert(s[rightIndex]);
            maxLength = max(maxLength, rightIndex - leftIndex + 1);
            rightIndex++;
        } else {
            // if the character is in the set, remove the character from the set
            uniqueChars.erase(s[leftIndex]);
            leftIndex++;
        }
    }

    return maxLength;
}


int main() {
    string s;

    // test case 1
    s = "abcabcbb";
    cout << "Test case 1: " << endl;
    cout << "String: " << s << endl;
    cout << "Length of longest unique substring: " << lengthOfLongestSubstring(s) << endl;

    // test case 2
    cout << endl;
    s = "bbbbb";
    cout << "Test case 2: " << endl;
    cout << "String: " << s << endl;
    cout << "Length of longest unique substring: " << lengthOfLongestSubstring(s) << endl;

    // test case 3
    cout << endl;
    s = "pwwkew";
    cout << "Test case 3: " << endl;
    cout << "String: " << s << endl;
    cout << "Length of longest unique substring: " << lengthOfLongestSubstring(s) << endl;

    return 0;
}