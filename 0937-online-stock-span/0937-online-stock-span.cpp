class StockSpanner {
    stack<pair<int,int>> spans;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count = 1;
        while(!spans.empty() && price >= spans.top().first){
            count += spans.top().second;
            spans.pop();
        }
        spans.push({price,count});
        return spans.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */