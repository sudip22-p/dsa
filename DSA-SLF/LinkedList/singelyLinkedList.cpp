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
    bool insertAtBeginning(int data);
    bool insertAtEnd(int data);
    bool insertBeforeNode(int data, int nodeData);
    bool insertAfterNode(int data, int nodeData);
    bool deleteAtBeginning();
    bool deleteAtEnd();
    bool deleteNode(int nodeData);
    void display();
    ~LinkedList()
    {
        delete start;
    }
};
bool LinkedList::insertAtBeginning(int data){
    Node*newNode=createNode();
    newNode->data=data;
    if(start==NULL){
        start=newNode;
        newNode->next=NULL;
    }
    else{
         newNode->next=start;
         start=newNode;
    }
    cout<<"Insertion SUCCESSFULL!!"<<endl;
    return true;
}
bool LinkedList::insertAtEnd(int data){
    Node*newNode=createNode();
    newNode->data=data;
    if(start==NULL){
        start=newNode;
        newNode->next=NULL;
    }
    else{
        Node*target=start;
        while(target->next!=NULL){
            target=target->next;
        }
         target->next=newNode;
         newNode->next=NULL;
    }
    cout<<"Insertion SUCCESSFULL!!"<<endl;
    return true;
}
bool LinkedList::insertBeforeNode(int data,int nodeData){
    Node*newNode=createNode();
    newNode->data=data;
    Node*target=start;
    while (target&&target->data!=nodeData)
    {
        target=target->next;
    }
    if(target==NULL){
        return false;
    }
    newNode->next=target->next;
    target->next=newNode;
    return true;
}
bool LinkedList::insertAfterNode(int data,int nodeData){
    Node*newNode=createNode();
    newNode->data=data;
    Node*target=start;
    Node*preTarget=NULL;
    while (target&&target->data!=nodeData)
    {
        preTarget=target;
        target=target->next;
    }
    if(target==NULL){
        return false;
    }
    if(target==start){
        newNode->next=start;
        start=newNode;
        return true;
    }
    newNode->next=target;
    preTarget->next=newNode;
    return true;
}
bool LinkedList::deleteAtBeginning(){
    if(start==NULL){
        cout<<"No item to delete.."<<endl;
        return false;
    }
    Node*target=start;
    start=start->next;
    cout << "data deleted=" << target->data << endl;
    delete target;
    return true;
}
bool LinkedList::deleteAtEnd(){
    if(start==NULL){
        cout<<"No item to delete.."<<endl;
        return false;
    }
    Node*target=start;
    Node*preTarget=NULL;
    while(target&&target->next!=NULL){
        preTarget=target;
        target=target->next;
    }
    preTarget->next=NULL;
    cout << "data deleted=" << target->data << endl;
    delete target;
    return true;
}
bool LinkedList::deleteNode(int nodeData){
    Node*target=start;
    Node*preTarget=NULL;
    while (target&&target->data!=nodeData)
    {
        preTarget=target;
        target=target->next;
    }
    if(target==NULL){
        cout<<"ERROR!!"<<endl;
        return false;
    }
    preTarget->next=target->next;
    cout << "data deleted=" << target->data << endl;
    delete target;
    return true;
}
void LinkedList::display(){
    Node*temp=start;
    if(start==NULL){
        cout<<"NO data in linked list to display"<<endl;
    }
    else{
        cout<<"DATA IN LINKED LIST ARE:-"<<endl;
        while(temp&&temp->next!=NULL){
            cout<<" * "<<temp->data<<endl;
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
            int nodeData3;
            cout << "Enter data of target node:" << endl;
            cin >> nodeData3;
            l.deleteNode(nodeData3);
            break;
        case 4:
            int data4;
            cout << "Enter data to add:" << endl;
            cin >> data4;
            l.insertAtBeginning(data4);
            break;
        case 5:
            int data5;
            cout << "Enter data to add:" << endl;
            cin >> data5;
            l.insertAtEnd(data5);
            break;
        case 6:
            int data6, nodeData6;
            cout << "Enter data to add:" << endl;
            cin >> data6;
            cout << "Enter data of target node:" << endl;
            cin >> nodeData6;
            l.insertAfterNode(data6, nodeData6);
            break;
        case 7:
            int data7, nodeData7;
            cout << "Enter data to add:" << endl;
            cin >> data7;
            cout << "Enter data of target node:" << endl;
            cin >> nodeData7;
            l.insertBeforeNode(data7, nodeData7);
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