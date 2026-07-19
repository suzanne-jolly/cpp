class Solution {
private:
    int f(int ind, int sum, vector<int>&nums,vector<vector<int>>& dp){
        if(ind==0){
            if(sum==0 &&nums[0]==0){
                return 2;
            }
            if(sum==0 || nums[0]==sum){
                return 1;
            }
            return 0;
        }
        if(dp[ind][sum]!=-1){
            return dp[ind][sum];
        }
        int take=0;
        if(nums[ind]<=sum){
            take=f(ind-1,sum-nums[ind],nums,dp);
        }
        int not_take=f(ind-1,sum,nums,dp);
        return dp[ind][sum]=take+not_take;
        

    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totsum=0;
        for(auto it: nums){
            totsum+=it;
        }
        if(totsum-target<0 ||(totsum-target)%2){
            return 0;
        }
        int s2=(totsum-target)/2;
        vector<vector<int>> dp(n,vector<int>(s2+1,-1));
        return f(n-1,s2,nums,dp);
        
    }
};