class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0, b = 0;
        vector<int> m(10, 0);
        for(int i = 0; i < secret.size(); i++) {
            if(secret[i] == guess[i]) a++;
            else {
                if(m[guess[i] - '0']++ < 0)  b++;
                if(m[secret[i] - '0']-- > 0)   b++;
                
            }
        }
        return to_string(a)+"A"+to_string(b) +"B";
    }
};
