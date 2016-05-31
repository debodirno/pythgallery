#include <bits/stdc++.h>

using namespace std;

int main() {
    int sizeArray, midElem;
    cout << "Enter the size of array : ";
    cin >> sizeArray;

    int arr[sizeArray], counter, key;

    cout << "Enter the elements of the array : \n";
    for(counter = 0; counter < sizeArray; counter ++)
        cin >> arr[counter];

    cout << "Enter the element to search for : \n";
    cin >> key;

    // to find the pivot

    int lo = 0, hi = sizeArray - 1, mid;
    bool flag = false;

    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(arr[lo] <= arr[mid]){                        // 1st half is sorted, hence pivot must be in the 2nd half
            lo = mid + 1;
        }
        else{                                           // 2nd half is sorted, hence pivot must be in the 1st half
            hi = mid - 1;
        }
    }

    cout << "The array has been rotated by " << mid + 1 << " positions to the right.\n";

    // to find the element in the array

    lo = 0, hi = sizeArray - 1, mid;
    flag = false;

    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(arr[mid] == key){
            flag = true;
            break;
        }
        if(arr[lo] <= arr[mid]){                            // 1st half sorted
            if(arr[lo] <= key && key < arr[mid])            // found in 1st half
                hi = mid - 1;
            else                                            // next time search in 2nd half
                lo = mid + 1;
        }
        else{                                               // 2nd half sorted
            if(arr[mid] < key && key <= arr[hi])            // found in the 2nd half
                lo = mid + 1;
            else                                            // next time search in 1st half
                hi = mid - 1;
        }
    }

    if(flag){
        cout << key << " is found in position : " << mid + 1 << ".\n";
    }
    else{
        cout << key << " not found in the array.\n";
    }
    return 0;
}
