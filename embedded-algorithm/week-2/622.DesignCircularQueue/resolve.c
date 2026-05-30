typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* my_circular = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    if(k > 0)
        my_circular->arr = malloc(k*sizeof(int));
    my_circular->front = -1;
    my_circular->rear = -1;
    my_circular->size = k;
    return my_circular;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(myCircularQueueIsFull(obj))
        return false;
    obj->rear = (obj->rear + 1) % obj->size;
    if(obj->front == -1)
        obj->front = obj->rear;
    obj->arr[obj->rear] = value;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
        return false;
    if(obj->front == obj->rear)
    {
        obj->front = -1;
        obj->rear = -1;
    }   
    else
        obj->front = (obj->front + 1) % obj->size;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)) return -1;
    return obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)) return -1;
    return obj->arr[obj->rear];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front == -1 && obj->rear == -1;
}
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->rear + 1) % obj->size == obj->front;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    if(obj)
    {
        free(obj->arr);
        free(obj);
    }
}
