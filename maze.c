#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "maze.h"

int rand_cell(){ // funkcja geneująca liczby wykorzystywane w generowaniu labiryntu
        int r;
        r = rand()%3;
       return r;
}

void print_maze(int n, struct graph **arr){ //funkcja wypisująca labirynt
	int i,j;
	printf("  ");
	for(i=0;i<(n)-1;i++){
                printf(" _");
        	}
        	printf("\n");
        for(i=0;i<n;i++){
		printf("|");
        for(j=0;j<n;j++){
                if( arr[i][j].connections[0]==0)
                        printf("_");
                else
                        printf(" ");
                if( arr[i][j].connections[1]==0)
                        if(i== n-1 && j == n-1)
				printf(" ");
			else
				printf("|");
                else
                        printf(" ");
        }
        printf("\n");
}
}
void dfs(int i,int j,int z,int v,struct graph **arr,int *visited,double *road,int dim,double *min, int *road_min,int *min_l,int *road_nr){ //funkcja przszukiwania ścieżek
                road[z] = arr[i][j].weight;
		road_nr[z] = arr[i][j].cell;
                z++;
		if(arr[i][j].cell == (dim*dim) -1){
			double dl = 0;
                        for(i=1;i<z;i++){
				dl += (road[i] + road[i-1])/2;
			}
                                if(dl < *min){
					*min = dl;
					for(i=0; i<z ;i++)
						road_min[i] = road_nr[i]; 
					*min_l = z-1;
				}
                        return ;
                }
		visited[v] = 1;
                if((i-1) >= 0)
                        if(arr[i-1][j].connections[0] == 1 && visited[arr[i-1][j].cell] == 0)
                                dfs(i-1,j,z,arr[i-1][j].cell,arr,visited,road,dim,min,road_min,min_l,road_nr);
                if((i+1) < dim)
                        if(arr[i][j].connections[0] == 1 && visited[arr[i+1][j].cell] == 0)
                                dfs(i+1,j,z,arr[i+1][j].cell,arr,visited,road,dim,min,road_min,min_l,road_nr);
                if((j-1) >= 0)
                        if(arr[i][j-1].connections[1] == 1 && visited[arr[i][j-1].cell] == 0)
                                dfs(i,j-1,z,arr[i][j-1].cell,arr,visited,road,dim,min,road_min,min_l,road_nr);
                if((j+1) < dim)
                        if(arr[i][j].connections[1] == 1 && visited[arr[i][j+1].cell] == 0)
                                dfs(i,j+1,z,arr[i][j+1].cell,arr,visited,road,dim,min,road_min,min_l,road_nr);
                else
                        return;
        }
	

