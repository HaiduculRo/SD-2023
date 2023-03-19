#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
ifstream f("citire.txt");
ofstream g("radix.out");
int x,buckets[1000000],maxx,sortat[100000002],aux[100000002];
void radix(int k,int sortat[], int maxim, int n)
{   int p=1;
    while(maxim)
    {   ///int k=10;
        for(int i=1;i<=n;++i)
            ++ buckets[sortat[i]/p%k];

        for(int i=1;i<k;++i)
            buckets[i] += buckets[i-1];
        for(int i=n; i>=1;--i)
        {   int poz = sortat[i]/p%k;
            aux[buckets[poz]] = sortat[i];
            buckets[poz] --;
        }

        for(int i=1;i<=n;++i)
            sortat[i] = aux[i];
        for(int i=0;i<k;++i)
            buckets[i] = 0;
        maxim/=k;
        p*=k;
    }
}

int main()
{   int n,k;
    cin>>k;
    f>>n;
    int maxx=-1;
    for(int i=1; i<=n; i++)
    {   f>>x;
        if(maxx < x)
            maxx = x;
        sortat[i] = x;
    }
    auto start = chrono::steady_clock::now();
    radix(k,sortat,maxx,n);
    auto end = chrono::steady_clock::now();

     cout << "Elapsed time in seconds: "
        << chrono::duration_cast<chrono::seconds>(end - start).count()
        << " sec"<< endl;

     cout << "Elapsed time in milliseconds: "
        << chrono::duration_cast<chrono::milliseconds>(end - start).count()
        << " ms" << endl;

        cout << "Elapsed time in nanoseconds: "
        << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
        << " ns" << endl;
    ///for(int i=1;i<=n;i++) cout<<sortat[i]<<' ';

    return 0;
}


/**
 int a=61;
    int b=16;
    unsigned int numar = 0b11010110;
    unsigned int ultimii_4_biti = numar & 0b1111;
    cout<< ultimii_4_biti<<'\n';
    int c = a & 16;
    cout<<c;
*/

