#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int op;
        cin>>op;
        int initial[op];
        for(int p=0;p<op;p++){
            cin>>initial[p];
        }
        for(int j=0;j<op;j++){
            int no_of_op;
            char str[15];
            scanf("%d %s",&no_of_op,str);

            for(int k = 0; k < no_of_op; k++){
                if(str[k] == 'D'){
                    if(initial[j] == 9){
                        initial[j] = 0;
                    }
                    else{
                        initial[j]++;
                    }
                }
                else{
                    if(initial[j] == 0){
                        initial[j] = 9;
                    }
                    else{
                        initial[j]--;
                    }
                }
            }
        }
        for(int o = 0; o < op; o++){
            cout<<initial[o]<<" ";
        }
        cout<<endl;
        
    }
}
