class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int a1,a2,b1,b2;
        char tem;
        stringstream aa(a),bb(b),result;
        aa>>a1>>tem>>a2>>tem;
        bb>>b1>>tem>>b2>>tem;
        result<<a1*b1-a2*b2<<"+"<<a1*b2+a2*b1<<"i";
        return result.str();
    }
};
