class Solution {
public:
    long long countCommas(long long n) {
        vector<long long>nums;
        long long res=1.0;
        long long temp;
        string s=to_string(n);
        if(s.size()<=3){
            return 0;
        }
        if(n<pow(10,6) || s.size()<7){
            
            long long m=1000;
            return n-m+1; 
        }
        temp=(long long)pow(10,3);
        int j=3;
        for(int i=0;i<5;i++){
            res=res*temp;
            nums.push_back(res);
        }
        long long mark=0;
        long long comms=0;
        long long inc=0;
        long long inc3=0;
        long long p=1000;
        for(int i=0;i<5;i++){
            if(n<nums[i]){
                break;
            }
            mark=nums[i];
            
            comms=comms+(999*p*(inc));
            inc++;
           
            p*=1000;
        }
        comms/=1000;
        
        
        return (n-mark+1)*(inc)+comms;
        
        
        
    }
};