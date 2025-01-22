#include <iostream>
using namespace std;

int checkNumber(int arr[], int left, int right, int key){
    while(left <= right){
        int mid = (left + right) / 2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
    }
    int key;
    cin >> key;
    int ans = checkNumber(arr, 0, n - 1, key);
    if(ans >= 0){
        cout << ans;
    }
    else{
        cout << "NO OCCURRENCES";
    }
}
