class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        map<pair<long long,int>,long long>mp;
        int n=capacity.size();
        long long cnt=0;
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=capacity[i];
            long long diff=sum-2*capacity[i];
            if(mp.find({diff,capacity[i]})!=mp.end()){
                cnt+=mp[{diff,capacity[i]}];
            }
            mp[{sum,capacity[i]}]++;
        }
        for(int i=0;i<n-1;i++){
            if(capacity[i]==capacity[i+1] && capacity[i+1]==0){
                cnt--;
            }
        }
        return cnt;

    }
};