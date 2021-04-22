#define _CRT_SECURE_NO_WARNINGS 1
/*
232. 用栈实现队列
请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
实现 MyQueue 类：
void push(int x) 将元素 x 推到队列的末尾
int pop() 从队列的开头移除并返回元素
int peek() 返回队列开头的元素
boolean empty() 如果队列为空，返回 true ；否则，返回 false
说明：
你只能使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
进阶：
你能否实现每个操作均摊时间复杂度为 O(1) 的队列？换句话说，执行 n 个操作的总时间复杂度为 O(n) ，即使其中一个操作可能花费较长时间。
示例：
输入：
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
输出：
[null, null, null, 1, 1, false]

解释：
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
链接：https://leetcode-cn.com/problems/implement-queue-using-stacks/
*/

//C++STL模拟实现
/*

class MyQueue
{
public:
    // Initialize your data structure here. 
    stack<int>_inSt;        //只作输入栈
    stack<int>_outSt;       //只作输出栈
    MyQueue()
    {

    }

    // Push element x to the back of queue.
    void push(int x)        //往输入栈中放元素
    {
        _inSt.push(x);
    }

    // Removes the element from in front of queue and returns that element. 
    int pop()
    {
        //如果输出栈中没有元素了，先看看输入栈中有没有元素，有就把输入栈的元素push到输出栈中
        //此时输出栈的top就是队头
        //元素从队头出
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
        //如果输出栈中没有元素了，先看看输入栈中有没有元素，有就把输入栈的元素push到输出栈中
        //此时输出栈的top就是队头
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
        //两个为NULL才为空
        return _outSt.empty() && _inSt.empty();
    }
};
*/


/*622. 设计循环队列
设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。
它也被称为“环形缓冲器”。
循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，
我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。
你的实现应该支持如下操作：
MyCircularQueue(k): 构造器，设置队列长度为 k 。
Front: 从队首获取元素。如果队列为空，返回 -1 。
Rear: 获取队尾元素。如果队列为空，返回 -1 。
enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
isEmpty(): 检查循环队列是否为空。
isFull(): 检查循环队列是否已满。
链接：https://leetcode-cn.com/problems/design-circular-queue/
*/

/*
typedef struct {
    int *array;         //
    int size;           //队列最多能存多少个数据
    int tail;           //尾（队尾数据的下一个）
    int front;          //头
} MyCircularQueue;
//本题思路
//永远空出一个位置，不存储数据
//如果头和尾相等，则证明为空
//如果头和尾的下一个相等，则证明已满

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
    //当头下标与尾下标相同时，则证明队列为空
    return obj->front == obj->tail;
}

bool myCircularQueueIsFull(MyCircularQueue* obj)
{
    //判断尾的下一个是否等于头，相等则已满
    int temp = obj->tail + 1;
    //特殊情况，当tail指向的是最后一个位置的下标，它+1，就会超过开辟的数组空间
    //要把它弄成环就要当它等于size+1的时候，让它等于0，这样相当于逻辑上的循环队列
    if (temp == obj->size + 1)
    {
        temp = 0;
    }
    return temp == obj->front;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
    //首先先判断是否已满，如果已满则返回false
    if (myCircularQueueIsFull(obj))
    {
        return false;
    }
    else
    {
        //把value赋给tail下标的位置
        obj->array[obj->tail] = value;
        obj->tail++;
        //当尾下标越界时，则需要我们要将它的下一个下标等于0，做逻辑上的循环队列
        if (obj->tail == obj->size + 1)
        {
            obj->tail = 0;
        }
        return true;
    }
}

bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
    //首先先判断是否为空，如果为空则返回-1
    if (myCircularQueueIsEmpty(obj))
    {
        return false;
    }
    else
    {
        
        //这里删除我们做逻辑上的删除，即front++即可
        //但front一直自增会有可能发生越界的情况
        //故当它等于size+1时，我们要将它的下一个下标等于0，做逻辑上的循环队列
        
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
    //首先先判断是否为空，如果为空则返回-1
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    else
    {
        //如果不是空，就返回front所指下标的元素
        return obj->array[obj->front];
    }
}

int myCircularQueueRear(MyCircularQueue* obj)
{
    //首先先判断是否为空，如果为空则返回-1
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    else
    {
        //此时这里我们还要处理一种特殊情况
        //由于tail指向的并不是尾，而是队尾数据的下一个
        //当tail等于0时，tail-1此时会越界，由于是要循环队列
        //所以我们要把它的前一个就等于size下标的位置
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
    //释放malloc出来的空间
    free(obj->array);
    free(obj);
}
*/