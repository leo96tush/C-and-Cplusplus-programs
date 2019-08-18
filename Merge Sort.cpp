#include <bits/stdc++.h>
using namespace std;

void merge(int arr[100] , int l , int r){
    vector<int> L;
    vector<int> R;
    int m = (l+r)/2;
    for(int i=0 ; i<m-l+1 ; i++){
        L.push_back(arr[l+i]);
    }
    
    for(int j=0 ; j<r-m ; j++){
        R.push_back(arr[m+j+1]);
    }
    
    int i=0,j=0,k=l;
    
    while(i<(m-l+1) && j<(r-m)){
        if(L[i]<=R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while(i<(m-l+1)){
        arr[k]=L[i];
        i++;
        k++;
    }
    
    while(j<(r-m)){
        arr[k]=R[j];
        j++;
        k++;
    }
    
}

void mergesort(int arr[100], int l , int r){
    if(l<r){
        int m = l+(r-l)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        /*for(int i=l ; i<=r ; i++){
            cout << arr[i] << " ";
        }*/
        cout << endl;
        merge(arr,l,r);    
    }
}




int main() {
    int arr[100] = {4,5,3,4,5,1,2,3,4};
    mergesort(arr,0,8);
    for(int i=0 ; i<9 ; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
