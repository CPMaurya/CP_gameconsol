#include<stdio.h>
int moves = 15;
int cur_pos = 3;
int gameMove(int);
void print();
char a[8]={'*','*','*','_','#','#','#'};
int main()
{
	int win=0,pos;
		print();
	while( !win && moves)
	{ 
	   puts("Enter position");
	   scanf("%d",&pos);
		win = gameMove(pos-1);
	    print();
    }   
	if(win)
	   	puts("you won !!");
	else
    	puts("\a no moves left \n Game over !");
 	return 0;	
}

int gameMove(int n)
{
  int k=0,i;
  char ch;
  
  if(moves == 0 )
  return 0;
  
  	if( n-cur_pos > 2 || n-cur_pos < -2 || n > 6 )
  {
  	puts("\a invalid !");
  	return 0;
  }
    ch = a[n];
    a[n]=a[cur_pos];
    a[cur_pos] = ch;
	cur_pos = n;  
    moves--;
   for(i=0;i<3;i++)
   {
  		if(a[i]=='#'&&a[6-i]=='*')
		  {
  			if(i==2)
  			k++;
		  }
		  else 
		  break;
	  }
    return k;
}
void print()
{
	int i;
	    printf("%c-----------------------------------%c\n%c",218,191,124);
		for(i=0;i<=6;i++)
		printf("  %c  ",a[i]);
		printf("%c\n",124);
		printf("%c",124);
		for(i=1;i<=7;i++)
		printf("  %d  ",i);
		printf("%c\n%c-----------------------------------%c\n",124,192,217);
}
