#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

FILE *smatch,*rmatch;
char match[100],hctam[100],win[50],score[50];
int count_player[2]={0,0},count_fplayer[2]={0,0};
struct player{
		char p_name[100];
		int p_number,p_foul;
	};
struct fol{
		char fp_name[100];
		int fp_number;
	};
struct check{
		char checkname[100];
		int checknum;
};
	struct team{
		char t_name[50],c_name[100];
		int t_score;
		struct fol fol[12];
		struct player player[12];
		struct check check[12];
	};
	struct team team[2];

int checkDigit(char word[100])
{
    int i;
    for(i = 0; i < strlen(word); i++){
        if(isdigit(word[i])){
            return 1;
        }
    }
    return 0;
}

int checkPunct(char word[100])
{
    int i;
    for(i = 0; i < strlen(word); i++){
        if(ispunct(word[i])){
            return 1;
        }
    }
    return 0;
}

int checkAlpha(char word[2])
{
    int i;
    for(i = 0; i < strlen(word); i++){
        if(isalpha(word[i])){
            return 1;
        }
    }
    return 0;
}

team_coach_player(){
	int sup_player,i,j,check_num,check_team,c,v,check_name,cName,cNum;
	char user,number[2],sup[2],x,y,u,z;
	for(i=0;i<2;i++)
	{
		cNum=0;
		cName=0;
		do{
			printf("Enter Team %d name: ",i+1);
			gets(team[i].t_name);
			for(u=0;u<100;u++){
				team[i].t_name[u]=toupper(team[i].t_name[u]);
			}
			y=checkPunct(team[i].t_name);
			if(x==1||y==1){
				printf("Please Enter Team Name.\n");
				continue;
			}else if(team[i].t_name[0]=='\0'||team[i].t_name[0]==' '){
				printf("Please Enter Team Name.\n");
				continue;
			}else{
				if(strcmp(team[i].t_name,team[i-1].t_name)==0){
					printf("Team name are DUPLICATE.\n");
					continue;
				}else{
					break;
				}
			}
		}while(1);
		do{
			printf("\nEnter Coach name: ");
			gets(team[i].c_name);
			for(u=0;u<100;u++){
				team[i].c_name[u]=toupper(team[i].c_name[u]);
			}
			x=checkDigit(team[i].c_name);
			y=checkPunct(team[i].c_name);
			if(x==1||y==1){
				printf("Please Enter Coach Name.\n");
				continue;
			}else if(team[i].c_name[0]=='\0'||team[i].c_name[0]==' '){
				printf("Please Enter Coach Name.\n");
				continue;
			}else{
				break;
			}
		}while(1);
		printf("\n");
		while(count_player[i]!=5){
			do{
				printf("Enter Player %d name: ",count_player[i]+1);
				gets(team[i].player[count_player[i]].p_name);
				for(u=0;u<100;u++){
					team[i].player[count_player[i]].p_name[u]=toupper(team[i].player[count_player[i]].p_name[u]);
				}
				x=checkDigit(team[i].player[count_player[i]].p_name);
				y=checkPunct(team[i].player[count_player[i]].p_name);
				if(x==1||y==1){
					printf("Please Enter Player Name.\n");
					continue;
				}else if(team[i].player[count_player[i]].p_name[0]=='\0'||team[i].player[count_player[i]].p_name[0]==' '){
					printf("Please Enter Player Name.\n");
					continue;
				}else{
					check_name=0;
					for(v=0;v<2;v++){
						for(c=0;c<12;c++){
							if(strcmp(team[i].player[count_player[i]].p_name,team[v].check[c].checkname)==0){
								check_name=1;
								break;
							}else if(strcmp(team[i].player[count_player[i]].p_name,team[v].c_name)==0){
								check_name=1;
								break;
							}
						}
					}
					if(check_name==1){
						printf("Player name are DUPLICATE.\n");
						continue;
					}
					if(check_name==0){
						strcpy(team[i].check[cName].checkname,team[i].player[count_player[i]].p_name);
						cName++;
						break;
					}
				}
			}while(1);
			do{
				printf("Enter Player %d number: ",count_player[i]+1);
				gets(number);
				z=checkAlpha(number);
				team[i].player[count_player[i]].p_number=atoi(number);
				if(z==1){
					printf("Please Enter Player Number.\n");
					continue;
				}else if(number[0]==' '||number[0]=='\0'||atoi(number)<1||atoi(number)>99){
					printf("Please Enter Player Number.\n");
					continue;
				}else{
					check_num=0;
					for(c=0;c<12;c++){
						if(team[i].player[count_player[i]].p_number==team[i].check[c].checknum){
							check_num=1;
							break;
						}
					}
					if(check_num==1){
						printf("Player Number are DUPLICATE.\n");
						continue;
					}else{
						team[i].check[cNum].checknum=team[i].player[count_player[i]].p_number;
						cNum++;
						break;
					}
				}
			}while(1);
			count_player[i]++;
		}
		count_player[i]--;
		printf("\n7 players left.\n");
		do{
			printf("Add more players?(Y/N): ");
			user=getche();
			user=toupper(user);
			if(user=='Y'){
				printf("\n");
				do{
					printf("How many player want to add?: ");
					gets(sup);
					sup_player=atoi(sup);
					if(sup_player<=7&&sup_player>0){
						count_player[i]+=sup_player;
						for(j=5;j<=count_player[i];j++){
							do{
								printf("Enter Player %d name: ",j+1);
								gets(team[i].player[j].p_name);
								for(u=0;u<100;u++){
									team[i].player[j].p_name[u]=toupper(team[i].player[j].p_name[u]);
								}
								x=checkDigit(team[i].player[j].p_name);
								y=checkPunct(team[i].player[j].p_name);
								if(x==1||y==1){
									printf("Please Enter Player Name.\n");
									continue;
								}else if(team[i].player[j].p_name[0]=='\0'||team[i].player[j].p_name[0]==' '){
									printf("Please Enter Player Name.\n");
									continue;
								}else{
									check_name=0;
									for(v=0;v<2;v++){
										for(c=0;c<12;c++){
											if(strcmp(team[i].player[j].p_name,team[v].check[c].checkname)==0){
												check_name=1;
												break;
											}else if(strcmp(team[i].player[j].p_name,team[v].c_name)==0){
												check_name=1;
												break;
											}
										}
									}
									if(check_name==1){
										printf("Player name are DUPLICATE.\n");
										continue;
									}
									if(check_name==0){
										strcpy(team[i].check[cName].checkname,team[i].player[j].p_name);
										cName++;
										break;
									}
								}
							}while(1);
							do{
								printf("Enter Player %d number: ",j+1);
								gets(number);
								z=checkAlpha(number);
								team[i].player[j].p_number=atoi(number);
								if(z==1){
									printf("Please Enter Player Number.\n");
									continue;
								}else if(number[0]==' '||number[0]=='\0'||atoi(number)<1||atoi(number)>99){
									printf("Please Enter Player Number.\n");
									continue;
								}else{
									check_num=0;
									for(c=0;c<12;c++){
										if(team[i].player[j].p_number==team[i].check[c].checknum){
											check_num=1;
											break;
										}
									}
									if(check_num==1){
										printf("Player Number are DUPLICATE.\n");
										continue;
									}else{
										team[i].check[cNum].checknum=team[i].player[j].p_number;
										cNum++;
										break;
									}
								}
							}while(1);
						}
						break;
					}else{
						printf("*** 7 player left. *** \nPlease try again.\n");
						continue;
					}
				}while(1);
				system("cls");
				break;
			}if(user=='N'){
				system("cls");
				break;
			}else{
				printf("\n");
				printf("Wrong letter. Please try again.\n");
			}
		}while(1);
	}
	system("cls");
	for(i=0;i<2;i++){
		printf("============================================\n\n");
		printf("Team %s\n\n",team[i].t_name);
		printf("____________________________________________\n\n");
		printf("Player list: \n\n");
		for(j=0;j<=count_player[i];j++)
			printf("Name: %s\nNumber: %d\n\n",team[i].player[j].p_name,team[i].player[j].p_number);
		printf("\n\n____________________________________________\n\n");
	}
	printf("Press any key to start.....");
}

annouce(){
	int i,j;
	if(count_fplayer[0]>0||count_fplayer[1]>0){
		printf("!! Player FOUL OUT. !!\n");
		for(i=0;i<2;i++){
			printf("Team %s\n",team[i].t_name);
			if(count_fplayer[i]==0){
				printf("(NONE)\n");
				continue;
			}
			for(j=0;j<count_fplayer[i];j++)
				printf("Name: %s Number: %d\n",team[i].fol[j].fp_name,team[i].fol[j].fp_number);
		}
		printf("\n");
	}
}

foul(int wteam){
	int i,foul,check;
	char glass[100];
	printf("\nTeam: %s\n\n",team[wteam].t_name);
	printf("Player list: \n\n");
	for(i=0;i<=count_player[wteam];i++)
		printf("%s Number: %d\n",team[wteam].player[i].p_name,team[wteam].player[i].p_number);
	do{
		printf("\nEnter player number to add foul: ");
		scanf("%d",&foul);
		check=0;
		for(i=0;i<=count_player[wteam];i++){
			if(foul==team[wteam].player[i].p_number){
				team[wteam].player[i].p_foul++;
				check++;
				if(team[wteam].player[i].p_foul==5){
					strcpy(team[wteam].fol[count_fplayer[wteam]].fp_name,team[wteam].player[i].p_name);
					team[wteam].fol[count_fplayer[wteam]].fp_number = team[wteam].player[i].p_number;
					count_fplayer[wteam]++;
					break;
				}
				break;
			}
			}
		if(check==0){
				printf("Wrong player number. Please try again.\n");
				continue;
		}else{
			break;
		}
	}while(1);
}

int summary(){
	if(team[0].t_score>team[1].t_score){
		printf("!!!!!!   %s Won   !!!!!!!\n",team[0].t_name);
		printf("Score    %d : %d\n",team[0].t_score,team[1].t_score);
		if((smatch=fopen("All Match.txt","a"))==NULL){
			printf("Can't open All Match.txt for save.\n");
			exit(1);
		}
		fprintf(smatch,"%svs%s ",team[0].t_name,team[1].t_name);
		fprintf(smatch,"%s ",team[0].t_name);
		fprintf(smatch,"%d:%d ",team[0].t_score,team[1].t_score);
		fclose(smatch);	
		return 0;
	}else if(team[0].t_score<team[1].t_score){
		printf("!!!!!!   %s Won   !!!!!!!\n",team[1].t_name);
		printf("Score    %d : %d\n\n",team[1].t_score,team[0].t_score);
		if((smatch=fopen("All Match.txt","a"))==NULL){
			printf("Can't open All Match.txt for save.\n");
			exit(1);
		}
		fprintf(smatch,"%s %s ",team[0].t_name,team[1].t_name);
		fprintf(smatch,"%s ",team[1].t_name);
		fprintf(smatch,"%d:%d ",team[1].t_score,team[0].t_score);
		fclose(smatch);	
		return 0;
	}else{
		return 1;
	}
}

score_foul(){
	char user,edit;
	int end=0,sum;
	do{
		do{
			printf("Team 1 : %s\n\n",team[0].t_name);
			printf("SCORE  : %d\n\n\n",team[0].t_score);
			printf("Team 2 : %s\n\n",team[1].t_name);
			printf("SCORE  : %d\n\n\n",team[1].t_score);
			printf("============================================\n\n\n");
			printf("Team 1 (1) || Team 2 (2) || End(E)\n\n");
			printf("____________________________________________\n\n\n");
			printf("Select choice: ");
			user=getche();
			printf("\n\n");
			printf("____________________________________________\n\n");
			if(user=='1'){
				printf("+1 point (1) || +2 point (2) || +3 point (3)\n\n");
				printf("                -1 point (-)\n\n");
				printf("                  Foul (F)\n\n");
				printf("                 Cancel (C)\n\n");
				printf("____________________________________________\n\n");
				printf("Enter keyword to edit: ");
				edit=getche();
				edit=toupper(edit);
				printf("\n");
				if(edit=='1'){
					team[0].t_score++;
					system("cls");
					break;
				}
				else if(edit=='2'){
					team[0].t_score+=2;
					system("cls");
					break;
				}
				else if(edit=='3'){
					team[0].t_score+=3;
					system("cls");
					break;
				}
				else if(edit=='-'){
					team[0].t_score--;
					if(team[0].t_score<0){
						system("cls");
						printf("!! Now, score Team 1 are 0. !!\n\n");
						team[0].t_score++;
						break;
					}
					system("cls");
					break;
				}
				else if(edit=='F'){
					foul(0);
					system("cls");
					annouce();
					break;
				}
				else if(edit=='C'){
					system("cls");
					break;
				}else{
					system("cls");
					printf("!! Wrong keyword. Please try again. !!\n\n");
					continue;
				}
			}else if(user=='2'){
				printf("+1 point (1) || +2 point (2) || +3 point (3)\n\n");
				printf("                -1 point (-)\n\n");
				printf("                  Foul (F)\n\n");
				printf("                 Cancel (C)\n\n");
				printf("____________________________________________\n\n");
				printf("Enter keyword to edit: ");
				edit=getche();
				edit=toupper(edit);
				printf("\n");
				if(edit=='1'){
					team[1].t_score++;
					system("cls");
					break;
				}
				else if(edit=='2'){
					team[1].t_score+=2;
					system("cls");
					break;
				}
				else if(edit=='3'){
					team[1].t_score+=3;
					system("cls");
					break;
				}
				else if(edit=='-'){
					team[1].t_score--;
					if(team[1].t_score<0){
						system("cls");
						printf("!! Now, score Team 2 are 0. !!\n\n");
						team[1].t_score++;
						break;
					}
					system("cls");
					break;
				}
				else if(edit=='F'){
					foul(1);
					system("cls");
					annouce();
					break;
				}
				else if(edit=='C'){
					system("cls");
					break;
				}else{
					system("cls");
					printf("!! Wrong keyword. Please try again. !! \n\n");
					break;
				}
			}else if(user=='E'||user=='e'){
				end=1;
				break;
			}else{
				system("cls");
				printf("!! Wrong keyword. Please try again. !!\n\n");
				break;
			}
		}while(1);
		if(end==1){
			system("cls");
			sum=summary();
			if(sum==1){
				end=0;
				printf("!! Draw. The game will continue. !!\n\n");
				continue;
			}
			break;
		}
	}while(1);
}

main(){
	char user,click;
	do{
		printf("=====================\n");
		printf("|    Bas-pointer    |\n");
		printf("---------------------\n");
		printf("|    New Match(N)   |\n");
		printf("|    Load Match(L)  |\n");
		printf("|    Quit(Q)        |\n");
		printf("---------------------\n\n");
		printf("Enter your choice: ");
		user=getche();
		user=toupper(user);
		printf("\n");
		if(user=='N'){
			system("cls");
			team_coach_player();
			if(click=getche()){
				system("cls");
				score_foul();
				printf("\n\n\nPress any key.....");
				if(click=getche()){
					system("cls");
					continue;
				}
			}
		}else if(user=='L'){
			if((rmatch=fopen("All Match.txt","r"))==NULL){
				printf("Don't have any SAVE in All Match.txt yet.\n");
				exit(1);
			}
			printf("---All Match in DATA---\n\n");
			printf("| Match || Win || Score |\n\n");
			while((fscanf(rmatch,"%s %s %s %s",&match,&hctam,&win,&score))!=EOF){
				printf("%s vs %s || %-20s || %-20s\n",match,hctam,win,score);
			}
			fclose(rmatch);
			printf("\n\nPress any key......");
			if(click=getche()){
				system("cls");
				continue;
			}
		}else if(user=='Q'){
			break;
		}else{
			system("cls");
			printf("!! Wrong keyword. Please try again. !!\n\n");
			continue;
		}
	}while(1);
}
