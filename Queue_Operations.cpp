#include<iostream>
using namespace std;

class Queue
{
    int q[100],f,r,n;
public:
    Queue()
    {
        f=r=-1;
        n=5;
    }
    Queue(int n)
    {
        f=r=-1;
        this->n=n;
    }

    void enqueue(int x)
    {
        if(r==n-1)
        {
            cout<<"queue overflow\n";
            return;
        }
        r+=1;
        q[r]=x;
        if(f==-1)
        {
            f=0;
        }
        return;
    }

    int dequeue()
    {

        if(f==-1)
        {
            cout<<"queue underflow\n";
            return -1;
        }
        int temp=q[f];
        if(r==f)
        {
            r=f=-1;
        }
        f+=1;
        return temp;
    }

    int peek()
    {
        if(f==-1)
        {
            cout<<"queue underflow\n";
            return -1;
        }

        return q[f];
    }


bool isempty()
{
    if(f==-1)
    {
        return true;
    }
    return false;
}


bool isfull()
{
    if(r=n-1)
    {
        return true;
    }
    return false;
}

int search(int x)
{
    if(f==-1)
    {
        cout<<"queue underflow\n";
    }
    for(int i=f;i<=r;i++)
    {
        int pos=0;
        if(q[i]==x)
        {
            pos=i+1-f;
            return pos;
        }
    }
}

void change(int i,int x)
{
    if(f==-1)
    {
        cout<<"queue underflow\n";
        return;
    }
    if(r-i+1<f)
    {
        cout<<"position less than front\n";
        return;
    }
    q[r-i+1]=x;
    return;
}
void display()
{
    if(f==-1)
    {
        cout<<"queue underflow\n";
    }
    for(int i=f;i<=r;i++)
    {
        cout<<q[i]<<" ";
    }
    cout<<endl;
}
};


int main()
{
    Queue q1;
    int s,val,p;
    do
    {
        cout<<"enter 1 for enqueue\n";
        cout<<"enter 2 for dequeue\n";
        cout<<"enter 3 for search\n";
        cout<<"enter 4 for change\n";
        cout<<"enter 5 for isempty\n";
        cout<<"enter 6 for isfull\n";
        cout<<"enter 7 for display\n";
        cout<<"enter 8 for peek\n";
        cout<<"enter 9 for exit\n";
        cout<<"enter your choice : ";
        cin>>s;
        switch(s)
        {
        case 1:
            cout<<"enter element to insert : ";
            cin>>val;
            q1.enqueue(val);
            break;
        case 2:
            cout<<"deleted element is "<<q1.dequeue()<<"\n";
            break;
         case 3:
             cout<<"enter the value : ";
             cin>>p;
             cout<<"position of value is "<<q1.search(p)<<"\n";
             break;
          case 4:
              cout<<"enter the position on which you have to make change : ";
              cin>>p;
              cout<<"enter value to change : ";
              cin>>val;
              q1.change(p,val);
              break;
          case 5:
                if(q1.isempty())
                    cout<<"stack is empty\n";

                else
                    cout<<"stack is not empty\n";
                break;
              case 6:
                if(q1.isfull())
                    cout<<"stack is full\n";
                else
                    cout<<"stack is not full\n";
                break;
          case 7:
            q1.display();
            break;
          case 8:
              cout<<"The peeked element from front is "<<q1.peek()<<endl;
            break;
          case 9:
            break;
          default:
            cout<<"Invalid input\n";
            break;

        }
    }while(s!=9);
q1.display();
}
