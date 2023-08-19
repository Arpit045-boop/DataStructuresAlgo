#include<bits/stdc++.h>
using namespace std;

int sum(vector<int> &v){
    int sum =0 ;
    for(int i=0;i<v.size();i++){
        sum += v[i];
    }
    return sum;
}
int func(vector<int> &v, int page){
    int st = 1, pageHold = 0;
    for(int i=0;i<v.size();i++){
        if(pageHold + v[i] <= page){
            pageHold+=v[i];
        }
        else{
            st++;
            pageHold = v[i];
        }
    }
    return st;
}
int main(){
    vector<int> v={12,34,67,90};
    int k = 2;
    int n = v.size();
    int low = *max_element(v.begin(),v.end());
    int high = sum(v);
    // Linear Search

    // for(int page=low;page <= high;page++){
    //     int countStu = func(v,page);
    //     if(countStu == k){
    //         cout<<page<<endl;
    //         break;
    //     }
    // }

    // Binary Search

    while(low<=high){
       int mid  = low + (high-low)/2;
       int studentCount = func(v,mid);
    //    cout<<"Mid "<<mid<<endl;
       if(studentCount  > k){
         low = mid+1;
       }
       else{
        high = mid-1;
       }
    //    cout<<"Low "<<high<<endl;
    }

    cout<<low<<endl;

}