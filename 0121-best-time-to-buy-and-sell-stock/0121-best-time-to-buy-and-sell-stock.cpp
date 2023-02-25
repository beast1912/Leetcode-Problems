class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int minimum_price = INT_MAX;
        
        for(int price = 0; price < prices.size(); price++)
        {
            minimum_price = min(minimum_price, prices[price]);
            max_profit = max(max_profit, prices[price] - minimum_price);
                
        }
        return max_profit;
    }
};