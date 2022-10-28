#include <stdio.h>
#include <string.h>
typedef struct{
	char name[30];
	int match,win,draw,lose,goal,loss,dif,score;
	
}table;
int getdata(table team[])
{
	int i=0;
	FILE *inf;
	inf = fopen("competition.txt","r");
	fscanf(inf,"%s",&team[i].name);
	while(!feof(inf))
	{
		
		fscanf(inf,"%d%d%d%d%d%d%d%d",&team[i].match,&team[i].win,&team[i].draw,&team[i].lose,&team[i].goal,&team[i].loss,&team[i].dif,&team[i].score);
		i++;
		fscanf(inf,"%s",&team[i].name);
	}
	fclose(inf);
	return (i);
}
void calculate(table team[],int cnt)
{
	int i ;
	for(i=0;i<cnt;i++)
	{
		team[i].score = (team[i].win*3)+team[i].draw;
	}
}
void display(table team[],int cnt)
{
	int i=0;
	for(i=0;i<cnt;i++)
	{
		printf("%-30s %-3d %-3d %-3d %-3d %-3d %-3d %-3d %-3d\n",team[i].name,team[i].match,team[i].win,team[i].draw,team[i].lose,team[i].goal,team[i].loss,team[i].dif,team[i].score);
	}
}
int main()
{
	table team[20];
	int cnt = 0;
	cnt = getdata(team);
	calculate(team,cnt);
	display(team,cnt);
	return 0;
}
