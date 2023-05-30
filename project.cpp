#include<iostream> 
#include<string.h> 
#include<cstdlib> 
#include<cstdio> 
#include<conio.h> 
using namespace std; 
static int p=0;
class meet 
{
char room_num[5],host[10], start[10],end[10], from [5], to[5], chair [5][5][10]; 
public: 
void install(); 
void allotment(); 
void empty(); 
void show(); 
void avail(); 
void position(int i); 
} 
room [10]; 
void vline(char choice)
{
    for (int i = 80; i >0; i--)
    cout<<choice;
}
    void meet::install()
    {
        cout<<"\n Enter the room number for booking :";
        cin>>room[p].room_num;
        cout<<"\n Enter the meeeting host name :";
        cin>>room[p].host;
        cout<<"\n Enter the meeting start time :";
        cin>>room[p].start;
        cout<<"\n Enter meeting end time :";
        cin>>room[p].end;
        cout<<"\n From :"; 
        cin>>room[p].from; 
        cout<<"\n To :";  
        cin>>room[p].to; 
        room[p].empty(); 
        p++; 
    }
    void meet::allotment()
    {
        int chair; 
        char number[5]; 
        top: 
        cout<<"Enter reserved room number :"; 
        cin>>number;
        int n; 
        for(n=0;n<=p;n++)
        {
            if(strcmp(room[n].room_num, number)==0) 
            break;
        }
        while(n<=p)
        {
            cout<<"\n Enter chair number :";
            cin>>chair; 
            if(chair>25) 
            {
                cout<<"\n The maximum strength of the room is only 25 chairs"; 
                cout<<"\n The chair is not available in this room.";
            }
            else
            {
                if (strcmp(room[n].chair [chair/5][(chair%5)-1], "Empty")==0) 
                { 
                cout<<" Enter the member's name :";
                cin>>room[n].chair[chair/5][(chair%5)-1]; 
                break; 
                }  
                else 
                cout<<"The Chair no. is already reserved.\n"; 
            }
        }
        if(n>p)  
        {   
        cout<<"\n Enter the correct room number.";
        goto top;
        }
    }
    void meet::empty()
    {
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                strcpy(room[p].chair[i][j],"Empty");
            }
        }
    }
    void meet::show()
    {
        int n; 
        char number[5]; 
        cout<<"\n Enter alloted room number :";
        cin>>number; 
        for (n=0;n<=p;n++) 
        {
            if(strcmp(room[n].room_num, number)==0) 
            break; 
        }
        while(n<=p)
        {
            cout<<"====================================================================================\n";
            cout<<"\n Room numbher :"<<room [n].room_num; 
            cout<<"\n Host name :"<<room [n].host;
            cout<<"\n Start time :"<<room [n].start;
            cout<<"\t\t\t\t End time :"<<room [n].end;
            cout<<"\n Meeting continued from :"<<room [n].from<<"\tTo :"<<room [n].to;
            cout<<"\n==================================================================================\n";
            room[0].position(n);
            cout<<"\n----------------------------------------------------------------------------------";
            int a=1;
            for(int i=0;i<5;i++) 
            {
                for(int j=0;j<5;j++) 
                {
                    a++;
                    if(strcmp(room[n].chair[i][j], "Empty") !=0) 
                    cout<<"\n The chair number "<<(a-1)<<" is reserved for "<<room[n].chair[i][j]<<"."; 
                }    
            }
            cout<<"\n----------------------------------------------------------------------------------";
            break;
        }
        if(n>p)
        cout<<"\n Please enter the correct room number :";
    }
    void meet::position (int l) 
    {
        int s=0;p=0; 
        for(int i=0;i<5;i++) 
        {
            cout<<"\n"; 
            for(int j=0;j<5;j++)
            {
                s++;
                if(strcmp(room[l].chair[i][j],"Empty")==0)
                {
                    cout.width(5); 
                    cout.fill(' '); 
                    cout<<s<<"."; 
                    cout.width(10); 
                    cout.fill(' '); 
                    cout<<room[l].chair[i][j]; 
                    p++; 
                }
                else
                {
                    cout.width(5); 
                    cout.fill(' '); 
                    cout<<s<<".";  
                    cout.width(10); 
                    cout.fill(' '); 
                    cout<<room[l].chair[i][j];
                }
            }
        }
        cout<<"\n_______________________________________________________________________________";
        cout<<"\n In room number "<<room[l].room_num<<" total "<<p<<" chairs are empty.";
    } 
    void meet::avail()
    {
        for(int n=0;n<p;n++)
        {
            cout<<"\n---------------------------------------------------------------------------";
            cout<<"\n Room no :"<<room [n].room_num 
            <<"\n Host name   :"<<room [n].host
            <<"\n Start time  :"<<room [n].start
            <<"\t\t End time  :"<<room [n].end
            <<"\nFrom         :"<<room [n].from
            <<"\tTo           :"<<room[n].to;
            cout<<"\n----------------------------------------------------------------------------";
        }
    }
    int main()
    {
        system("cls");
        int w;
        while(1)
        {
            cout<<"\n\n"; 
            cout<<"\n 1) INSTALL"; 
            cout<<"\n 2) RESERVATION"; 
            cout<<"\n 3) SHOW";
            cout<<"\n 4) ROOMS AVAILABLE"; 
            cout<<"\n 5)EXIT"; 
            cout<<"\n\t\t Enter your choice :-->"; 
            cin>>w;
            switch(w)
            {
                case 1:
                {
                    room[p].install(); 
                } 
                break;
                case 2:
                {
                    room[p].allotment();
                }
                break;
                case 3:
                {
                    room[p].show();
                }
                break;
                case 4:
                {
                    room[p].avail();
                }
                break;
                case 5:
                    exit(0);
            }
        }
        return 0;
    }
        