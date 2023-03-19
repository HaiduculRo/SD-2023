#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
ifstream f("1-10^3 aporape random.txt");
ofstream g("radix.out");
int b[100000002],k,a[100000002];
void msort(int a[], int st, int dr)
{   if(st>=dr) return;
    int mid=(st+dr)/2;
    msort(a,st,mid);
    msort(a,mid+1,dr);
    int i=st,j=mid+1,k=st-1;
    ///Interclasare
    while(i<=mid and j<=dr)
        if(a[i]<a[j])
        {   k++;
            b[k]=a[i++];
        }
        else
        {   k++;
            b[k]=a[j++];
        }
    while(i<=mid)
    {   k++;
        b[k]=a[i++];
    }
    while(j<=dr)
    {   k++;
        b[k]=a[j++];
    }
    for(int t=st;t<=dr;t++) a[t]=b[t];
}
int main()
{   f>>k;
    for(int i=1;i<=k;i++) f>>a[i];
    auto start = chrono::steady_clock::now();
    msort(a,1,k);
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
    ///for(int i=1;i<=k;i++) cout<<a[i]<<' ';

    return 0;
}
