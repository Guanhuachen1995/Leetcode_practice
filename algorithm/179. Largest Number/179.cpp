class Solution {
public:
    
    
    string largestNumber(vector<int>& nums) {
        string res;
        vector<string> tem;
        for(auto i:nums)
            tem.push_back(to_string(i));
        sort(tem.begin(), tem.end(), [](string &s1, string &s2){ return s1+s2 > s2 + s1;});
        for(auto i:tem)
            res+=i;
        
        while(res[0]=='0' && res.length()>1)
            res.erase(0,1);
        return res;
        
    }
};
