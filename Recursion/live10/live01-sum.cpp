//============================================================================
// Name        : live01-sum.cpp
// Author      : 
// Version     :
// Copyright   :
// Description : Sum of the first n naturals implemented in several iterative or
//				 recursive ways
//============================================================================

#include<iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;



// Sum of arithmetic series 1..n, i.e. 1+..+n

// smart implementation :)  //O(1) because the interation of the loop dosn't depands on the n.
unsigned int sum_fast(unsigned int n){

    return (n* (n+1.0)) / 2 ;

}

// iterative implementation //O(n) because the interation of the loop depands on the n.
unsigned int sum_iter(unsigned int n){

    unsigned int sum = 0;
    for(unsigned int i=1; i<=n; i++){
        sum += i;
    }

    return sum;
}

// Three different implementations using recursion

unsigned int sum_rec1(unsigned int n){
    unsigned int r = 0;
    if (n > 0) {
        r = sum_rec1(n-1);
    }
    r = r + n;
    return r;
}

unsigned int sum_rec2(unsigned int n){
    if (n == 0) {
        return 0;
    } else {
        return n + sum_rec2(n-1);
    }
}

unsigned int sum_rec3(unsigned int n, unsigned int r=0){
    if (n==0) {
        return r;
    }
    return sum_rec3(n-1,n+r);
}

//the time of five different method : 0 23 183 47 47 (ms)
int main(){

    unsigned int n;

    // Try with with big numbers, e.g. 1000000
    // Compare compilation with and without optimization (-O3)

    // Ordinary compilation like
    // g++ -o live01-sum live01-sum.cpp
    // may make the program fail (segmentation fault)

    // Optimized compilation like
    // g++ -o live01-sum -O3 live01-sum.cpp
    // may make the program run forever

    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    int res=0;

    cout << "Give me a non-negative integer: " ;
    cin >> n;
    cout << "Computing sum(1.." << n << ") using sum_fast... ";
    t1 = high_resolution_clock::now();
    res = sum_fast(n);
    t2 = high_resolution_clock::now();
    cout << res << " in " << duration_cast<microseconds>( t2 - t1 ).count() << " microseconds" <<endl;
    cout << "Computing sum(1.." << n << ") using sum_iter... ";
    //cout << sum_iter(n) << endl;
    t1 = high_resolution_clock::now();
    res = sum_iter(n);
    t2 = high_resolution_clock::now();
    cout << res << " in " << duration_cast<microseconds>( t2 - t1 ).count() << " microseconds" <<endl;
    cout << "Computing sum(1.." << n << ") using sum_rec3... ";
    //cout << sum_rec3(n) << endl;
    t1 = high_resolution_clock::now();
    res = sum_rec3(n);
    t2 = high_resolution_clock::now();
    cout << res << " in " << duration_cast<microseconds>( t2 - t1 ).count() << " microseconds" <<endl;
    cout << "Computing sum(1.." << n << ") using sum_rec2... ";
    //cout << sum_rec2(n) << endl;
    t1 = high_resolution_clock::now();
    res = sum_rec2(n);
    t2 = high_resolution_clock::now();
    cout << res << " in " << duration_cast<microseconds>( t2 - t1 ).count() << " microseconds" <<endl;
    cout << "Computing sum(1.." << n << ") using sum_rec1... ";
    //cout << sum_rec1(n) << endl;
    t1 = high_resolution_clock::now();
    res = sum_rec1(n);
    t2 = high_resolution_clock::now();
    cout << res << " in " << duration_cast<microseconds>( t2 - t1 ).count() << " microseconds" <<endl;

    return 0;
}
