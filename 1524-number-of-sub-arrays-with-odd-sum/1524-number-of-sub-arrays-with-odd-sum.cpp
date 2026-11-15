class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int MOD=pow(10,9)+7;
        int total=0;
        int odd=0;
        int even=1;
        int presum=0;

        for(int elem: arr){
            presum+=elem;
            if(presum&1){
                
                total=(total+even)%MOD;
                odd++;
            }
            else{
                even++;
                total=(total+odd)%MOD;
            }
        }
        return total;
    }
};