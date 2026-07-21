class Solution {
private:
    bool f(string& s, int ind, int count,vector<vector<int>>& dp){
        if(count<0){
            return false;
        }
        if(ind==s.size()){
            return count==0;//j=count
        }
        if(dp[ind][count]!=-1){
            return dp[ind][count];
        }
        if(s[ind]=='('){
            return dp[ind][count]=f(s,ind+1,count+1,dp);
        }else if(s[ind]==')'){
            return dp[ind][count]=f(s,ind+1,count-1,dp);
        }
        if(s[ind]=='*'){
            return dp[ind][count]=f(s,ind+1,count+1,dp) || (f(s,ind+1,count-1,dp) || f(s,ind+1,count,dp));
        }
        return dp[ind][count]=false;
    }
public:
    bool checkValidString(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(s,0,0,dp);
        
    }
};