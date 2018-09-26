class MedianFinder {
private:
    priority_queue<int> max_heap;  //下半部
    priority_queue<int, vector<int>, greater<int>>  min_heap;  //上半部
public:
    void addNum(int num) {
        if(min_heap.empty() || num > min_heap.top())  min_heap.push(num);
        else
            max_heap.push(num);
        
        if(min_heap.size() > max_heap.size() + 1) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        
        if(max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }
    
    double findMedian() {
        if(max_heap.size() == min_heap.size())  return max_heap.size() == 0?0:(max_heap.top() + min_heap.top())/2.0;
        return min_heap.size() > max_heap.size()?min_heap.top():max_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
