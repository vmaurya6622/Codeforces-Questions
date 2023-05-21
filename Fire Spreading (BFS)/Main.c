#include <stdio.h>
int Checkpoint(int s,int r,int Rows,int Columns){
    if ((s>=0 && s<Rows && r>=0 && r<Columns)){
        return 1;
    }
    else{
        return 0;
    }
}

struct Location_of_values{
    int first;
    int Second;
};

int Counter=0; //counter of the time.
int main(){
    int Rows,Columns;
    scanf("%d %d",&Rows,&Columns);
    int Matrix[Rows][Columns];
    for (int i=0;i<Rows;i++){
        for (int j=0;j<Columns;j++){
            scanf("%d",&Matrix[i][j]);
        }
    }
    struct Location_of_values queue[Rows*Columns];
    int Testing_Done[Rows][Columns];
    for (int i=0;i<Rows;i++){
        for (int j=0;j<Columns;j++){
            Testing_Done[i][j]=0;
        }
    }
    int f=0,r=0;
    for (int i=0;i<Rows;i++){
        for (int j=0;j<Columns;j++){
            if (Matrix[i][j]==1){
                queue[r++]=(struct Location_of_values){i,j};
                Testing_Done[i][j]=1;
            }
        }
    }
    //Now traversing at every Location_of_valuessible locations adjacent to the number.
    while (f<=r){
        struct Location_of_values now=queue[f++];
        int First_val_check,second_val_check;
        // top
        First_val_check=now.first-1;
        second_val_check=now.Second;
        if (Checkpoint(First_val_check,second_val_check,Rows,Columns)==1 && Matrix[First_val_check][second_val_check]==0 && Testing_Done[First_val_check][second_val_check]==0){
            Testing_Done[First_val_check][second_val_check]=1;
            queue[r++]=(struct Location_of_values){First_val_check,second_val_check};
            Matrix[First_val_check][second_val_check]=Matrix[now.first][now.Second]+1;
            if (Counter<Matrix[First_val_check][second_val_check]){
                Counter=Matrix[First_val_check][second_val_check];
            }
        }
        // down
        First_val_check=now.first+1;
        second_val_check=now.Second+1;
        if (Checkpoint(First_val_check,second_val_check,Rows,Columns)==1 && Matrix[First_val_check][second_val_check]==0 && Testing_Done[First_val_check][second_val_check]==0){
            Testing_Done[First_val_check][second_val_check]=1;
            queue[r++]=(struct Location_of_values){First_val_check,second_val_check};
            Matrix[First_val_check][second_val_check]=Matrix[now.first][now.Second] + 1;
            if (Counter<Matrix[First_val_check][second_val_check]){
                Counter=Matrix[First_val_check][second_val_check];
            }
        }
        // down left
        First_val_check=now.first+1;
        second_val_check=now.Second-1;
        if (Checkpoint(First_val_check,second_val_check,Rows,Columns)==1 && Matrix[First_val_check][second_val_check]==0 && Testing_Done[First_val_check][second_val_check]==0){
            Testing_Done[First_val_check][second_val_check]=1;
            queue[r++]=(struct Location_of_values){First_val_check,second_val_check};
            Matrix[First_val_check][second_val_check]=Matrix[now.first][now.Second] + 1;
            if (Counter<Matrix[First_val_check][second_val_check]){
                Counter=Matrix[First_val_check][second_val_check];
            }
        }
        // down right
        First_val_check=now.first+1;
        second_val_check=now.Second;
        if (Checkpoint(First_val_check, second_val_check, Rows, Columns) == 1 && Matrix[First_val_check][second_val_check]==0 && Testing_Done[First_val_check][second_val_check]==0){
            Testing_Done[First_val_check][second_val_check] = 1;
            queue[r++]=(struct Location_of_values){First_val_check,second_val_check};
            Matrix[First_val_check][second_val_check]=Matrix[now.first][now.Second]+1;
            if (Counter<Matrix[First_val_check][second_val_check]){
                Counter=Matrix[First_val_check][second_val_check];
            }
        }
        // top right
        First_val_check=now.first-1;
        second_val_check=now.Second+1;
        if (Checkpoint(First_val_check,second_val_check,Rows,Columns)==1 && Matrix[First_val_check][second_val_check]==0 && Testing_Done[First_val_check][second_val_check]==0){
            Testing_Done[First_val_check][second_val_check]=1;
            queue[r++]=(struct Location_of_values){First_val_check,second_val_check};
            Matrix[First_val_check][second_val_check]=Matrix[now.first][now.Second]+1;
            if (Counter<Matrix[First_val_check][second_val_check]){
                Counter=Matrix[First_val_check][second_val_check];
            }
        }
        // top left
        First_val_check=now.first-1;
        second_val_check=now.Second-1;
        if (Checkpoint(First_val_check,second_val_check,Rows,Columns)==1 && Matrix[First_val_check][second_val_check] == 0 && Testing_Done[First_val_check][second_val_check]==0){
            Testing_Done[First_val_check][second_val_check]=1;
            queue[r++]=(struct Location_of_values){First_val_check,second_val_check};
            Matrix[First_val_check][second_val_check]=Matrix[now.first][now.Second]+1;
            if (Counter<Matrix[First_val_check][second_val_check]){
                Counter=Matrix[First_val_check][second_val_check];
            }
        }
        // mid left
        First_val_check=now.first;
        second_val_check=now.Second-1;
        if (Checkpoint(First_val_check,second_val_check,Rows,Columns)==1 && Matrix[First_val_check][second_val_check]==0 && Testing_Done[First_val_check][second_val_check]==0){
            Testing_Done[First_val_check][second_val_check]=1;
            queue[r++]=(struct Location_of_values){First_val_check, second_val_check};
            Matrix[First_val_check][second_val_check]=Matrix[now.first][now.Second] + 1;
            if (Counter<Matrix[First_val_check][second_val_check]){
                Counter=Matrix[First_val_check][second_val_check];
            }
        }
        // mid right
        First_val_check=now.first;
        second_val_check=now.Second+1;
        if (Checkpoint(First_val_check,second_val_check,Rows,Columns)==1 && Matrix[First_val_check][second_val_check]==0 && Testing_Done[First_val_check][second_val_check]==0){
            Testing_Done[First_val_check][second_val_check]=1;
            queue[r++]=(struct Location_of_values){First_val_check,second_val_check};
            Matrix[First_val_check][second_val_check]=Matrix[now.first][now.Second]+1;
            if (Counter<Matrix[First_val_check][second_val_check]){
                Counter=Matrix[First_val_check][second_val_check];
            }
        }
    }
    printf("%d", (Counter-1 > 0) ? Counter-1 : 0);   //printing the answer/counter.
    return 0;
}
