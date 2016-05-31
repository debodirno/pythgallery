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

    int countL = 0, countU = 0;
    int lo = 0, hi = sizeArray - 1, mid;
    bool flag = false;

    // for finding the lower bound of the key

    while(lo <= hi){
        mid = (hi + lo) / 2;

        if(arr[mid] < key && arr[mid + 1] >= key){              // next element is the first occurrence of key
            flag = true;
            mid = mid + 1;
            break;
        }
        if(arr[mid] == key && (arr[mid - 1] < key || (mid - 1) < 0)){       // current element is the first occurrence of key
            flag = true;
            break;
        }

        if(arr[mid] >= key){                                    // find in the first half of the array
            hi = mid - 1;
        }
        else if(arr[mid] < key){                                // find in the second half of the array
            lo = mid + 1;
        }
    }
    if(flag){
        countL = mid;
        lo = mid, hi = sizeArray - 1;

        // for finding the upper bound of the key

        while(lo <= hi){
            mid = (hi + lo) / 2;

            if(arr[mid] > key && arr[mid - 1] <= key){              // last element was the last occurrence of key
                mid = mid - 1;
                break;
            }
            if(arr[mid] == key && (arr[mid + 1] > key || (mid + 1) > sizeArray)){           // current element is the last occurrence of key
                break;
            }

            if(arr[mid] <= key){                                    // find in the second half of the array
                lo = mid + 1;
            }
            else if(arr[mid] > key){                                // find in the first half of the array
                hi = mid - 1;
            }
        }
        countU = mid;
        cout << key << " is found " << countU - countL + 1 << " times in the array.\n";
    }
    else{
        cout << "Not found\n";
    }
    return 0;
}
