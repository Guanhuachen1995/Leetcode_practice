class Solution {
public:
    int len;
    string ss;
    bool canWin(string s) {
        len = s.size();
        ss = s;
        return canWin();
    }
    
    bool canWin()
    {
        for(int i = 0; i < len-1; i++)
        {
            if(ss[i] =='+' && ss[i+1] == '+')
            {
                ss[i] = ss[i+1]='-';
                bool wins = !canWin();
                ss[i] = ss[i+1]='+';
                if(wins == true)    return true;
            }
        }
        return false;
    }
};
