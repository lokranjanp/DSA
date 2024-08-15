#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val = 0;
    Node *next = nullptr;

    Node() {}

    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }

    Node(int val, Node *next) {
        this->val = val;
        this->next = next;
    }

    Node *createlist();

    static void printlist(Node *node);

    Node *insertend(Node *head, int data);

    Node* insertfront(Node *head, int data);

    Node *deletefront(Node *head);

    Node *deleteend(Node *head);

    Node *insertafter(Node *head, int data, int key);

};

    Node* Node::createlist()
    {
        int inputval = 0;
        cin>>inputval;
        Node *head = new Node(inputval);
        Node *ptr = head;
        cin>>inputval;
        while(inputval!=-1)
        {
            Node *newnode = new Node(inputval);
            ptr->next = newnode;
            ptr = newnode;
            newnode->next = NULL;
            cin>>inputval;
        }

        return head;
    }

    void Node::printlist(Node *node)
    {
        while(node != nullptr)
        {
            cout << node->val << " ";
            node = node->next;
        }
        cout<<endl;
    }

    Node* Node::insertend(Node *head, int data)
    {
        Node *newnode = new Node(data);
        if (head == nullptr)
            return newnode;

        Node *temp = head;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        return head;
    }

    Node* Node::insertfront(Node *head, int data)
    {
        Node *newnode = new Node(data);
        newnode->next = head;
        return newnode;
    }

    Node* Node::deletefront(Node *head)
    {
        if (head == nullptr)
            return nullptr;

        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* Node::deleteend(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            delete head;
            return nullptr;
        }

        Node *temp = head;
        while(temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        return head;
    }

    Node* Node::insertafter(Node *head, int data, int key)
    {
        Node *ptr = head;

        while(ptr != nullptr && ptr->val != key)
        {
            ptr = ptr->next;
        }

        if (ptr == nullptr)
        {
            // Key not found
            return head;
        }

        Node *newnode = new Node(data);
        Node *temp = ptr->next;
        ptr->next = newnode;
        newnode->next = temp;

        return head;
    }


int main()
{
    Node obj;
    Node *head = obj.createlist();
    obj.printlist(head);
    return 0;
}