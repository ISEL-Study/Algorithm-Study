#include <iostream>

using namespace std ;

#define MAX 16

void check(int cur, int task, int pay, int N) ;
int Pmax = 0 ;
int T[MAX] ;
int P[MAX] ;

int
main()
{
    cin.tie(NULL) ;
    int N ;
    
    cin >> N ;
    
    for(int i = 1 ; i <= N ; i++) cin >> T[i] >> P[i] ;
    
    for(int i = 1 ; i <= N ; i++)
    {
        if(i + T[i] <= N + 1) //  N일 까지 일할 수 있는 경우가 존재하면 (하루 포함이므로 +1)
            check(i, T[i], P[i], N) ;
    }
    
    cout << Pmax << "\n" ;
}

void check(int cur, int task, int pay, int N)
{
    for(int i = cur + task ; i <= N ; i++)
        if(i + T[i] <= N + 1) check(i, T[i], pay + P[i], N) ;
    
    if(Pmax < pay) Pmax = pay ;
    
    return ;
}
