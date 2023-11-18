#include <stdio.h>
#include <conio.h>

char map[20][20];
char player = '^', food = 'O';
char tail[10] = {'*','*','*','*','*','*','*','*','*','*'};
int y = 12;
int x = 3;
int a[10];
int b[10];
char walk;
int score = 0;
int n = 0, p = 10, q = 10, rand = 2, R = 1, i, j;

void generateMap(int p, int q, int R);
void outputMap(int score);
void moveUp();
void moveDown();
void moveLeft();
void moveRight();

int main(){
	int i,j;
	
	do{
	
		generateMap(p,q,R);
		outputMap(score);
		walk = getch();
		for(i=9; i>0; i--){
			a[i] = a[i-1];b[i] = b[i-1];
		}
		a[0] = y;b[0] = x;
		switch(walk){
			case 'w':
				moveUp();
				break;
			case 's':
				moveDown();
				break;
			case 'a':
				moveLeft();
				break;
			case 'd':
				moveRight();
				break;						
		}
			
		}while(score < 10);
	
	printf("\t\t+==============================+\n");
	printf("\t\t|      CONGRATULATION !!!      |\n");
	printf("\t\t+==============================+\n");
	printf("Your Score : 10");
	getch();
	return 0;
}

void generateMap(int p, int q, int R){
	int i,j;
	for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			map[i][j] = ' ';
		}
	}
	map[0][0] = '+';
	map[19][0] = '+';
	map[19][19] = '+';
	map[0][19] = '+';
	for(i=1; i<19; i++){
		map[i][0] = '|';
		map[i][19]= '|';
	}
	for(j=1; j<19; j++){
		map[0][j] = '=';
		map[19][j] = '=';
	}
	map[y][x] = player;
	for(i=0; i<R; i++){
		map[a[i]][b[i]] = tail[i];
	}
	map[p][q] = food;
}

void outputMap(int score){
	int i,j;
	for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			printf("%c",map[i][j]);
		}
		printf("\n");
	}
	printf("Score: 00%d",score);
}
void moveUp(){
	if(map[y - 1][x] == ' '){
				y--;
				map[y][x] = player;
				}
				else if(map[y - 1][x] == food){
					p *= (rand + y * 3);q *= (rand + x * 9);
					if(p >= 19) p %= 13;p++; 
					if(q >= 19) q %= 16;q++;
					score++;
					R++;
				}
				player = '^';
				for(i=0; i<R; i++){
					for(j=0; j<R; j++){
						map[a[i]][b[j]] = tail[n];
						n++;
					}
				}
}
void moveDown(){
	if(map[y+1][x] == ' '){
				y++;
				map[y][x] = player;															
	}
				else if(map[y + 1][x] == food){
					p *= (rand + y * 6);q *= (rand + x * 8);
					if(p >= 19) p %= 18;p++; 
					if(q >= 19) q %= 15;q++;
					score++;
					R++;
				}
				player = 'v';
				for(i=0; i<R; i++){
					for(j=0; j<R; j++){
						map[a[i]][b[j]] = tail[n];
						n++;
					}
				}
}
void moveLeft(){
	if (map[y][x-1] == ' '){
				x--;
				map[y][x] = player;		
				}
				else if(map[y][x-1] == food){
					p *= (rand + y * 5);q *= (rand + x * 7);
					if(p >= 19) p %= 18;p++; 
					if(q >= 19) q %= 17;q++;
					score++;
					R++;
				}
				player = '<';
				for(i=0; i<R; i++){
					for(j=0; j<R; j++){
						map[a[i]][b[j]] = tail[n];
						n++;
					}
				}
}
void moveRight(){
	if(map[y][x+1] == ' '){
				x++;
				map[y][x] = player;	
				}
				else if(map[y][x+1] == food){
					p *= (rand + y * 2);q *= (rand + x * 3);
					if(p >= 19) p %= 18;p++;
					if(q >= 19) q %= 18;q++;
					score++;
					R++;
				}
				player = '>';
				for(i=0; i<R; i++){
						for(j=0; j<R; j++){
							map[a[i]][b[j]] = tail[n];
							n++;
					}
				}
}
