#include <bits/stdc++.h>

using namespace std;

int main() {
    string text;                                                                        // text to search in
    string pattern;                                                                     // pattern to search for in 'text'
    while(cin >> text >> pattern){                                                      // for multiple search test cases
        int i = 1, j = 0, len1 = text.length(), len2 = pattern.length();                // len1 - length of 'text', len2 - length of 'pattern'
        bool flag = false;                                                              // to check if search is successful

        /*
        * Prefix Array Building
        */

        int prefix[len2];                                                               // prefix equal to the size of 'pattern'
        prefix[0] = 0;                                                                  // 1st element always 0
        while(i < len2){
            if(pattern[i] != pattern[j]){                                               // suffix element not equal to prefix element
                while(j && prefix[j - 1] >= 0){                                         // check if it matches any element in the cases previous to it
                    j = prefix[j - 1];                                                  // make j fall back
                    if(pattern[i] == pattern[j]){                                       // if suffix element equals prefix element, move both iterators forward
                        prefix[i] = j + 1;
                        i ++;
                        j ++;
                        break;
                    }
                }
                if(!j && pattern[i] != pattern[j]){                                     // suffix matched no prefix hence start from beginning
                    prefix[i] = 0;
                    i ++;
                }
            }
            if(pattern[i] == pattern[j]){                                               // match found
                prefix[i] = j + 1;
                i ++;
                j ++;
            }
        }

        /*
        * Searching for 'pattern' in 'text'
        */

        i = 0, j = 0;
        while(i < len1){
            while(j < len2 && text[i] == pattern[j]){                                   // current 'text' element is same as the 'pattern' element
                i ++;
                j ++;
            }
            if(j == len2){                                                              // successfully found
                flag = true;
                cout << i - len2 << "\n";
                break;
            }
            if(j && j < len2){                                                          // match not found, j fall back
                j = prefix[j - 1];
            }
            else{                                                                       // j is 0 and match not found, j cannot fall back, move i forward
                i ++;
            }
        }
        if(!flag)                                                                       // unsuccessful pattern match
            cout << "-1\n";
    }
    return 0;
}

// Time Complexity : O(len1 + len2)
// Prefix table building : O(len2)
// Searching : O(len1)
// Space Complexity : O(len2) for building the prefix table.
