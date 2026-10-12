class Solution {
public:
    const int MOD=1000000007;
    int maxSum(vector<int>& nums, int k) {
        vector<int>bits(30,0);
        long long ans=0;
        for(int x:nums){
            for(int i=0;i<30;i++){
                if(x & (1<<i)){
                    bits[i]++;
                }
            }
        }
        while(k-- >0){
            long long x=0;
            for(int i=0;i<30;i++){
                if(bits[i]>0){
                    x |= 1LL<<i;
                    bits[i]--;
                }
            }
            ans=(ans+x*x)%MOD;
        }
        return ans%MOD;
    }
};