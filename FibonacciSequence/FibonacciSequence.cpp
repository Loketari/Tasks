#include <tchar.h>
#include <iostream>
#include <stdint.h>
#include <unordered_map>

std::unordered_map<int32_t, int64_t> values;

int64_t fib(int32_t n)
{
    if(n == 1 || n == 2)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

int64_t fib2(int32_t n)
{
    if(n == 1 || n == 2)
        return 1;
    else{

        int64_t a, b;

        auto it1 = values.find(n - 1); // search by key
        if(it1 != values.end()) //if exists in container
            a = it1->second; // get velue for this key
        else
        {
            a = fib2(n - 1);
            values.insert({n - 1, a}); // insert new pair:key and processed value by this key
        }

        auto it2 = values.find(n - 2); // search by key
        if(it2 != values.end()) //if exists in container
            b = it2->second; // get velue for this key
        else
        {
            b = fib2(n - 2);
            values.insert({n - 2, b}); // insert new pair:key and processed value by this key
        }

        return a + b;
    }
}

int64_t fib3(int32_t n)
{
    for (int i = 1; i <= n; i++)
    {
        int64_t v;
        if(i == 1 || i == 2)
            v = 1;
        else
            v = values[i - 1] + values[i - 2];

        values.insert({i, v});
    }

     return values[n];
}


int _tmain(int argc, _TCHAR* argv[])
{
    //for(int32_t i = 1; i < 100; i++)
    //    std::cout << i << "=" << fib(i) << std::endl;

    //for(int32_t i = 1; i < 100; i++)
    //    std::cout << i << "=" << fib2(i) << std::endl;

    for(int32_t i = 1; i < 100; i++)
        std::cout << i << "=" << fib3(i) << std::endl;

    return 0;
}

