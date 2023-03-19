#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
ifstream f("1-10^3 aporape random.txt");
int frecventa[100000004],rez[100000005];
void counting_sort(int rez[], int n)
{   for(int i=1;i<=n;++i)
        frecventa[i]+=1;
    int j=1;
    for(int i=1;i<=n;++i)
        while(frecventa[i]!=0)
        {   rez[j]=i;
            j++;
            frecventa[i]--;
        }
}
int main()
{   int n,x;
    f>>n;
    for(int i=1;i<=n;i++)
    {   f>>x;
        rez[i]=x;
    }
    auto start = chrono::steady_clock::now();
    counting_sort(rez,n);
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
    ///for(int i=0;i<=n;i++) cout<<rez[i]<<' ';

    return 0;
}
