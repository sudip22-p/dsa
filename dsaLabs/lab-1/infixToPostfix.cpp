#include <iostream>
#include <string>

using namespace std;
//class for stack
class Stack
{
private:
   int *stk;
   int top;
   int size;
   string postfix="";

public:
   Stack(int size);
   ~Stack();
   bool isEmpty();
   bool isFull();
   bool push(int data);
   int pop();
   Stack infixToPostfix(Stack ob,string infix);
   string getPostfixExp(){
    return postfix;
   }
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
bool Stack::isEmpty()
{
   if (top == -1)
   {
      return true;
   }
   return false;
}
bool Stack::isFull()
{
   if (top >= size - 1)
   {
      cout << "ERROR!!!" << endl;
      return true;
   }
   return false;
}
bool Stack::push(int data)
{
   if (isFull())
   {
      cout << "ERROR!!!" << endl;
      return false;
   }
   top++;
   stk[top] = data;
   return true;
}
int Stack::pop()
{
   if (isEmpty())
   {
      cout << "ERROR!!!" << endl;
      return false;
   }
   int data;
   data = stk[top];
   top--;
   return data;
}
// Function to return precedence of operators
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

// Function to convert infix to postfix
Stack Stack::infixToPostfix(Stack ob,string infix)
{
    Stack obj=ob;

    for (char c : infix)
    {
        // If the character is an operand, add it to the postfix expression
        if (isalnum(c))
        {
            postfix += c;
        }
        // If the character is an operator
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        {
            // Pop operators with higher or equal precedence and add them to postfix expression
            while (!obj.isEmpty() && precedence(obj.stk[top]) >= precedence(c))
            {
                postfix += obj.stk[top];
                obj.pop();
            }
            // Push the current operator onto the stack
            obj.push(c);
        }
        // If the character is a left parenthesis, push it onto the stack
        else if (c == '(')
        {
            obj.push(c);
        }
        // If the character is a right parenthesis
        else if (c == ')')
        {
            // Pop operators and add them to postfix expression until a left parenthesis is found
            while (!obj.isEmpty() && obj.stk[top]!= '(')
            {
                postfix += obj.stk[top];
                obj.pop();
            }
            // Pop the left parenthesis from the stack
            if (!obj.isEmpty() && obj.stk[top] == '(')
            {
                obj.pop();
            }
        }
    }

    // Pop remaining operators and add them to postfix expression
    while (!obj.isEmpty())
    {
        postfix += obj.stk[top];
        obj.pop();
    }

    return obj;
}

int main()
{
    string infix;
    cout<<"Write the valid infix expression to convert:"<<endl;
    cin>>infix;
    Stack obj(50);
    obj.infixToPostfix(obj,infix);
    string postfix=obj.getPostfixExp();
    cout << "Infix expression: " << infix << endl;
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}
