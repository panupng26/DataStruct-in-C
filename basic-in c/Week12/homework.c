#include <stdio.h>
int main()
{	
	int id[11],sect[11],depart[11];
	int e1[10],e2[10],e3[10],e4[10],e5[10],e6[10],e7[10];
	int i=0,j;
	int q,emp=0;
	char name[11][25];
	int total1=0,total2=0,total3=0,total4=0,total5=0,total6=0,total7=0;
	FILE *inf,*inf1,*out1,*out2,*out3,*out4,*out5,*out6,*out7,*report;
	inf = fopen("science.txt","r");
	inf1 = fopen("edimond.txt","r");
	out1 = fopen("mode1.txt","w");
	out2 = fopen("mode2.txt","w");
	out3 = fopen("mode3.txt","w");
	out4 = fopen("mode4.txt","w");
	out5 = fopen("mode5.txt","w");
	out6 = fopen("mode6.txt","w");
	out7 = fopen("mode7.txt","w");
	report = fopen("summary.txt","w");
	fscanf(inf,"%d%s%d%d",&id[i],&name[i],&sect[i],&depart[i]);
	while(!feof(inf))
	{
		i++;
		fscanf(inf,"%d%s%d%d",&id[i],&name[i],&sect[i],&depart[i]);
	}
	
	fscanf(inf1,"%d%d%d%d%d%d%d",&e1[emp],&e2[emp],&e3[emp],&e4[emp],&e5[emp],&e6[emp],&e7[emp]);
	while(!feof(inf1))
	{
	
		emp++;
		fscanf(inf1,"%d%d%d%d%d%d%d",&e1[emp],&e2[emp],&e3[emp],&e4[emp],&e5[emp],&e6[emp],&e7[emp]);
	}
	
	for(j=0;j<i;j++)
	{
		if(e1[j]!=0)
		{
			fprintf(out1,"No.%d %s\n",j+2-1,name[j]);
			total1++;											
		}
	
		if(e2[j]!=0)
		{
			fprintf(out2,"No.%d %s\n",j+2-1,name[j]);																	
			total2++;
		}
		if(e3[j]!=0)
		{
			fprintf(out3,"No.%d %s\n",j+2-1,name[j]);																
			total3++;		
		}	
		if(e4[j]!=0)
		{
		 	fprintf(out4,"No.%d %s\n",j+2-1,name[j]);																	
			total4++;
		}
		if(e5[j]!=0)
		{
			fprintf(out5,"No.%d %s\n",j+2-1,name[j]);														
			total5++;
		}
		if(e6[j]!=0)
		{
			fprintf(out6,"No.%d %s\n",j+2-1,name[j]);														
			total6++;
		}
		if(e7[j]!=0)
		{
			fprintf(out7,"No.%d %s\n",j+2-1,name[j]);														
			total7++;
		}
		
	}
	fprintf(out1,"Total = %d",total1);
	fprintf(out2,"Total = %d",total2);
	fprintf(out3,"Total = %d",total3);
	fprintf(out4,"Total = %d",total4);
	fprintf(out5,"Total = %d",total5);
	fprintf(out6,"Total = %d",total6);
	fprintf(out7,"Total = %d",total7);
	
	fprintf(report,"ID    \tName\t\t  Dept Year E1 E2 E3 E4 E5 E6 E7\n");
	fprintf(report,"--------------------------------------------------------------------------------\n");
	for(q=0;q<i;q++)
	{
	fprintf(report,"%d    \t%s     %d %d ",id[q],name[q],sect[q],depart[q]);
		if(e1[q]!=0)
		{
			fprintf(report,"Yes ");										
		}else
			{
				fprintf(report,"- ");	
			}
	
		if(e2[q]!=0)
		{
			fprintf(report,"Yes ");										
		}else
			{
				fprintf(report,"- ");	
			}
			
		if(e3[q]!=0)
		{
			fprintf(report,"Yes ");										
		}else
			{
				fprintf(report,"- ");	
			}
			
		if(e4[q]!=0)
	{
			fprintf(report,"Yes ");										
		}else
			{
				fprintf(report,"- ");	
			}
			
		if(e5[q]!=0)
		{
			fprintf(report,"Yes ");										
		}else
			{
				fprintf(report,"- ");	
			}
			
		if(e6[q]!=0)
		{
			fprintf(report,"Yes ");										
		}else
			{
				fprintf(report,"- ");	
			}
		if(e7[q]!=0)
		{
			fprintf(report,"Yes\n");										
		}else
			{
				fprintf(report,"-\n");	
			}
			
	}
	// 
	
	
	fclose(inf);
	fclose(inf1);
	fclose(out1);
	fclose(out2);
	fclose(out3);
	fclose(out4);
	fclose(out5);
	fclose(out6);
	fclose(out7);
	return 0 ;
}
