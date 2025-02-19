/*DYNAMIC MEMORY ALLOCATION*/

#include<stdio.h>
#include<stdlib.h>
void countVotes(int votes[], int n_votes, int candidateVotes[]) {
                                        //{4 3 1 1 1}
    for(int i = 0; i < n_votes; i++) {
        candidateVotes[votes[i] - 1]++;
    }
}

int findWinner(int candidateVotes[],int n_candidates){
    int max_votes = 0;
    int winnerIndex = -1;
    
    for(int i=0 ; i< n_candidates; i++){
        if(candidateVotes[i]>max_votes){
            max_votes = candidateVotes[i];
            winnerIndex = i;
        }
    }
    return winnerIndex;
}


int main() {
    int n_votes,n_candidates;
    
    printf("Enter the number of Candidates: ");
    scanf("%d",&n_candidates);
    
    printf("Enter the number of Votes: ");
    scanf("%d", &n_votes);
    
    int* votes = NULL;//no wild pointer//int votes[1000];//{1, 2, 2, 3, 1, 4, 2, 5, 1, 1};
    votes = (int*)malloc(sizeof(int) * n_votes);

    printf("\nEnter votes (1-%d): ",n_candidates);
    for (int i = 0; i < n_votes; i++) {
        scanf("%d", &votes[i]);
    }


    int* candidateVotes = NULL;
    candidateVotes = (int*)calloc(5, sizeof(int));//int candidateVotes[5] = {0, 0, 0, 0, 0};
    
    countVotes(votes, n_votes, candidateVotes);
    int winnerIndex = findWinner(candidateVotes, n_candidates);
    
    for(int i=0;i < n_candidates; i++)
    {
        printf("Candidates %d votes are %d\n",i+1,candidateVotes[i]);
    }
    if (winnerIndex != -1) {
        printf("WINNER: Candidate %d\n", winnerIndex + 1);
    } else {
        printf("No votes were cast.\n");
    }

    free(votes);//dangling pointer
    votes = NULL; //no dangling
    free(candidateVotes);
    candidateVotes = NULL;
    //printf("%d\n",votes[0]);//unde
    return 0;
}