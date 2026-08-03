#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<pair<ll,ll>,null_type,
    less<pair<ll,ll>>,
    rb_tree_tag,
    tree_order_statistics_node_update
>ordered_multiset;
class PBDS_multiset{
    ordered_multiset st;
    ll id=0;
public:
    void insert(ll x){
        st.insert({x,id++});
    }
    void erase(ll x){
        auto it=st.lower_bound({x,-1});
        if(it!=st.end() && it->first==x){
            st.erase(it);
        }
    }
    ll countLess(ll x){
        return st.order_of_key({x,-1});
    }
    ll countLessEqual(ll x){
        return st.order_of_key({x,2e18});
    }
};

class Solution {
public:
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        int cnt_even=0;
        int cnt_odd=0;
        int n=nums.size();
        int counter=0;
        vector<ll>po(n+1,0);
        vector<ll>pe(n+1,0);
        PBDS_multiset m;
        //similar to:
        //subarray sum equals K, number of good pairs/bad pairs(O(n))
        ll count=0;
        int k=0;
        for(int i=1;i<=n;i++){
            if(nums[i-1]&1){
                cnt_odd++;
            }
            else{
                cnt_even++;
            }
            po[i]=cnt_odd;
            pe[i]=cnt_even;
        }
        for(int i=1;i<=n;i++){
            while(k<i && po[k]<po[i]){
                ll LHS=a*po[k]-b*pe[k];
                m.insert(LHS);
                k++;
                
            }
            ll RHS=a*po[i]-b*pe[i];
            ll cnt=m.countLessEqual(RHS);
            count=count+cnt;
            
        }
        return count;
        
    }
    /*int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int cnt_even=0;
        int cnt_odd=0;
        int n=nums.size();
        int counter=0;
        for(int i=0;i<n;i++){
            cnt_odd=0;
            cnt_even=0;
            for(int j=i;j<n;j++){
                if(nums[j]&1){
                    cnt_odd++;
                }
                else{
                    cnt_even++;
                }
                int x=cnt_even,y=cnt_odd;
                if(y>0 && x*b<=y*a){
                    counter++;
                }

            }
        }
        return counter;
    }*/
};