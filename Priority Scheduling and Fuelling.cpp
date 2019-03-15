#include<iostream>
#include<stdio.h>
#include<unistd.h>

using namespace std;

//int timer=0;

struct plane
{
    string name;
    int arr_time;
    int passengers;
    int fuel;
    bool vip=false;
}a[5],priority[5];

void input()
{
    char ch;int index=-1;
    for(int i=0;i<5;i++)
    {
        cout<<endl<<"Enter Plane name: ";
        cin>>a[i].name;
        cout<<"Enter Arrival order: ";
        cin>>a[i].arr_time;
        cout<<"Enter Passenger count: ";
        cin>>a[i].passengers;
        cout<<"Is the Plane a VIP? ";
        cin>>ch;
        if(ch=='Y'|| ch=='y')
        {
            a[i].vip=true;
        }
    }
    
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(a[j].passengers>a[j+1].passengers)
            {
                plane t;
                t=a[j+1];
                a[j+1]=a[j];
                a[j]=t;
            }
        }
    }
    for(int i=0;i<5;i++)
    {
        if(a[i].vip==true)
        {
            index++;
            priority[index]=a[i];
        }
    }
    for(int i=0;i<5;i++)
    {
        if(a[i].vip=false)
        {
            index++;
            priority[index]=a[i];
        }
    }
}

int c[5]={1,1,1,1,1};

void process()
{
    plane offloading_queue[5]; int idx=-1;
    int count=0;
    int flag[5]={0,0,0,0,0};
    do
    {
        for(int i=0;i<5;i++)
        {
            a[i].passengers-=10;
            if(flag[i]==0)
            {
                if(a[i].passengers<=0)
                {
                    flag[i]=1;
                    cout<<endl<<"Offloading: "<<a[i].name<<"   No.of bus trips: "<<c[i];
                    idx++;
                    offloading_queue[idx]=a[i];
                    count++;
                }
                else
                {
                    c[i]++;
                }
                
            }
        }
    }while(count!=5);
    
    int avg=0;
    for(int i=0;i<5;i++)
    {
        avg=avg+c[i];
    }
    avg=avg/5;
    cout<<endl<<"Average waiting time is: "<<avg*2;

    for(int i=0;i<5;i++)
    {
        //incrementing the fuel of every plane
        while(offloading_queue[i].fuel!=150)
        {
            //incrementing till fuel doesnt reach the cap limit of 150
            offloading_queue[i].fuel++;
        }
        cout<<endl<<"Plane "<<a[i].name<<" is done with fuelling\n";
    }
}

int main()
{
    input();
    process();
}
