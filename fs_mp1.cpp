#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
using std::copy;
using std::istream_iterator;

void add_party(){
    fstream fp1;
    fp1.open("cand.txt",ios::out);
    int numCan;
    char partyName[25];
    cout<<"Enter number of candidates: ";
    cin>>numCan;
    if(numCan>1){
        for(int i=1;i<=numCan;i++){
            cout<<"Enter party name"<<i;
            cin>>partyName;
            fp1<<partyName<<endl;
        }
    }
    fp1.close();
}
void register_user(){
    fstream fp2,fp3;
    fp2.open("voter.txt",ios::out|ios::app);
    fp3.open("ids.txt",ios::out|ios::app);
    int age,id,check;
    char name[25];
    cout<<"Enter age: ";
    cin>>age;
    if(age>=18){
        cout<<"Enter id:";
        cin>>id;
        fp3<<id<<endl;
        cout<<"Enter your name: ";
        cin>>name;
        fp2<<name<<"\t"<<age<<endl;
    }
    else{
        cout<<"Minimum age to vote is 18 years.";
    }
    fp2.close();
    fp3.close();
}


void display_cand(){
    fstream fdata;
	fdata.open("cand.txt",ios::in);
	
	char list1[100][20];
    int count=0;
	while(!fdata.eof())
	{
		fdata.getline(list1[count],20,'\n');
        cout<<list1[count]<<endl;
        count++;
	}
	fdata.close();
}

void cast_vote()
{
    fstream fp4,fp5;
    fp4.open("ids.txt",ios::in);
    fp5.open("votes.txt",ios::out|ios::app);
    int id,uid;
    char partyName[25];

    unsigned int curLine;
    cout<<"\nEnter voter id: ";
    cin>>uid;
    while(fp4>>id)//check for record line by line
    {
        if(id==uid){
            cout<<"\nUser eligible to vote";
            cout<<"\nContesting parties are: \n";
            display_cand();
            cout<<"\nEnter party name you wish to vote for: ";
            cin>>partyName;
            fp5<<partyName<<"\n";
            cout<<"\nThanks for voting! ";
        }
        else{
            cout<<"\nRegister to vote";
        }
    }
}
void get_votes(){
    vector<string> votelist;
    ifstream data("votes.txt");
    string inp;
    while(data>>inp){
        votelist.push_back(inp);
    }
    unordered_map<string,int> mapObj ;
    for (auto& str : votelist)
    {
            mapObj[str]++;
    }
    int maxValueInMap = 0;
    string winner;
    for (auto& entry : mapObj)
    {
        string key  = entry.first;
        int val = entry.second;
        if (val > maxValueInMap)
        {
            maxValueInMap = val;
            winner = key;
        }
        else if (val == maxValueInMap && winner>key)
                cout<<"\n It is a tie";
        }
        cout <<"\nThe winner is: "<<winner<<endl;
}
int main()
{
    int c;
    int achoice, vchoice;
    string uname="admin";
    string pass="admin";
    string euname,epass;
    vector<string>votelist;
    ifstream data("votes.txt");
    string inp;
    while(data>>inp){
        votelist.push_back(inp);
    }
    cout << "**************************************************************************************************************************************" << endl;
    cout << "                                                         W E L C O M E                                                                " << endl;
    cout << "**************************************************************************************************************************************" << endl << endl << endl;
    cout << "**************************************************************************************************************************************" << endl;
	cout << "                                                      ONLINE VOTING SYSTEM                                                             " << endl << endl; 
    cout << "**************************************************************************************************************************************" << endl << endl;
    cout << "\n\n";
    
    while(1){
        cout<<"\n1.Admin\n2.User\n3.Exit";
        cout<<"\nEnter choice: ";
        cin>>c;
        if(c==1){
            cout<<"Enter Username: ";
            cin>>euname;
            cout<<"Enter Password: ";
            cin>>epass;
            if(euname=="admin" && epass=="admin"){
                    cout<<"\n1.Add Party\n2.Display result\n3.Exit";
                cout<<"\nEnter choice: ";
                cin>>achoice;
                switch(achoice){
                    case 1: add_party();
                            break;
                    case 2: get_votes();
                            break;
                    case 3: exit(0);
                }
            }
            else
                cout<<"Invalid credentials. Please login again";
        }

        if(c==2){
            cout<<"\n1.Register voter\n2.Cast your vote\n3.Exit";
            cout<<"Enter choice: ";
            cin>>vchoice;
            switch(vchoice){
                case 1: register_user();
                        break;
                case 2: cast_vote();
                        break;
                case 3: exit(0);
            }
        }

        if(c==3)
            exit(0);
    }
}