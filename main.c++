#include"header.h"
using namespace std;
int main(){
    char OP;
    SLL* headPtr=0;
    while(1){
        cout<<"*****STUDENT RECORD MENU*****"<<endl;
        cout<<"a/A"<<" "<<":Add new record "<<endl;
        cout<<"d/D"<<" "<<":delete a record "<<endl;
        cout<<"s/S"<<" "<<":show the list "<<endl;
        cout<<"m/M"<<" "<<":modify a record "<<endl;
        cout<<"v/V"<<" "<<":save"<<endl;
        cout<<"e/E"<<" "<<":Sort the list"<<endl;
        cout<<"t/T"<<" "<<":Delete all the records"<<endl;
        cout<<"r/R"<<" "<<":Reverse the lsit"<<endl;
        cout<<endl;
        cout<<"Enter your option"<<endl;
        cin>>OP;
        switch(OP){
            case 'A': addRecord( &headPtr);
                        break;
            case 'a': addRecord(&headPtr);
                        break;
            case 's': printRecord(headPtr);
                        break;
            case 'S': printRecord(headPtr);
                        break;
             case 'd':deleteRecord(&headPtr);break;
             case 'D':deleteRecord(&headPtr);break;
            // case 'm':
            // case 'M':
            // case 'v':
            // case 'V':
            // case 'e':
            // case 'E':
            // case 't':
            // case 'T':
            default:cout<<"Enter valid option "<<endl;
        }
    }
}
int countNode(SLL *ptr){
    int count=0;
    while(ptr){
        count++;
        ptr=ptr->next;
    }
    return count;
}
void deleteAccordingToRollNo(SLL **ptr){
    int roll;
    cout<<"Enter the rollNo that you want to delete"<<endl;
    cin>>roll;
    SLL *del=*ptr;
    SLL *prev=NULL;
    while(del!=NULL && del->rollNo!=roll){
        prev=del;
        del=del->next;
    }
    if(del==NULL){
        cout<<"Roll number not found"<<endl;
        return;
    }
    if(prev==NULL){
        *ptr=del->next;
    }
    else{
        prev->next=del->next;
    }
    free(del);
    del=*ptr;
    int c=countNode( *ptr);
    for(int i=1;i<c+1;i++){
        del->rollNo=i;
        del=del->next;
    }
}
void deleteAccordingToName(SLL **ptr){
    char nameToBeDeleted[20];
    int c=0;
    if(*ptr==NULL)
    {
        cout<<"No record present"<<endl;
        return;
    }
    cout<<"Enter the name: "<<endl;
    cin>>nameToBeDeleted;
    SLL *del=*ptr;
    SLL *prev=NULL;
    while(del!=NULL ){
        if(strcmp(del->name,nameToBeDeleted)==0){
            c++;
        }
        del=del->next;
    }
    if(c<=1){
        del=*ptr;
        prev=NULL;
        while(del!=NULL && strcmp(del->name,nameToBeDeleted)!=0){
            prev=del;
            del=del->next;
        }
        if(prev==NULL)
            *ptr=del->next;

        else{
            prev->next=del->next;
        }
        free(del);
    }
    else if(c>1){
        del=*ptr;
        int op;
        cout<<"Name that you enter is present more than 1 time"<<endl;
        cout<<"Here is roll no of that name so,you can delete in proper way"<<endl;
        while(del){
            if(strcmp(del->name,nameToBeDeleted)==0){
                cout<<del->rollNo<<" "<<del->name<<endl;
            }
            del=del->next;
        }
        del=*ptr;
        cout<<"Now enter the roll No"<<endl;
        cin>>op;
         prev=NULL;
        while(del!=NULL && del->rollNo!=op){
            prev=del;
            del=del->next;
        }
        if(del==NULL){
            cout<<"Roll number not found"<<endl;
            return;
        }
        if(prev==NULL){
            *ptr=del->next;
        }
        else{
            prev->next=del->next;
        }
        free(del);
        
    }
    del=*ptr;
    int count=countNode( *ptr);
    for(int i=1;i<count+1;i++){
        del->rollNo=i;
        del=del->next;
    }
}
void addRecord(SLL **ptr){
    SLL *newRecord = new SLL;
    cout<<"Enter the student deltail :"<<endl;
    cin>>newRecord->name;
    cin>>newRecord->precent;
        newRecord->rollNo=1;
        newRecord->next=*ptr;
        *ptr=newRecord;
    int c=countNode( *ptr);
    for(int i=1;i<c+1;i++){
        newRecord->rollNo=i;
        newRecord=newRecord->next;
    }
}
void printRecord(SLL *ptr){
    if(ptr==0){
        cout<<"There are no record present "<<endl;
    }
    while(ptr){
        cout<<ptr->rollNo<<" "<<ptr->name<<" "<<ptr->precent<<endl;
        ptr=ptr->next;
    }

}
void deleteRecord(SLL **ptr){
    char op;
    cout<<"How would you like to delete record according -"<<endl;
    cout<<"R/r:  enter the rollNo"<<endl;
    cout<<"N/n: enter the name"<<endl;
    cin>>op;
    switch(op){
        case 'r': deleteAccordingToRollNo(ptr);break;
        case 'R': deleteAccordingToRollNo(ptr);break;
        case 'n': deleteAccordingToName(ptr);break;
        case 'N': deleteAccordingToName(ptr);break;
    }
}
