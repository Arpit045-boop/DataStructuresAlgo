#include<bits/stdc++.h>
using namespace std;

int bs(vector<int> &v, int low, int high, int key){
    while(low <= high){
        int mid = low + (high - low)/2;
        if(v[mid] == key){
            return mid;
        }
        else if(v[mid] < key){
            low = mid;
        }
        else if(v[mid]> key){
            high = mid;
        }
    }
    return 0;
}


int searchInfinite(vector<int> &v, int key, int low, int high){
    while(v[high] < key){
        low = high;
        high=2*high;
    }
    return bs(v,low,high,key);
}

int main(){
    vector<int> v={9, 11, 17, 26, 37, 52, 89, 111, 129, 144, 198};
    int key = 89;
    cout<<searchInfinite(v,key,0,1);

}
