# include <stdio.h>
int max(int a, int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int main()
{
    int Rows , Column;
    scanf("%d %d",&Rows,&Column);
    char arr[Rows][Column];
    for (int i=0;i<Rows;i++){
            scanf("%s", &arr[i]);
    }
    int Perimeter_Answer = 0;
    for (int i=0 ; i<Rows ; i++){
        for (int j=0 ; j< Column ; j++){
            if (arr[i][j]=='.'){
                int Left_Index = 1, Right_Index = 1;
                for (int k = i+1 ; k<Rows && arr[k][j]=='.';k++){
                    Left_Index++;
                }
                for (int k=j+1 ; k<Column && arr[i][k] == '.'; k++){
                    Right_Index++;
                }
                if (Left_Index > Right_Index){
                    Perimeter_Answer = max(Perimeter_Answer, 2*(Left_Index)+1);
                }
                else{
                    Perimeter_Answer = max(Perimeter_Answer, 2*(Right_Index)+1);
                }
            }
        }
    }
    printf("%d",Perimeter_Answer);
}
