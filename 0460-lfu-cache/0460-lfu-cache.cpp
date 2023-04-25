    class LFUCache {
        struct element{
            int valeur,frequency;
            list<int> ::iterator it;
        };
    public:
        int c,minfreq;
        map<int, element> cache;
        map<int,list<int>>freq;
        LFUCache(int capacity) {
            c = capacity;
        }

        int get(int key) {
            if (cache.count(key)){
                freq[cache[key].frequency].erase(cache[key].it);//erase the element from the old frequency;
                cache[key].frequency++;//update the frequency
                freq[cache[key].frequency].push_back(key);//update the list of the frequencies
                cache[key].it=prev(freq[cache[key].frequency].end());//update the iterator
                return cache[key].valeur;
            }
            if(freq[minfreq].empty())
                minfreq++;
            return -1;
        }

        void put(int key, int value) {
        if(!c)
            return;
            if (get(key)!=-1) {
                cache[key].valeur = value;
                return;
            }

            if (cache.size() == c){
                cache.erase(freq[minfreq].front());
                freq[minfreq].pop_front();
            }

            freq[1].push_back(key);
            cache[key] = {value, 1, prev(freq[1].end())};
            minfreq = 1;
        }
        
    };

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */