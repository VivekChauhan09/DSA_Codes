#include<bits/stdc++.h>
using namespace std;

// Recursive function to find the Longest Common Subsequence (LCS) string
string lcs(string &s1, string &s2, int m, int n) {
    // Base Case: If either string becomes empty, return an empty string
    if (m == 0 || n == 0)
        return "";
    
    // If the characters at the current positions are equal,
    // include this character in the LCS and move to the next characters
    if (s1[m - 1] == s2[n - 1])
        return lcs(s1, s2, m - 1, n - 1) + s1[m - 1]; // Append the current character to the LCS
    
    // If the characters are not equal, recursively explore two possibilities:
    // 1. Exclude the last character of the first string
    // 2. Exclude the last character of the second string
    else {
        string lcs1 = lcs(s1, s2, m - 1, n);
        string lcs2 = lcs(s1, s2, m, n - 1);
        // Return the longer LCS obtained from the two possibilities
        return (lcs1.length() > lcs2.length()) ? lcs1 : lcs2;
    }
}

int main() {
    // Input two strings
    string s1, s2;
    cin >> s1 >> s2;
    
    // Get the lengths of the strings
    int m = s1.size();
    int n = s2.size();
    
    // Calculate the LCS string using the recursive function
    string lcsStr = lcs(s1, s2, m, n);
    
    // Output the LCS string
    cout << "Longest Common Subsequence (LCS) string: " << lcsStr << endl;
    
    return 0;
}
