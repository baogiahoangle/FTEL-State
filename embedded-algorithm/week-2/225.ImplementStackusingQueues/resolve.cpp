class MyStack {
private:
    queue<int> queue1;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        queue1.push(x);
        for(int i = 0; i < queue1.size() - 1; i++)
        {
            queue1.push(queue1.front());
            queue1.pop();
        }
    }
    
    int pop() {
        int x = queue1.front();
        queue1.pop();
        return x;
    }
    
    int top() {
        return queue1.front();
    }
    
    bool empty() {
        return queue1.empty();
    }
};