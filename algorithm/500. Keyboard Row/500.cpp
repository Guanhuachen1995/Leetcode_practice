class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> row1 {'q', 'w', 'e', 'r', 't', 'y','u', 'i', 'o', 'p'};
        unordered_set<char> row2 {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'}; 
        unordered_set<char> row3 { 'z', 'x', 'c', 'v', 'b' ,'n', 'm'};
        vector<unordered_set<char>> rows {row1, row2, row3};
        
        vector<string> result;
        for (int i=0 ;i<words.size();i++)
        {
            int row=0;
            for(int j=0;j<3;j++)
            {
                if(rows[j].count((char)tolower(words[i][0])))
                    row=j;
            }
            result.push_back(words[i]);
            for(int j=1;j<words[i].size();j++)
            {
                if(rows[row].count((char)tolower(words[i][j]))==0)
                {
                    result.pop_back();
                    break;
                }
            }
        }
        return result;
    }
};
