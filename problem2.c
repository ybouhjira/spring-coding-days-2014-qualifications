#include<stdio.h>
#define MAX 30000
#define MAXMILLE 10000

typedef struct{
    int gauche;
    int droite;
}Compa;

int main()
{
    FILE *entree = fopen("maxpath.in","r");
    FILE *sortie =fopen("maxpath.out","w");
    int lecas = 0;
    int i;
    Compa Tab[MAX];
    int j,sum;
    int sum1,sum2,n1,n2;
    fscanf(entree,"%d",&n1);
    fgetc(entree);
    while(n1 != 0)
    {
        for(i = 0; i < MAX ; i++)
        {
            Tab[i].gauche = 0;
            Tab[i].droite = 0;
        }
        for(i = 0 ; i < n1 ; i++ )
        {
            fscanf(entree,"%d",&j);
            fgetc(entree);
            if(j == 0) Tab[MAXMILLE].gauche = 1;
            else Tab[MAXMILLE + j].gauche = 1;
        }
        fscanf(entree,"%d",&n2);
        fgetc(entree);
        for(i = 0 ; i < n2 ; i++)
        {
            fscanf(entree,"%d",&j);
            fgetc(entree);
            if(j == 0)Tab[MAXMILLE].droite = 1;
            else Tab[j+MAXMILLE].droite = 1;
        }
        sum = 0;
        for(i = 0 ; i < MAX ; i++)
        {
            for(sum1 = 0 , sum2 = 0 ; !(Tab[i].gauche == 1 && Tab[i].droite == 1) && i < MAX ; i++)
            {
                if(Tab[i].gauche == 1 && Tab[i].droite == 0) sum1 =sum1 + i - MAXMILLE ;
                else if (Tab[i].droite == 1 && Tab[i].gauche == 0)sum2 = sum2 + i - MAXMILLE;
            }
            if(i < MAX) sum += i - MAXMILLE;
            if(sum1 > sum2) sum+=sum1;
            else sum+=sum2;
        }
        if(lecas==0){
          fprintf(sortie,"%d",sum);
          lecas= 1;
      }
      else{
          fprintf(sortie,"\n%d",sum);
      }
      fscanf(entree,"%d",&n1);
      fgetc(entree);
  }

  fclose(entree);
  fclose(sortie);
  return 0;
}
