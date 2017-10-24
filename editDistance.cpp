#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int mini(int a,int b,int c) {
    return min(min(a,b), c);
}

int editDistance(string s1,string s2,int m,int n) {
    int dp[m+1][n+1];

    for (int i=0; i<=m; i++) {
        for (int j=0; j<=n; j++) {
        
            if (i==0)
                dp[i][j] = j;  
 
 
            else if (j==0)
                dp[i][j] = i; 
 
 
            else if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
                
            else
                dp[i][j] = 1 + mini(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]); 
        }
    }
 
    return dp[m][n];
}


int main() {
    int t;
    cin>> t;
    while (t--) {
        string s1,s2;
        cin>>s1>>s2;
        cout<<editDistance(s1,s2,s1.length(),s2.length())<<endl;
    }
    //cout <<s1<<" "<<s2<<endl;
    return 0;
}
