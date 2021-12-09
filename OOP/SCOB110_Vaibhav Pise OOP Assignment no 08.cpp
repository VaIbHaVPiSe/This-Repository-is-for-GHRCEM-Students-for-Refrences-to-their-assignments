#include <iostream>
using namespace std;
int main()
{
    int *ptr1 = NULL;  // pointer initialization to null
    ptr1 = new int;  // using new operator
    float *ptr2 = new float(1.5);
    int *ptr3 = new int[2];
    *ptr1 = 2;
    cout << "VALUE 1 --> " << *ptr1 << endl;
    cout << "VALUE 2 --> " << *ptr2 << endl;
    if (!ptr3)
        cout << "Allocation of memory failed\n";
    else
    {
        for (int i = 10; i < 15; i++)
            ptr3[i] = i + 1;
        cout << "Value of store in block of memory: ";
        for (int i = 10; i < 15; i++)
            cout << ptr3[i] << " ";
    }
    delete ptr1;
    delete ptr2;
    cout<<" \n Memory is allocated "<<endl;
    delete[] ptr3;
    return 0;
}
