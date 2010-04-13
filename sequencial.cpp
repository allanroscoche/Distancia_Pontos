#include "utilidades.h"
//#include "stdlib.h"
#include <list>
#include <iostream>
#include <algorithm> // copy algorithm
#include <iterator>  // ostream_iterator

using namespace std;

int main(int argc, char ** argv)
{
	int x, y;
	int i, j;
	list<int> L;

	Matriz m(argv[1]);
	m.imprime();

	m.getPontos(L);

	/*
 	list<int>::const_iterator pos;
    for (pos = L.begin(); pos != L.end(); ++pos) {
        cout << *pos << ' ';
    }
    cout << endl;
	*/
	return 0;

}
