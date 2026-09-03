class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd_cnt=0;
        int even_cnt=0;
        int mn=nums1[0];
        bool isOdd=false;
        for(int num:nums1){
            if(num<mn){
                mn=num;
            }
            if(num&1){
                isOdd=true;
            }
        }
        if(mn&1){
            return true;;
        }
        
        return !isOdd;
    }
};