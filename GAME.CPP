#include <iostream>
using namespace std;
//#include <conio.h>
int checkwin(char a[][3],char symbol ) {
	int status=0;
	for (int i=0;i < 3;i++) {
		if(a[i][0]==a[i][1] && a[i][1]==a[i][2] && a[i][2] == symbol ) {
		status = 1;
		break;
		}
		}
	if(status ==0 ) {
		for ( int i=0;i<3;i++) {
			if ( a[0][i]==a[1][i] && a[1][i]==a[2][i] && a[2][i]  == symbol  ) {
				status = 1;
				break;
				}
			}
			}
	if(status==0 ) {
		for(int i=0;i<3;i++) {
		if(a[0][0]==a[1][1] && a[1][1]==a[2][2] && a[2][2]== symbol || a[0][2]==a[1][1] && a[1][1]==a[2][0] && a[2][0] == symbol ) {
		status =1;
		break;
			}
		}
		}
return status;
}


void initialize(char a[][3] ){
for (int i=0 ;i<3;i++) {
a[i][0]='_';
a[i][1]='_';
a[i][2]='_';
}
}

int checkposition (char a[][3]) {
int code = 0;
for (int i=0;i<3;i++)
if (a[i][0]=='_'|| a[i][1]=='_' || a[i][2]=='_')
	code=1;
return code;
}



void display(char a[][3]){
	int r,c;
	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
		cout<<a[i][j]<<"\t";
		}

	cout<<"\n";
	}
	}


int main() {
system("clear");
char s1,s2;
int r,c;
char a[3][3];
cout<<"enter symbol with which you want to play (x or o) ";
cin>>s1;
if(s1 == 'x')
s2='o';
else
s2='x';

initialize(a);
while(1){
cout<<"\n";
display(a);
cout<<"\n";
int s=checkposition(a);
if(s==0) {
	cout<<"Draw";
	getchar();
	}
cout<<"PLAYER 1 enter row and column index ";
cin>>r>>c;
if (a[r][c]=='_' || a[r][c]=='_' || a[r][c]=='_') {
a[r][c] =s1 ;
}
else
cout<<"invalid move";
int j=checkwin(a,s1);
if (j==1) {
	  cout<<"player 1 wins"<<endl;
	  getchar();
	  break;
	  }


s=checkposition(a);
if(s==0) {
	cout<<"Draw";
	getchar();
	break;
	}


cout<<"\n";
display(a);
cout<<"\n";

cout <<"PLAYER 2 enter row and column index ";
cin>>r>>c;
if (a[r][c]=='_' || a[r][c]=='_' || a[r][c]=='_' )
a[r][c]=s2;
else
cout<<"invalid move";
j= checkwin (a,s2);
if (j==1 ) {
cout<<"player 2 wins"<<endl;
getchar();
break;


}
}
return 0;

}
