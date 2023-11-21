#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "maze.h"
int main(int argc,char *argv[]){
	
	if(argc != 2){
		printf("Proszę podać jeden argument \n");
		exit(0);}

	srand(time(NULL));
	int dimension = atoi(argv[1]); 	// zmienna określająca wymiar labiryntu
	int i,j,z,r;			// zmienne pomocnicze
	int nr = dimension * dimension; // zmienna określająca ilośc pól labiryntu
	int cell_temp = 0;		//zmienna pomocnicza określająca numer komórki
	int *visited = malloc(sizeof(int) * nr); // tablicza odwiedzonych pól
	double *road = malloc(sizeof(double) * 100); //tablica ukazująca ścieżkę labiryntu
	int *road_nr = malloc(sizeof(int) * 100); // tablica przetrzymująca nr pól drogi
	int *road_min = malloc(sizeof(int) * 100); //tablica prztrzymująca najmniejszą ścieżkę
	double weight_temp;			//zmienna pomocnicza wagi	
	double min = 1000;			// zmiennna minimalnej wagi ścieżki
	int n = 0;				//zmienna długości minimalnej ścieżki
	struct graph **arr = malloc(sizeof(struct graph) * dimension); //tablica struktur labiryntu
			
	printf("Wizualizacja wygenerowanego labiryntu o podnaym rozmiarze %d: \n",dimension);
	
	for(i=0;i<dimension;i++){		//petla wypełniająca tablicę struktur
		arr[i] = malloc(sizeof(struct graph) * dimension);
		for(j=0;j<dimension;j++){
			arr[i][j].cell = cell_temp;
			weight_temp = (rand()%1000);
			arr[i][j].weight = weight_temp/100;
			cell_temp += 1;	
			for(z=0;z<2;z++){
			arr[i][j].connections[z] = 0;
		}
	}
}

	for(i=0;i<dimension;i++){ //pętla generująca labirynt
		for(j=0;j<dimension;j++)
			if(i== dimension -1)
				arr[i][j].connections[1] = 1;
			else if(j == dimension -1)
				arr[i][j].connections[0] = 1;
			else{
				r = rand_cell();
				if(r != 2)
					arr[i][j].connections[r] = 1;
				else{
					arr[i][j].connections[0] =1;
					arr[i][j].connections[1] =1;
			}}

	}
	arr[dimension -1][dimension-1].connections[1] = 0;
	
	print_maze(dimension,arr); //wypisanie labiryntu
	
	for(i=0;i<nr;i++) //wypełnianie tablicy odwiedzonych pól zerami
		visited[i] = 0;
	dfs(0,0,0,0,arr,visited,road,dimension,&min,road_min,&n,road_nr); //wywołanie dfs
	printf("\nDługość najkrótszej ścieżka odnalezionej w labiryncie wynosi %lf \n",min);
	printf("Przechodzi ona przez pola o numerach: ");
	for(i= 0; i<=n;i++) //wypisywanie ścieżki
		printf("%d ",road_min[i]);
	printf("\n");
	free(visited);	//czyszczenie pamięci
	free(road);
	free(road_min);
	free(road_nr);
	free(arr);
        for(i=0;i<dimension;i++)
                free(arr[i]);
	return 0;
}
