class Solution {
public:
    string nextClosestTime(string time) {
        int a = time[0] - '0', b = time[1] - '0', c = time[3]- '0', d = time[4] - '0';
        vector<int> choice{a,b,c,d};
        sort(choice.begin(), choice.end());
        string res = time;
        
        res[4] = '0' + nextdigit(d, choice, 9);
        if(res[4] > time[4])    return res;
        
        res[3] = '0' + nextdigit(c, choice, 5);
        if(res[3] > time[3])    return res;
        
        res[1] = '0' + (a == 2?nextdigit(b, choice, 4):nextdigit(b, choice, 9));
        if(res[1] > time[1])    return res;
        
        res[0] = '0' + nextdigit(a, choice, 2);
        return res;

    }
    
    
    int nextdigit(int cur, vector<int> &choice, int limit) {
        int i = 0;
        for(; i < 4; i++) {
            if((choice[i] > cur))  break;
        }
        if(i == 4 || choice[i] > limit) return choice[0];
        else
            return choice[i];
    }
};
