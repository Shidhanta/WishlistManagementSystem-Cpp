#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<conio.h>
#include<string.h>
#include<fstream>
#include <vector>
#include<conio.h>
using namespace std;

//global password function for login
int password();

//Record class
class Record{

    protected:
    char name[30];
    char type[25];
    char price[10];
    char note[500];


public:
void addrecord();
void viewrecord();
void editrecord();
void deleterecord();
friend void size_record(vector <Record>, string a);
friend double size_record(vector <Record>);

void writefile(vector <Record> a){
system("CLS");
cout<<"\n\tWRITING FILENAME . . ."<<endl;
system("PAUSE");
ofstream filename;
filename.open("wishlist.txt");
fflush(stdin);

for(int i=0;i<a.size();i++){
    filename<<a.at(i).name<<" "<<a.at(i).type<<" "<<a.at(i).price<<" "<<a.at(i).note<<endl;
}
filename.close();
}

};

class MetaData:protected Record{

protected:
double size_rec;

public:
MetaData(){};
void meta_functions( vector<Record> a){
Record* x;
this->size_rec=size_record(a);
x->writefile(a);
}
};


void size_record(vector <Record> a,string r){
    system("cls");
    for (int i=0;i<a.size();i++){
        if(a.at(i).name==r){
            cout<<"\tRECORD FOUND!\n";
            cout<<"Size of:\n"<<a.at(i).name<<"\n";
            cout<<"Record: "<<sizeof(a[i])<<"\n";
            cout<<"Name: "<<sizeof(a.at(i).name)<<"\n";
            cout<<"Type: "<<sizeof(a.at(i).type)<<"\n";
            cout<<"Price: "<<sizeof(a.at(i).price)<<"\n";
            cout<<"Note: "<<sizeof(a.at(i).type)<<"\n";
        }
        else{
            cout<<"No such record exists! \n";
            system("PAUSE");
        }
}
}

double size_record(vector <Record> a){
    system("cls");
    double dummy=0;
    for (int i=0;i<a.size();i++){
            dummy+=sizeof(a[i]);
}
return dummy;
}



vector<Record>record;

int login(){
    string pass="";
    char character;
    cout << "\n\n\n\n\n\t\t\t\t     Personal Wishlist Management";
   cout << "\n\n\n\n\n\t\t\t\t\tEnter Password:";
   character=_getch();
   while(character!=13)//Avoiding carriage return//
   {
       pass.push_back(character);
       cout<<"*";
       character=getch();
   }

   if(pass=="pass"){
    cout<<"\n\n \n Access Granted ";
    system("PAUSE");
    system("CLS");
    return 0;
   }
   else{
    cout << "\nAccess Aborted...\n";
      system("CLS");
	  login();
   }
}


Record r;
int main(){
login();


MetaData *p;
p=new MetaData;



int choice;
    cout<<"\n\n\t***********************************\n";
    cout<<"\t  *WISHLIST MANAGEMENT SYSTEM*\n";
    cout<<"\t***********************************";

    while(1)
    {
        cout<<"\n\n\t\tMAIN MENU:";
        cout<<"\n\n\tADD RECORD\t[1]";
        cout<<"\n\tVIEW RECORD\t[2]";
        cout<<"\n\tEDIT RECORD\t[3]";
        cout<<"\n\tDELETE RECORD\t[4]";
        cout<<"\n\tWRITE TO FILE\t[5]";
        cout<<"\n\tEXIT\t\t[6]";
        cout<<"\n\n\tENTER YOUR CHOICE:";
        cin>>choice;

        switch(choice){
        case 1:r.addrecord(); break;
        case 2:r.viewrecord(); break;
        case 3:r.editrecord(); break;
        case 4:r.deleterecord(); break;
        case 5:p->meta_functions(record); break;
        case 6:cout<<"\n\n\t\tTHANK YOU FOR USING THE WISHLIST SYSTEM ";
                getchar();
                delete p;
                exit(0);
                break;
        default: cout<<"\n\n\t\tInvalid Input, please try again...";

                 getchar();
                  break;
        }
        system("cls");
}

return 0;

}


void Record::addrecord(){
system("cls");
string n;
Record rec;
fflush(stdin);
cout<<"\n\n\tENTER NAME OF ITEM: \n";
cout<<"\t";
cin.getline(rec.name,30);
fflush(stdin);

system("CLS");

cout<<"\n\n\tENTER TYPE OF ITEM: \n";
cout<<"\t";
cin.getline(rec.type,25);
fflush(stdin);

system("CLS");


cout<<"\n\n\tENTER PRICE OF ITEM: \n";
cout<<"\t";
cin.getline(rec.price,10);
fflush(stdin);

system("CLS");

cout<<"\n\n\tENTER SHORT DESCRIPTION OF ITEM: \n";
cout<<"\t";
cin.getline(rec.note,500);
fflush(stdin);

record.push_back(rec);
cout<<"\n\n\t NEW WISHLIST ITEM HAS BEEN ADDED! PLEASE CHECK USING VIEW OPTION FROM THE MENU";
getchar();
fflush(stdin);
system("CLS");

/*
ofstream outfile;
outfile.open(filename,ios::app);
outfile.write((*char)&rec, sizeof(rec));
outfile.close();


   ifstream infile;
   infile.open(filename,ios::in);
      file2.seekg(0);
    file2.read((char*)&rec,sizeof(rec));
    cout<<rec.name;
   infile.close();*/
};

void Record::deleterecord(){

system("CLS");
string identifier;

cout<<"\n\n \t ENTER NAME OF RECORD TO BE DELETED . . . \n";
cin>>identifier;

//checking whether entered record exists or not
for (int i=0;i<record.size();i++){

    if(record.at(i).name==identifier){
        cout<<"\n\n\tRECORD FOUND! DELETING . . .\n";
        system("PAUSE");
        getch();
        record.erase(record.begin()+i);
        cout<<"\n\n\tRECORD HAS BEEN SUCCESSFULLY ERASED!";
        system("PAUSE");
        fflush(stdin);
        system("cls");
        return;
    }
    else {
        cout<<"\n\n\tRECORD NOT FOUND! PLEASE CHECK AND TRY AGAIN";
        getchar();
        fflush(stdin);
        system("cls");
        return;
    }
}

};

void Record::editrecord(){

system("CLS");
    string identifier;
    cout<<"\n\tENTER NAME OF RECORD THAT NEEDS TO BE EDITED: \n";
    cin>>identifier;
    int choice;


for (int i=0;i<record.size();i++){
    if(record.at(i).name==identifier){
        cout<<"\n\tRECORD FOUND!!\n";
        system("cls");
        getch();
        cout<<"\t\tWhat record would you like to edit? \n";
        cout<<"\t[0] For changing the name\n";
        cout<<"\t[1] For changing the type\n";
        cout<<"\t[2] For changing the price\n";
        cout<<"\t[3] For changing the description\n";
        cin>>choice;

        switch(choice){

        case 0: cout<<"Enter new name: ";fflush(stdin);cin.getline(record[i].name,30);fflush(stdin);
                 break;
        case 1: cout<<"Enter new type: ";fflush(stdin);cin.getline(record[i].type,25);fflush(stdin); break;

        case 2: cout<<"Enter new price: ";fflush(stdin);cin.getline(record[i].price,10);fflush(stdin); break;

        case 3: cout<<"Enter new note: ";fflush(stdin);cin.getline(record[i].note,500);fflush(stdin); break;

        default: cout<<"invalid input please try again"; break;
        }

}}}

void Record::viewrecord(){
system("cls");
cout<<"\n\tDISPLAY OF ALL RECORDS: \n";
for(int i=0; i<record.size();i++){
    cout<<"Name: "<<record[i].name<<"\tType: "<<record[i].type<<"\n\n";
}
getch();
fflush(stdin);
};

