#include <stdio.h>
#include <set>

int printArray(int arr[], int n)
{
    int i = 0;
    for (i = 0; i < n; ++i)
    {
        printf("%d,", arr[i]);
    }

    printf("\n");
}

int main()
{
    std::set<int> numbers{3, 1,4,1,5,9,2,6};
}