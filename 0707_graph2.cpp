//
//  test.cpp
//  testing.cpp
//
//  Created by 김영빈 on 2020/07/08.
//  Copyright © 2020 김영빈. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std ;

bool visit[10000] ;
void bfs(int start, int end) ;
int L_digit(int num) ;
int R_digit(int num) ;

int
main()
{
    cin.tie(NULL) ;
    
    int loop ;
    int start, end ;
    
    cin >> loop ;
    
    for(int i = 0 ; i < loop ; i++)
    {
        cin >> start >> end ;
        bfs(start, end) ;
    }
    
}

void bfs(int start, int end)
{
    queue<pair<int, string>> que ;
    string result = "" ;
    
    for(int i = 0 ; i < 10000 ; i++) visit[i] = false ;
    
    que.push(make_pair(start, result)) ;
    visit[start] = true ;
    
    while(!que.empty())
    {
        auto temp = que.front() ;
        que.pop() ;
        // cout << "String is " << temp.second << "number is " << temp.first << "\n" ;
        if(temp.first == end)
        {
            cout << temp.second << "\n" ;
            break ;
        }
        // D part
        int D_int = (temp.first * 2) % 10000 ;
        if(!visit[D_int])
        {
            if(D_int == end)
            {
                cout << temp.second + "D" << "\n" ;
                break ;
            }
            que.push(make_pair(D_int, temp.second + "D")) ;
            visit[D_int] = true ;
        }
        
        // S part
        int S_int ;
        if(temp.first == 0) S_int = 9999 ;
        else S_int = temp.first - 1 ;
        if(!visit[S_int])
        {
            if(S_int == end)
            {
                cout << temp.second + "S" << "\n" ;
                break ;
            }
            que.push(make_pair(S_int, temp.second + "S")) ;
            visit[S_int] = true ;
        }
                
        // L part
        int L_int = L_digit(temp.first) ;
        if(!visit[L_int])
        {
            if(L_int == end)
            {
                cout << temp.second + "L" << "\n" ;
                break ;
            }
            que.push(make_pair(L_int, temp.second + "L")) ;
            visit[L_int] = true ;
        }
        
        // R part
        int R_int = R_digit(temp.first) ;
        if(!visit[R_int])
        {
            if(R_int == end)
            {
                cout << temp.second + "R" << "\n" ;
                break ;
            }
            que.push(make_pair(R_int, temp.second + "R")) ;
            visit[R_int] = true ;
        }
    }
}

int R_digit(int num)
{
    return (num % 10) * 1000 + (num / 10) ;    
}
int L_digit(int num)
{
    return (num % 1000) * 10 + (num / 1000) ;
}
