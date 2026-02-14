class Node {
public:
    int key, value, cnt;
    Node* next;
    Node* prev;

    Node(int _key, int _value) {
        key = _key;
        value = _value;
        cnt = 1;
        next = nullptr;
        prev = nullptr;
    }
};

class List {
public:
    int size;
    Node* head;
    Node* tail;

    List() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node* node) {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }

    void removeNode(Node* delnode) {
        Node* prevNode = delnode->prev;
        Node* nextNode = delnode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        size--;
    }
};

class LFUCache {
private:
    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqListMap;

    int maxSizeCache;
    int minFreq;
    int curSize;

public:
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }

    void updateFreqListMap(Node* node) {
        keyNode.erase(node->key);

        freqListMap[node->cnt]->removeNode(node);

        if (node->cnt == minFreq && freqListMap[node->cnt]->size == 0) {
            minFreq++;
        }

        List* nextHigherFreqList;

        if (freqListMap.find(node->cnt + 1) != freqListMap.end()) {
            nextHigherFreqList = freqListMap[node->cnt + 1];
        } else {
            nextHigherFreqList = new List();
            freqListMap[node->cnt + 1] = nextHigherFreqList;
        }

        node->cnt += 1;
        nextHigherFreqList->addFront(node);
        keyNode[node->key] = node;
    }

    int get(int key) {
        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            int val = node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (maxSizeCache == 0) return;

        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        } else {

            if (curSize == maxSizeCache) {
                List* list = freqListMap[minFreq];
                Node* nodeToRemove = list->tail->prev;

                keyNode.erase(nodeToRemove->key);
                list->removeNode(nodeToRemove);
                curSize--;
            }

            curSize++;
            minFreq = 1;

            List* listFreq;
            if (freqListMap.find(minFreq) != freqListMap.end()) {
                listFreq = freqListMap[minFreq];
            } else {
                listFreq = new List();
                freqListMap[minFreq] = listFreq;
            }

            Node* node = new Node(key, value);
            listFreq->addFront(node);
            keyNode[key] = node;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
