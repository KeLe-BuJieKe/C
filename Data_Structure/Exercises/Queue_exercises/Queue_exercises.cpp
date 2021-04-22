#define _CRT_SECURE_NO_WARNINGS 1
/*
232. ��ջʵ�ֶ���
�����ʹ������ջʵ�������ȳ����С�����Ӧ��֧��һ�����֧�ֵ����в�����push��pop��peek��empty����
ʵ�� MyQueue �ࣺ
void push(int x) ��Ԫ�� x �Ƶ����е�ĩβ
int pop() �Ӷ��еĿ�ͷ�Ƴ�������Ԫ��
int peek() ���ض��п�ͷ��Ԫ��
boolean empty() �������Ϊ�գ����� true �����򣬷��� false
˵����
��ֻ��ʹ�ñ�׼��ջ���� ���� Ҳ����ֻ�� push to top, peek/pop from top, size, �� is empty �����ǺϷ��ġ�
����ʹ�õ�����Ҳ��֧��ջ�������ʹ�� list ���� deque��˫�˶��У���ģ��һ��ջ��ֻҪ�Ǳ�׼��ջ�������ɡ�
���ף�
���ܷ�ʵ��ÿ��������̯ʱ�临�Ӷ�Ϊ O(1) �Ķ��У����仰˵��ִ�� n ����������ʱ�临�Ӷ�Ϊ O(n) ����ʹ����һ���������ܻ��ѽϳ�ʱ�䡣
ʾ����
���룺
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
�����
[null, null, null, 1, 1, false]

���ͣ�
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
���ӣ�https://leetcode-cn.com/problems/implement-queue-using-stacks/
*/

//C++STLģ��ʵ��
/*

class MyQueue
{
public:
    // Initialize your data structure here. 
    stack<int>_inSt;        //ֻ������ջ
    stack<int>_outSt;       //ֻ�����ջ
    MyQueue()
    {

    }

    // Push element x to the back of queue.
    void push(int x)        //������ջ�з�Ԫ��
    {
        _inSt.push(x);
    }

    // Removes the element from in front of queue and returns that element. 
    int pop()
    {
        //������ջ��û��Ԫ���ˣ��ȿ�������ջ����û��Ԫ�أ��оͰ�����ջ��Ԫ��push�����ջ��
        //��ʱ���ջ��top���Ƕ�ͷ
        //Ԫ�شӶ�ͷ��
        if (_outSt.empty())
        {
            while (!_inSt.empty())
            {
                _outSt.push(_inSt.top());
                _inSt.pop();
            }
        }
        int cur = _outSt.top();
        _outSt.pop();
        return cur;

    }

    // Get the front element. 
    int peek()
    {
        //������ջ��û��Ԫ���ˣ��ȿ�������ջ����û��Ԫ�أ��оͰ�����ջ��Ԫ��push�����ջ��
        //��ʱ���ջ��top���Ƕ�ͷ
        if (_outSt.empty())
        {
            while (!_inSt.empty())
            {
                _outSt.push(_inSt.top());
                _inSt.pop();
            }
        }
        return _outSt.top();
    }

    //Returns whether the queue is empty.
    bool empty()
    {
        //����ΪNULL��Ϊ��
        return _outSt.empty() && _inSt.empty();
    }
};
*/


/*622. ���ѭ������
������ѭ������ʵ�֡� ѭ��������һ���������ݽṹ����������ֻ��� FIFO���Ƚ��ȳ���ԭ���Ҷ�β�������ڶ���֮�����γ�һ��ѭ����
��Ҳ����Ϊ�����λ���������
ѭ�����е�һ���ô������ǿ��������������֮ǰ�ù��Ŀռ䡣��һ����ͨ�����һ��һ���������ˣ�
���ǾͲ��ܲ�����һ��Ԫ�أ���ʹ�ڶ���ǰ�����пռ䡣����ʹ��ѭ�����У�������ʹ����Щ�ռ�ȥ�洢�µ�ֵ��
���ʵ��Ӧ��֧�����²�����
MyCircularQueue(k): �����������ö��г���Ϊ k ��
Front: �Ӷ��׻�ȡԪ�ء��������Ϊ�գ����� -1 ��
Rear: ��ȡ��βԪ�ء��������Ϊ�գ����� -1 ��
enQueue(value): ��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻��档
deQueue(): ��ѭ��������ɾ��һ��Ԫ�ء�����ɹ�ɾ���򷵻��档
isEmpty(): ���ѭ�������Ƿ�Ϊ�ա�
isFull(): ���ѭ�������Ƿ�������
���ӣ�https://leetcode-cn.com/problems/design-circular-queue/
*/

/*
typedef struct {
    int *array;         //
    int size;           //��������ܴ���ٸ�����
    int tail;           //β����β���ݵ���һ����
    int front;          //ͷ
} MyCircularQueue;
//����˼·
//��Զ�ճ�һ��λ�ã����洢����
//���ͷ��β��ȣ���֤��Ϊ��
//���ͷ��β����һ����ȣ���֤������

MyCircularQueue* myCircularQueueCreate(int k)
{
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->array = (int*)malloc(sizeof(int) * (k + 1));
    obj->size = k;
    obj->tail = 0;
    obj->front = 0;
    return obj;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
    //��ͷ�±���β�±���ͬʱ����֤������Ϊ��
    return obj->front == obj->tail;
}

bool myCircularQueueIsFull(MyCircularQueue* obj)
{
    //�ж�β����һ���Ƿ����ͷ�����������
    int temp = obj->tail + 1;
    //�����������tailָ��������һ��λ�õ��±꣬��+1���ͻᳬ�����ٵ�����ռ�
    //Ҫ����Ū�ɻ���Ҫ��������size+1��ʱ����������0�������൱���߼��ϵ�ѭ������
    if (temp == obj->size + 1)
    {
        temp = 0;
    }
    return temp == obj->front;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
    //�������ж��Ƿ���������������򷵻�false
    if (myCircularQueueIsFull(obj))
    {
        return false;
    }
    else
    {
        //��value����tail�±��λ��
        obj->array[obj->tail] = value;
        obj->tail++;
        //��β�±�Խ��ʱ������Ҫ����Ҫ��������һ���±����0�����߼��ϵ�ѭ������
        if (obj->tail == obj->size + 1)
        {
            obj->tail = 0;
        }
        return true;
    }
}

bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
    //�������ж��Ƿ�Ϊ�գ����Ϊ���򷵻�-1
    if (myCircularQueueIsEmpty(obj))
    {
        return false;
    }
    else
    {
        
        //����ɾ���������߼��ϵ�ɾ������front++����
        //��frontһֱ�������п��ܷ���Խ������
        //�ʵ�������size+1ʱ������Ҫ��������һ���±����0�����߼��ϵ�ѭ������
        
        obj->front++;
        if (obj->front == obj->size + 1)
        {
            obj->front = 0;
        }
        return true;
    }
}

int myCircularQueueFront(MyCircularQueue* obj)
{
    //�������ж��Ƿ�Ϊ�գ����Ϊ���򷵻�-1
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    else
    {
        //������ǿգ��ͷ���front��ָ�±��Ԫ��
        return obj->array[obj->front];
    }
}

int myCircularQueueRear(MyCircularQueue* obj)
{
    //�������ж��Ƿ�Ϊ�գ����Ϊ���򷵻�-1
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    else
    {
        //��ʱ�������ǻ�Ҫ����һ���������
        //����tailָ��Ĳ�����β�����Ƕ�β���ݵ���һ��
        //��tail����0ʱ��tail-1��ʱ��Խ�磬������Ҫѭ������
        //��������Ҫ������ǰһ���͵���size�±��λ��
        int temp = obj->tail - 1;
        if (temp == -1)
        {
            temp = obj->size;
        }
        return obj->array[temp];
    }
}

void myCircularQueueFree(MyCircularQueue* obj)
{
    //�ͷ�malloc�����Ŀռ�
    free(obj->array);
    free(obj);
}
*/