#include<forward_list>
#include <vector>
class MyHashSet {
private:
    size_t cp = 16;
    size_t sz = 0;
    vector<forward_list<int>> buckets;
public:
    MyHashSet() {
        buckets.resize(cp);
    }
    
    void add(int key) {
        if (sz == cp) {
            reallocate_buckets();
        }
        if (!contains(key)) {
            buckets[key % cp].push_front(key);
            sz++;
        }
    }
    
    void remove(int key) { 
        if (!contains(key)) {
            return;
        }
        int h = key % cp;
        auto& chain = buckets[h];
        auto prev = chain.before_begin();
        for (auto it = chain.begin(); it != chain.end(); it++, prev++) {
            if (key == *it) {
                chain.erase_after(prev, ++it);
                sz--;
                break;
            }
        }
    }
    
    bool contains(int key) {
        return find(buckets[key % cp].begin(), buckets[key % cp].end(), key) != buckets[key % cp].end();
    }
    
    void reallocate_buckets() {
        size_t ncp = cp * 2;
        vector<forward_list<int>> old_buckets(move(buckets)); // moved buckets to new without copying
        buckets = vector<forward_list<int>>(ncp);
        for (const forward_list<int> &chain: old_buckets) {
            for (const int& key : chain) {
                add(key);
            }
        }
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */