#include <bits/stdc++.h>

using namespace std;

int main() {
    string text;                                                                // text to search in
    string pattern;                                                             // pattern to search for in 'text'
    while(cin >> text >> pattern){                                              // for multiple searching test cases
        bool flag = false;                                                      // to check if search is successful
        int i, j, len1 = text.length(), len2 = pattern.length();                // len1 - length of text, len2 - length of pattern
        for(i = 0; i <= len1 - len2; i ++){                                     // maximum upper bound for searching is len1 - len2
                                                                                // after that len2 cannot be contained in len1
            j = 0;
            while(j < len2 && (i + j) < len1 && text[i + j] == pattern[j])      // check if adjacent characters are same both in 'text' and 'pattern'
                j ++;
            if(j == len2){                                                      // search successful
                flag = true;
                cout << i << "\n";
                break;
            }
        }
        if(!flag)                                                               // search unsuccessful
            cout << "-1\n";
    }
    return 0;
}
