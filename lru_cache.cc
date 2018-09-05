class LRUCache {
 public:
  LRUCache(int capacity) {
    capacity_ = capacity;
    rank_ = -1;
    }
    
    int get(int key) {
      if (storage.find(key) != storage.end()) {
        usage[key] = ++rank_;
        return storage[key];
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
      if (storage.find(key) != storage.end()) {
        storage[key] = value;
        usage[key] = ++rank_;
        } else if(storage.size() == capacity_) {
            // find lowest rank
            int least_used = 0;
            int number_of_times = 0;
            for(auto itr = usage.begin(); itr != usage.end(); ++itr) {
              if (itr == usage.begin()) {
                number_of_times = itr->second;
                least_used = itr->first;
                } else {
                    if(itr->second < number_of_times) {
                      least_used = itr->first;
                      number_of_times = itr->second;
                    }
                }
            }
            storage.erase(least_used);
            storage[key] = value;
            usage.erase(least_used);
            usage[key] = ++rank_;
        } else {
            storage[key] = value;
            usage[key] = ++rank_;
        }
    }

   private:
    map<int, int> storage{};
    int capacity_;
    int rank_;
    map<int, int> usage{};
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
