#include<iostream>
#include<algorithm>
using namespace std;
typedef struct student{
    string name;
    int roll;
    string branch;
}Student;
void display(Student s[]){
    cout<<'\n';
    for(int i=0;i<4;i++)
        cout<<s[i].name<<" "<<s[i].roll<<" "<<s[i].branch<<"\n";
}
int main(){
    Student s[4];
    for(int i=0;i<4;i++)
        cin>>s[i].name>>s[i].roll>>s[i].branch;
    int min;
    for(int i=0;i<4;i++){
        min=i;
        for(int j=i+1;j<4;j++)
            if(s[j].name.compare(s[min].name)==-1)
                min=j;
        if(min!=i){
        swap(s[i].name,s[min].name);
        swap(s[i].roll,s[min].roll);
        swap(s[i].branch,s[min].branch);
        }
    }
    display(s);
    return 0;
}