#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
class LinkedList
{
protected:
    Node *start;

public:
    LinkedList()
    {
        start = NULL;
    }
    Node *createNode()
    {
        Node *temp = new Node();
        if (!temp)
        {
            cout << "Error occurred!!" << endl;
            return NULL;
        }
        return temp;
    }
    bool insertAtBeginning();
    bool insertAtEnd();
    bool insertBeforeNode();
    bool insertAfterNode();
    bool deleteAtBeginning();
    bool deleteAtEnd();
    bool deleteNode();
    void display();
    ~LinkedList()
    {
        delete start;
    }
};
bool LinkedList::insertAtBeginning()
{
    int data;
    cout << "Enter data to add:" << endl;
    cin >> data;
    Node *newNode = createNode();
    newNode->data = data;
    if (start == NULL)
    {
        start = newNode;
        newNode->next = NULL;
    }
    else
    {
        newNode->next = start;
        start = newNode;
    }
    cout << "Insertion SUCCESSFULL!!" << endl;
    return true;
}
bool LinkedList::insertAtEnd()
{
    int data;
    cout << "Enter data to add:" << endl;
    cin >> data;
    Node *newNode = createNode();
    newNode->data = data;
    if (start == NULL)
    {
        start = newNode;
        newNode->next = NULL;
    }
    else
    {
        Node *target = start;
        while (target->next != NULL)
        {
            target = target->next;
        }
        target->next = newNode;
        newNode->next = NULL;
    }
    cout << "Insertion SUCCESSFULL!!" << endl;
    return true;
}
bool LinkedList::insertAfterNode()
{

    int data, nodeData;
    cout << "Enter data of target node:" << endl;
    cin >> nodeData;
    Node *target = start;
    while (target && target->data != nodeData)
    {
        target = target->next;
    }
    if (target == NULL)
    {
        cout << "No such node ERROR!!!" << endl;
        return false;
    }
    cout << "Enter data to add:" << endl;
    cin >> data;
    Node *newNode = createNode();
    newNode->data = data;
    newNode->next = target->next;
    target->next = newNode;
    cout << "Insertion SUCCESSFULL!!" << endl;
    return true;
}
bool LinkedList::insertBeforeNode()
{

    int data, nodeData;
    cout << "Enter data of target node:" << endl;
    cin >> nodeData;
    Node *target = start;
    Node *preTarget = NULL;
    while (target && target->data != nodeData)
    {
        preTarget = target;
        target = target->next;
    }
    if (target == NULL)
    {
        cout << "No such node ERROR!!!" << endl;
        return false;
    }

    cout << "Enter data to add:" << endl;
    cin >> data;

    Node *newNode = createNode();
    newNode->data = data;
    if (target == start)
    {
        newNode->next = start;
        start=newNode;
        cout << "Insertion SUCCESSFULL!!" << endl;
        return true;
    }
    newNode->next = target;
    preTarget->next = newNode;
    cout << "Insertion SUCCESSFULL!!" << endl;
    return true;
}
bool LinkedList::deleteAtBeginning()
{
    if (start == NULL)
    {
        cout << "No item to delete.." << endl;
        return false;
    }
    Node *target = start;
    start = start->next;
    cout << "Deletion SUCCESSFULL!!" << endl;
    cout << "data deleted=" << target->data << endl;
    delete target;
    return true;
}
bool LinkedList::deleteAtEnd()
{
    if (start == NULL)
    {
        cout << "No item to delete.." << endl;
        return false;
    }
    Node *target = start;
    Node *preTarget = NULL;
    while (target && target->next != NULL)
    {
        preTarget = target;
        target = target->next;
    }
    preTarget->next = NULL;
    cout << "Deletion SUCCESSFULL!!" << endl;
    cout << "data deleted=" << target->data << endl;
    delete target;
    return true;
}
bool LinkedList::deleteNode()
{

    int nodeData;
    cout << "Enter data of target node:" << endl;
    cin >> nodeData;
    Node *target = start;
    Node *preTarget = NULL;
    while (target && target->data != nodeData)
    {
        preTarget = target;
        target = target->next;
    }
    if (target == NULL)
    {
        cout << "No such node ERROR!!" << endl;
        return false;
    }
    if (target == start)
    {
        deleteAtBeginning();
        return true;
    }
    if (target->next == NULL)
    {
        deleteAtEnd();
        return true;
    }
    preTarget->next = target->next;
    cout << "Deletion SUCCESSFULL!!" << endl;
    cout << "data deleted=" << target->data << endl;
    delete target;
    return true;
}
void LinkedList::display()
{
    Node *temp = start;
    if (start == NULL)
    {
        cout << "NO data in linked list to display" << endl;
    }
    else
    {
        cout << "DATA IN LINKED LIST ARE:-" << endl;
        while (temp != NULL)
        {
            cout << " * " << temp->data << endl;
            temp = temp->next;
        }
    }
}
int main()
{
    int choice;
    LinkedList l;
    while (1)
    {
        cout << "\nSelect one of the following:-:-" << endl;
        cout << "1) DELETE AT BEGINNING NODE" << endl;
        cout << "2) DELETE AT ENDING NODE" << endl;
        cout << "3) DELETE  INTERMEDIATE NODE" << endl;
        cout << "4) INSERT AT BEGINNING" << endl;
        cout << "5) INSERT AT END" << endl;
        cout << "6) INSERT AFTER A NODE" << endl;
        cout << "7) INSERT BEFORE A NODE" << endl;
        cout << "8) DISPLAY NODE DATA" << endl;
        cout << "9) EXIT" << endl;
        cout << "Choose one(1--10)-" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            l.deleteAtBeginning();
            break;
        case 2:
            l.deleteAtEnd();
            break;
        case 3:
            l.deleteNode();
            break;
        case 4:
            l.insertAtBeginning();
            break;
        case 5:
            l.insertAtEnd();
            break;
        case 6:
            l.insertAfterNode();
            break;
        case 7:
            l.insertBeforeNode();
            break;
        case 8:
            l.display();
            break;
        case 9:
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
