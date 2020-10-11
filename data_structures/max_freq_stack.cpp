#include <unordered_map>
#include <stack>

using namespace std;


/* Link : https://leetcode.com/problems/maximum-frequency-stack/ */
class FreqStack {
public:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int> > freqGrp;
    int maxFreq;
    
    FreqStack() {
        maxFreq = 0; 
    }
    
    void push(int x) {
        freq[x]++; // increase freq
        int xf = freq[x];
        maxFreq = max(maxFreq, xf); // change maxFreq if required
        freqGrp[xf].push(x); // push x to freq-group stack
    }
    
    int pop() {
        // remove from freq-group stack
        int ele = freqGrp[maxFreq].top();
        freqGrp[maxFreq].pop();
        
        // decrease freq
        freq[ele]--;
        
        //change maxFreq if required
        if (freqGrp[maxFreq].empty()) {
            maxFreq--;
        }
        return ele;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */