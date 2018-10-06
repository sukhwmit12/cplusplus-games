#include<iostream.h>
#include<conio.h>

int mat[3][3];
void table(void);
void main()
{int mat[3][3]={{1,2,3},{4,5,6},{7,8,9}};
table();
cout<<mat[2][1];
getch();
}
void table()
	{
	cout<<"\n\n\t\t   1   2   3\n";
	    cout<<"\t\t 1 "<<mat[0][0]<<" | "<<mat[0][1]<<" | "<<mat[0][2];
	  cout<<"\n\t\t   --|---|--";
	  cout<<"\n\t\t 2 "<<mat[1][0]<<" | "<<mat[1][1]<<" | "<<mat[1][2];
	  cout<<"\n\t\t   --|---|--";
	  cout<<"\n\t\t 3 "<<mat[2][0]<<" | "<<mat[2][1]<<" | "<<mat[2][2]<<"\n\n";
	}