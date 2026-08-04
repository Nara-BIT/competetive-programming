class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        map<int,int>freq;
        map<long long,int>width;
        int ans=0;
        for(int it:planks){
            freq[it]++;
            width[it]++;
            ans=max(freq[it],ans);

        }
        for(auto it1:freq){
            for(auto it2:freq){
                int x=it1.first;
                int y=it2.first;
                long long sum=1LL*x+y;
                if(x<y){
                    width[sum]+=min(it1.second,it2.second);
                }
                else if(x==y){
                    width[sum]+=it1.second/2;
                }
            }
        }
        for(auto it:width){
            ans=max(ans,it.second);
        }
        return ans;
    }
};