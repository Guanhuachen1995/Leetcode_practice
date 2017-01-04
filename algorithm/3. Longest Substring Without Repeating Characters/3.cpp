class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	int max=0,lastbit=-1;
        unordered_map<char,int> m;
        for (int i =0; i < s.length();i++)
        {
        	if(m.find(s[i])!=m.end() && lastbit < m[s[i]])
        	{
        		lastbit = m[s[i]];
        	}
        	if ( i - lastbit > max )
        		max = i - lastbit;
        	m[s[i]]=i;
        }
        return max;
    }
};