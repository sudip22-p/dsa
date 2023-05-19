#include <iostream>
#include <string.h>
using namespace std;
class LinearQueue
{
protected:
    int rear, front;
    int *queue;
    int size;

public:
    LinearQueue(int size)
    {
        this->size = size;
        queue = new int(size);
        rear = -1;
        front = -1;
    }
    bool isEmpty(); // check q is empty or not.
    bool isFull();  // check q is full or not.
    bool enqueue(int data);
    int dequeue();
    void display();
    ~LinearQueue()
    {
        delete queue;
    }
};
bool LinearQueue::isEmpty()
{
    if ((front == -1 && rear == -1) || (front > rear))
    {
        cout << "Q UNDERFLOW!!!" << endl;
        return true;
    }
    return false;
}
bool LinearQueue::isFull()
{
    if (rear == size - 1)
    {
        cout << "Q OVERFLOW!!!" << endl;
        return true;
    }
    return false;
}
bool LinearQueue::enqueue(int data)
{
    if (isFull())
    {
        cout << "enque failure....." << endl;
        return false;
    }
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = data;
        cout << "enque success....." << endl;
        return true;
    }
    rear++;
    queue[rear] = data;
    cout << "enque success....." << endl;
    return true;
}
int LinearQueue::dequeue()
{
    if (isEmpty())
    {
        cout << "No data in Q!!!" << endl;
        return 0;
    }
    int data = queue[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
    cout << "dequeue success....." << endl
         << "data removed:" << data << endl;
    return front;
}
void LinearQueue::display()
{
    if (isEmpty())
    {
        cout << "NO DATA TO DISPLAY!!" << endl;
    }
    else
    {
        cout << "Data in queue ARE:" << endl;
        for (int i = front; i <= rear; i++)
        {
            cout << " * " << queue[i] << endl;
        }
    }
}
int main()
{
    int size, choice;
    cout << "Enter the size of queue:" << endl;
    cin >> size;
    LinearQueue q(size);
    while (1)
    {
        cout << "\nSelect one of the following:-:-" << endl;
        cout << "1) ENQUEUE" << endl;
        cout << "2) DEQUEUE" << endl;
        cout << "3) DISPLAY" << endl;
        cout << "4) EXIT" << endl;
        cout << "Choose one(1/2/3/4)-" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            int data;
            cout << "Enter data to add in queue:" << endl;
            cin >> data;
            q.enqueue(data);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "Exited succesfully......" << endl;
            exit(0);
            break;
        default:
            cout << "choose a valid number:" << endl;
            break;
        }
    }
    return 0;
}
