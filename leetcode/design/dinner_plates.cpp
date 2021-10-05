class DinnerPlates {
private:
    int stackCapacity;
    int totalStacks = 0;
    vector<stack<int>> stacks;
    priority_queue<int, vector<int>, greater<int> > emptyStacks; // will store only indices
public:
    DinnerPlates(int capacity) {
        this->stackCapacity = capacity;
    }
    
    void push(int val) {
        if (emptyStacks.empty()) {
            pushToEnd(val);
        } else {
            int leftMostIdx = emptyStacks.top();
            emptyStacks.pop();
            stacks[leftMostIdx].push(val);
            if (stacks[leftMostIdx].size() < stackCapacity) {
                emptyStacks.push(leftMostIdx);
            }
        }
    }
    
    void pushToEnd(int val) {
        if (stacks[totalStacks].size() < stackCapacity) {
            stacks[totalStacks].push(val);
        } else {
            totalStacks++;
            stacks.push_back(stack<int>());
            stacks[totalStacks].push(val);
        }
    }
    
    int pop() {
        
    }
    
    int popAtStack(int index) {
        
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */