#ifndef _MAZE_H
#define _MAZE_H

struct graph{//struktura pola labiryntu
                int cell;
                int connections[2];
                double weight;
        };

int rand_cell(void);
void print_maze(int n, struct graph **arr);
void dfs(int i,int j,int z,int v,struct graph **arr,int *visited,double *road,int dim,double *min,int *road_min,int *min_l,int *road_nr);
#endif
