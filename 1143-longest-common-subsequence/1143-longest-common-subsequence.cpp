class Solution {
private:
    int f(string&s, string&t, int i, int j, vector<vector<int>>& dp){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==t[j]){
            return dp[i][j]=1+f(s,t,i-1,j-1,dp);
        }
        return dp[i][j]=max(f(s,t,i-1,j,dp),f(s,t,i,j-1,dp));

    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(text1,text2,n-1,m-1,dp);
        
    }
};