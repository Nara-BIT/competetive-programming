class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        vector<double>temp;
        double ans=0.0;
        sort(prices.begin(),prices.end(),greater<int>());
        sort(discounts.begin(),discounts.end(),greater<int>());
        int n1=prices.size();
        int n2=discounts.size();
        int i=0,j=0;
        while(i<n1 && j<n2){
            double p=prices[i];
            double d=discounts[j];
            double st=(p*(100-d))/100;
            temp.push_back(st);
            i++;
            j++;
        }
        while(i<n1){
            temp.push_back((double)prices[i]);
            i++;
        }
        for(double d:temp){
            ans+=d;
        }
        return ans;



    }
};