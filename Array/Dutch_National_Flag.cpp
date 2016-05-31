#include <bits/stdc++.h>

using namespace std;

int main() {
    int sizeArray, midElem;
    cout << "Enter the size of array : ";
    cin >> sizeArray;

    int arr[sizeArray], counter;

    cout << "Enter the elements of the array : \n";
    for(counter = 0; counter < sizeArray; counter ++)
        cin >> arr[counter];

    cout << "Enter the partition element : ";
    cin >> midElem;

    int lo = 0, hi = sizeArray - 1;                         // lo to track the elements lesser than key, hi to track the elements greater than key
    int key = arr[midElem], currentElem = 0;

    while(currentElem <= hi){
        if(arr[currentElem] < key){                         // must be moved to the 1st partition
            swap(arr[currentElem], arr[lo]);
            currentElem ++;
            lo ++;                                          // always lo <= currentElem
        }

        else if(arr[currentElem] == key){                   // do not do anything if the current element is equal to the key
            currentElem ++;
        }

        else{
            swap(arr[currentElem], arr[hi]);                // move the heavier element to the 3rd partition
            hi --;                                          // we do not increment currentElem here (Note)
                                                            // this is because the swapped element in the index of currentElem may be greater than key
        }
    }

    cout << "Three way partitioned : \n";
    for(counter = 0; counter < sizeArray; counter ++)
        cout << arr[counter] << " ";
    cout << "\n";
    return 0;
}
