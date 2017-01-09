class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        vector<vector<int>> result;  
        int length = num.size();  
        if (length < 3 )  
            return result;  
        sort(num.begin(),num.end());
        for(int i = 0; i < num.size() ; ++ i)
        {
            if(i > 0 && num[i] == num[i - 1])
                continue;
            int l = i + 1, r = num.size() - 1;
            while(l<r)
            {
                if(num[l] + num[r] == 0 - num[i])
                {
                    result.push_back( {num[i], num[l], num[r]} );
                    while(++ l < r && num[l] == num[l - 1]); // 跳过重复元素
                    while(l < -- r && num[r] == num[r + 1]); // 跳过重复元素
                }
                else if(num[l] + num[r] > 0 - num[i])
                {
                    r--;
                }
                else
                    l++;
            }
        }
        return result;
    }
};
