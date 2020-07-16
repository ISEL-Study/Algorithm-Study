#include <iostream>
#include <vector>

using namespace std ;

int
main()
{
    cin.tie(NULL) ;
    
    int N, loop, first, second, j ;
    int cnt = 0 ;
    
    cin >> N ;
    
    while(N--)
    {
        cin >> loop ;
        
        vector<int> person(loop + 1, 0);
        
        for(int i = 0 ; i < loop ; i++)
        {
            scanf("%d %d", &first, &second) ;
            
            person[first] = second ;
        }
        
        for(int i = 1 ; i < loop ; i++)
        {
            for(j = 1 ; j < i ; j++) if(person[i] > person[j]) break ;
            if(j == i)
            {
                // cout << i << " " << person[i] << "\n" ;
                cnt++ ;
            }
        }
        
        if(person[loop] == 1) cnt++ ;
    
        cout << cnt << "\n" ;
        cnt = 0 ;
    }
    
}

