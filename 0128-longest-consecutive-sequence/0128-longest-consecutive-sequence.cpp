class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>cnt;
        int n=nums.size();
        int count=0,itr=1;
        int i,j;
        if(n==1)
            return 1;
        for(i=0;i<n;i++){
            cnt[nums[i]]=1;
        }
        j=0;
        vector<int>csRes(n);
        for(auto h:cnt){
            csRes[j++]=h.first;
        }
        for(i=1;i<n;i++){
            if(csRes[i]-csRes[i-1]==1)
                itr++;
            else
                itr=1;
            count=max(count,itr);
        }
        return count;
    }
};