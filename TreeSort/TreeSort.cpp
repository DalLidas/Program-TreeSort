#include "pch.h"
#include "TreeSortClass.h"

int main()
{
    std::vector<double> a = { 1, 5, 7, 9, 2, 7, 8, 9 };

    TreeSortClass tsc;

    tsc.TreeSort(a);

    for (auto i = a.begin(); i != a.end(); ++i) {
        std::cout << std::endl << *i << " " ;
    }

    return 0;
}
