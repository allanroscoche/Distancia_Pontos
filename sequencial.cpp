#include "utilidades.h"
//#include "stdlib.h"
#include <list>
#include <iostream>
#include <algorithm> // copy algorithm
#include <iterator>  // ostream_iterator

using namespace std;

int main(int argc, char ** argv)
{
	vector<Ponto> L;

	Matriz m(argv[1]);
	m.imprime();

	cout << "Num Pontos:" << m.getPontos(L) << endl;

	int i,j;

	for(i=0;i< (L.size()) ;i++)
	{
		cout << "P[" << i+1 << "]= " << L[i];
		for(j=i+1;j<L.size();j++)
			cout << "p[" << i+1 << "][" << j+1 << "]:" << L[i].distancia(L[j]) << ", ";
		cout << endl << endl;
	}

/*
	vector<Ponto>::iterator i,j;

	for(i=L.begin(); i != L.end(); ++i)
	{
		cout << *i;
		for(j=L.begin(); j!= L.end(); j++)
			cout << "d:" << i->distancia(*j) << "  ";
		cout << endl;
	}
*/

	return 0;

}
