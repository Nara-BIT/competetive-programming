class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int balance=0;
        map<int,int>freq;
        freq[0]=-1;
        int n=nums.size();
        int len=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                balance++;
            }
            else{
                balance--;
            }
            if(balance==0){
                len=max(len,i+1);
            }
            if(freq.count(balance)){
                len=max(len,i-freq[balance]);
            }
            if(!freq.count(balance))
                freq[balance]=i;
        }
        return len;
    }
};