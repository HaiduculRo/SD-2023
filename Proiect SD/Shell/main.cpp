#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
ifstream f("1-10^3 aporape random.txt");
ofstream g("radix.out");
int n,sortat[100000006];
int shellSort(int sortat[], int n)
{   for (int salt=n/2; salt>=1; salt/=2)
    {   for (int i=salt; i<=n; i++)
        {   int temp=sortat[i];
            int j;
            for (j=i; j>=salt && sortat[j-salt] > temp; j-=salt)
                sortat[j] = sortat[j-salt];
            sortat[j] = temp;
        }
    }
    return 0;
}
int main()
{   int n,x;
    f>>n;
     for(int i=1; i<=n; i++)
    {   f>>x;
        sortat[i] = x;
    }

    auto start = chrono::steady_clock::now();
    shellSort(sortat,n);
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
