class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end(), greater<int>());
        sort(discounts.begin(),discounts.end(), greater<int>());
        double sum = 0;
        int i = 0;
        int j = 0;
        while(j<discounts.size() && i<prices.size()){
            double dis = (prices[i] * (100 - discounts[j])) / 100.0;
            sum+=dis;
            i++;
            j++;
        }
        while(i<prices.size()){
            sum+=prices[i];
            i++;
        }
        return sum;
    }
};