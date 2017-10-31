class Solution {
public:
    string fractionToDecimal(int64_t numerator, int64_t denominator) {
        if(numerator == 0)
            return "0";
        string res;
        if(numerator < 0 ^ denominator < 0) res += '-';
        
        numerator = abs(numerator);
        denominator = abs(denominator);
        res += to_string(numerator / denominator);
        if (numerator % denominator == 0) return res;
        res += '.';
        unordered_map<int, int> map;
        for(int64_t r = numerator % denominator; r > 0; r %= denominator)
        {
            if(map.find(r) != map.end())
            {
                res.insert(map[r],1,'(');
                res.push_back(')');
                break;
            }
            

            map[r] = res.size();
            r *= 10;
            res += to_string(r/denominator);
        }
        return res;
    }
};
