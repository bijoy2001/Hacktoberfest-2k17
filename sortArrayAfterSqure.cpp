#include<iostream>
using namespace std;

int main() {
    int i,j,n,p=0;
    cin>>n;
    int arr[n],ar1[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    while(arr[p]<0)
        p++;
    i=p-1;j=p;p=0;
    
    while(i>=0 && j<n) {
        if((arr[i]*arr[i]) < (arr[j]*arr[j])) {
            ar1[p] = arr[i]*arr[i];
            i--;
        }
        else {
            ar1[p] = arr[j]*arr[j];
            j++;
        }
        p++;
    }
    while(i>=0) {
        ar1[p] = arr[i]*arr[i];
        i--;
        p++;
    }
    while(j<n) {
        ar1[p] = arr[j]*arr[j];
        j++;
        p++;
    }
    for(i=0;i<n;i++)
        cout<<ar1[i]<<" ";
    cout<<endl;
    return 0;
}
