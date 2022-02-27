#include <iostream>
#include <cstdio>
#include <conio.h>
#include <string.h>
#include <cstdlib>

using namespace std;
static int p =0;

class a
{
    private:
        char busn[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];
    public:
        void install();
        void allotment();
        void empty();
        void show();
        void position(int i);
        void avail();
}bus[10];

void vline(char ch)
{
    for(int i=80;i>0;i--)
        cout<<ch;
}

void a::install()
{
    cout<<"\n Enter Bus No.: ";
    cin>>bus[p].busn;
    cout<<"\n Enter Driver's Name: ";
    cin>>bus[p].driver;
    cout<<"\n Arrival Time: ";
    cin>>bus[p].arrival;
    cout<<"\n Departure Time: ";
    cin>>bus[p].depart;
    cout<<"\n From: ";
    cin>>bus[p].from;
    cout<<"\n To: ";
    cin>>bus[p].to;
    bus[p].empty();
    p++;
}
void a::allotment()
{
    int seat, n;
    char number[5];
    top:
        cout<<"\n Bus No.: ";
        cin>>number;
        for(int n=0;n<=p;n++)
        {
            if(strcmp(bus[n].busn,number)==0)
                break;
        }
        while(n<=p)
        {
            cout<<"\n Seat No.: ";
            cin>>seat;
            if(seat>32)
            {
                cout<<"\n 32 Seats Available";
            }
            else
            {
                if(strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)
                {
                    cout<<"\n Enter Passanger's Name: ";
                    cin>>bus[n].seat[seat/4][(seat%4)-1];
                    break;
                }
                else
                cout<<"\n This Seat is Reserved.";
            }
        }
        if(n>p)
        {
            cout<<"\n Enter CorrectBus No.: ";
            goto top; 
        }
}
void a::empty()
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<4;j++)
        {
            strcpy(bus[p].seat[i][j],"Empty");
        }
    }
}
void a::show()
{
    int n;
    char number[5];
    cout<<"\n Enter Bus No.: ";
    cin>>number;
    for(n=0;n<=p;n++)
    {
        if(strcmp(bus[n].busn,number)==0)
            break;
    }
    while(n<=p)
    {
        vline('*');
        cout<<"\n Bus No.: "<<bus[n].busn
            <<"\t\t Driver: "<<bus[n].driver
            <<"\n Arrival Time: "<<bus[n].arrival
            <<"\t\t Departure Time: "<<bus[n].depart
            <<"\n From: "<<bus[n].from
            <<"\t\t To: "<<bus[n].to<<"\n";
        vline('*');
        bus[0].position(n);
        int a=1;
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<4;j++)
            {
                a++;
                if(strcmp(bus[n].seat[i][j],"Empty")!=0)
                    cout<<"\n The Seat No. "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";
            }
        }
        break;
    }
    if(n>p)
        cout<<"\n Enter correct Bus No. ";
}
void a::position(int i)
{
    int s=0,p=0;
    for(int i=0;i<8;i++)
    {
        cout<<"\n";
        for(int j=0;j<4;j++)
        {
            s++;
            if(strcmp(bus[1].seat[i][j],"Empty")==0)
            {
                cout.width(5);
                cout.fill(' ');
                cout<<s<<".";
                cout.width(10);
                cout.fill(' ');
                cout<<bus[1].seat[i][j];
                p++;
            }
        }
    }
    cout<<"\n There are "<<p<<" seats empty in bus no. "<<bus[1].busn;
}
void a::avail()
{
    for(int n=0;n<p;n++)
    {
        vline('*');
        cout<<"\n Bus No.: "<<bus[n].busn
            <<"\n Driver: "<<bus[n].driver
            <<"\n Arrival Time: "<<bus[n].arrival
            <<"\n Departure Time: "<<bus[n].depart
            <<"\n From: "<<bus[n].from
            <<"\n To: "<<bus[n].to<<"\n";
            vline('*');
            cout<<"\n";
            vline('_');
    }
}

int main()
{
    system("cls");
    int w;
    while(1)
    {
        cout<<"\n\n\n";
        cout<<"\t\t\tBUS RESERVATION\n"
            <<"\n1.Install\t\t\t"
            <<"\n2.Reservation\t\t\t"
            <<"\n3.Show Details\t\t\t"
            <<"\n4.Buses Available\t\t\t"
            <<"\n5.Exit\t\t\t";
        cout<<"\n\t\t\tEnter your choice: ";
        cin>>w;
        switch(w)
        {
            case 1:
                    bus[p].install();
                    break;
            case 2:
                    bus[p].allotment();
                    break;
            case 3:
                    bus[p].show();
                    break;
            case 4:
                    bus[p].avail();
                    break;
            case 5:
                    exit(0);
            default:
                    cout<<"\n Wrong Option";
        }
    }
    return 0;
}
