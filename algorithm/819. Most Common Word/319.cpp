class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string,int> m;
        
        int start = 0;
        int i;
        for( i = 0; i < paragraph.size(); i++)
        {
            paragraph[i] = tolower(paragraph[i]);
            if(!isalnum(paragraph[i]))
            {
                if(i > start)
                {
                    m[paragraph.substr(start,i - start)]++;
                }
                start = i + 1;
            }
        }
        if(i > start)
        {
            m[paragraph.substr(start,i - start)]++;
        }
        for(i = 0; i <banned.size(); i++)
            m[banned[i]] = -1;
        int maxone = -1;
        string res;
        for(auto it = m.cbegin(); it != m.cend(); it++)
        {
            if(it->second > maxone)
            {
                res = it->first;
                maxone = it->second;
            }
        }
        return res;
    }
};
