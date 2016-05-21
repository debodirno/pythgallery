/*
A possible derangement of characters in a string
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    string output(s);

    int i = 0, j = i + 1, len = s.length();

    while(i < len){
        if(output[i] == s[i]) {                             // only change if the current character is same as the character in the same position in the original string
            while(j < len && output[i] == output[j]){       // find a character which is different from the current one
                j ++;
            }

            if(j >= len){                                   // start the character to replace the current character again from the beginning
                j = 0;
                i --;
                continue;
            }

            if(output[i] != output[j] && j < len) {         // swap the characters (pairwise swap)
                swap(output[i], output[j]);
                j ++;
            }
        }
        i ++;
    }

    for(i = 0; i < len; i ++){                              // also not possible if the occurance of any particular character in the string is greater than half the length of the string
        if(s[i] == output[i]){
            cout << "Not possible\n";
            return 0;
        }
    }

    cout << output << "\n";

    return 0;
}
