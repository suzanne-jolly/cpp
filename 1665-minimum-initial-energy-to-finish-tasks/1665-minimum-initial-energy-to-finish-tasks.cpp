class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[&](vector<int>& a,vector<int>& b){
            return (a[1]-a[0])>(b[1]-b[0]);
        });
        long long ans=0;
        long long energy=0;

        for(int i=0; i<tasks.size(); i++){
            int actual=tasks[i][0];
            int mini=tasks[i][1];

            if(energy<mini){
                ans+=(mini-energy);
                energy=mini;
            }
            energy-=actual;
        }
        return (int)ans;


        
    }
};