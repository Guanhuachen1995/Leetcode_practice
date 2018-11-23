class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.size();
        string s1, s2;
        for (int i = 0; i < n; ++i) 
            if (start[i] != 'X') s1 += start[i];
        for (int i = 0; i < n; ++i) 
            if (end[i] != 'X') s2 += end[i];
        if (s1 != s2) return false;
        int i = 0, j = 0;
        while(i < start.size() && j < end.size()) {
            
            while(i < start.size() && start[i] == 'X')  i++;
            while(j < end.size() && end[j] == 'X') j++;
            
            if(i == start.size() && j == end.size()) return true;
            if(i == start.size() || j == end.size()) return false;
            
            if(start[i] == 'L' &&  j > i)   return false;
            if(start[i] == 'R' &&  i > j)   return false;
            i++;j++;
        }
        return true;
    }
};
