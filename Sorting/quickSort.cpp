#include<bits/stdc++.h>
//TC Average and Best case O(NlogN) and worst is O(N^2)
using namespace std;
int partition(vector<int> &arr,int s,int e){
    int c=0;int el=arr[s];
    for(int i=s+1;i<=e;i++){
        if(el>=arr[i])
        c++;
    }
    int elIndex=c+s;
    swap(arr[s],arr[elIndex]);
    int i=s,j=e;
    while(i<elIndex && elIndex<j){
        if(arr[i]>arr[c] && arr[c]>arr[j]){
        swap(arr[i],arr[j]);
        i++;j++;}
        else if(arr[c]>arr[i])
        i++;
        else if(arr[c]<arr[j])
        j--;

    }
    return elIndex;
}
void quickSort(vector<int> &arr,int s,int e){
    if(s>=e)
    return ;
    int p=partition(arr,s,e);
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}
int main(){
 int n;
 cin>>n;
 vector<int> ans;
 for(int i=0;i<n;i++){
    int k;
    cin>>k;
    ans.push_back(k);
 }
 quickSort(ans,0,n-1);
 for(int i=0;i<n;i++){
    cout<<ans[i]<<endl;
 }
 
 
}
