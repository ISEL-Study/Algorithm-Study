#include <iostream>
#include <queue>

using namespace std ;

char map[101][101] ;
char variant_map[101][101] ;
bool visit[101][101] = { false } ;
bool variant_visit[101][101] = { false } ;

int x[4] = {0, 1, -1, 0} ;
int y[4] = {1, 0, 0, -1} ;

int
main()
{
    cin.tie(NULL) ;
    
    int N ;
    int org_cnt = 0, var_cnt = 0 ;
    queue<pair<int, int>> que ;
    queue<pair<int, int>> var ;
    
    cin >> N ;
    
    for(int i = 1 ; i <= N ; i++)
    {
        for(int j = 1 ; j <= N ; j++)
        {
            cin >> map[i][j] ;
            if(map[i][j] == 'G') variant_map[i][j] = 'R' ;
            else variant_map[i][j] = map[i][j] ;
        }
    }
    
    for(int i = 1 ; i <= N ; i++)
    {
        for(int j = 1 ; j <= N ; j++)
        {
            if(!visit[i][j])
            {
                que.push(make_pair(i, j)) ;
                visit[i][j] = true ;
                org_cnt++ ;
            }
            
            if(!variant_visit[i][j])
            {
                var.push(make_pair(i, j)) ;
                variant_visit[i][j] = true ;
                var_cnt++ ;
            }
            
            while(!que.empty())
            {
                auto x_cor = que.front().first ;
                auto y_cor = que.front().second ;
                
                que.pop() ;
                
                for(int i = 0 ; i < 4 ; i++) // Check range
                {
                    if(x_cor + x[i] <= N && x_cor + x[i] >= 1) // About x cor
                    {
                        if(y_cor + y[i] <= N && y_cor + y[i] >= 1) // About y cor
                        {
                            if(map[x_cor][y_cor] == map[x_cor + x[i]][y_cor + y[i]] && !visit[x_cor + x[i]][y_cor + y[i]])
                            {
                                que.push(make_pair(x_cor + x[i], y_cor + y[i])) ;
                                visit[x_cor + x[i]][y_cor + y[i]] = true ;
                            }
                        }
                    }
                }
            }
            
            while(!var.empty())
            {
                auto x_cor = var.front().first ;
                auto y_cor = var.front().second ;
                
                var.pop() ;
                
                for(int i = 0 ; i < 4 ; i++) // Check range
                {
                    if(x_cor + x[i] <= N && x_cor + x[i] >= 1) // About x cor
                    {
                        if(y_cor + y[i] <= N && y_cor + y[i] >= 1) // About y cor
                        {
                            if(variant_map[x_cor][y_cor] == variant_map[x_cor + x[i]][y_cor + y[i]] && !variant_visit[x_cor + x[i]][y_cor + y[i]])
                            {
                                var.push(make_pair(x_cor + x[i], y_cor + y[i])) ;
                                variant_visit[x_cor + x[i]][y_cor + y[i]] = true ;
                            }
                        }
                    }
                }
            }
        }
    }
    
    cout << org_cnt << " " << var_cnt << "\n" ;
}
