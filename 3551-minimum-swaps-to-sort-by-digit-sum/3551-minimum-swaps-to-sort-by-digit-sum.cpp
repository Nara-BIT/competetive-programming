class Solution {
public:
    int cal_sum(int num){
        string s=to_string(num);
        int ans=0;
        for(char c:s)
            ans+=(c-'0');
        return ans;
    }
    int minSwaps(vector<int>& nums) {
        vector<pair<int,pair<int,int>>>chk;
        int i,j;
        int n=nums.size();
        map<int,int>ind;
        for(i=0;i<n;i++){
            int curr=cal_sum(nums[i]);
            chk.push_back({curr,{nums[i],i}});
            ind[nums[i]]=i;
        }
        sort(chk.begin(),chk.end());
        int swaps=0;
        vector<int>visited(n,0);
        for(i=0;i<n;i++){
        
            if(visited[i]||chk[i].second.second==i)
                continue;
            int temp=0;

            j=i;

            while(!visited[j]){
                visited[j]=1;
                j=chk[j].second.second;
                temp+=1;
            }
            if(temp>0)
                swaps+=temp-1;
        }
        return swaps;
    }
};