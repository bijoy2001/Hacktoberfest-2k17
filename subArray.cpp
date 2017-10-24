#include<iostream>
using namespace std;
 

int maxsum(int a[], int n)
{
   int rmax = a[0];
   int cmax = a[0];
 
   for (int i = 1; i < n; i++) {
        cmax = max(a[i], cmax+a[i]);
        rmax = max(rmax, cmax);
    }
   return rmax;
}
 
 
int main() {
    int lp;
    cin >>lp;
    while(lp--) {
        int i,n;
        cin >>n;
        int arr[n];               
        
        for(i=0;i<n;i++)  {
            cin >> arr[i];
                
        }
        
        cout << maxsum(arr, n) << endl;
    }
    return 0;
}
