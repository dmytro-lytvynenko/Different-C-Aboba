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

std::vector<int> FindMaxIncreasingRange(const std::vector<int>& array)
{
    int it1 = -1, sum = 0;

    std::vector<Range> ranges;
    for (int i = 0; i < array.size(); i++)
    {
        if(array[i+1] > array[i])
            sum += array[i];

        else
        {
            sum += array[i];
            ranges.push_back({it1+1, i+1, i+1 - it1+1, sum});
            // std::cout << "Push back: " << it1+1 << ' ' << i+1 << ' '  
            //     << i+1 - it1+1 << ' ' << sum << std::endl;

            sum = 0;
            it1 = i;
        }
    }
    std::sort(ranges.begin(), ranges.end(), 
    [](const Range& a, const Range& b) 
    {
        if(a.size == b.size)
            return a.sum < b.sum;

        return a.size < b.size;
    });

    return {array.begin() + ranges[ranges.size()-1].begin, array.begin() + ranges[ranges.size()-1].end};
}

const int Sum(const std::vector<int>& vec)
{
    int sum = 0;
    for(const auto& el : vec)
        sum += el;

    return sum;
}

int main()
{
    srand(time(NULL));
    int n;
    std::cin >> n;

    std::vector<int> array;

    for(int i = 0; i < n; i++)
    {
        array.push_back(GetRandomNum(-5, 5));
        std::cout << "Arr elem: " << array[i] << std::endl;
    }
    // std::cout << "Arr " << array << " " << *array << " " << array++ << " " << *(array++) << std::endl;
    std::vector<int> range = FindMaxIncreasingRange(array);

    std::cout << "Max increasing range: ";
    for(const auto& element : range)
        std::cout << element << " ";

    std::cout << std::endl;
    return 0;
}