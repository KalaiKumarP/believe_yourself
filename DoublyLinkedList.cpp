#include <iostream>
using namespace std;
//Structure create
struct node
{
    int data;
    struct node *next;
    struct node *pre;
};
struct node *head,*temp,*newnode;
class DoublyList
{
    int i=0,s;
public:
    //create a doubly list
    void create(int n)
    {
        head =nullptr;
        for(i;i<n;i++)
        {
            newnode = new node;
            cout<<"\nEnter the Data:";
            cin>>newnode->data;
            newnode->next = nullptr;
            newnode->pre = nullptr;
            if(head==NULL)
            {
                head=newnode;
                temp=newnode;
            }
            else
            {
                temp->next=newnode;
                newnode->pre=temp;
                temp=newnode;
            }
        }
    }
    //display the doubly list
    void display()
    {
        temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    //inserte at beginning
    void insertb(int a)
    {
        temp = head;
        newnode=new node;
        newnode->data=a;
        newnode->next=temp;
        temp->pre=newnode;
        head=newnode;
    }
    //insert at end
    void inserte(int a)
    {
        temp=head;
        newnode = new node;
        newnode->next=nullptr;
        newnode->pre=nullptr;
        newnode->data=a;
        while(temp->next!=nullptr)
        {
            temp= temp->next;
        }
        temp->next=newnode;
        newnode->pre=temp;
        temp=newnode;
    }
    //insert at specific point
    void insertp(int val,int p)
    {
        temp=head;
        newnode=new node;
        newnode->data=val;
        newnode->next=nullptr;
        newnode->pre = nullptr;
        for(int i=0;i<p-1;i++)
        {
            temp= temp->next;
        }
        newnode->next=temp->next;
        newnode->pre=temp;
        temp->next->pre=newnode;
        temp->next=newnode;
    }
    //delete a node in beginning
    void delb()
    {
        temp=head;
        head = temp->next;
        head->pre=nullptr;
    }
    //delete a node in end
    void dele()
    {
        temp=head;
        while(temp->next->next!=nullptr)
        {
            temp=temp->next;
        }
        temp->next=nullptr;
    }
    //delete a node in specific position
    void delp(int p)
    {
        temp = head;
        for(int i=0;i<p-1;i++)
        {
            temp =temp->next;
        }
        temp->next= temp->next->next;
        //temp->next->next->pre=temp;
    }
};

int main()
{
    cout<<"\nImplementation of Doubly Linked list ";
    cout<<"\n1 : Insert at Beginning \n2 : Insert at End \n3 : Insert at Position"<<endl;
    cout<<"\n4 : Delete at Beginning \n5 : Delete at End \n6 : Delete at Position"<<endl;
    cout<<"\n7 : Display\n8 : Create a list"<<endl;
    int ch,val,p,n;
    DoublyList obj;
    do
    {
       cout<<"\nEnter the choise :";
       cin>>ch;
       switch(ch)
       {
       case 1:
            cout<<"Enter the data :"<<endl;
            cin>>val;
            obj.insertb(val);
            break;
       case 2:
            cout<<"Enter the data :"<<endl;
            cin>>val;
            obj.inserte(val);
            break;
       case 3:
            cout<<"Enter the data : "<<endl;
            cin>>val;
            cout<<"Enter the position (start with o) : ";
            cin>>p;
            obj.insertp(val,p);
            break;
       case 4:
            obj.delb();
            break;
       case 5:
            obj.dele();
            break;
       case 6:
            cout<<"Enter the position (start with 0) :";
            cin>>p;
            obj.delp(p);
            break;
       case 7:
            obj.display();
            break;
       case 8:
            cout<<"No of node you enter :";
            cin>>n;
            obj.create(n);
            break;
       }
    }while(ch<9);
    return 0;
}
