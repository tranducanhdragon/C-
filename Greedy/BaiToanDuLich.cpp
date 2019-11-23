#include<iostream>
using namespace std;
 
const int size = 20;
 
int maxE = 100;
int maxC = size * maxE;
int C[size][size];  //Ma tran chi phí
int X[size+1];  //X de thu các kha nang
int T[size];  //T[i] de luu chi phí di tu X[1] den X[i]
int BestWay[size+1];  //, BestWay de ghi nhan nghiem
bool FREE[size];  //Free de dánh dau, Free[i]= True neu chua di qua tp i
int minSpending;  //Chi phí hành trình toi uu
int M,N;
 
void input()
{
 
    int i,j,k;
    cout<<"Nhap so thanh pho: ", cin >> N;   //Nhap so thanh pho
    cout<<"Nhap so duong: ", cin >> M;   //Nhap so duong
    for ( i = 1; i <= N; i++ )  //Khoi tao bang chi phí ban dau
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
        C[j][i] = C[i][j];  //Chi phí nhu nhau trên 2 chieu
    }
}
 
void init()
{
    for ( int i = 0; i <= N; i++ )
        FREE[i] = true;
    FREE[1] = false;  //Các thành pho là chua di qua ngoai tru thành pho 1
    X[1] = 1;  //xuat phat tu thanh pho 1
    T[1] = 0;  //Chi phí toi thành pho xuat phát là 0
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
 
void tim(int i)  //Thu các cách chon xi
{
    for ( int j = 2; j <= N; j++ )  //Thu các thành pho tu 2 den n
    {
        if (FREE[j])   //Neu gap thành pho chua di qua
        {
            X[i] = j;
            T[i] = T[i-1] + C[X[i-1]][j];  //Chi phí = Chi phí buoc truoc + chi phí duong di truc tiep
            if ( T[i] < minSpending )   //Hien nhiên neu có dieu này thì C[x[i - 1], j] < +8 roi
            {
                FREE[j] = false;  //Ðánh dau thành pho vua thu
                if(i == N)
                {
                    if ( ( T[N] + C[X[N]][1] ) < minSpending )  // Tu x[n] quay lai 1 van ton chi phí ít hon truoc
                    {
                        for ( int i = 0; i <= N; i++ )  // Cap nhat BestConfig
                            BestWay[i] = X[i];
                        minSpending = T[N] + C[X[N]][1];
                    }
                }
                else tim( i + 1 );  //  Tìm các kha nang chon x[i+1]
                FREE[j] = true;  // Bo dánh dau
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
