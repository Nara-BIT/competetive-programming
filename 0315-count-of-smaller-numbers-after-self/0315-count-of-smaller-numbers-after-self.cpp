#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pair<long long,int>,null_type,less<pair<long long, int>>,rb_tree_tag
,tree_order_statistics_node_update>order;


class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>ans;
        order s;
        int n=nums.size();
        reverse(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            pair<long long,int>target={1LL*nums[i],INT_MIN};
            int cnt=s.order_of_key(target);
            ans.push_back(cnt);
            s.insert({1LL*nums[i],i});

        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};