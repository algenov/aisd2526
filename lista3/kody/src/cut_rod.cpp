#include "../include/cut_rod.hpp"
#include <iostream>
using namespace std;


long long naive_cut_rod(long long prices[], int n, Counters& cnt){
    cnt.cmp++;
    if (n==0)
    {
        return 0;
    }
    
    long long max_price = -1;
    cnt.assign++;

    for (int i=1; i <= n; i++)
    {
        long long possible_price = prices[i] + naive_cut_rod(prices, n - i, cnt);
        cnt.assign++;
        cnt.cmp++;
        if (possible_price>max_price)
        {
            max_price = possible_price;
            cnt.assign++;
        }
    }
    return max_price;
}

// memorised version shoud get best_prices initialized to -1
long long memorized_cut_rod(long long prices[], int n, long long best_prices[], long long how_to_cut[], Counters& cnt){
    long long max_price = -1;
    cnt.assign++;

    cnt.cmp++;
    if (best_prices[n]>=0)
    {
        return best_prices[n];
    }

    cnt.cmp++;
    if (n==0)
    {
        max_price = 0;
        cnt.assign++;
    }
    else
    {
        for (int i=1; i <= n; i++)
        {
            long long possible_price = prices[i] + memorized_cut_rod(prices, n - i, best_prices, how_to_cut, cnt);
            cnt.assign++;
            cnt.cmp++;
            if (possible_price>max_price)
            {
                max_price = possible_price;
                cnt.assign++;
                how_to_cut[n] = i;
                cnt.assign++;
            }
        }
    }

    best_prices[n] = max_price;
    cnt.assign++;
    return max_price;
}

long long iter_cut_rod(long long prices[], int n, long long best_prices[], long long how_to_cut[], Counters& cnt){
    best_prices[0] = 0;
    cnt.assign++;

    for (int length = 1; length <= n; length++)
    {
        long long max_price = -1;
        cnt.assign++;

        for (int cut_length = 1; cut_length <= length; cut_length++)
        {
            long long possible_price = prices[cut_length] + best_prices[length - cut_length];
            cnt.assign++;
            cnt.cmp++;
            if (possible_price > max_price)
            {
                max_price = possible_price;
                cnt.assign++;
                how_to_cut[length] = cut_length;
                cnt.assign++;
            }
        }
        best_prices[length] = max_price;
        cnt.assign++;
    }
    return best_prices[n];
}

void print_solution(int n, const long long how_to_cut[]) {
    while (n > 0) {
        int cut = how_to_cut[n];
        std::cout << cut << " ";
        n -= cut;
    }
    std::cout << "\n";
}
