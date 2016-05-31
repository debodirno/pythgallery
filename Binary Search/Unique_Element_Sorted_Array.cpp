#include <bits/stdc++.h>

using namespace std;

int main() {
    int sizeArray;
    cout << "Enter the size of array : ";
    cin >> sizeArray;

    int arr[sizeArray], counter, key;

    cout << "Enter the elements of the array : \n";
    for(counter = 0; counter < sizeArray; counter ++)
        cin >> arr[counter];

    // to find the unique element in an array which is sorted and the other elements occur in pairs(consecutive)
    // so normally, 0th element and 1st element are pairs, 2nd element and 3rd element are pairs, and so on.
    // thus the middle element and the preceding/ succeeding element must be same if unique element does not lie in the first half and other conditions

    int lo = 0, hi = sizeArray - 1, mid;
    bool flag = false;

    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1])            // unique element(trivial)
            break;
        if(mid % 2 != 0){                                                   // middle element index is odd
            if(arr[mid] == arr[mid - 1])                                    // middle element and the preceding element are same, hence the 2nd half contains he unique element
                lo = mid + 1;
            else                                                            // middle element and the preceding element are not same, hence the 1st half contains the unique element
                hi = mid - 1;
        }
        else{                                                               // middle element index is even
            if(arr[mid] == arr[mid + 1])                                    // middle element and the succeeding element are same, hence the 2nd half contains he unique element
                lo = mid + 1;
            else                                                            // middle element and the succeeding element are not same, hence the 1st half contains the unique element
                hi = mid - 1;
        }
    }

    cout << arr[mid] << " is a unique element in the array.\n";

    return 0;
}
