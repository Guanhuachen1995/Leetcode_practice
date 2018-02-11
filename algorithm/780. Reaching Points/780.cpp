class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(tx >= sx && ty >= sy)
        {
            if(tx == sx && ty == sy)    return 1;
            if(tx > ty)
            {
                if((tx -sx)/ty == 0)
                    return 0;
                tx -= ty*((tx -sx)/ty);
            }
            else
            {
                if((ty -sy)/tx == 0)
                    return 0;
                ty -= tx*((ty -sy)/tx);
            }
                
        }
        return 0;
    }
};
