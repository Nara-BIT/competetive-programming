class Solution {
public:
    int right(string s,int l,vector<int>&first, vector<int>& last){
        int r=last[s[l]-'a'];
        for(int i=l;i<=r;i++){
            int c=s[i]-'a';
            if(first[c]<l){
                return -1;
            }
            r=max(r,last[c]);
        }
        return r;
    }
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();
        vector<int>first(26,n);
        vector<int>last(26,-1);
        for(int i=0;i<n;i++){
            int c=s[i]-'a';
            first[c]=min(first[c],i);
            last[c]=i;
        }
        vector<pair<int,int>>intervals;
        for(int c=0;c<26;c++){
            if(first[c]==n){
                continue;
            }
            int l=first[c];
            int r=right(s,l,first,last);
            if(r!=-1){
                intervals.push_back({l,r});
            }
        }
        sort(intervals.begin(),intervals.end(),[](const auto& a,const auto& b){
            if(a.second!=b.second){
                return a.second<b.second;
            }
            return a.first>b.first;
        });
        vector<string>ans;
        int end=-1;
        for(auto& [L,R]:intervals){
            if(L>end){
                ans.push_back(
                    s.substr(L,R-L+1)
                );
                end=R;
            }
        }
        return ans;
    }
};