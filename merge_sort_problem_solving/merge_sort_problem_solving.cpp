#include<bits/stdc++.h>
using namespace std;
int n,k;
bool isExist=false;

vector<int>mergeSort(vector<int>arr){
    // CHECK THE LENGTH OF ARR.
    if(arr.size() <= 1)
        return arr;
    int mid= arr.size() / 2;
    vector<int>left;
    vector<int>right;
    for(int i=0;i<mid;i++){
        left.push_back(arr[i]);
    };
    for(int i=mid;i<arr.size();i++){
        right.push_back(arr[i]);
    };
    vector<int>sorted_left=mergeSort(left);
    vector<int>sorted_right=mergeSort(right);

    vector<int>sorted_arr;
    int il=0,ir=0;
    while(il<sorted_left.size() && ir<sorted_right.size()){
        if(sorted_left[il] < sorted_right[ir]){
            sorted_arr.push_back(sorted_left[il]);
            il++;
        }else{
            sorted_arr.push_back(sorted_right[ir]);
            ir++;
        };
    };
    //
    while(il < sorted_left.size()){
        sorted_arr.push_back(sorted_left[il]);
        il++;
    };
    while(ir < sorted_right.size()){
        sorted_arr.push_back(sorted_right[ir]);
        ir++;
    };
    if(sorted_arr.size() == n){
        int c=0;
        int i=0, j=n-1;
        while(i<=j){
            // cout << sorted_arr[i] << " and " << sorted_arr[j] << "\n";
            if(sorted_arr[i]==k){
                c++;
            };
            if(sorted_arr[j] == k){
                c++;
            };
            if(i==j)
                c--;
            // cout << "c: " << c << "\n";
            if(c>1){
                isExist=true;
                break;
            };
            i++;
            j--;
        }
    };
    return sorted_arr;
};

int main()
{
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cin >> k;
    vector<int>ans=mergeSort(arr);
    if(isExist==true)
        cout << "YES" <<"\n";
    else
        cout << "NO" << "\n";
    return 0;
};
