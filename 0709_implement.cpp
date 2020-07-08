//
//  test.cpp
//  testing.cpp
//
//  Created by 김영빈 on 2020/07/08.
//  Copyright © 2020 김영빈. All rights reserved.
//

/*****************
  에라토스테네스의 체
*****************/

#include <iostream>
#include <queue>

using namespace std ;

int
main()
{
    cin.tie(NULL) ;
    int N, K, p = 0 ;
    int cnt = 0 ;
    bool flag = true ;
    
    cin >> N >> K ;
    
    bool check[N + 1] ;
    for(int i = 2 ; i <= N ; i++) check[i] = false ;
    
    while(flag)
    {
        // Search "p"
        for(int i = 2 ; i <= N ; i++)
        {
            if(!check[i])
            {
                // cout << cnt + 1 << "번째로 지워진 수는 " << i << "\n" ;
                check[i] = true ;
                cnt++ ;
                if(cnt == K)
                {
                    cout << i << "\n" ;
                    flag = false ;
                }
                p = i ;
                break ;
            }
        }
        // Delete multiple of "p"
        if(flag)
        {
            for(int i = p * p ; i <= N ; i += p)
            {
                // cout << cnt + 1 << "번째로 지워진 수는 " << i << "\n" ;
                if(!check[i])
                {
                    check[i] = true ;
                    cnt++ ;
                    if(cnt == K)
                    {
                        cout << i << "\n" ;
                        flag = false ;
                        break ;
                    }
                }
            }
        }
    }
}

