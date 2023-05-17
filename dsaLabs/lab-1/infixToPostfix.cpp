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
   Stack(int size);//initializing Stack class
   ~Stack();//destructor for Stack class
   bool isEmpty();//check stk is empty or not
   bool isFull();//check stk is full or not
   bool push(char data);//push data(operator and parenthesis) to stk
   char pop();//pop data(operator and parenthesis) from stk
   int precedence(char op);//check the precedence of operators and assign integer value accordingly
   void infixToPostfix(string infix);//function for converting infix argument and storing it in postfix string var
   string getPostfixExp()//return postfix when called
   {
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
bool Stack::push(char data)
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
char Stack::pop()
{
   if (isEmpty())
   {
      cout << "ERROR!!!" << endl;//
      return false;
   }
   char data;
   data = stk[top];
   top--;
   return data;
}
int Stack:: precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^'||op == '$')
        return 3;
    return 0;
}
 void Stack::infixToPostfix(string infix)
{
    int length=infix.length();
    for (int i=0;i<length;i++)
    {
        char c=infix[i];
        // If the character is an operand, add it to the postfix expression
        if (isalnum(c))
        {
            postfix += c;
        }
        // If the character is an operator
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^'||c == '$')
        {
            // Pop operators with higher or equal precedence and add them to postfix expression
            while (!isEmpty() && precedence(stk[top]) >= precedence(c))
            {
                postfix += stk[top];
                pop();
            }
            // Push the current operator onto the stack
            push(c);
        }
        // If the character is a left parenthesis, push it onto the stack
        else if (c == '(')
        {
            push(c);
        }
        // If the character is a right parenthesis
        else if (c == ')')
        {
            // Pop operators and add them to postfix expression until a left parenthesis is found
            while (!isEmpty() && stk[top]!= '(')
            {
                postfix += stk[top];
                pop();
            }
            // Pop the left parenthesis from the stack
            if (!isEmpty() && stk[top] == '(')
            {
                pop();
            }
        }
    }

    // Pop remaining operators and add them to postfix expression
    while (!isEmpty())
    {
        postfix += stk[top];
        pop();
    }
}

int main()
{
    string infix;
    cout<<"Write the valid infix expression to convert:"<<endl;
    cin>>infix;
    int size=infix.length();
    Stack obj(size);
    obj.infixToPostfix(infix);
    string postfix=obj.getPostfixExp();
    cout << "Infix expression: " << infix << endl;
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}
