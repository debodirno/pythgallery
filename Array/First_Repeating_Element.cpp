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

    map<int, int> HashMap;
    int minimum = INT_MAX, minimumIndex = INT_MAX;
    for(counter = 0; counter < sizeArray; counter ++){
        if(minimum > HashMap[arr[counter]] && HashMap[arr[counter]] > 0)
            minimum = HashMap[arr[counter]], minimumIndex = arr[counter];
        HashMap[arr[counter]] = counter + 1;
    }
    cout << minimumIndex << " is the first repeating element in the array\n";
    return 0;
}
