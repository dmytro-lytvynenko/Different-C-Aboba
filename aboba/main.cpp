#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
#include <cstdlib>

int GetRandomNum(const int& min, const int& max)
{
    int num = min + rand() % (max - min + 1);
    // std::cout << "In random func: " << num << std::endl;

    return num;
}

struct Range
{
    int begin, end, size, sum;
};

Range* BubbleSort(Range*& ranges, const int& ranges_counter)
{
    Range temp;
 
    for (int i = 0; i < ranges_counter; i++)
    {
        if (ranges[i].size > ranges[i+1].size)
        {
            temp = ranges[i];       
            ranges[i] = ranges[i+1];
            ranges[i+1] = temp;
        }
        if (ranges[i].size == ranges[i+1].size)
        {
            if (ranges[i].sum > ranges[i+1].sum)
            {
                temp = ranges[i];       
                ranges[i] = ranges[i+1];
                ranges[i+1] = temp;
            }
        }
    }
    return ranges;
}

int*& FindMaxIncreasingRange(int*& array, int*& res, int& n)
{
    int it1 = -1, sum = 0, ranges_counter = 0;

    Range* ranges = (Range*)calloc(1, sizeof(Range));
    for (int i = 0; i < n-1; i++)
    {
        if(array[i+1] > array[i])
            sum += array[i];

        else
        {
            sum += array[i];
            
            ranges = (Range*)realloc(ranges, (ranges_counter+1)*sizeof(Range));
            ranges[ranges_counter] = {it1+1, i+1, i+1 - it1+1, sum};
            ranges_counter++;
            // std::cout << "Push back: " << it1+1 << ' ' << i+1 << ' '  
            //     << i+1 - it1+1 << ' ' << sum << std::endl;
            it1 = i;
        }
    }
    BubbleSort(ranges, ranges_counter);

    res = new int[ranges[ranges_counter].size];

    for(int* i = array + ranges[ranges_counter].begin; i <= array + ranges[ranges_counter].end; i++)
    {
        *res = *i;
        ++res;
    }

    free(ranges);

    n = ranges[ranges_counter].size;
    return res;
}

const int Sum(const std::vector<int>& vec)
{
    int sum = 0;
    for(auto el : vec)
        sum += el;

    return sum;
}

int main()
{
    srand(time(NULL));
    int n;
    std::cin >> n;

    int* array = (int*)calloc(n, sizeof(int));

    for(size_t i = 0; i < n; i++)
    {
        array[i] = GetRandomNum(-5, 5);
        std::cout << "Arr elem: " << array[i] << std::endl;
    }
    // std::cout << "Arr " << array << " " << *array << " " << array++ << " " << *(array++) << std::endl;
    int* res = FindMaxIncreasingRange(array, res, n);
    
    free(array);

    std::cout << "Max increasing range: ";
    for(int i = 0; i < n; i++)
        std::cout << res[i] << " ";

    delete[] res;

    std::cout << std::endl;
    return 0;
}