class Solution {
private:
    string getnext(string s){
        string result;  
        int i=0;  
        int count ;  
        while (i < s.size())  
        {  
            count = 1;  
            char temp;  
            if (s[i] == s[i + 1])  
            {  
                while (s[i] == s[i + 1])  
                {  
                    count++;  
                    i++;  
                }  
                temp = count + '0';  
                result = result + temp + s[i];  
                i++;  
            }  
            else  
            {  
                temp = '1';  
                result = result + temp + s[i];  
                i++;  
            }  
        }  
        return result;  
    }
public:
    string countAndSay(int n) {
        string result="1";
        for (int i=1; i<n;i++)
        {
            result=getnext(result);
        }
        return result;
    }
};
