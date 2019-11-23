#include<iostream>
using namespace std;
 
const int size = 20;
 
int maxE = 100;
int maxC = size * maxE;
int C[size][size];  //Ma tran chi ph�
int X[size+1];  //X de thu c�c kha nang
int T[size];  //T[i] de luu chi ph� di tu X[1] den X[i]
int BestWay[size+1];  //, BestWay de ghi nhan nghiem
bool FREE[size];  //Free de d�nh dau, Free[i]= True neu chua di qua tp i
int minSpending;  //Chi ph� h�nh tr�nh toi uu
int M,N;
 
void input()
{
 
    int i,j,k;
    cout<<"Nhap so thanh pho: ", cin >> N;   //Nhap so thanh pho
    cout<<"Nhap so duong: ", cin >> M;   //Nhap so duong
    for ( i = 1; i <= N; i++ )  //Khoi tao bang chi ph� ban dau
    {
        for ( j = 1; j <= N; j++ )
        {
            if ( i == j ) C[i][j] = 0;
            else C[i][j] = maxC;
        }
    }
 
    for ( int k = 1; k <= M; k++ )
    {
        cout<<"Nhap thanh pho ban muon di: ", cin >> i;  //Nhap thanh pho bat dau
        cout<<"Nhap thanh pho den: ",cin >> j;  //Nhap thanh pho den
        cout<<"Nhap gia di: ",cin >> C[i][j];  //Nhap gia di tu thanh pho i den j
        C[j][i] = C[i][j];  //Chi ph� nhu nhau tr�n 2 chieu
    }
}
 
void init()
{
    for ( int i = 0; i <= N; i++ )
        FREE[i] = true;
    FREE[1] = false;  //C�c th�nh pho l� chua di qua ngoai tru th�nh pho 1
    X[1] = 1;  //xuat phat tu thanh pho 1
    T[1] = 0;  //Chi ph� toi th�nh pho xuat ph�t l� 0
    minSpending = maxC;
}
 
void output()
{
    if ( minSpending == maxC )
        cout << "NO SOLUTION ";
    else
    {
        for ( int i = 1; i <= N; i++ )
            cout << BestWay[i] << "->";
        cout << "1" << endl;
        cout << "Cost : " << minSpending;
    }
}
 
void tim(int i)  //Thu c�c c�ch chon xi
{
    for ( int j = 2; j <= N; j++ )  //Thu c�c th�nh pho tu 2 den n
    {
        if (FREE[j])   //Neu gap th�nh pho chua di qua
        {
            X[i] = j;
            T[i] = T[i-1] + C[X[i-1]][j];  //Chi ph� = Chi ph� buoc truoc + chi ph� duong di truc tiep
            if ( T[i] < minSpending )   //Hien nhi�n neu c� dieu n�y th� C[x[i - 1], j] < +8 roi
            {
                FREE[j] = false;  //��nh dau th�nh pho vua thu
                if(i == N)
                {
                    if ( ( T[N] + C[X[N]][1] ) < minSpending )  // Tu x[n] quay lai 1 van ton chi ph� �t hon truoc
                    {
                        for ( int i = 0; i <= N; i++ )  // Cap nhat BestConfig
                            BestWay[i] = X[i];
                        minSpending = T[N] + C[X[N]][1];
                    }
                }
                else tim( i + 1 );  //  T�m c�c kha nang chon x[i+1]
                FREE[j] = true;  // Bo d�nh dau
            }
        }
    }
}
 
int main()
{
    input();
    init();
    tim(2);
    output();
}
