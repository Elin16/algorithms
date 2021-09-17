#include<iostream>
#include<cstdio>
#include<vector>
#include<time.h>
#include<cstdlib>
#include<fstream>
#include<iomanip>
using namespace std;
class Sort{
private:
    ofstream out;
public:
    Sort(){
        out.open("sort.in",ios::app);
    }
    template <typename T>
    vector<T> insertion_sort(vector<T>& a){ //返回值的赋值也会消耗时间
        if(a.empty()) return a;
        int j,key;
        for(int i=1;i<a.size();++i){
            j=i;key=a[i];
            while(j>0&&a[j-1]>key) a[j]=a[j-1],j--; //a[j]=a[--j];
            a[j]=key;
        }
        return a;
    }
    template <typename T>
    vector<T> merge_sort(vector<T>& a){ //返回值的赋值也会消耗时间
        if(a.empty()) return a;
        merge(a,0,a.size());
    }
    template <typename T>
    void merge(vector<T>& a,int l,int r){//左闭右开
        if(r-l<2) return;
        int mid=(l+r+1)>>1;
        merge(a,l,mid);
        merge(a,mid,r);
        vector<T> tem(r-l);
        int p1=l,p2=mid;
        for(int p=0;p<r-l;++p)
            if(p1<mid&&a[p1]<=a[p2]) tem[p]=a[p1++]; //要有等号，否则可能碰到p2越界的情况
            else tem[p]=a[p2++];
        a.assign(tem.begin(),tem.end());
    }
    template <typename T>
    vector<T> get_answer(vector<T> a){
        sort(a.begin(),a.end());
        return a;
    }
    template <typename T>
    bool vertify_answer(vector<T>&a1,vector<T>&a2){
        if(a1.empty()&&a2.empty()) return true;
        if(a1.empty()||a2.empty()) return false;
        for(int i=0;i<a1.size();++i)
        if(a1[i]!=a2[i]) return false;
        return true;
    }
    template <typename T>
    void test(vector<T> input){
        vector<T> ans=get_answer(input);
        vector<T> output=insertion_sort(input);
        bool f=vertify_answer<int>(ans,output);
        if(!f) cout<<"warning!";
        else cout<<"OK";
    }
    vector<int> testCase(int size){ //生产int测试点
        srand((unsigned int)time(NULL));
        vector<int> arr(size);
        while(size) arr[--size]=rand();
        return arr;
    }
    void printCase(vector<int>&arr){
        cout<<arr.size()<<"     ";
        for(auto &a:arr) out<<a<<" ";
        out<<endl;
    }
    void act(){
        int a[]={100,1000,10000,100000,1000000,10000000,
                100000000,1000000000};
        test(testCase(100000));
    }
};
int main(){
    Sort s;
    s.act();
}