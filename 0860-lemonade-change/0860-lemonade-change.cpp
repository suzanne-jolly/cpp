class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int>m;
        int f=0;
        int t=0;
        int tw=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                f++;
            }else if(bills[i]==10){
                if(f>=1){
                    f--;
                    t++;
                }else{
                    return false;
                }


            }else{
                if(t>=1 && f>=1){
                    t--;
                    f--;
                    tw++;
                }else if(f>=3){
                    f-=3;
                    tw++;
                }else{
                    return false;
                }
            }
        }
               
               
        return true;
        
    }
};