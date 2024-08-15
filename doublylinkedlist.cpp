#include <bits/stdc++.h>
using namespace std;

class DNode {
public:
    int val;
    DNode *next;
    DNode *prev;

    DNode() {}

    DNode(int data) {
        this->val = data;
        this->next = nullptr;
        this->prev = nullptr;
    }

    DNode(int data, DNode *nextnode, DNode *prevnode) {
        this->val = data;
        this->next = nextnode;
        this->prev = prevnode;
    }

    void printlist(DNode *head);

    DNode *createlist();

};
    void DNode::printlist(DNode *head)
    {
        while(head != nullptr)
        {
            cout<<head->val<<"  ";
            head = head->next;
        }
        cout<<endl;
    }

    DNode * DNode::createlist()
    {
        cout<<"Enter the value of the node :";
        int inputval;
        cin>>inputval;
        DNode *head = new DNode(inputval);
        head->prev = nullptr;
        DNode *ptr = head;

        cout<<"Enter the value of the node :";
        cin>>inputval;
        while(inputval!=-1)
        {
            DNode *newnode = new DNode(inputval);
            ptr->next = newnode;
            newnode->prev = ptr;
            newnode->next = nullptr;
            ptr = newnode;
            cout<<"Enter the value of the node :";
            cin>>inputval;
        }

        return head;
    }


int main()
{
    DNode obj;
    DNode *head = obj.createlist();
    obj.printlist(head);

    return 0;
}