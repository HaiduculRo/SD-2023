#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
ifstream f("1-10^3 aporape random.txt");
ofstream g("afis.out");
int x, n, sir[100000002];
void bubble(int n, int sir[])
{   bool sortat;
    int m=n;
    do
    {   sortat = true;
        int p = m;
        for(int i=0; i<p-1; ++i)
        {   if(sir[i] > sir[i+1])
            {   int aux = sir[i];
                sir[i] = sir[i+1];
                sir[i+1] = aux;
                sortat = false;
                m = i+1;
            }
        }
    }
    while(!sortat);
}
int main()
{   f>>n;
    for(int i=1;i<=n;i++)
    {   f >> x;
        sir[i] = x;

    }
    auto start = chrono::steady_clock::now();
    bubble(n,sir);
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
    return 0;
}
