class Solution {
public:
    bool isMatch(string s, string p) {
        bool isstar=false;
        int s1=0,p1=0;
        int ss,pp;
        while(s1<s.size() && ( p1 < p.size() || isstar == true))
        {
        	if(s[s1]==p[p1] || p[p1]=='?')
        	{
        		s1++;
        		p1++;	
        	}
        	else if (p[p1]=='*')
        	{
        		isstar=true;
        		p1++;
        		if(p1 >= p.size())
        			return true;
        		ss=s1;
        		pp=p1;
        	}
        	else
        	{
        		if(!isstar) return false;
        		p1=pp;
        		s1=++ss;
        	}
        }
        if(s1 >= s.size())
        {
        	while (p[p1]=='*') p1++;
        	if(p1>= p.size())
        		return true;
        }
        return false;
    }
};
