#include <iostream>
using namespace std;
class Stack
{
private:
   int *stk;
   int top;
   int size;

public:
   Stack(int size);
   ~Stack();
   bool isEmpty();
   bool isFull();
   bool push(int data);
   int pop();
   void display();
};

Stack::Stack(int size)
{
   this->size = size;
   stk = new int(size);
   top = -1;
}

Stack::~Stack()
{
}
void Stack::display()
{
   cout << "Data in Stack are::" << endl;
   for (int i = 0; i <= top; i++)
   {
      cout << "data no:" << i + 1 << "\tdata = " << stk[i] << endl;
   }
}
bool Stack::isEmpty()
{
   if (top == -1)
   {
      cout << "Stack underflow" << endl;
      return true;
   }
   return false;
}
bool Stack::isFull()
{
   if (top >= size - 1)
   {
      cout << "Stack overflow" << endl;
      return true;
   }
   return false;
}
bool Stack::push(int data)
{
   if (isFull())
   {
      cout << "No Space in Stack to add data" << endl;
      return false;
   }
   top++;
   stk[top] = data;
   cout << "data added successfully....." << endl;
   return true;
}
int Stack::pop()
{
   if (isEmpty())
   {
      cout << "No data in Stack to delete data" << endl;
      return false;
   }
   int data;
   data = stk[top];
   top--;
   cout << "data deleted successfully....." << endl;
   return data;
}
int main()
{
   int size, choice;
   cout << "Enter the size of stack:" << endl;
   cin >> size;
   Stack stk(size);
   while (1)
   {
      cout << "\nSelect one of the following:-:-" << endl;
      cout << "1) POP" << endl;
      cout << "2) PUSH" << endl;
      cout << "3) DISPLAY" << endl;
      cout << "4) EXIT" << endl;
      cout << "Choose one(1/2/3/4)-" << endl;
      cin >> choice;
      switch (choice)
      {
      case 1:
         cout << "data deleted=" << stk.pop() << endl;
         break;
      case 2:
         int data;
         cout << "Enter data to add in stack:" << endl;
         cin >> data;
         stk.push(data);
         break;
      case 3:
         stk.display();
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
