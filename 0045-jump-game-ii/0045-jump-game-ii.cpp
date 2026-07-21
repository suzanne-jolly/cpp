class Solution {
private:
    int f(int ind, const vector<int>& nums, vector<int>& dp) {
        int n = nums.size();
        
        // Base case: If we've reached or passed the last index, 0 jumps are needed
        if (ind >= n - 1) {
            return 0; 
        }
        
        if (dp[ind] != -1) {
            return dp[ind];
        }
        
        // Use 1e9 (1 billion) instead of INT_MAX to prevent overflow when adding 1 later
        int mini = 1e9; 
        
        // Try every possible jump length from 1 up to nums[ind]
        for (int i = 1; i <= nums[ind]; i++) {
            // The cost is 1 jump + the minimum jumps from where we land
            mini = min(mini, 1 + f(ind + i, nums, dp));
        }
        
        return dp[ind] = mini;
    }
    
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        // We only need a 1D array to track the min jumps from any given index
        vector<int> dp(n, -1);
        
        return f(0, nums, dp);
    }
};