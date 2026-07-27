class Solution {
private:
    bool isprime(int a){
        if(a<2){
            return false;
        }
        for(int i=2; i*i<=a; i++){
            if(a%i==0){
                return false;
            }
        }
        return true;
    }
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int n=nums.size();
        int ans=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(isprime(nums[i][i])){
                maxi=max(maxi,nums[i][i]);
            }
            if(isprime(nums[i][n-i-1])){
                maxi=max(maxi,nums[i][n-i-1]);
            }
        }
       return maxi; 
    }
};