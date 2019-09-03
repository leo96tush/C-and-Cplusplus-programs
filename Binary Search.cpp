#include <bits/stdc++.h>
using namespace std;

int binary_search(int arr[] , int low , int high , int search){
    if( low > high ){
        return -1;
    }
    else{
        int mid = low + (high - low)/2 ;
        if(arr[mid]==search){
            return mid;
        }
        
        else if(arr[mid]>search){
            return binary_search(arr,0,mid-1,search);
        }
        else{
            return binary_search(arr,mid+1,high,search);
        }
    }
    return -1;
}


int main() {
	int num;
	cin >> num ;
	int arr[100];
	for(int i=0 ; i<num ; i++){
	    int a;
	    cin >> a;
	    arr[i] = a;
	}
	
	int search;
	cin >> search;
	cout << binary_search(arr,0,num-1,search);
	
	return 0;
}
