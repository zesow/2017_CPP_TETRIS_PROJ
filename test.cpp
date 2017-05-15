#include <iostream>

int main(void)
{
        int arr[20][10];

        for(int i=0; i<20; i++)
        {
                for(int j=0; j<10; j++)
                {
                        arr[i][j]=0;
                }
        }

        for(int i=0; i<20; i++)
        {
                for(int j=0; j<10; j++)
                {
                        std::cout<<arr[i][j];
                }
                std::cout<<std::endl;
        }
}
