#include <stdio.h>
#include <stdlib.h>

int visit(int i,int j,int top,char** map,char** visited);

int main()
{
    FILE *entree = fopen("nappe.in","r");
    FILE *sortie = fopen("nappe.out","w");
    char**map,**visited,*temp;
    int i,x,y,j,count,top;
    count = 1;
    int max = 0;
    int tempor=0;
    int ligne,colone;
    fscanf(entree,"%d %d",&ligne,&colone);
    map = (char**) malloc(100*sizeof(char*));
    visited = (char**) malloc(100*sizeof(char*));
    temp = (char*) malloc(100);
    temp[0] = 0;
    int was,you;
    for(i=0;i<101;i++)
    {
        visited[i] = (char*) malloc(100);
        map[i] = (char*) malloc(100);
    }
    fgetc(entree);

    while(count-->0)
    {
        top=0;
        while(fgets(temp,1000,entree) && temp[0])
        {

            if(temp[0]=='W'||temp[0]=='L')
            {
                sscanf(temp,"%s",map[top++]);
            }
            else
            {
                for(i=0;i<top;i++)
                {
                    for(j=0;map[i][j];j++)
                        visited[i][j]=0;
                }
                /*
                printf("XXX",visit(1,2,top,map,visited));
                */
            }


        }

        for(was=0;was < ligne;was++){
         for(you=0;you<colone;you++){
           if(map[was][you]=='W'){
             tempor = visit(was,you,top,map,visited);
             if(max < tempor){
                 max = tempor;
             }
         }
     }
 }
}


fprintf(sortie,"%d",max);
fclose(entree);
fclose(sortie);
return 0;
}
int visit(int i,int j,int top,char** map,char** visited)
{
    if(i>=0&&j>=0&&i<top&&map[i][j]&&map[i][j]=='W'&&!visited[i][j])
    {
        visited[i][j] = 1;
        return 1 + visit(i+1,j,top,map,visited)+
        visit(i-1,j,top,map,visited)+
        visit(i,j+1,top,map,visited)+
        visit(i,j-1,top,map,visited)+
        visit(i+1,j+1,top,map,visited)+
        visit(i-1,j-1,top,map,visited)+
        visit(i-1,j+1,top,map,visited)+
        visit(i+1,j-1,top,map,visited);
    }
    return 0;
}
