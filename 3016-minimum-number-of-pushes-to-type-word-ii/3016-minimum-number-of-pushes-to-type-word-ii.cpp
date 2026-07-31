class Solution {
public:
    int minimumPushes(string word) {
        map<char,int>freq;
        vector<int>mpp(26);
        for(char c:word){
            freq[c]++;
            mpp[c-'a']++;
        }
        int n=freq.size();
        int cnt=0;
        if(n<=8){
            for(auto it:freq){
                cnt+=(it.second);
            }
            return cnt;
        }
        
        cnt=0;
        sort(mpp.begin(),mpp.end());
        for(int i=25;i>=0 && mpp[i]>0;i--){
            cnt+=mpp[i]*(((25-i)/8)+1);
        }
        return cnt;
    }
};