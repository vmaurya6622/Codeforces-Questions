#include <bits/stdc++.h>
using namespace std;
#define N 105
int counter=0;

void total_swaps(int n, int arr[],int max){
    for (int i = max; i > 0; i--) {
        int temp = arr[i];
        arr[i] = arr[i-1];
        arr[i-1] = temp;
        counter++;
    }
    int min_element=arr[0]; //find the min index here because due to swapping the elements must have changed their positions
    int min_index=0;
    for (int i = 1; i < n; i++){
        if (arr[i] <= min_element){    //here equality is necessary so that the rightmost minimum element must be selected
            min_element = arr[i];
            min_index=i;
        }
    }
    for (int i = min_index; i < n - 1; i++) {
        swap(arr[i], arr[i+1]);
        counter++;     //update the counter variable
    }
    cout<<counter<<endl;
}

int main(){
    int n;
    cin >> n;   //take the input from STDIN
    int arr[N];
    for (int i = 0; i < n; i++){   
        cin >> arr[i];
    }
    int max_index=0;
    int max_element = arr[0];
    for (int i = 1; i < n; i++){
        if (arr[i] > max_element){  //here the equality isn't meeded as the first-most/leftmost occurence of the highest element must be considered to get there
            max_element = arr[i];
            max_index=i;
        }
    }
    total_swaps(n, arr,max_index); 
    return 0;
}
