#include <iostream>

int main()
{
    int *array = new int[3];

    for (int i = 0; i < 3; i++)
    {
        array[i] = i*10;
    }

    for (int i = 0; i < 3; i++)
    {
        std::cout << array[i];
    }

    delete[] array;

    

    return 0;
}
