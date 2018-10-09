class LRUCache {
    int _capacity;
    list<int> used;
    unordered_map<int, pair<int, list<int>::iterator>>  cache;
    
    void touch(unordered_map<int, pair<int, list<int>::iterator>>::iterator it) {
        used.erase(it->second.second);
        used.push_front(it->first);
        it->second.second = used.begin();
    }
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()) {
            touch(cache.find(key));
            return cache[key].first;
        }   else
            return -1;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if(it != cache.end()) {
            touch(it);
        }   else {
            if(cache.size() >= _capacity){
                cache.erase(used.back());
                used.pop_back();
            }
            used.push_front(key);
            
        }
        cache[key] = {value, used.begin()};
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
