#include <stdio.h>

int solveMaze(char** maze, const int HT, const int WD, int x, int y); 
void printMaze(char** maze, const int HT, const int WD);

int main(){
    char mazeStr[] = "  ##############"
           			 "#     #     ####"
           			 "# ####* ### ####"
		             "#    ###### ####"
          		     "#### # #### ####"
          		     "#    # #### ####"
            		 "#### # #### ####"
            		 "####        ####"
            		 "################";

    const int HT = 9;
    const int WD = 16;
    char *maze[HT];

    for (int i=0; i<HT ; i++)             // filling the 2D char array
	    maze[i]=&mazeStr[i*WD];

    solveMaze(maze, HT, WD, 0, 0);
    
	printMaze(maze, HT, WD);

    return 0;
}

int solveMaze(char** maze, const int HT, const int WD, int x, int y){

    const char *p = ".";       // path shown with "."
	const char *g = "*";       // goal
	const char *b = "#";
	const char *k = " ";

    if(x < 0 || x >= WD || y < 0 || y >= HT) 
		return 0; 

    if(*(*(maze + y) + x) == *g) 
		return 1;
 
    if(*(*(maze + y) + x) == *b || *(*(maze + y) + x) == *p) 
		return 0;

    *(*(maze + y) + x) = *p; 

    if(solveMaze(maze, HT, WD, x, y - 1) == 1) return 1;    // north
    if(solveMaze(maze, HT, WD, x, y + 1) == 1) return 1;    // south
    if(solveMaze(maze, HT, WD, x + 1, y) == 1) return 1;    // east 
    if(solveMaze(maze, HT, WD, x - 1, y) == 1) return 1;    // west 
    
	*(*(maze + y) + x) = *k; 
    
	return 0;
}

void printMaze(char **maze, const int HT, const int WD){
    for (int i=0; i<HT ; i++){
    for(int j=0; j<WD-1; j++)
      printf("%c",maze[i][j]);
    printf("%c\n",maze[i][WD-1]);
    }
}
