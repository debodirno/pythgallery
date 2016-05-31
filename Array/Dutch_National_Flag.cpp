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

    int lo = 0, hi = sizeArray - 1;
    int key = arr[midElem], currentElem = 0;

    while(currentElem <= hi){
        if(arr[currentElem] < key){
            swap(arr[currentElem], arr[lo]);
            currentElem ++;
            lo ++;
        }

        else if(arr[currentElem] == key){
            currentElem ++;
        }

        else{
            swap(arr[currentElem], arr[hi]);
            hi --;
        }
    }

    cout << "Three way partitioned : \n";
    for(counter = 0; counter < sizeArray; counter ++)
        cout << arr[counter] << " ";
    cout << "\n";
    return 0;
}
