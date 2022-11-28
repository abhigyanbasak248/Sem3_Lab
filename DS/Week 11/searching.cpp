#include <iostream>
using namespace std;

void linear(int arr[],int n,int t) {
    for (int i=0;i<n;i++) {
        if (arr[i]==t) {
            cout<<"Element found at position "<<(i+1)<<endl;
            return;
        }
    }
    cout<<"Element not found"<<endl;
}

void binary(int arr[],int l,int r,int t) {
    if (r>=1) {
        int mid=l+(r-l)/2;
        if (t==arr[mid])
            cout<<"Element found at "<<(mid+1)<<endl;
        else if (t>arr[mid]) {
            binary(arr,mid+1,r,t); 
        }
        else {
            binary(arr,l,mid-1,t);
        }
    }
}

int main() {
    cout<<"Enter number of elements in array"<<endl;
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter elements:"<<endl;
    for (int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter element to search for: "<<endl;
    int t;
    cin>>t;
    int ch;
    cout<<"1.Linear Search\n2.Binary Search"<<endl;
    cin>>ch;
    switch(ch) {
        case 1:
            linear(arr,n,t);
            break;
        case 2:
            binary(arr,0,n,t);
            break;
    }
}