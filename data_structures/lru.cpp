{
#include<bits/stdc++.h>
using namespace std;
class LRUCache
{
public:
    LRUCache(int );
 
    int get(int );
 
    void set(int , int );
};
int main()
{
    int t;
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
    }
}

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

typedef struct Node {
    int val;
    struct Node *next;
    struct Node *prev;
    Node(int v): val(v), next(nullptr), prev(nullptr) {}
} Node;

class List {
public:
    Node* push_front();
    Node* push_back();
    void pop_front();
    void pop_back();
    void moveToFront(Node*);
private:
    Node *head = nullptr;
    Node *tail = nullptr;
};

Node* List::push_front(int v) {
    Node *newNode = new Node(v);
    if (empty()) {
        head = newNode;
    } else {
        nodeNode->next = head;
        head->prev = newNode;
        head = nodeNode;
    }
    return head;
}

Node* List::push_back(int v) {
    Node *newNode = new Node(v);
    if (empty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
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
}

void List::pop_back() {
    if (!empty()) {
        if (head == tail) { // if size is 1
            delete(tail);
            head = nullptr;
            tail = nullptr;
        } else {
            tail->prev->next = nullptr;
            Node *temp = tail;
            tail = tail->prev;
            delete(tmp);
        }
    }
}

void List::moveToFront(Node *node) {
    if (head != tail) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = head;
        head = node;
    }
}

unordered_map<int, Node*> nodeOfKey;
List list;
int capacity;

LRUCache::LRUCache(int N)
{
    capacity = n;
    nodeOfKey.clear();
}

/*Sets the key x with value y in the LRU cache */
void LRUCache::set(int x, int y) 
{
    if (values.size() > capacity) {
        pop_back(tail);
    }
    Node *pushNodeRef = list.push_back(y);
    nodeOfKey[x] = pushedNodeRef;
}
/*Returns the value of the key x if 
present else returns -1 */
int LRUCache::get(int x)
{
    Node *nodeRef = nodeOfKey[x];
    list.moveToFront(nodeRef);
    return nodeRef->val;
}