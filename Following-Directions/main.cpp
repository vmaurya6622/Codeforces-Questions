#include <bits\stdc++.h>
#include <string>
using namespace std;
string arrs[1005];
int index=0;
int flag=0;

void ans_maker(char arr[],int k){
    int xc=0;
    int yc=0;
    for(int i=0 ;i<k;i++){
        if (arr[i]=='U'){
            yc++;
            if(xc==yc && xc==1){
                flag+=10;
            }
        }
        if (arr[i]=='D'){
            yc--;
            if(xc==yc && xc==1){
                flag+=10;
            }
        }
        if (arr[i]=='R'){
            xc++;
            if(xc==yc && xc==1){
                flag+=10;
            }
        }
        if (arr[i]=='L'){
            xc--;
            if(xc==yc && xc==1){
                flag+=10;
            }
        }
    }
    if (flag>0){
        arrs[index]="YES";
    }
    else{
        arrs[index]="NO";
    }

}

int main(){
    int n;
    cin>>n;
    for(int i = 0 ; i<n ; i++ ){
        int k;
        cin>>k;
        char arr[k];
        for(int j =0 ;j<k;j++){
            cin>>arr[j];
        }
        ans_maker(arr,k);
        index++;
        flag=0;
    }
    for(int j=0;j<index;j++){
        cout<<arrs[j]<<endl;
    }
}
