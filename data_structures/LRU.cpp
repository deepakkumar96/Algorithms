

#include<bits/stdc++.h>
using namespace std;
class LRUCache
{
public:
    LRUCache(int );

    int get(int );

    void set(int , int );
};

typedef struct Node {
    int key;
    int val;
    struct Node *next;
    struct Node *prev;
    Node(int k, int v): key(k), val(v), next(nullptr), prev(nullptr) {}
} Node;

void lruDump(LRUCache);

class List {
public:
    Node* push_front(int, int);
    Node* push_back(int, int);
    void pop_front();
    Node* getTail();
    void pop_back();
    void moveToFront(Node*);
    bool empty();
    size_t size();
    size_t capacity();
    void setCapacity(int);
    void dump() {
        auto itr = head;
        while (itr != nullptr) {
            cout << itr->val << " ";
            itr = itr->next;
        }
    }
    void rdump() {
        cout << size() << " :: ";
        auto itr = tail;
        while (itr != nullptr) {
            cout << itr->val << " ";
            itr = itr->prev;
        }
    }
private:
    Node *head = nullptr;
    Node *tail = nullptr;
    size_t list_size = 0;
    size_t capacity_size = 0;
};

int main()
{
    /*int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        LRUCache *l  = new LRUCache(n);
        int q;
        cin>>q;
        for(int i=0;i<q;i++)
        {
            string a;
            cin>>a;
            if(a=="SET")
            {
                int aa,bb;
                cin>>aa>>bb;
                l->set(aa,bb);
            }else if(a=="GET")
            {
                int aa;
                cin>>aa;
                cout<<l->get(aa)<<" ";
            }
        }
        cout<<endl;
    }*/

    //list.pop_back();
    //list.pop_back();

    //list.rdump();
    cout << endl;
    LRUCache lru(3);
    cout << "get 1 " << lru.get(1) << endl;
    lru.set(1, 10);
    lru.set(2, 20);
    lru.set(3, 30);
    lruDump(lru);

    lru.get(1);
    lru.set(4, 40);
    lru.set(3, 30);
    //cout << "get 2 " << lru.get(2) << endl;
    lruDump(lru);
}


/*This is a function problem.You only need to complete the function given below*/
/*The structure of the class is as follows
class LRUCache
{
public:
    LRUCache(int );
    int get(int );
    void set(int , int );
};*/
/*You are required to complete below methods */
/*Inititalize an LRU cache with size N */



void List::setCapacity(int n) {
    capacity_size = n;
}

bool List::empty() {
    return head == nullptr;
}

size_t List::size() {
    return list_size;
}

size_t List::capacity() {
    return capacity_size;
}

Node* List::getTail() {
    return tail;
}

Node* List::push_front(int k, int v) {
    Node *newNode = new Node(k, v);
    if (empty()) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    list_size++;
    return head;
}

Node* List::push_back(int k, int v) {
    Node *newNode = new Node(k, v);
    if (empty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    list_size++;
    return tail;
}

void List::pop_front() {
    if (!empty()) {
        Node *tmp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete(tmp);
    }
    list_size--;
}

void List::pop_back() {
    if (size() == 1) { // if size is 1
            delete(tail);
            head = nullptr;
            tail = nullptr;
    } else {
            tail->prev->next = nullptr;
            Node *tmp = tail;
            tail = tail->prev;
            delete(tmp);
    }
    list_size--;
}

void List::moveToFront(Node *node) {
    if (size() > 1) {
        if (node == head) {
            return;
        }
        if (node == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        node->next = head;
        head->prev = node;
        node->prev = nullptr;
        head = node;
    }
}

unordered_map<int, Node*> nodeOfKey;
List valueList;

LRUCache::LRUCache(int n)
{
    valueList.setCapacity(n);
    nodeOfKey.clear();
}

/*Sets the key x with value y in the LRU cache */
void LRUCache::set(int x, int y)
{
    //return;
    if (nodeOfKey.find(x) != nodeOfKey.end()) {
        Node* valueNode = nodeOfKey[x];
        valueNode->val = y;//update
        valueList.moveToFront(valueNode);
    } else {
        if (valueList.size() >= valueList.capacity()) {
            auto lastNode = valueList.getTail();
            nodeOfKey.erase(lastNode->key);
            valueList.pop_back();
        }
        Node *pushedNodeRef = valueList.push_front(x, y);
        nodeOfKey[x] = pushedNodeRef;
    }
}
/*Returns the value of the key x if
present else returns -1 */
int LRUCache::get(int x)
{
    if (nodeOfKey.find(x) == nodeOfKey.end()) {
        return -1;
    }
    Node *nodeRef = nodeOfKey[x];
    valueList.moveToFront(nodeRef);
    return nodeRef->val;
}

void lruDump(LRUCache lruCache) {
    cout << valueList.size() << ":: ";
    valueList.dump();
    cout << endl;
}
