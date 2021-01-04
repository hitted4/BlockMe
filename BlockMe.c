#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
struct Player{
        char Name[50];
        int type; //Type 1 Xrhsths, Type 2 BOT
        char pawn; //@,#,&,*
        int seq; //Seira twn paiktwn
        int pos[2]; //thesi pioniou
        int obst; //Diathesima empodia
        int dir; //kateu8unsh  bot
        int pdir; //prohgoumenh kateythinsh bot
        int dd; //default direction
        int WCC; //win condition counter for BOTs
};
void tablo(char** arr,int x);
int main(void) {
    char ans;
    int x;
    printf("Do you want the default table(10x10)?(Y/N)\n");
    ans=getchar();
    while(ans!='y'&&ans!='Y'&&ans!='n'&&ans!='N'){
        printf("Wrong input.\n\nDo you want the default table(10x10) or a customized one?(Y/N)\n");
        ans=getchar();
    }
    if (ans=='y'||ans=='Y'){
        x=10;
    }
    else{
        printf("Give the dimensions of the table, that must be >=5.\n");
        scanf("%d", &x);
    }
    char *ptr;
    while(x<5){
        printf("Wrong input! Dimensions must be >=5 !!!\n");
        scanf("%d", &x);
    }
    int i;
    srand(time(NULL));
    char **arr;
    arr = (char **) malloc(x *sizeof(char *));
    for(i=0;i<x;i++){
        arr[i]= (char*)malloc(x*sizeof(char));
    }
    int j;
   
    for(i=0;i<x;i++){
        for(j=0;j<x;j++){
            arr[i][j]=46;
        }
    }
    struct Player Player[4];
    for(i=0;i<4;i++){
        Player[i].obst=5;
    }
    int users;
    printf("Give the number of human players(at least one)\n");
    scanf("%d", &users);
    while(users<1 || users>4){
        printf("Wrong input.\n\nThere has to be at least one human player.\n");
        scanf("%d", &users);
    }
    int players;
    if(users>2){
        printf("Exete epileksei arithmo xrhstwn megalytero apo duo.\nTo paixnidi 8a einai me tesseris paiktes.\n");
        players=2;
        goto jump;
    }
    printf("Choose mode.\n\n1. 2 players.\n\n2. 4 players.");
    scanf("%d", &players);
    while(players!=1 && players!=2){
        printf("Wrong input.\n\nChoose mode.\n\n1. 2 players.\n\n2.4 players.");
        scanf("%d",&players);
    }
    jump:
    if(players==1){
        getchar();
        printf("Give player 1 name\n");
        fgets(Player[0].Name, 50,stdin);
        printf("Give player 2 name\n");
        fgets(Player[1].Name, 50,stdin);
        if(users==1){
            Player[0].type=1;
            Player[1].type=2;
        }
        else{
            Player[0].type=1;
            Player[1].type=1;
        }
    }
    else{
        getchar();
        printf("Give player 1 name.\n");
        fgets(Player[0].Name, 50,stdin);
        printf("Give player 2 name.\n");
        fgets(Player[1].Name, 50,stdin);
        printf("Give player 3 name.\n");
        fgets(Player[2].Name, 50,stdin);
        printf("Give player 4 name.\n");
        fgets(Player[3].Name, 50,stdin);
        if(users==1){
            Player[0].type=1;
            Player[1].type=2;
            Player[2].type=2;
            Player[3].type=2;
        }
        else if(users==2){
            Player[0].type=1;
            Player[1].type=1;
            Player[2].type=2;
            Player[3].type=2;
        }
        else if(users==3){
            Player[0].type=1;
            Player[1].type=1;
            Player[2].type=1;
            Player[3].type=2;
        }
        else{
            Player[0].type=1;
            Player[1].type=1;
            Player[2].type=1;
            Player[3].type=1;
        }
    }
    char a;//answer (y/n)
    
    char Pawns1[4]={'@','#','&','*'};
    char temp,Pawns[4];
    for(i=0;i<4;i++){
        temp=Pawns1[rand()%4];
        for(j=0;j<4;j++){
            while(Pawns[j]==temp){
                temp=Pawns1[rand()%4];
                j=0;
            }
        }
                
        Pawns[i]=temp;
    }

    char temparr[4];
    for(i=0;i<4;i++){
        temparr[i]=Pawns[i];
    }
    char temp2;
    for(i=0;i<4;i++){
            temp2=temparr[rand()%4];
            for(j=0;j<4;j++){
                while(Player[j].pawn==temp2){
                    temp2=temparr[rand()%4];
                    j=0;
                }
            }
        Player[i].pawn=temp2;
    }
    int temp3; 
    struct Player temp4;
    do{
        for(i=0;i<4;i++){
            Player[i].seq=6;
        }
        if(players==2){
            for(i=0;i<4;i++){
                temp3=rand()%4;
                for(j=0;j<4;j++){
                    while(Player[j].seq==temp3){
                        temp3=rand()%4;
                        j=0;
                    }
                }
                Player[i].seq=temp3;
            }printf("\n");
        }
        else{
            for(i=0;i<2;i++){
                temp3=rand()%2;
                for(j=0;j<2;j++){
                    while(Player[j].seq==temp3){
                        temp3=rand()%2;
                        j=0;
                    }
                }
                Player[i].seq=temp3;
            }printf("\n");
        }
        for(i=0;i<(4-1);i++){
            for(j=0;j<4-i-1;j++){
                if (Player[j].seq>Player[j+1].seq){
                    temp4= Player[j];
                    Player[j]= Player[j+1];
                    Player[j+1]= temp4;
                }
            }
        }  
    }while(Player[0].type!=1);
    int InitPos[4][2];
    if(players==2){
        i=(x/2);
        arr[x-1][i]=Player[0].pawn;
        InitPos[0][0]=Player[0].pos[0]=x-1;
        InitPos[0][1]=Player[0].pos[1]=i;
        arr[i][0]=Player[1].pawn;
        InitPos[1][0]=Player[1].pos[0]=i;
        InitPos[1][1]=Player[1].pos[1]=0;
        arr[0][i]=Player[2].pawn;
        InitPos[2][0]=Player[2].pos[0]=0;
        InitPos[2][1]=Player[2].pos[1]=i;
        arr[i][x-1]=Player[3].pawn;
        InitPos[3][0]=Player[3].pos[0]=i;
        InitPos[3][1]=Player[3].pos[1]=x-1;
    }
    else{
        i=(x/2);
        arr[x-1][i]=Player[0].pawn;
        InitPos[0][0]=Player[0].pos[0]=x-1;
        InitPos[0][1]=Player[0].pos[1]=i;
        arr[0][i]=Player[1].pawn;
        InitPos[1][0]=Player[1].pos[0]=0;
        InitPos[1][1]=Player[1].pos[1]=i;
    }
    
        
    printf("Do you want a new game with already placed obstacles?(y/n)\n");
    scanf("%c", &a);
    while(a!='y' && a!='n'){
        scanf("%c", &a);
    }
    int dir; //direction 0=katheto empodio
    if(a=='y'){
        int k,CAP=x-3;
        for(k=0;k<CAP;k++){
            i=rand()%x;
            j=rand()%x;
            while(i==0 || j==0){
                i=rand()%x;
                j=rand()%x;
            }
            dir=rand()%2;
            if(dir==0){
                while ((arr[i][j]!='.')||(arr[i-1][j]!='.'||i==0||j==0)){
                    i=rand()%x;
                    j=rand()%x;
                }
                arr[i][j]='X';
                arr[i-1][j]='X';
            }
            else{
                while ((arr[i][j]!='.')||(arr[i][j-1]!='.'||i==0||j==0)){
                    i=rand()%x;
                    j=rand()%x;
                }
                arr[i][j]='X';
                arr[i][j-1]='X';
            }
        }
    }
    int WC=0; //WIN CONDITION
    char exit[5]={'e','x','i','t','\n'};
    char help[5]={'h','e','l','p','\n'};
    char input[20];
    char S[3],U[3];
    int o,p,flag=0;
    getchar();
    for(i=0;i<4;i++){
        Player[i].dir=i;
        Player[i].dd=i;
        Player[i].WCC=0;
    }
    i=0;
    do{
        if(players==2){
            if(Player[i].type==1)/*xrhstes*/{
                if(strcmp(input,help)==0){}
                else{
                    tablo(arr,x);
                }
                printf("Player %s\n\nYou have %d obstacles left\n", Player[i].Name,Player[i].obst);
                fgets(input,20,stdin);
                do{
                    if(strcmp(input,exit)==0||strcmp(input,help)==0){
                        if(strcmp(input,help)==0){
                            
                        }
                    }
                    else{
                        if(flag==1){
                            printf("Wrong input.\nGive coordinates again!!!\n");
                            fgets(input,20,stdin);
                        }
                        if(strcmp(input,help)==0){
                            
                        }
                        flag=0;
                        if(strlen(input)<8||strlen(input)>2){
                            if(strlen(input)==3){        
                                if(input[0]-'a'<0||input[0]-'a'>x-1||input[1]-'1'<0||input[1]-'1'>x-1){
                                    flag=1;
                                }
                                if(flag!=1){
                                    if(((input[0]-'a')-Player[i].pos[1]<-1||(input[0]-'a')-Player[i].pos[1]>1)||input[1]-'1'-Player[i].pos[0]<-1||input[1]-'1'-Player[i].pos[0]>1||arr[input[1]-'1'][input[0]-'a']!='.'){
                                        flag=1;
                                    }
                                    else if(((input[1]-'1')-Player[i].pos[0]==1||(input[1]-'1')-Player[i].pos[0]==-1)&&((input[0]-'a')-Player[i].pos[1]==1||(input[0]-'a')-Player[i].pos[1]==-1)){
                                        flag=1;
                                    }
                                    else if(input[0]-'a'!=Player[i].pos[1]&&input[1]-'1'!=Player[i].pos[0]){
                                        flag=1;
                                    }
                                }
                            }
                            else if(strlen(input)==4){
                                S[0]=input[1];
                                S[1]=input[2];
                                S[2]='\n';
                                o=atoi(S);
                                printf("%d",o);
                                if(input[0]-'a'<0||input[0]-'a'>x-1||o<0||o>x-1){
                                    flag=1;
                                }
                                if(flag!=1){
                                    if((input[0]-'a')-Player[i].pos[1]<-1||(input[0]-'a')-Player[i].pos[1]>1||o-1-Player[i].pos[0]<-1||o-1-Player[i].pos[0]>1||arr[o-1][input[0]-'a']!='.'){
                                        flag=1;
                                    }
                                    else if((o-1-Player[i].pos[0]==1||o-1-Player[i].pos[0]==-1)&&((input[0]-'a')-Player[i].pos[1]==1||(input[0]-'a')-Player[i].pos[1]==-1)){
                                        flag=1;
                                    }
                                    else if((input[0]-'a'!=Player[i].pos[1]&&o-1!=Player[i].pos[0])){
                                        flag=1;
                                    }
                                }
                            }
                            else if(strlen(input)==5&&(strcmp(input,help)!=0&&(strcmp(input,exit)!=0))){
                                if(input[0]-'a'<0||input[0]-'a'>x-1||input[1]-'1'<0||input[1]-'1'>x-1||input[2]-'a'<0||input[2]-'a'>x-1||input[3]-'1'<0||input[3]-'1'>x-1||Player[i].obst<=0){
                                    flag=1;
                                }
                                if(flag!=1){
                                    if(arr[input[1]-'1'][input[0]-'a']!='.'||arr[input[3]-'1'][input[2]-'a']!='.'){
                                        flag=1;
                                    }
                                    if(input[0]==input[2]&&(input[1]-input[3]<-1||input[1]-input[3]>1)){
                                        flag=1;
                                    }
                                    if(input[1]==input[3]&&(input[0]-input[2]<-1||input[0]-input[2]>1)){
                                        flag=1;
                                    }
                                    if(input[0]!=input[2]&&input[1]!=input[3]){
                                        flag=1;
                                    }
                                }
                            }
                            else if(strlen(input)==6||strlen(input)==7){
                                if(strlen(input)==6){
                                    if((input[1]<'9'+1&&input[1]>'0'-1)&&(input[2]<'9'+1&&input[2]>'0'-1)){
                                        S[0]=input[1];
                                        S[1]=input[2];
                                        S[2]='\n';
                                        o=atoi(S);
                                        if(input[0]-'a'<0||input[0]-'a'>x-1||o<0||o>x-1||input[3]-'a'<0||input[3]-'a'>x-1||input[4]-'1'<0||input[4]-'1'>x-1||Player[i].obst<=0){
                                            flag=1;
                                        }
                                        if(flag!=1){
                                            if(arr[o-1][input[0]-'a']!='.'||arr[input[4]-'1'][input[3]-'a']!='.'){
                                                flag=1;
                                            }
                                            if(input[0]==input[3]&&(o-input[4]+'1'<-'1'||o+'1'-input[4]>'1')){
                                                flag=1;
                                            }
                                            if(input[0]!=input[3]&&o!=input[4]){
                                                flag=1;
                                            }
                                        }
                                    }
                                    else{
                                        S[0]=input[3];
                                        S[1]=input[4];
                                        S[2]='\n';
                                        o=atoi(S);
                                        if(input[0]-'a'<0||input[0]-'a'>x-1||o<0||o>x-1||input[1]-'1'<0||input[1]-'1'>x-1||input[2]-'a'<0||input[2]-'a'>x-1||Player[i].obst<=0){
                                            flag=1;
                                        }
                                        if(flag!=1){
                                            if(arr[input[1]-'1'][input[0]-'a']!='.'||arr[o-1][input[2]-'a']!='.'){
                                                flag=1;
                                            }
                                            if(input[0]==input[2]&&(o-input[1]+'1'<-'1'||o-input[1]+'1'>'1')){
                                                flag=1;
                                            }
                                            if(input[0]!=input[2]&&input[1]!=o){
                                                flag=1;
                                            }
                                        }
                                    }
                                }
                                else{
                                    S[0]=input[1];
                                    S[1]=input[2];
                                    S[2]='\n';
                                    o=atoi(S);
                                    U[0]=input[4];
                                    U[1]=input[5];
                                    U[2]='\n';
                                    p=atoi(U);
                                    if(input[0]-'a'<0||input[0]-'a'>x-1||o<0||o>x-1||input[3]-'a'>x-1||input[3]-'a'<0||p<0||p>x-1||Player[i].obst<=0){
                                        flag=1;
                                    }
                                    if(flag!=1){
                                        if(arr[o-1][input[0]-'a']!='.'||arr[p-1][input[3]-'a']!='.'){
                                            flag=1;
                                        }
                                        if(input[0]==input[3]&&(o-p<-1||o-p>1)){
                                            flag=1;
                                        }
                                        if(input[0]!=input[3]&&o!=p){
                                            flag=1;
                                        }
                                    }
                                }
                            }   
                        }
                        else if(strcmp(input,help)!=0&&strcmp(input,exit)!=0){
                            flag=1;
                        }
                    }
                }while(((strcmp(input,exit)==0)&&(strcmp(input,help)==0)||flag==1)); 
                if(flag==1){
                }
                else if(strlen(input)==5&&(strcmp(input,exit)!=0)&&(strcmp(input,help)!=0)){
                    arr[input[1]-'1'][input[0]-'a']='X';
                    arr[input[3]-'1'][input[2]-'a']='X';
                    Player[i].obst--;
                }
                else if(strlen(input)==3||strlen(input)==4){
                    if(strlen(input)==3){
                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                        Player[i].pos[0]=input[1]-'1';
                        Player[i].pos[1]=input[0]-'a';
                        arr[Player[i].pos[0]][Player[i].pos[1]]=Player[i].pawn;
                    }
                    else{
                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                        o=input[1]-'0';
                        p=input[2]-'1';
                        Player[i].pos[0]=o*10+p;
                        Player[i].pos[1]=input[0]-'a';
                        arr[Player[i].pos[0]][Player[i].pos[1]]=Player[i].pawn;
                    }
                }
                else if(strlen(input)==6||strlen(input)==7){
                    Player[i].obst--;
                    if(strlen(input)==6){
                        Player[i].obst--;
                        if((input[1]<'9'+1&&input[1]>'0'-1)&&(input[2]<'9'+1&&input[2]>'0'-1)){
                            o=input[1]-'0';
                            p=input[2]-'1';
                            arr[o*10+p][input[0]-'a']='X';
                            arr[input[4]-'1'][input[3]-'a']='X';
                        }
                        else{
                            arr[input[1]-'1'][input[0]-'a']='X';
                            o=input[3]-'0';
                            p=input[4]-'1';
                            arr[o*10+p][input[0]-'a']='X';
                        }
                    }
                    else{
                        if((input[1]<'9'+1&&input[1]>'0'-1)&&(input[2]<'9'+1&&input[2]>'0'-1)&&(input[4]<'9'+1&&input[4]>'0'-1)&&(input[5]<'9'+1&&input[5]>'0'-1)){
                            o=input[1]-'0';
                            p=input[2]-'1';
                            arr[o*10+p][input[0]-'a']='X';
                            o=input[4]-'0';
                            p=input[5]-'1';
                            arr[o*10+p][input[3]-'a']='X';
                        }
                    }
                } 
            }
            else/*BOTs*/{
                if(Player[i].dd==1){
                    if(arr[Player[i].pos[0]][Player[i].pos[1]+1]=='.'&&Player[i].dir!=3){
                        arr[Player[i].pos[0]][Player[i].pos[1]+1]=Player[i].pawn;
                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                        Player[i].pos[1]++;
                        Player[i].WCC++;
                        Player[i].dir=1;
                    }
                    else{
                        if(Player[i].dir==0&&Player[i].pos[0]-1<0){//an phge panw kai twra de mporei na ksanapaei logw oriwn
                            if(Player[i].pos[1]-1>=0){//elegxos oriwn pisw
                                Player[i].dir=3;
                                arr[Player[i].pos[0]][Player[i].pos[1]-1]=Player[i].pawn;//paei pisw
                                arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                Player[i].pos[1]--;
                                Player[i].WCC--;
                                Player[i].pdir=0;
                            }
                        }
                        else if(Player[i].dir==0&&arr[Player[i].pos[0]-1][Player[i].pos[1]]!='.'){//an phge panw kai de mporei na ksanapaei logw empodiwn
                            if(Player[i].pos[1]-1>=0){//elegxos oriwn pisw
                                Player[i].dir=3;
                                arr[Player[i].pos[0]][Player[i].pos[1]-1]=Player[i].pawn;//paei pisw
                                arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                Player[i].pos[1]--;
                                Player[i].WCC--;
                                Player[i].pdir=0;
                            }
                        }
                        else if(Player[i].dir==2&&Player[i].pos[0]+1>x-1){//an phge katw kai twra de mporei na ksanapaei logw oriwn
                            if(Player[i].pos[1]-1>=0){//elegxos oriwn pisw
                                Player[i].dir=3;
                                arr[Player[i].pos[0]][Player[i].pos[1]-1]=Player[i].pawn;//paei pisw
                                arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                Player[i].pos[1]--;
                                Player[i].WCC--;
                                Player[i].pdir=2;
                            }
                        }
                        else if(Player[i].dir==2&&arr[Player[i].pos[0]+1][Player[i].pos[1]]!='.'){
                            if(Player[i].pos[1]-1>=0){//elegxos oriwn pisw
                                Player[i].dir=3;
                                arr[Player[i].pos[0]][Player[i].pos[1]-1]=Player[i].pawn;//paei pisw
                                arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                Player[i].pos[1]--;
                                Player[i].WCC--;
                                Player[i].pdir=2;
                            }
                        }
                        else{
                            if(Player[i].dir==Player[i].dd){
                                do{
                                    Player[i].dir=rand()%3;
                                }while(Player[i].dir==1);
                            }
                            if(Player[i].dir==0){
                                if(Player[i].pos[0]-1<0){ //elegxos oriwn(panw)
                                    Player[i].dir=2;
                                    if(Player[i].pos[0]+1>x-1){//elegxos oriwn katw
                                        if(Player[i].pos[1]-1>=0){//elegxos oriwn pisw
                                            Player[i].dir=3;
                                            arr[Player[i].pos[0]][Player[i].pos[1]-1]=Player[i].pawn;//paei pisw
                                            arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                            Player[i].pos[1]--;
                                            Player[i].WCC--;
                                        }
                                    }
                                    else if(arr[Player[i].pos[0]+1][Player[i].pos[1]]!='.'){ //elegxos empodiwn katw
                                        if(Player[i].pos[1]-1>=0){//elegxos oriwn pisw
                                            arr[Player[i].pos[0]][Player[i].pos[1]-1]=Player[i].pawn;//paei pisw
                                            arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                            Player[i].pos[1]--;
                                            Player[i].WCC--;
                                            Player[i].dir=3;
                                        }
                                    }
                                    else{
                                        arr[Player[i].pos[0]+1][Player[i].pos[1]]=Player[i].pawn;//katw
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[0]++;
                                    }
                                }
                                else if(arr[Player[i].pos[0]-1][Player[i].pos[1]]!='.'){//elegxei empodia panw
                                    Player[i].dir=2;
                                    if(Player[i].pos[0]+1>x-1){//elegxei oria katw
                                        if(Player[i].pos[1]-1>=0){//elegxos oriwn pisw
                                            Player[i].dir=3;
                                            arr[Player[i].pos[0]][Player[i].pos[1]-1]=Player[i].pawn;//paei pisw
                                            arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                            Player[i].pos[1]--;
                                            Player[i].WCC--;
                                        }
                                    }
                                    else if(arr[Player[i].pos[0]+1][Player[i].pos[1]]!='.'){//elegxei empodia katw
                                        if(Player[i].pos[1]-1>=0){//elegxos oriwn pisw
                                            arr[Player[i].pos[0]][Player[i].pos[1]-1]=Player[i].pawn;//paei pisw
                                            arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                            Player[i].pos[1]--;
                                            Player[i].WCC--;
                                            Player[i].dir=3;
                                        }
                                    }
                                    else{
                                        arr[Player[i].pos[0]+1][Player[i].pos[1]]=Player[i].pawn;//katw
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[0]++;
                                    }
                                }
                                else if(Player[i].dir==0){
                                    arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;
                                    arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                    Player[i].pos[0]--;
                                }
                            }
                            else if(Player[i].dir==2){
                                if(Player[i].pos[0]+1>x-1){//elegxei oria katw
                                    Player[i].dir=0;
                                    if(Player[i].pos[0]-1<0){// elegxei oria panw
                                        if(Player[i].pos[1]-1>=0){//elegxos oriwn pisw
                                            Player[i].dir=3;
                                            arr[Player[i].pos[0]][Player[i].pos[1]-1]=Player[i].pawn;//paei pisw
                                            arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                            Player[i].pos[1]--;
                                            Player[i].WCC--;
                                        }
                                    }
                                    else if(arr[Player[i].pos[0]-1][Player[i].pos[1]]!='.'){//elegxei empodia katw
                                        if(Player[i].pos[1]-1>=0){//elegxos oriwn pisw
                                            Player[i].dir=3;
                                            arr[Player[i].pos[0]][Player[i].pos[1]-1]=Player[i].pawn;//paei pisw
                                            arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                            Player[i].pos[1]--;
                                            Player[i].WCC--;
                                        }
                                    }
                                    else{
                                        arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//panw
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[0]--;
                                    }
                                }
                                else if(arr[Player[i].pos[0]+1][Player[i].pos[1]]!='.'){//elegxei empodia katw
                                    Player[i].dir=0;
                                    if(Player[i].pos[0]-1<0){// elegxei oria panw
                                        if(Player[i].pos[1]-1>=0){//elegxos oriwn pisw
                                            Player[i].dir=3;
                                            arr[Player[i].pos[0]][Player[i].pos[1]-1]=Player[i].pawn;//paei pisw
                                            arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                            Player[i].pos[1]--;
                                            Player[i].WCC--;
                                        }
                                    }
                                    else if(arr[Player[i].pos[0]-1][Player[i].pos[1]]!='.'){//elegxei empodia katw
                                        if(Player[i].pos[1]-1>=0){//elegxos oriwn pisw
                                            Player[i].dir=3;
                                            arr[Player[i].pos[0]][Player[i].pos[1]-1]=Player[i].pawn;//paei pisw
                                            arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                            Player[i].pos[1]--;
                                            Player[i].WCC--;
                                        }
                                    }
                                    else{
                                        arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//panw
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[0]--;
                                    }
                                }
                                else if(Player[i].dir==2){
                                    arr[Player[i].pos[0]+1][Player[i].pos[1]]=Player[i].pawn;
                                    arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                    Player[i].pos[0]++;
                                }
                            }
                            else{
                                if(Player[i].pdir==0){
                                    if(Player[i].pos[0]-1<0){
                                        Player[i].dir=3;
                                        arr[Player[i].pos[0]][Player[i].pos[1]-1]=Player[i].pawn;//paei pisw
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[1]--;
                                        Player[i].WCC--;
                                        Player[i].pdir=0;
                                    }
                                    else if(arr[Player[i].pos[0]-1][Player[i].pos[1]]!='.'){
                                        Player[i].dir=3;
                                        arr[Player[i].pos[0]][Player[i].pos[1]-1]=Player[i].pawn;//paei pisw
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[1]--;
                                        Player[i].WCC--;
                                        Player[i].pdir=2;
                                    }
                                    else{
                                        arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//panw
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[0]--;
                                        Player[i].dir=0;
                                    }
                                }
                                else if(Player[i].pdir==2){
                                    if(Player[i].pos[0]+1>x-1){
                                        Player[i].dir=3;
                                        arr[Player[i].pos[0]][Player[i].pos[1]-1]=Player[i].pawn;//paei pisw
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[1]--;
                                        Player[i].WCC--;
                                        Player[i].pdir=2;
                                    }
                                    else if(arr[Player[i].pos[0]+1][Player[i].pos[1]]!='.'){
                                        Player[i].dir=3;
                                        arr[Player[i].pos[0]][Player[i].pos[1]-1]=Player[i].pawn;//paei pisw
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[1]--;
                                        Player[i].WCC--;
                                        Player[i].pdir=2;
                                    }
                                    else{
                                        arr[Player[i].pos[0]+1][Player[i].pos[1]]=Player[i].pawn;//panw
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[0]++;
                                        Player[i].dir=2;
                                    }
                                }
                            }
                        }
                    }
                }
                else if(Player[i].dd==3){
                    if(arr[Player[i].pos[0]][Player[i].pos[1]-1]=='.'&&Player[i].dir!=1){
                        arr[Player[i].pos[0]][Player[i].pos[1]-1]=Player[i].pawn;
                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                        Player[i].pos[1]--;
                        Player[i].WCC++;
                        Player[i].dir=3;
                    }
                    else{
                        if(Player[i].dir==0&&Player[i].pos[0]-1<0){//an phge panw kai twra de mporei na ksanapaei logw oriwn
                            if(Player[i].pos[1]+1>=x-1){//elegxos oriwn pisw
                                Player[i].dir=1;
                                arr[Player[i].pos[0]][Player[i].pos[1]+1]=Player[i].pawn;//paei pisw
                                arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                Player[i].pos[1]++;
                                Player[i].WCC--;
                                Player[i].pdir=0;
                            }
                        }
                        else if(Player[i].dir==0&&arr[Player[i].pos[0]-1][Player[i].pos[1]]!='.'){//an phge panw kai de mporei na ksanapaei logw empodiwn
                            if(Player[i].pos[1]+1>=x-1){//elegxos oriwn pisw
                                Player[i].dir=1;
                                arr[Player[i].pos[0]][Player[i].pos[1]+1]=Player[i].pawn;//paei pisw
                                arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                Player[i].pos[1]++;
                                Player[i].WCC--;
                                Player[i].pdir=0;
                            }
                        }
                        else if(Player[i].dir==2&&Player[i].pos[0]+1>x-1){//an phge katw kai twra de mporei na ksanapaei logw oriwn
                            if(Player[i].pos[1]+1>=x-1){//elegxos oriwn pisw
                                Player[i].dir=1;
                                arr[Player[i].pos[0]][Player[i].pos[1]+1]=Player[i].pawn;//paei pisw
                                arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                Player[i].pos[1]++;
                                Player[i].WCC--;
                                Player[i].pdir=2;
                            }
                        }
                        else if(Player[i].dir==2&&arr[Player[i].pos[0]+1][Player[i].pos[1]]!='.'){//logw empodiwn
                            if(Player[i].pos[1]+1>=x-1){//elegxos oriwn pisw
                                Player[i].dir=1;
                                arr[Player[i].pos[0]][Player[i].pos[1]+1]=Player[i].pawn;//paei pisw
                                arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                Player[i].pos[1]++;
                                Player[i].WCC--;
                                Player[i].pdir=2;
                            }
                        }
                        else{
                            if(Player[i].dir==Player[i].dd){
                                do{
                                    Player[i].dir=rand()%2;
                                }while(Player[i].dir==1);
                            }
                            if(Player[i].dir==0){
                                if(Player[i].pos[0]-1<0){ //elegxos oriwn(panw)
                                    Player[i].dir=2;
                                    if(Player[i].pos[0]+1>x-1){//elegxos oriwn katw
                                        if(Player[i].pos[1]+1>=x-1){//elegxos oriwn pisw
                                            Player[i].dir=1;
                                            arr[Player[i].pos[0]][Player[i].pos[1]+1]=Player[i].pawn;//paei pisw
                                            arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                            Player[i].pos[1]++;
                                            Player[i].WCC--;
                                        }
                                    }
                                    else if(arr[Player[i].pos[0]+1][Player[i].pos[1]]!='.'){ //elegxos empodiwn katw
                                        if(Player[i].pos[1]+1>=x-1){//elegxos oriwn pisw
                                            arr[Player[i].pos[0]][Player[i].pos[1]+1]=Player[i].pawn;//paei pisw
                                            arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                            Player[i].pos[1]++;
                                            Player[i].WCC--;
                                            Player[i].dir=1;
                                        }
                                    }
                                    else{
                                        arr[Player[i].pos[0]+1][Player[i].pos[1]]=Player[i].pawn;//katw
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[0]++;
                                    }
                                }
                                else if(arr[Player[i].pos[0]-1][Player[i].pos[1]]!='.'){//elegxei empodia panw
                                    Player[i].dir=2;
                                    if(Player[i].pos[0]+1>x-1){//elegxei oria katw
                                        if(Player[i].pos[1]+1>=x-1){//elegxos oriwn pisw
                                            Player[i].dir=1;
                                            arr[Player[i].pos[0]][Player[i].pos[1]+1]=Player[i].pawn;//paei pisw
                                            arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                            Player[i].pos[1]++;
                                            Player[i].WCC--;
                                        }
                                    }
                                    else if(arr[Player[i].pos[0]+1][Player[i].pos[1]]!='.'){//elegxei empodia katw
                                        if(Player[i].pos[1]+1>=x-1){//elegxos oriwn pisw
                                            arr[Player[i].pos[0]][Player[i].pos[1]+1]=Player[i].pawn;//paei pisw
                                            arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                            Player[i].pos[1]++;
                                            Player[i].WCC--;
                                            Player[i].dir=1;
                                        }
                                    }
                                    else{
                                        arr[Player[i].pos[0]+1][Player[i].pos[1]]=Player[i].pawn;//katw
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[0]++;
                                    }
                                }
                                else if(Player[i].dir==0){
                                    arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;
                                    arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                    Player[i].pos[0]--;
                                }
                            }
                            else if(Player[i].dir==2){//panw
                                if(Player[i].pos[0]+1>x-1){//elegxei oria katw
                                    Player[i].dir=0;
                                    if(Player[i].pos[0]-1<0){// elegxei oria panw
                                        if(Player[i].pos[1]+1>=x-1){//elegxos oriwn pisw
                                            Player[i].dir=1;
                                            arr[Player[i].pos[0]][Player[i].pos[1]+1]=Player[i].pawn;//paei pisw
                                            arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                            Player[i].pos[1]++;
                                            Player[i].WCC--;
                                        }
                                    }
                                    else if(arr[Player[i].pos[0]-1][Player[i].pos[1]]!='.'){//elegxei empodia katw
                                        if(Player[i].pos[1]+1>=x-1){//elegxos oriwn pisw
                                            Player[i].dir=1;
                                            arr[Player[i].pos[0]][Player[i].pos[1]+1]=Player[i].pawn;//paei pisw
                                            arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                            Player[i].pos[1]++;
                                            Player[i].WCC--;
                                        }
                                    }
                                    else{
                                        arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//panw
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[0]--;
                                    }
                                }
                                else if(arr[Player[i].pos[0]+1][Player[i].pos[1]]!='.'){//elegxei empodia katw
                                    Player[i].dir=0;
                                    if(Player[i].pos[0]-1<0){// elegxei oria panw
                                        if(Player[i].pos[1]+1>=x-1){//elegxos oriwn pisw
                                            Player[i].dir=1;
                                            arr[Player[i].pos[0]][Player[i].pos[1]+1]=Player[i].pawn;//paei pisw
                                            arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                            Player[i].pos[1]++;
                                            Player[i].WCC--;
                                        }
                                    }
                                    else if(arr[Player[i].pos[0]-1][Player[i].pos[1]]!='.'){//elegxei empodia katw
                                        if(Player[i].pos[1]+1>=x-1){//elegxos oriwn pisw
                                            Player[i].dir=1;
                                            arr[Player[i].pos[0]][Player[i].pos[1]+1]=Player[i].pawn;//paei pisw
                                            arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                            Player[i].pos[1]++;
                                            Player[i].WCC--;
                                        }
                                    }
                                    else{
                                        arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//panw
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[0]--;
                                    }
                                }
                                else if(Player[i].dir==2){
                                    arr[Player[i].pos[0]+1][Player[i].pos[1]]=Player[i].pawn;
                                    arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                    Player[i].pos[0]++;
                                }
                            }
                            else{
                                if(Player[i].pdir==0){
                                    if(Player[i].pos[0]-1<0){
                                        Player[i].dir=1;
                                        arr[Player[i].pos[0]][Player[i].pos[1]+1]=Player[i].pawn;//paei pisw
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[1]++;
                                        Player[i].WCC--;
                                        Player[i].pdir=0;
                                    }
                                    else if(arr[Player[i].pos[0]-1][Player[i].pos[1]]!='.'){
                                        Player[i].dir=1;
                                        arr[Player[i].pos[0]][Player[i].pos[1]+1]=Player[i].pawn;//paei pisw
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[1]++;
                                        Player[i].WCC--;
                                        Player[i].pdir=2;
                                    }
                                    else{
                                        arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//panw
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[0]--;
                                        Player[i].dir=0;
                                    }
                                }
                                else if(Player[i].pdir==2){
                                    if(Player[i].pos[0]+1>x-1){
                                        Player[i].dir=1;
                                        arr[Player[i].pos[0]][Player[i].pos[1]+1]=Player[i].pawn;//paei pisw
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[1]++;
                                        Player[i].WCC--;
                                        Player[i].pdir=2;
                                    }
                                    else if(arr[Player[i].pos[0]+1][Player[i].pos[1]]!='.'){
                                        Player[i].dir=1;
                                        arr[Player[i].pos[0]][Player[i].pos[1]+1]=Player[i].pawn;//paei pisw
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[1]++;
                                        Player[i].WCC--;
                                        Player[i].pdir=2;
                                    }
                                    else{
                                        arr[Player[i].pos[0]+1][Player[i].pos[1]]=Player[i].pawn;//panw
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[0]++;
                                        Player[i].dir=2;
                                    }
                                }
                            }
                        }
                    }
                }
                else if(Player[i].dd==2){
                    if(arr[Player[i].pos[0]+1][Player[i].pos[1]]=='.'&&Player[i].dir!=0){
                        arr[Player[i].pos[0]+1][Player[i].pos[1]]=Player[i].pawn;
                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                        Player[i].pos[0]++;
                        Player[i].WCC++;
                        Player[i].dir=2;
                    }
                    else{
                        if(Player[i].dir==3&&Player[i].pos[1]-1<0){//an phge aristera kai twra de mporei na ksanapaei logw oriwn
                            if(Player[i].pos[0]-1>=0){//elegxos oriwn panw
                                Player[i].dir=0;
                                arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//paei panw
                                arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                Player[i].pos[0]--;
                                Player[i].WCC--;
                                Player[i].pdir=3;
                            }
                        }
                        else if(Player[i].dir==3&&arr[Player[i].pos[0]][Player[i].pos[1]-1]!='.'){//an phge aristera kai de mporei na ksanapaei logw empodiwn
                            if(Player[i].pos[0]-1>=0){//elegxos oriwn panw
                                Player[i].dir=0;
                                arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//paei panw
                                arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                Player[i].pos[0]--;
                                Player[i].WCC--;
                                Player[i].pdir=3;
                            }
                        }
                        else if(Player[i].dir==1&&Player[i].pos[1]+1>x-1){//an phge deksia kai twra de mporei na ksanapaei logw oriwn
                            if(Player[i].pos[0]-1>=0){//elegxos oriwn panw
                                Player[i].dir=0;
                                arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//paei panw
                                arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                Player[i].pos[0]--;
                                Player[i].WCC--;
                                Player[i].pdir=1;
                            }
                        }
                        else if(Player[i].dir==1&&arr[Player[i].pos[0]][Player[i].pos[1]+1]!='.'){//empodia panw??
                            if(Player[i].pos[0]-1>=0){//elegxos oriwn panw
                                Player[i].dir=0;
                                arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//paei pisw
                                arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                Player[i].pos[0]--;
                                Player[i].WCC--;
                                Player[i].pdir=1;
                            }
                        }
                        else{
                            if(Player[i].dir==Player[i].dd){
                                do{
                                    Player[i].dir=rand()%4;
                                }while(Player[i].dir==2);
                            }
                            if(Player[i].dir==3){//aristera
                                if(Player[i].pos[1]-1<0){ //elegxos oriwn(aristera)
                                    Player[i].dir=1;
                                    if(Player[i].pos[1]+1>x-1){//elegxos oriwn deksia
                                        if(Player[i].pos[0]-1>=0){//elegxos oriwn panw
                                            Player[i].dir=0;
                                            arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//paei panw
                                            arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                            Player[i].pos[0]--;
                                            Player[i].WCC--;
                                        }
                                    }
                                    else if(arr[Player[i].pos[0]][Player[i].pos[1]+1]!='.'){ //elegxos empodiwn deksia
                                        if(Player[i].pos[0]-1>=0){//elegxos oriwn panw
                                            arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//paei panw
                                            arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                            Player[i].pos[0]--;
                                            Player[i].WCC--;
                                            Player[i].dir=0;
                                        }
                                    }
                                    else{
                                        arr[Player[i].pos[0]][Player[i].pos[1]+1]=Player[i].pawn;//deksia
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[1]++;
                                    }
                                }
                                else if(arr[Player[i].pos[0]][Player[i].pos[1]-1]!='.'){//elegxei empodia aristera
                                    Player[i].dir=1;
                                    if(Player[i].pos[1]+1>x-1){//elegxei oria deksia
                                        if(Player[i].pos[0]-1>=0){//elegxos oriwn panw
                                            Player[i].dir=0;
                                            arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//paei pisw
                                            arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                            Player[i].pos[0]--;
                                            Player[i].WCC--;
                                        }
                                    }
                                    else if(arr[Player[i].pos[0]][Player[i].pos[1]+1]!='.'){//elegxei empodia deksia
                                        if(Player[i].pos[0]-1>=0){//elegxos oriwn panw
                                            arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//paei pisw
                                            arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                            Player[i].pos[0]--;
                                            Player[i].WCC--;
                                            Player[i].dir=0;
                                        }
                                    }
                                    else{
                                        arr[Player[i].pos[0]][Player[i].pos[1]+1]=Player[i].pawn;//deksia
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[1]++;
                                    }
                                }
                                else if(Player[i].dir==3){
                                    arr[Player[i].pos[0]][Player[i].pos[1]-1]=Player[i].pawn;//aristera
                                    arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                    Player[i].pos[1]--;
                                }
                            }
                            else if(Player[i].dir==1){//aristera
                                if(Player[i].pos[1]+1>x-1){//elegxei oria deksia
                                    Player[i].dir=3;
                                    if(Player[i].pos[1]-1<0){// elegxei oria aristera
                                        if(Player[i].pos[0]-1>=0){//elegxos oriwn panw
                                            Player[i].dir=0;
                                            arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//paei pisw
                                            arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                            Player[i].pos[0]--;
                                            Player[i].WCC--;
                                        }
                                    }
                                    else if(arr[Player[i].pos[0]][Player[i].pos[1]-1]!='.'){//elegxei empodia aristera
                                        if(Player[i].pos[0]-1>=0){//elegxos oriwn pisw
                                            Player[i].dir=0;
                                            arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//paei pisw
                                            arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                            Player[i].pos[0]--;
                                            Player[i].WCC--;
                                        }
                                    }
                                    else{
                                        arr[Player[i].pos[0]][Player[i].pos[1]-1]=Player[i].pawn;//aristera
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[1]--;
                                    }
                                }
                                else if(arr[Player[i].pos[0]+1][Player[i].pos[1]]!='.'){//elegxei empodia deksia
                                    Player[i].dir=3;
                                    if(Player[i].pos[1]-1<0){// elegxei oria aristera
                                        if(Player[i].pos[0]-1>=0){//elegxos oriwn pisw
                                            Player[i].dir=0;
                                            arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//paei pisw
                                            arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                            Player[i].pos[0]--;
                                            Player[i].WCC--;
                                        }
                                    }
                                    else if(arr[Player[i].pos[0]][Player[i].pos[1]-1]!='.'){//elegxei empodia deksia
                                        if(Player[i].pos[0]-1>=0){//elegxos oriwn panw
                                            Player[i].dir=0;
                                            arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//paei pisw
                                            arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                            Player[i].pos[0]--;
                                            Player[i].WCC--;
                                        }
                                    }
                                    else{
                                        arr[Player[i].pos[0]][Player[i].pos[1]-1]=Player[i].pawn;//aristera
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[1]--;
                                    }
                                }
                                else if(Player[i].dir==1){
                                    arr[Player[i].pos[0]][Player[i].pos[1]+1]=Player[i].pawn;//deksia
                                    arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                    Player[i].pos[1]++;
                                }
                            }
                            else{
                                if(Player[i].pdir==3){//aristera
                                    if(Player[i].pos[1]-1<0){
                                        Player[i].dir=0;
                                        arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//paei pisw
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[0]--;
                                        Player[i].WCC--;
                                        Player[i].pdir=3;
                                    }
                                    else if(arr[Player[i].pos[0]][Player[i].pos[1]-1]!='.'){
                                        Player[i].dir=0;
                                        arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//paei pisw
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[0]--;
                                        Player[i].WCC--;
                                        Player[i].pdir=1;
                                    }
                                    else{
                                        arr[Player[i].pos[0]][Player[i].pos[1]-1]=Player[i].pawn;//aristera
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[1]--;
                                        Player[i].dir=0;
                                    }
                                }
                                else if(Player[i].pdir==1){//deksia
                                    if(Player[i].pos[1]+1>x-1){
                                        Player[i].dir=0;
                                        arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//paei pisw
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[0]--;
                                        Player[i].WCC--;
                                        Player[i].pdir=1;
                                    }
                                    else if(arr[Player[i].pos[0]][Player[i].pos[1]+1]!='.'){
                                        Player[i].dir=0;
                                        arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//paei pisw
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[0]--;
                                        Player[i].WCC--;
                                        Player[i].pdir=1;
                                    }
                                    else{
                                        arr[Player[i].pos[0]][Player[i].pos[1]+1]=Player[i].pawn;//deksia
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[1]++;
                                        Player[i].dir=1;
                                    }
                                }
                            }
                        }
                    }
                }
                if(Player[i].WCC==x-1){
                    printf("Nikhse to BOT %s", Player[i].Name);
                    break;
                }
            }
            if(InitPos[i][0]==x-1&&Player[i].pos[0]==0){
                WC=1;
                printf("\nCongatulations Player %s\n\nYou WON!!!\n",Player[i].Name);
            }
            if(InitPos[i][0]==0&&Player[i].pos[0]==x-1){
                WC=1;
                printf("\nCongatulations Player %s\n\nYou WON!!!\n",Player[i].Name);
            }
            if(InitPos[i][1]==x-1&&Player[i].pos[1]==0){
                WC=1;
                printf("\nCongatulations Player %s\n\nYou WON!!!\n",Player[i].Name);
            }
            if(InitPos[i][1]==0&&Player[i].pos[1]==x-1){
                WC=1;
                printf("\nCongatulations Player %s\n\nYou WON!!!\n",Player[i].Name);
            }
            if(i==4){i=0;}
            else {
                if((strcmp(input,exit)==0)||(strcmp(input,help)==0)){}
                else{
                    i++;
                }
            }
        }
        else{
            if(Player[i].type==1)/*xrhstes*/{
                if(strcmp(input,help)==0){}
                else{
                    tablo(arr,x);
                }
                printf("Player %s\n\nYou have %d obstacles left\n", Player[i].Name,Player[i].obst);
                fgets(input,20,stdin);
                do{
                    if(strcmp(input,exit)==0||strcmp(input,help)==0){
                        if(strcmp(input,help)==0){
                            printf(":\(\n");
                        }
                    }
                    else{
                        if(flag==1){
                            printf("Wrong input.\nGive coordinates again!\n");
                            fgets(input,20,stdin);
                        }
                        if(strcmp(input,help)==0){
                            printf(":\(\n");
                        }
                        flag=0;
                        if(strlen(input)<8||strlen(input)>2){
                            if(strlen(input)==3){        
                                if(input[0]-'a'<0||input[0]-'a'>x-1||input[1]-'1'<0||input[1]-'1'>x-1){
                                    flag=1;
                                }
                                if(flag!=1){
                                    if(((input[0]-'a')-Player[i].pos[1]<-1||(input[0]-'a')-Player[i].pos[1]>1)||input[1]-'1'-Player[i].pos[0]<-1||input[1]-'1'-Player[i].pos[0]>1||arr[input[1]-'1'][input[0]-'a']!='.'){
                                        flag=1;
                                    }
                                    else if(((input[1]-'1')-Player[i].pos[0]==1||(input[1]-'1')-Player[i].pos[0]==-1)&&((input[0]-'a')-Player[i].pos[1]==1||(input[0]-'a')-Player[i].pos[1]==-1)){
                                        flag=1;
                                    }
                                    else if(input[0]-'a'!=Player[i].pos[1]&&input[1]-'1'!=Player[i].pos[0]){
                                        flag=1;
                                    }
                                }
                            }
                            else if(strlen(input)==4){
                                S[0]=input[1];
                                S[1]=input[2];
                                S[2]='\n';
                                o=atoi(S);
                                printf("%d",o);
                                if(input[0]-'a'<0||input[0]-'a'>x-1||o<0||o>x-1){
                                    flag=1;
                                }
                                if(flag!=1){
                                    if((input[0]-'a')-Player[i].pos[1]<-1||(input[0]-'a')-Player[i].pos[1]>1||o-1-Player[i].pos[0]<-1||o-1-Player[i].pos[0]>1||arr[o-1][input[0]-'a']!='.'){
                                        flag=1;
                                    }
                                    else if((o-1-Player[i].pos[0]==1||o-1-Player[i].pos[0]==-1)&&((input[0]-'a')-Player[i].pos[1]==1||(input[0]-'a')-Player[i].pos[1]==-1)){
                                        flag=1;
                                    }
                                    else if((input[0]-'a'!=Player[i].pos[1]&&o-1!=Player[i].pos[0])){
                                        flag=1;
                                    }
                                }
                            }
                            else if(strlen(input)==5&&(strcmp(input,help)!=0&&(strcmp(input,exit)!=0))){
                                if(input[0]-'a'<0||input[0]-'a'>x-1||input[1]-'1'<0||input[1]-'1'>x-1||input[2]-'a'<0||input[2]-'a'>x-1||input[3]-'1'<0||input[3]-'1'>x-1||Player[i].obst<=0){
                                    flag=1;
                                }
                                if(flag!=1){
                                    if(arr[input[1]-'1'][input[0]-'a']!='.'||arr[input[3]-'1'][input[2]-'a']!='.'){
                                        flag=1;
                                    }
                                    if(input[0]==input[2]&&(input[1]-input[3]<-1||input[1]-input[3]>1)){
                                        flag=1;
                                    }
                                    if(input[1]==input[3]&&(input[0]-input[2]<-1||input[0]-input[2]>1)){
                                        flag=1;
                                    }
                                    if(input[0]!=input[2]&&input[1]!=input[3]){
                                        flag=1;
                                    }
                                }
                            }
                            else if(strlen(input)==6||strlen(input)==7){
                                if(strlen(input)==6){
                                    if((input[1]<'9'+1&&input[1]>'0'-1)&&(input[2]<'9'+1&&input[2]>'0'-1)){
                                        S[0]=input[1];
                                        S[1]=input[2];
                                        S[2]='\n';
                                        o=atoi(S);
                                        if(input[0]-'a'<0||input[0]-'a'>x-1||o<0||o>x-1||input[3]-'a'<0||input[3]-'a'>x-1||input[4]-'1'<0||input[4]-'1'>x-1||Player[i].obst<=0){
                                            flag=1;
                                        }
                                        if(flag!=1){
                                            if(arr[o-1][input[0]-'a']!='.'||arr[input[4]-'1'][input[3]-'a']!='.'){
                                                flag=1;
                                            }
                                            if(input[0]==input[3]&&(o-input[4]+'1'<-'1'||o+'1'-input[4]>'1')){
                                                flag=1;
                                            }
                                            if(input[0]!=input[3]&&o!=input[4]){
                                                flag=1;
                                            }
                                        }
                                    }
                                    else{
                                        S[0]=input[3];
                                        S[1]=input[4];
                                        S[2]='\n';
                                        o=atoi(S);
                                        if(input[0]-'a'<0||input[0]-'a'>x-1||o<0||o>x-1||input[1]-'1'<0||input[1]-'1'>x-1||input[2]-'a'<0||input[2]-'a'>x-1||Player[i].obst<=0){
                                            flag=1;
                                        }
                                        if(flag!=1){
                                            if(arr[input[1]-'1'][input[0]-'a']!='.'||arr[o-1][input[2]-'a']!='.'){
                                                flag=1;
                                            }
                                            if(input[0]==input[2]&&(o-input[1]+'1'<-'1'||o-input[1]+'1'>'1')){
                                                flag=1;
                                            }
                                            if(input[0]!=input[2]&&input[1]!=o){
                                                flag=1;
                                            }
                                        }
                                    }
                                }
                                else{
                                    S[0]=input[1];
                                    S[1]=input[2];
                                    S[2]='\n';
                                    o=atoi(S);
                                    U[0]=input[4];
                                    U[1]=input[5];
                                    U[2]='\n';
                                    p=atoi(U);
                                    if(input[0]-'a'<0||input[0]-'a'>x-1||o<0||o>x-1||input[3]-'a'>x-1||input[3]-'a'<0||p<0||p>x-1||Player[i].obst<=0){
                                        flag=1;
                                    }
                                    if(flag!=1){
                                        if(arr[o-1][input[0]-'a']!='.'||arr[p-1][input[3]-'a']!='.'){
                                            flag=1;
                                        }
                                        if(input[0]==input[3]&&(o-p<-1||o-p>1)){
                                            flag=1;
                                        }
                                        if(input[0]!=input[3]&&o!=p){
                                            flag=1;
                                        }
                                    }
                                }
                            }   
                        }
                        else if(strcmp(input,help)!=0&&strcmp(input,exit)!=0){
                            flag=1;
                        }
                    }
                }while(((strcmp(input,exit)==0)&&(strcmp(input,help)==0)||flag==1)); 
                if(flag==1){
                }
                else if(strlen(input)==5&&(strcmp(input,exit)!=0)&&(strcmp(input,help)!=0)){
                    arr[input[1]-'1'][input[0]-'a']='X';
                    arr[input[3]-'1'][input[2]-'a']='X';
                    Player[i].obst--;
                }
                else if(strlen(input)==3||strlen(input)==4){
                    if(strlen(input)==3){
                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                        Player[i].pos[0]=input[1]-'1';
                        Player[i].pos[1]=input[0]-'a';
                        arr[Player[i].pos[0]][Player[i].pos[1]]=Player[i].pawn;
                    }
                    else{
                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                        o=input[1]-'0';
                        p=input[2]-'1';
                        Player[i].pos[0]=o*10+p;
                        Player[i].pos[1]=input[0]-'a';
                        arr[Player[i].pos[0]][Player[i].pos[1]]=Player[i].pawn;
                    }
                }
                else if(strlen(input)==6||strlen(input)==7){
                    Player[i].obst--;
                    if(strlen(input)==6){
                        if((input[1]<'9'+1&&input[1]>'0'-1)&&(input[2]<'9'+1&&input[2]>'0'-1)){
                            o=input[1]-'0';
                            p=input[2]-'1';
                            arr[o*10+p][input[0]-'a']='X';
                            arr[input[4]-'1'][input[3]-'a']='X';
                        }
                        else{
                            arr[input[1]-'1'][input[0]-'a']='X';
                            o=input[3]-'0';
                            p=input[4]-'1';
                            arr[o*10+p][input[0]-'a']='X';
                        }
                    }
                    else{
                        if((input[1]<'9'+1&&input[1]>'0'-1)&&(input[2]<'9'+1&&input[2]>'0'-1)&&(input[4]<'9'+1&&input[4]>'0'-1)&&(input[5]<'9'+1&&input[5]>'0'-1)){
                            o=input[1]-'0';
                            p=input[2]-'1';
                            arr[o*10+p][input[0]-'a']='X';
                            o=input[4]-'0';
                            p=input[5]-'1';
                            arr[o*10+p][input[3]-'a']='X';
                        }
                    }
                } 
            }
            else/*BOTs*/{
                if(Player[i].dd==1){
                    if(arr[Player[i].pos[0]+1][Player[i].pos[1]]=='.'&&Player[i].dir!=0){
                        arr[Player[i].pos[0]+1][Player[i].pos[1]]=Player[i].pawn;
                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                        Player[i].pos[0]++;
                        Player[i].WCC++;
                        Player[i].dir=2;
                    }
                    else{
                        if(Player[i].dir==3&&Player[i].pos[1]-1<0){//an phge aristera kai twra de mporei na ksanapaei logw oriwn
                            if(Player[i].pos[0]-1>=0){//elegxos oriwn panw
                                Player[i].dir=0;
                                arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//paei panw
                                arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                Player[i].pos[0]--;
                                Player[i].WCC--;
                                Player[i].pdir=3;
                            }
                        }
                        else if(Player[i].dir==3&&arr[Player[i].pos[0]][Player[i].pos[1]-1]!='.'){//an phge aristera kai de mporei na ksanapaei logw empodiwn
                            if(Player[i].pos[0]-1>=0){//elegxos oriwn panw
                                Player[i].dir=0;
                                arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//paei panw
                                arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                Player[i].pos[0]--;
                                Player[i].WCC--;
                                Player[i].pdir=3;
                            }
                        }
                        else if(Player[i].dir==1&&Player[i].pos[1]+1>x-1){//an phge deksia kai twra de mporei na ksanapaei logw oriwn
                            if(Player[i].pos[0]-1>=0){//elegxos oriwn panw
                                Player[i].dir=0;
                                arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//paei panw
                                arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                Player[i].pos[0]--;
                                Player[i].WCC--;
                                Player[i].pdir=1;
                            }
                        }
                        else if(Player[i].dir==1&&arr[Player[i].pos[0]][Player[i].pos[1]+1]!='.'){//empodia panw??
                            if(Player[i].pos[0]-1>=0){//elegxos oriwn panw
                                Player[i].dir=0;
                                arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//paei pisw
                                arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                Player[i].pos[0]--;
                                Player[i].WCC--;
                                Player[i].pdir=1;
                            }
                        }
                        else{
                            if(Player[i].dir==Player[i].dd){
                                do{
                                    Player[i].dir=rand()%4;
                                }while(Player[i].dir==2);
                            }
                            if(Player[i].dir==3){//aristera
                                if(Player[i].pos[1]-1<0){ //elegxos oriwn(aristera)
                                    Player[i].dir=1;
                                    if(Player[i].pos[1]+1>x-1){//elegxos oriwn deksia
                                        if(Player[i].pos[0]-1>=0){//elegxos oriwn panw
                                            Player[i].dir=0;
                                            arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//paei panw
                                            arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                            Player[i].pos[0]--;
                                            Player[i].WCC--;
                                        }
                                    }
                                    else if(arr[Player[i].pos[0]][Player[i].pos[1]+1]!='.'){ //elegxos empodiwn deksia
                                        if(Player[i].pos[0]-1>=0){//elegxos oriwn panw
                                            arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//paei panw
                                            arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                            Player[i].pos[0]--;
                                            Player[i].WCC--;
                                            Player[i].dir=0;
                                        }
                                    }
                                    else{
                                        arr[Player[i].pos[0]][Player[i].pos[1]+1]=Player[i].pawn;//deksia
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[1]++;
                                    }
                                }
                                else if(arr[Player[i].pos[0]][Player[i].pos[1]-1]!='.'){//elegxei empodia aristera
                                    Player[i].dir=1;
                                    if(Player[i].pos[1]+1>x-1){//elegxei oria deksia
                                        if(Player[i].pos[0]-1>=0){//elegxos oriwn panw
                                            Player[i].dir=0;
                                            arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//paei pisw
                                            arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                            Player[i].pos[0]--;
                                            Player[i].WCC--;
                                        }
                                    }
                                    else if(arr[Player[i].pos[0]][Player[i].pos[1]+1]!='.'){//elegxei empodia deksia
                                        if(Player[i].pos[0]-1>=0){//elegxos oriwn panw
                                            arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//paei pisw
                                            arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                            Player[i].pos[0]--;
                                            Player[i].WCC--;
                                            Player[i].dir=0;
                                        }
                                    }
                                    else{
                                        arr[Player[i].pos[0]][Player[i].pos[1]+1]=Player[i].pawn;//deksia
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[1]++;
                                    }
                                }
                                else if(Player[i].dir==3){
                                    arr[Player[i].pos[0]][Player[i].pos[1]-1]=Player[i].pawn;//aristera
                                    arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                    Player[i].pos[1]--;
                                }
                            }
                            else if(Player[i].dir==1){//aristera
                                if(Player[i].pos[1]+1>x-1){//elegxei oria deksia
                                    Player[i].dir=3;
                                    if(Player[i].pos[1]-1<0){// elegxei oria aristera
                                        if(Player[i].pos[0]-1>=0){//elegxos oriwn panw
                                            Player[i].dir=0;
                                            arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//paei pisw
                                            arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                            Player[i].pos[0]--;
                                            Player[i].WCC--;
                                        }
                                    }
                                    else if(arr[Player[i].pos[0]][Player[i].pos[1]-1]!='.'){//elegxei empodia aristera
                                        if(Player[i].pos[0]-1>=0){//elegxos oriwn pisw
                                            Player[i].dir=0;
                                            arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//paei pisw
                                            arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                            Player[i].pos[0]--;
                                            Player[i].WCC--;
                                        }
                                    }
                                    else{
                                        arr[Player[i].pos[0]][Player[i].pos[1]-1]=Player[i].pawn;//aristera
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[1]--;
                                    }
                                }
                                else if(arr[Player[i].pos[0]+1][Player[i].pos[1]]!='.'){//elegxei empodia deksia
                                    Player[i].dir=3;
                                    if(Player[i].pos[1]-1<0){// elegxei oria aristera
                                        if(Player[i].pos[0]-1>=0){//elegxos oriwn pisw
                                            Player[i].dir=0;
                                            arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//paei pisw
                                            arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                            Player[i].pos[0]--;
                                            Player[i].WCC--;
                                        }
                                    }
                                    else if(arr[Player[i].pos[0]][Player[i].pos[1]-1]!='.'){//elegxei empodia deksia
                                        if(Player[i].pos[0]-1>=0){//elegxos oriwn panw
                                            Player[i].dir=0;
                                            arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//paei pisw
                                            arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                            Player[i].pos[0]--;
                                            Player[i].WCC--;
                                        }
                                    }
                                    else{
                                        arr[Player[i].pos[0]][Player[i].pos[1]-1]=Player[i].pawn;//aristera
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[1]--;
                                    }
                                }
                                else if(Player[i].dir==1){
                                    arr[Player[i].pos[0]][Player[i].pos[1]+1]=Player[i].pawn;//deksia
                                    arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                    Player[i].pos[1]++;
                                }
                            }
                            else{
                                if(Player[i].pdir==3){//aristera
                                    if(Player[i].pos[1]-1<0){
                                        Player[i].dir=0;
                                        arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//paei pisw
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[0]--;
                                        Player[i].WCC--;
                                        Player[i].pdir=3;
                                    }
                                    else if(arr[Player[i].pos[0]][Player[i].pos[1]-1]!='.'){
                                        Player[i].dir=0;
                                        arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//paei pisw
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[0]--;
                                        Player[i].WCC--;
                                        Player[i].pdir=1;
                                    }
                                    else{
                                        arr[Player[i].pos[0]][Player[i].pos[1]-1]=Player[i].pawn;//aristera
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[1]--;
                                        Player[i].dir=0;
                                    }
                                }
                                else if(Player[i].pdir==1){//deksia
                                    if(Player[i].pos[1]+1>x-1){
                                        Player[i].dir=0;
                                        arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//paei pisw
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[0]--;
                                        Player[i].WCC--;
                                        Player[i].pdir=1;
                                    }
                                    else if(arr[Player[i].pos[0]][Player[i].pos[1]+1]!='.'){
                                        Player[i].dir=0;
                                        arr[Player[i].pos[0]-1][Player[i].pos[1]]=Player[i].pawn;//paei pisw
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[0]--;
                                        Player[i].WCC--;
                                        Player[i].pdir=1;
                                    }
                                    else{
                                        arr[Player[i].pos[0]][Player[i].pos[1]+1]=Player[i].pawn;//deksia
                                        arr[Player[i].pos[0]][Player[i].pos[1]]='.';
                                        Player[i].pos[1]++;
                                        Player[i].dir=1;
                                    }
                                }
                            }
                        }
                    }
                }
                if(Player[i].WCC==x-1){
                    printf("\nBOT %s won\n",Player[i].Name);
                    break;
                }
            }
            if(Player[i].dd==0&&Player[i].pos[0]==0){
                WC=1;
                printf("\nCongatulations Player %s\n\nYou WON!!!\n",Player[i].Name);
            }
            if(Player[i].dd==2&&Player[i].pos[0]==x-1){
                WC=1;
                printf("\nCongatulations Player %s\n\nYou WON!!!\n",Player[i].Name);
            }
            if(i>=1){i=0;}
            else {
                if((strcmp(input,exit)==0)||(strcmp(input,help)==0)){}
                else{
                    i++;
                }
            }
        }
    }while((strcmp(exit,input)!=0)&&(WC!=1));
    for(i=0;i<x;i++){
        free(arr[i]);
    }
    free(arr);
    return 0;
}
void tablo(char** arr,int x){
    int i;
    int j;
    printf("      ");
    for (i=0;i<x;i++){
        printf("%c ", 97+i);
    }
    printf("\n  ---");
    for (i=0;i<x;i++){
        printf("--");
    }
    printf("\n");
    for(j=0;j<x;j++){
        printf("%3d | ", j+1);
        for(i=0;i<x;i++){
            printf("%c ", arr[j][i]);
        }
        printf("\n");
    }
    printf("\n\n\n");
}
