
#include <iostream>
#include <list>
#include <unordered_map>
#include <iterator>
#include <vector>
using namespace std;

class LRUCache {
private:
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    int capacity;

public:
    LRUCache(int cap) : capacity(cap) {}

    int get(int key) {
        auto it = mp.find(key);

        if (it == mp.end()) {
            return -1;
        }

        // Move accessed key to the front
        cache.splice(cache.begin(), cache, it->second);

        return it->second->second;
    }

    void put(int key, int value) {
        auto it = mp.find(key);

        // Update existing key
        if (it != mp.end()) {
            it->second->second = value;
            cache.splice(cache.begin(), cache, it->second);
            return;
        }

        if (capacity <= 0) return;

        // Remove least recently used key
        if ((int)cache.size() == capacity) {
            int oldKey = cache.back().first;
            mp.erase(oldKey);
            cache.pop_back();
        }

        cache.push_front({key, value});
        mp[key] = cache.begin();
    }

    void display() {
        cout << "MRU -> LRU: ";

        for (auto item : cache) {
            cout << "[" << item.first
                 << ":" << item.second << "] ";
        }

        cout << '\n';
    }
};

int main() {
    LRUCache lru(3);

    lru.put(1, 100);
    lru.put(2, 200);
    lru.put(3, 300);

    lru.display();

    cout << "Get 1: " << lru.get(1) << '\n';
    lru.display();

    lru.put(4, 400);
    lru.display();

    cout << "Get 2: " << lru.get(2) << '\n';

    return 0;
}

