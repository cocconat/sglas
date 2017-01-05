#include<iostream>
#include<array>

using namespace std;
void func(int* p, int*& pr)
{
        p++;
            pr++;

}

int main()
{

            int a[3]={1,2,3};
            int * b;
            //array<int,3> d={5,6,7};
            b=a;
            //*(b)=d;
            //std::cout << *(a+1) << std::endl;
            std::cout << *(b+1)<< std::endl;
            //std::cout << *(b+2) << std::endl;

            return 0;
}
