class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> s;
        map<int,int> m;
        for(int i : nums)
        {
            while(!s.empty() && s.top()<i)
            {
                m[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        vector<int> result;
        for(int i:findNums)
        {
            if(m.count(i)!=0)
                result.push_back(m[i]);
            else
                result.push_back(-1);
        }
        return result;
    }
};
