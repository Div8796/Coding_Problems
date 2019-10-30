//Problem: Given a sequence, find the length of the longest palindromic subsequence in it. 
//Input: GEEKSFORGEEKS
//Output: 5

#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i=a; i<b; i++)
#define FOREQ(i, a, b) for(int i=a; i<=b; i++)

//Approach 1: Using recursion
int lps_rec(string s, int i, int j){
	if(i == j)
		return 1;
	if(i+1 == j && s[i] == s[j])
		return 2;
	if(s[i] == s[j])
		return lps_rec(s, i+1, j-1) + 2;
	else
		return max(lps_rec(s, i+1, j), lps_rec(s, i, j-1));
	
}

//Approach 2: Using Dynamic Programming
int lps_dp(string s) {
        int len = s.length();
        int dp[len][len];
        
	FOR(i, 0, len)
            dp[i][i] = 1;
        
	FOREQ(l, 2, len){			
            FOR(i, 0, len-l+1){
                int j = i+l-1;
                if(l==2 && s[i] == s[j])
                    dp[i][j] = 2;
                else if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1] + 2;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
            }
        }
        return dp[0][len-1];
}

int main(){
	string s;
	int len = 0;

	cin >> s;
	len = s.length();

	cout << lps_rec(s, 0, len-1) << endl;
	cout << lps_dp(s) << endl;
	return 0;
}
