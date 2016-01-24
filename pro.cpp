#include <cstdlib>
#include <iostream>

using namespace std;

class Silnik
{
public:
	string rodzaj;
	double pojemnosc;

	double cena;
	Silnik(string rs, double p, double cs)
	{
		rodzaj = rs;
		pojemnosc = p;
		cena = cs;
	}

	void show()
	{	
		cout<<"Silnik: "<<rodzaj<<"  "<<pojemnosc<<endl;
	}


};

class Nadwozie
{
public:
	string rodzaj;


	double cena;
	Nadwozie(string rn, double cn)
	{
		rodzaj = rn;
		cena = cn;
	}

	void show()
	{	
		cout<<"Nadwozie: "<<rodzaj<<endl;
	}
};

class Model
{
public:
	string nazwa;
	
	double cena;
	Model(string n, double cm)
	{
		nazwa = n;
		cena = cm;
	}

	void show()
	{	
		cout<<"Model: "<<nazwa<<endl;
	}
};

class Samochod
:public Silnik, public Nadwozie, public Model
{
public:
	int rok_produkcji;


	Samochod(string n_model, double c_model, string r_nadwozie, double c_nadwozie, string r_silnik, double p_silnik, double c_silnik, int r) 
	:Model(n_model, c_model), Silnik(r_silnik, p_silnik, c_silnik), Nadwozie(r_nadwozie, c_nadwozie)
	{
		rok_produkcji = r;
	}

	void show()
	{
		Model::show();
		Nadwozie::show();
		Silnik::show();
		cout<<"Rok produkcji: "<<rok_produkcji<<endl;;
	}
	
	void sumuj_cene()
	{
		double suma;
		suma = Model::cena + Nadwozie::cena + Silnik::cena;
		cout<<"Cena samochodu: "<<suma;
	}

};



int main(){

Silnik s1("benzyna", 2.01, 3000);
Nadwozie n1("sedan", 4500);
Model m1("Passat", 10000);

Model m2("Golf", 6000);

Samochod car(m1.nazwa, m1.cena, n1.rodzaj, n1.cena, s1.rodzaj, s1.pojemnosc, s1.cena, 2012);

car.show();
car.sumuj_cene();

return 0;
}