#include <bits/stdc++.h>

using namespace std;

int arr[20000];

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr, arr+n);
   
    int avg = sum / n;
   

   
    int ans = 0;
    for(int i=0; i<n; i++){
        ans += abs(avg - arr[i]);
    }
   

   
    int low = 0;
    int high = n-1;
    int mid;
    int idx;

   
    while(low <= high){
        mid = (low + high) / 2;
        int tmp = 0;
        for(int i=0; i<n; i++){
            tmp += abs(arr[mid] - arr[i]);
        }

        if(ans >= tmp){
            sum = tmp;
            high = mid - 1;
            idx = mid;
        }else{
            low = mid + 1;
        }
        cout << arr[idx];
       
        return 0;
    }
   
}