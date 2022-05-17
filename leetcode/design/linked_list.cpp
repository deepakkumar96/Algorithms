class Node {
public:
    int val;
    Node *prev;
    Node *next;
    
    ~Node() {
        delete prev;
        delete next;
    }
    Node(int v, Node *n = nullptr, Node *p = nullptr): val(v), next(n), prev(p) { }
    Node *next() const { return next; }
};

class MyLinkedList {
private:
    Node *head;
    Node *tail;
    size_t size;
    
    Node* find(int idx) const {
        Node *node = head;
        int i = 0;
        while (i <= idx && node != nullptr) {
            if (i == idx && node != nullptr) {
                return node;
            }
            i++;
            node = node->next;
        }
        return nullptr;
    }
    
    void connect(Node *a, Node *b) const {
        if (a != nullptr) {
            a->next = b;
        }
        if (b != nullptr) {
            b->prev = a;
        }
    }
    bool isEmpty() const { return size == 0; }
    bool isNotEmpty() const { return size != 0; }
public:
    MyLinkedList() {
        head = tail = nullptr;
        size = 0;
    }
    
    int get(int index) {
        Node *node = find(index);
        if (node != nullptr) {
            return node->val;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        Node *newNode = new Node(val, head, nullptr);
        if (isNotEmpty()) {
            head->prev = newNode;
        }
        head = newNode;
    }
    
    void addAtTail(int val) {
        Node *newNode = new Node(val, nullptr, tail);
        if (isNotEmpty()) {
            tail->next = newNode;
        }
        tail = newNode;
    }
    
    void addAtIndex(int idx, int val) {
        if (idx < 0 || idx > size) {
            return;
        } else if (idx == 0) {
            addAtHead(val);
        } else if (idx == size) {
            addAtTail(val);
        } else {
            // between head & tail
            Node *node = find(idx);
            connect(node->prev, node->next);
            delete node;
        }
    }
    
    void deleteAtIndex(int idx) {
        if (idx == 0) {
            if (head != nullptr) {
                Node *nodeToDel = head;
                head = head->next;
                delete nodeToDel;
            }
        } else if (idx == size - 1) {
            
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */