#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<pair<long long,int>,null_type,less<pair<long long,int>>,rb_tree_tag,tree_order_statistics_node_update>ordered_multiset;
class Solution {
public:
    
    int reversePairs(vector<int>& nums) {
        ordered_multiset s;
        int n=nums.size();
        int cnt=0;
        int total_prev=0;
        for(int i=0;i<n;i++){
            
            total_prev=s.size();
            pair<long long,int>target= {2LL*nums[i]+1, INT_MIN};
            int less_key=s.order_of_key(target);
            cnt+=(total_prev-less_key);
            s.insert({1LL*nums[i],i});
        }
        return cnt;
    }
};