//using unorderd map
//time complexity O(1) for best and avg cases
//worst time complexity O(N) but very rare.This happens due to collisions.
//Much prefred to use
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_map<int,int> mpp;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        //storing
        mpp[arr[i]]++;
    }
    int w;
    cin>>w;
    while(w--){
        int q;
        cin>>q;
        //calling
        cout<<mpp[q]<<endl;
    }
    return 0;
}