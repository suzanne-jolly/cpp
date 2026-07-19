class Solution {
private:
    bool f(vector<vector<int>>& dp,int ind, int target,vector<int>& arr){
        if(ind==0){
            return arr[0]==target;
        }
        if(target==0){
            return true;
        }
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        bool not_take=f(dp,ind-1,target,arr);
        bool take=false;
        if(target-arr[ind]>=0){
            take=f(dp,ind-1,target-arr[ind],arr);
            
        }
        return dp[ind][target]=take || not_take;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int target=0;
        for(auto it: nums){
            target+=it;
        }
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        if(target%2!=0){
            return false;
        }
        return f(dp,n-1,target/2,nums);
        
    }
};