// Q7. Write a program that uses an array of structures to represent a cricket team (player name, runs, wickets). Print the player with the highest runs.
#include<stdio.h>
#include<string.h>
struct cricket {
    char name[50];
    int runs;
    int wickets;
};
int main(){
    int n;
    printf("Enter the number of players: ");
    scanf("%d", &n);
    struct cricket team[n];
    for(int i=0; i<n; i++){
        printf("Enter name, runs and wickets of player %d: ", i+1);
        scanf("%s %d %d", team[i].name, &team[i].runs, &team[i].wickets);
    }
    struct cricket *top_run = &team[0];
    for(int i=1; i<n; i++){
        if(team[i].runs > top_run->runs){
            top_run = &team[i];
        }
    }
    printf("Top Scorer: %s with runs %d and wickets %d\n", top_run->name, top_run->runs, top_run->wickets);
    return 0;
}

