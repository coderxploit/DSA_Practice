#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int cal_score(string str){
    int n = str.size();
    bool table[n][n];
    memset(table, 0, sizeof(table));
    int maxLength = 1;
    for (int i = 0; i < n; ++i)
        table[i][i] = true;

    int start = 0;
 
    for (int i = 0; i < n - 1; ++i) {
 
        if (str[i] == str[i + 1]) {
 
            table[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    for (int k = 3; k <= n; ++k) {
 
        
        for (int i = 0; i < n - k + 1; ++i) {
 
            
            int j = i + k - 1;
 
            
            if (table[i + 1][j - 1] && str[i] == str[j]) {

                table[i][j] = true;
 
                
                if (k > maxLength) {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }
 
    // Return length of LPS
    return maxLength;
}

int lcs(vector<int>X, vector<int> Y, int m, int n)
{
    vector<int> prev(n + 1, 0), curr(n + 1, 0);
    int i, j;
 
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                prev[j] = 0;
 
            else if (X[i - 1] == Y[j - 1])
                curr[j] = prev[j - 1] + 1;
 
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
       
        prev = curr;
    }
 
    /* L[m][n] contains length of LCS for X[0..n-1]
            and Y[0..m-1] */
    return prev[n];
}

int minIns(vector<int>score){
    int n = score.size();
    vector<int> rev = score;
    reverse(rev.begin(), rev.end());
    return (n - lcs(score, rev, n, n));
}

int MNPS(int N, vector<string> arr){
    vector<int>score;
    for(auto x : arr){
        score.push_back(cal_score(x));
    }
    return minIns(score);
}

int main(){
    int N = 3;
    vector<string> str = {"a","b", "c","dd", "daad", "ebcbe"};
    cout<< MNPS(N,str);
}