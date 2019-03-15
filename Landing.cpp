#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

void bubbleSort();
void VIPPlanes();
void midWayRefuel();
void LockRunway();
void UnlockRunway();
void LandPlane(int);

bool runwayfree=true;
int countOfIndex=0;
struct plane
{
    string name;
    int index;
    int fuel;
    int passengers;
    int staff_present;
    int staff_required; //Total requirement for it to be able to fly
    bool priority=false;
};

int staff_available=3; //staff available on the ground ready to fly
int n;
struct plane a[10];
int landingList[10];
int refuelingList[10];
int semaphore=0;
void enterdetails()
{
    srand (time(0));
    cout<<"Enter number of planes arriving at the Airport: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"\n Enter plane name for plane "<<i+1<<": ";
        cin>>a[i].name;
        cout<<" Enter number of passengers in plane "<<a[i].name<<": ";
        cin>>a[i].passengers;
        char priority_choice;
        cout<<" Is it a VIP plane?(y/n): ";
        cin>>priority_choice;
        if(priority_choice=='y'||priority_choice=='Y')
        {
            a[i].priority=true;
        }
        else if(priority_choice=='n'||priority_choice=='N')
        {
            a[i].priority=false;
        }
        else
        {
            cout<<"Invalid Input";
        }
        a[i].fuel=(rand() % 100 + 50)%100;
        cout<<" Fuel in Plane "<<a[i].name<<": "<<a[i].fuel;
        a[i].staff_present=rand() % 10 + 3;
        cout<<endl<<" Staff present in plane "<<a[i].name<<" is: "<<a[i].staff_present<<"\n";
        a[i].index=countOfIndex;
        countOfIndex++;
    }

}
int findSmallestElement()
    {
       int temp = 0;
       for(int i=0; i<n; i++) {
          if(a[temp].fuel>a[i].fuel) {
             temp=i;
          }
       }
       return temp;
    }
int flag=0;

void swaps(int *xp, int *yp)
    {
        int temp = *xp;
        *xp = *yp;
        *yp = temp;
    }

int main()
{
    for(int i=0;i<n;i++)
    {
        landingList[i]=a[i].index;
    }
    enterdetails();
    bubbleSort();
    VIPPlanes();
    midWayRefuel();
    LandPlane(2);
    LockRunway();
    LandPlane(0);
    UnlockRunway();
    LandPlane(1);
}
void bubbleSort()
    {
       int i,j;
       for (i=0;i<n-1;i++)
           for (j=0;j<n-i-1;j++)
               if (a[j].fuel>a[j+1].fuel)
                  swaps(&a[j].index, &a[j+1].index);
    }

void VIPPlanes()
    {
        int counter=0;
        for(int i=0;i<n;i++)
        {
            if(a[i].priority==true)
            {
                swaps(&a[i].index, &a[counter].index);
                counter++;
            }
        }
    }

void midWayRefuel()
{
    for(int i=0;i<n;i++)
    {
        if(a[i].fuel<10*i)
        {
            cout<<"Plane needs mid-air refueling: "<<a[i].name<<endl;
            a[i].fuel+=100;
        }
    }
}

void LockRunway()
{
    if(semaphore==0)
    {
        cout<<"Locking runway."<<endl;
        cout<<"Runway Locked."<<endl;
        semaphore=1;
    }
    else
        cout<<"Runway already locked."<<endl;
}

void UnlockRunway()
{
    if(semaphore==1)
    {
        cout<<"Unlocking runway."<<endl;
        cout<<"Runway unlocked successfully."<<endl;
        semaphore=0;
    }
    else
        cout<<"Runway already unlocked."<<endl;
}

void LandPlane(int index)
{
    LockRunway();
    cout<<"Plane "<<a[index].name<<" has landed successfully!"<<endl;
    UnlockRunway();
}
