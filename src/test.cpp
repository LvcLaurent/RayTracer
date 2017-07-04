#include <iostream>
#include "../include/Matrice.h"
#include <vector>
using namespace std;

int main()
{

Matrice *test = new Matrice(4);
test->grille[0][0]=-1;
test->grille[0][1]=0;
test->grille[0][2]=1;
test->grille[0][3]=1;

test->grille[1][0]=1;
test->grille[1][1]=-2;
test->grille[1][2]=1;
test->grille[1][3]=-1;

test->grille[2][0]=1;
test->grille[2][1]=0;
test->grille[2][2]=-1;
test->grille[2][3]=1;

test->grille[3][0]=1;
test->grille[3][1]=0;
test->grille[3][2]=1;
test->grille[3][3]=-1;

Matrice *test2 = new Matrice(3);

test2->grille[0][0]=8;
test2->grille[0][1]=-1;
test2->grille[0][2]=9;

test2->grille[1][0]=3;
test2->grille[1][1]=1;
test2->grille[1][2]=8;

test2->grille[2][0]=11;
test2->grille[2][1]=0;
test2->grille[2][2]=17;


Matrice *test3 = new Matrice(2);
test3->grille[0][0]=0;
test3->grille[0][1]=1;
test3->grille[1][0]=1;
test3->grille[1][1]=0;
//test3->toString();
/* 3 -2  4 
 2 -4  5 
 1  8  2 */

int i = 0;
int j = 0;
int cpt=0;

/*	for(;i<4;i++)
	{
		
		for(j=0;j<4;j++)
		{
			test->grille[i][j]=cpt++;
		}
	}*/

	cout<<"[4*4]\n";
//test->toString();
test->toString();
		//cout<<"-"<<test->determinant()<<"\n";
		test=test->inversion();
test->toString();
return 0;
}
