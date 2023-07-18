#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

// function that calculates the longest unique substring
// using dynamic programming - tabulation
// returns - length of the longest unique substring
int longestCommonSubsequence(string text1, string text2) {
    // create a dp table of size (text1.size() + 1) * (text2.size() + 1) because we need to consider the case when one of the strings is empty
    vector<vector<int>> dp_table(text1.size() + 1, vector<int>(text2.size() + 1, 0));

    for (size_t i = 1; i <= text1.size(); ++i) {
        for (size_t j = 1; j <= text2.size(); ++j) {
            int max_value = max(dp_table[i-1][j], dp_table[i][j-1]);
            
            // if the characters are the same, then add 1 to the previous diagonal value
            if (text1[i-1] == text2[j-1])
                dp_table[i][j] = dp_table[i-1][j-1] + 1;
            else
            // else take the max of [i-1][j] and [i][j-1]
                dp_table[i][j] = max_value;
        }
    }

    // return the last element of the dp table
    return dp_table[text1.size()][text2.size()];
}


int main() {
    string text1, text2;

    // test case 1
    text1 = "abcde";
    text2 = "ace";
    cout << "Test case 1: " << endl;
    cout << "Text 1: " << text1 << endl;
    cout << "Text 2: " << text2 << endl;
    cout << "Length of the longest common subsequence: " << longestCommonSubsequence(text1, text2) << endl;

    // test case 2
    text1 = "abc";
    text2 = "abc";
    cout << endl;
    cout << "Test case 2: " << endl;
    cout << "Text 1: " << text1 << endl;
    cout << "Text 2: " << text2 << endl;
    cout << "Length of the longest common subsequence: " << longestCommonSubsequence(text1, text2) << endl;

    // test case 3
    text1 = "abc";
    text2 = "def";
    cout << endl;
    cout << "Test case 3: " << endl;
    cout << "Text 1: " << text1 << endl;
    cout << "Text 2: " << text2 << endl;
    cout << "Length of the longest common subsequence: " << longestCommonSubsequence(text1, text2) << endl;

    return 0;
}