#include<bits/stdc++.h>
using namespace std;
//TC O(NlogN) and used with recursion
void merge(vector<int> &arr,int s,int e){
    int mid=s+(e-s)/2;
    int l=s;
    int r=mid+1;
    vector<int> temp;
    while(l<=mid && r<=e){
        if(arr[l]<arr[r]){
            temp.push_back(arr[l]);
            l++;
        }else{
            temp.push_back(arr[r]);
            r++;
        }
    }
    while(l<=mid){
        temp.push_back(arr[l]);
            l++;
    }
    while(r<=e){
        temp.push_back(arr[r]);
            r++;
    }
    for(int i=s;i<=e;i++){
        arr[i]=temp[i-s];
    }
}
void mergeSort(vector<int> &arr,int s,int e){
    if(s>=e)
    return;
    int mid=s+(e-s)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,e);
}
int main(){
    vector<int> arr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        arr.push_back(k);
    }
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;     
    }
}