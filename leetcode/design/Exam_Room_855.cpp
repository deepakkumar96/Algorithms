struct Intvl {
  int x;
  int y;
  bool isLeftPresent;
  bool isRightPresent;
  Intvl(int xPos, int yPox, bool left = true, bool right = true):
    x(xPos), y(yPos), isLeftPresent(left), isRightPresent(right) { }
  int size() {
      return abs(x - y);
  }
    
  bool operator< (const Intvl &other) {
      return size() > other.size();
  } 
};

class ExamRoom {
private:
    set<Intvl> intvls;
    map<int, set<Intvl>> mapping;
public:
    ExamRoom(int n) {
        intvls.insert(Intvl(0, 9, false, false));
    }
    
    int seat() {
        auto tp = *intvls.begin(); // get first element
        intvls.erase(intvls.begin());
        if (!tp.isLeftPresent) {
            tp.isPresent = true;
            mapping[tp.x].erase(tp);
            mapping[tp.x].insert(tp);
            return tp.x;
        }
        if (!tp.isRightPresent) {
            return tp.y;
        }
        
    }
    
    void leave(int p) {
        
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */