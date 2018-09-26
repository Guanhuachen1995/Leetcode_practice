if(x == 0)  return 0;
        int l = 1, r = x;
        while(l+1<r) {
            int mid = l + (r - l)/2;
            if(mid <= x/mid) {
                l = mid;
            } else
                r = mid;
        }
        if(r <= x/r) return r;
        return l;
