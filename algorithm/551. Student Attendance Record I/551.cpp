class Solution {
public:
    bool checkRecord(string s) {
        int l=0,A=0;
        for(auto a:s)
        {
            if(a=='L')
                l++;
            else
                l=0;
            if(a=='A')
                A++;
            if((A>1)||(l>2)) return false; 
        }
        return true;
    }
};
