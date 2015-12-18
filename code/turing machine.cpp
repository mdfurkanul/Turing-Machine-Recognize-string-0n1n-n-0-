#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    char ch[100];
    scanf("%[^\n]s",ch);
    int l=strlen(ch);
    ch[l]='\0';
    int head=0,state=0;
    while(true)
    {
        switch(state)
        {
        case 0:
                if(ch[head]=='0'){
                    state=1;
                    ch[head++]='x';
                    }
                else if(ch[head]=='y'){
                        state=3;
                        ch[head++]='y';
                        }
                else
                    state=5;
                //cout<<ch<<endl;
                continue;
        case 1:
                if(ch[head]=='0'){
                   state=1;
                   ch[head++]='0';
                   }
                else if(ch[head]=='1'){
                        state=2;
                        ch[head--]='y';
                        }
                else if(ch[head]=='y'){
                        state=1;
                        ch[head++]='y';
                        }
                else
                        state=5;
            //cout<<ch<<endl;
            continue;
        case 2:
            {
                if(ch[head]=='0'){
                    state=2;
                    ch[head--]='0';
                    }
                else if(ch[head]=='x'){
                        state=0;
                        ch[head++]='x';
                        }
                else if(ch[head]=='y'){
                        state=2;
                        ch[head--]='y';
                        }

                else
                        state=5;
            //cout<<ch<<endl;
            continue;

            }
        case 3:
                if(ch[head]=='y'){
                    state=3;
                    ch[head++]='y';
                    }
                else if(ch[head]=='\0'){
                        state=4;
                        ch[head]='\0';
                        }
                else
                        state=5;
           // cout<<ch<<endl;
            continue;
        case 4:
            cout<<"Accept"<<"\t";
            cout<<ch<<endl;
            return 0;


        case 5:
            cout<<"Reject"<<"\t";
            cout<<ch<<endl;
            return 0;


        default:
            cout<<"Error"<<endl;
            return 0;
        }
    }

    return 0;
}
