#include <iostream>
#include <time.h>
#include <cstdlib>

int GetRandomNum(const int& min, const int& max)
{
    return (min + rand() % (max - min + 1));
}

int FindSizeSumMaxRange(int*& array, const int& n)
{
    int old_size = 1, new_size = 0;

    for(size_t i = 0; i < n-1; i++)
    {
        if(array[i+1] > array[i])
            new_size++;

        else if(new_size >= old_size)
        {
                new_size++;
                old_size = new_size;
                new_size = 0;
        }
    }

    return old_size;
}

int main()
{
    srand(time(nullptr));
    size_t n;
    std::cin >> n;

    int* array = (int*)calloc(n, sizeof(int));

    for(size_t i = 0; i < n; i++)
    {
        array[i] = GetRandomNum(-5, 5);
        std::cout << "Arr element: " << array[i] << std::endl;
    }

    std::cout << "Size of max range: " << FindSizeSumMaxRange(array, n) << std::endl;

    free(array);

    return 0;
}