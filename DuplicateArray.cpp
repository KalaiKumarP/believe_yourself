#include<iostream>
using namespace std;
int main()
{
    int a,n[10],i,j=0,k;
    cout<<"\nEnter the no of data:";                               //(++j == i)) { arr[j] = arr[i]; } } ++j;
    cin>>a;
    for(i=0;i<a;i++)
    {
        cin>>n[i];
    }
    for(int index=0;index <a;index++)
    {
        for(k=0;k<index;k++)
        {
            if(n[index]==n[k])
            {
                break;
            }
        }

        if(index == k)
        {
            n[j] =n[index];
            j++;
        }
    }

    cout<<"\nThe duplicate array is ...";
    for(i=0;i<a;i++)
    {
        cout<<n[i]<<endl;
    }
    return 0;
}
