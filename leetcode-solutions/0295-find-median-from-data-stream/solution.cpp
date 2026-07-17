class MedianFinder {
public:
    priority_queue<int> left_maxheap;
    priority_queue<int,vector<int> , greater<int>> right_minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left_maxheap.empty() || num < left_maxheap.top()){
            left_maxheap.push(num);
        }else{
            right_minheap.push(num);
        }

        //always maintain left max heap size equal or 1 greater than right min heap
        if(abs((int)left_maxheap.size()- (int)right_minheap.size()) > 1){
        //there should not be more than 1 extra ele in left max heap 
            right_minheap.push(left_maxheap.top());
            left_maxheap.pop();
        }else if(left_maxheap.size() < right_minheap.size()){
            left_maxheap.push(right_minheap.top());
            //left can never be smaller than right 
            right_minheap.pop();
        }
    }
    
    double findMedian() {
        if(left_maxheap.size() ==  right_minheap.size()){
            return (double)(left_maxheap.top() + right_minheap.top()) / 2;
        }else{
            return left_maxheap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
