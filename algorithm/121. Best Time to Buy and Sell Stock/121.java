class Solution {
    public int maxProfit(int[] prices) {
        int maxp = 0, minprice = Integer.MAX_VALUE;
        for(int i = 0; i < prices.length; i++)
        {
            minprice = Math.min(minprice, prices[i]);
            maxp = Math.max(maxp, prices[i] - minprice);
        }
        return maxp;
    }
}
