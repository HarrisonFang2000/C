


#include <iostream>
#include <list>
using namespace std;

int BinarySearch(int myarray[], int n, int key)
{


    int low=0,high=n-1;
    int mid=0;
    while(low<=high)
    {
        mid=(low+high)/2;
        if (myarray[mid]==key)
            return mid;
        if (myarray[mid]<key)
            low=mid+1;

        else
            high=mid-1;

    }
    return -1;
}


int main()
{
    int myarray[]={1,3,4,6,8,7};
    int index=BinarySearch(myarray,6,8);
    if(index!=-1)
        {cout<<"Find it!"<<endl;
        cout << "index is:"<<index<< endl;}
    else
    cout<<"Not Found!"<<endl;

    return 0;
}
