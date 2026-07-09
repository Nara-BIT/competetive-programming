class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fb=0;
        int tb=0;
        for(int it:bills){
            if(it==5){
                fb++;
            }
            else if(it==10){
                if(fb>0){
                    tb++;
                    fb--;
                }
                else{
                    return false;
                }
            }
            else if(it==20){
                if(fb>0&&tb>0){
                    fb--;
                    tb--;
                }
                else if(fb>=3){
                    fb-=3;
                }
                else
                    return false;
            }
        }
        return true;
    }
};