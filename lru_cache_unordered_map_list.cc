class LRUCache {
 public:
  LRUCache(int capacity) { capacity_ = capacity; }

  int get(int key) {
    auto itr = storage.find(key);
    if (itr == storage.end()) return -1;
    update(itr);
    return itr->second.first;
        
    }
    
    void put(int key, int value) {
      auto itr = storage.find(key);
      if (itr != storage.end()) {
        itr->second.first = value;
        update(itr);
        } else {
            if(storage.size() == capacity_) {
              storage.erase(usage.back());
              usage.pop_back();
            }
            usage.push_front(key);
            storage[key] = {value, usage.begin()};
        }
        
    }

   private:
    int capacity_;
    list<int> usage;
    unordered_map<int, pair<int, list<int>::iterator> > storage;

    void update(
        unordered_map<int, pair<int, list<int>::iterator> >::iterator itr) {
      int key = itr->first;
      usage.push_front(key);
      usage.erase(itr->second.second);
      itr->second.second = usage.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
