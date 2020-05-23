/*
  Luca Wehrstedt
 */

// Assume file di input e file di output non malformati.

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <limits>
#include <cmath>
#include <cassert>

using namespace std;

ifstream fin; // File di input
ifstream fcor; // File di output
ifstream fout; // File da correggere

void ex (const char *msg, float res)
{
	if (msg)
	{
		cerr << msg << endl;
	}
	cout << res << endl;
	exit (0);
}

template <class T>
T safe_read (istream& source, const T& lower = numeric_limits<T>::min (), const T& upper = numeric_limits<T>::max ())
{
	// Legge un valore da source, assicurandosi che sia tra lower e upper (inclusi)
	if (lower > upper)
	{
		cerr << "safe_read chiamato con parametri errati: " << lower << " " << upper << endl;
		exit (1);
	}

	T x;
	source >> x;
	if (source.fail () || source.eof ())
	{
		ex ("Output malformato.", 0.0f);
	}
	if (x < lower || x > upper)
	{
		ex ("Output invalido. ", 0.0f);
	}
	return x;
}

void check_fine_file ()
{
	string x;
	fout >> x;
	if (!fout.eof ())
	{
		ex ("Output malformato. ", 0.0f);
	}
}

int main(int argc, char *argv[])
{
	if (argc < 4)
	{
		cerr << "Usage: " << argv[0] << " <input> <correct output> <test output>" << endl;
		return 1;
	}

	fin.open (argv[1]);
	fcor.open (argv[2]);
	fout.open (argv[3]);

	if (fin.fail())
	{
		cerr << "Impossibile aprire il file di input " << argv[1] << ". " << endl;
		return 1;
	}
	if (fcor.fail())
	{
		cerr << "Impossibile aprire il file di output corretto " << argv[2] << ". " << endl;
		return 1;
	}
	if (fout.fail())
	{
		ex ("Impossibile aprire il file di output generato dal codice sottoposto al problema. ", 0.0);
	}

	int result_cor = safe_read<int> (fcor, 0);
	int result_out = safe_read<int> (fout, 0);

	if (result_cor != result_out) // Il risultato deve essere uguale
	{
		ex ("Output errato. ", 0.0f);
	}

	// Commentare da qui se non e' richiesto di produrre la lista delle componenti connesse

	vector< set<int> > componenti_cor;
	vector< set<int> > componenti_out;

	int a, b;
	for (int i = 0; i < result_cor; i += 1)
	{
		a = safe_read<int> (fcor, 0);
        componenti_cor.push_back (set<int> ());
		for (int i = 0; i < a; i += 1)
		{
			b = safe_read<int> (fcor, 0);
			componenti_cor.back ().insert (b);
		}
	}

	for (int i = 0; i < result_out; i += 1)
	{
		a = safe_read<int> (fout, 0);
		componenti_out.push_back (set<int> ());
		for (int i = 0; i < a; i += 1)
		{
			b = safe_read<int> (fout, 0);
			componenti_out.back ().insert (b);
		}
	}

	sort (componenti_cor.begin (), componenti_cor.end ());
	sort (componenti_out.begin (), componenti_out.end ());

	for (int i = 0; i < result_cor; i += 1)
	{
		if (componenti_cor[i] != componenti_out[i])
		{
			ex ("Output errato. ", 0.0f);
		}
	}

	// Commentare fin qui se non e' richiesto di produrre la lista delle componenti connesse

	check_fine_file ();

	ex ("Corretto. ", 1.0f);

	return 0;
}
