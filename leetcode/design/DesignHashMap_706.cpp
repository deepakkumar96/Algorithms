
struct KeyCmp {
private:
    int k;
public:
    KeyCmp(int key): k(key){ }
    bool operator()(const pair<int, int> &pr) const {
        return pr.first == k;
    }
};

class MyHashMap {
private:
    size_t cp = 16;
    size_t sz = 0;
    vector<forward_list<pair<int, int>>> buckets;
public:
    MyHashMap() {
        buckets.resize(cp);
    }
    
    
    void put(int key, int value) {
        if (sz == cp) {
            reallocate_buckets();
        }
        int h = key % cp;
        auto it = find(key);
        if (it != buckets[h].end()) { // if exist
            *it = {key, value}; //update
        } else {
            buckets[h].push_front({key, value});
            sz++;
        }
    }
    
    int get(int key) {
        int h = key % cp;
        auto it = find(key);
        if (it != buckets[h].end()) {
            return it->second;
        }
        return -1;
    }
    
    void remove(int key) {
        int h = key % cp;
        if (find(key) == buckets[h].end()) {
            return;
        }
        auto& chain = buckets[h];
        auto prev = chain.before_begin();
        for (auto it = chain.begin(); it != chain.end(); it++, prev++) {
            if (key == it->first) {
                chain.erase_after(prev, ++it);
                sz--;
                break;
            }
        }
    }
    
    forward_list<pair<int, int>>::iterator find(int key) {
        return find_if(buckets[key % cp].begin(), buckets[key % cp].end(), KeyCmp(key));
    }
    
    void reallocate_buckets() {
        size_t ncp = cp * 2;
        vector<forward_list<pair<int, int>>> old_buckets(move(buckets)); // moved buckets to new without copying
        buckets = vector<forward_list<pair<int, int>>>(ncp);
        for (const forward_list<pair<int, int>> &chain: old_buckets) {
            for (const pair<int, int>& p : chain) {
                put(p.first, p.second);
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */