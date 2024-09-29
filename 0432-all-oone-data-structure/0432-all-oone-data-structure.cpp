
class Node {
public:
    int freq;
    Node *prev;
    Node *next;
    unordered_set<string> keys;

    Node(int freq) : freq(freq), prev(nullptr), next(nullptr) {}

    void removeNode() {
        Node *prevNode = this->prev;
        Node *nextNode = this->next;

        prevNode->next = nextNode;  // Link previous node to next node
        nextNode->prev = prevNode;  // Link next node to previous node

        delete this;  // Free the memory of the removed node
    }
};


class AllOne {
public:
    Node *head;                        // Dummy head
    Node *tail;                        // Dummy tail
    unordered_map<string, Node *> map;  // Mapping from key to its node

    AllOne() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }

    void inc(string key) {
        if (map.count(key)) {
            Node *node = map[key];
            int freq = node->freq;
            node->keys.erase(key);  // Remove key from current node

            Node *nextNode = node->next;
            if (nextNode == tail || nextNode->freq != freq + 1) {
                // Create a new node if next node does not exist or freq is not
                // freq + 1
                Node *newNode = new Node(freq + 1);
                newNode->keys.insert(key);
                newNode->prev = node;
                newNode->next = nextNode;
                node->next = newNode;
                nextNode->prev = newNode;
                map[key] = newNode;
            } else {
                nextNode->keys.insert(key);
                map[key] = nextNode;
            }
            // Remove the current node if it has no keys left
            if (node->keys.empty()) {
                node->removeNode();
            }
        } else {
            // Key does not exist
            Node *firstNode = head->next;
            if (firstNode == tail || firstNode->freq > 1) {
                // Create a new node
                Node *newNode = new Node(1);
                newNode->keys.insert(key);
                newNode->prev = head;
                newNode->next = firstNode;
                head->next = newNode;
                firstNode->prev = newNode;
                map[key] = newNode;
            } else {
                firstNode->keys.insert(key);
                map[key] = firstNode;
            }

        }
    }

    void dec(string key) {
        if (!map.count(key)) {
            return;  // Key does not exist
        }

        Node *node = map[key];
        node->keys.erase(key);
        int freq = node->freq;

        if (freq == 1) {
            // Remove the key from the map if freq is 1
            map.erase(key);
        } else {
            Node *prevNode = node->prev;
            if (prevNode == head || prevNode->freq != freq - 1) {
                // Create a new node if the previous node does not exist or freq
                // is not freq - 1
                Node *newNode = new Node(freq - 1);
                newNode->keys.insert(key);
                newNode->prev = prevNode;
                newNode->next = node;
                prevNode->next = newNode;
                node->prev = newNode;
                map[key] = newNode;
            } else {
                // Decrement the existing previous node
                prevNode->keys.insert(key);
                map[key] = prevNode;
            }
        }

        // Remove the node if it has no keys left
        if (node->keys.empty()) {
            node->removeNode();
        }
    }

    string getMaxKey() {
        string ans = "";
        Node *last = tail->prev;
        if (last != head) {
            ans = *(last->keys.begin());
        }
        return ans;
    }

    string getMinKey() {
        string ans = "";
        Node *first = head->next;
        if (first != tail) {
            ans = *(first->keys.begin());
        }
        return ans;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */