//using orderd map
//time complexity O(logN) for all cases best,avg,worst
//stored in orderd ascending way always
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int,int> mpp;
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