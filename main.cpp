#include "match.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cstring>

using namespace std;

void printAll(char**, char**, int, int);
bool comp(char*, char*, vector<match>);
int contar(vector<bool>, int);

int main(int argc, char* argv[]){
	vector<match> matches;
	int colA,colB;
	cout<<"Columna A: ";
	cin>>colA;
	cout<<"Columna B: ";
	cin>>colB;
	srand(time(0));
	char** columnaA=new char* [colA];
	char** columnaB=new char* [colB];
	for(int i=0; i<colA;i++){
		columnaA[i]=new char[20];
	}
	for(int i=0; i<colB;i++){
		columnaB[i]=new char[20];
	}
	cout<<"Ahora llenara Columna A"<<endl;
		for(int i=0; i<colA;i++){
			cout<<"Palabra: ";
			cin>>columnaA[i];	
		}
	cout<<"Ahora llenara Columna B"<<endl;	
		for(int i=0; i<colB;i++){
			cout<<"Palabra: ";
			cin>>columnaB[i];
		}	
	printAll(columnaA,columnaB,colA,colB);
	char resp='S';
	int a,b;
		while(resp=='S'||resp=='s'){
			cout<<"Ingrese los numeros de las palabras correspondientes: "<<endl;
			cout<<"Columna A: ";
			cin>>a;
			cout<<"Columna B:";
			cin>>b;
			//const char* str1=(const char*) columnaA[a-1];
			//const char* str2=(const char*) columnaB[b-1];
			match p(columnaA[a-1],columnaB[b-1]);
			matches.push_back(p);
			cout<<"¿Desea seguir emparejando?[S/N]";
			cin>>resp;
		}
			random_shuffle(&columnaA[0],&columnaA[colA-1]);	
			random_shuffle(&columnaB[0],&columnaB[colA-1]);	
			printAll(columnaA,columnaB,colA,colB);
			vector<bool> aciertos;
				char r='s';
					while(r=='s'||r=='S'){
						cout<<"Ingrese los numeros de las palabras correspondientes: "<<endl;
						cout<<"Columna A: ";
						cin>>a;
						cout<<"Columna B:";
						cin>>b;
						aciertos.push_back(comp(columnaA[a-1],columnaB[b-1],matches));
						cout<<"¿Desea seguir emparejando?[S/N]";
						cin>>r;

					}
				int por=contar(aciertos, matches.size());
				cout<<por<<" de sus aciertos estuvieron correctos"<<endl;	
	for(int i=0; i<colA;i++){
		delete[] columnaA[i];
	}
	for(int i=0; i<colB;i++){
		delete[] columnaB[i];
	}
	delete[] columnaA;
	delete[] columnaB;
		//matches.at(0).toString();
	return 0;
}

void printAll(char** a, char** b, int sizeA, int sizeB){
	cout<<"Palabras Columna A: "<<endl;	
	for(int i=0; i<sizeA;i++){
		cout<<i+1<<". "<<a[i]<<endl;;
	}
	cout<<"Palabras Columna B: "<<endl;
	for(int i=0; i<sizeB;i++){
		cout<<i+1<<". "<<b[i]<<endl;;
	}
}

bool comp(char* a, char* b, vector<match> m){
	for(int i=0; i<m.size();i++){
		if(strncmp(a,m[i].getStr1(),20)==0&&strncmp(b,m[i].getStr2(),20)==0){
			return true;
		}
	}
	return false;
}

int contar(vector<bool>aciertos, int tam){
int cont=0;	
//cout<<tam<<"<----";
	for(int i=0; i<aciertos.size();i++){
		if(aciertos[i]){
			cont++;
			//cout<<"true";
		}	
	}
	//cout<<cont<<"<-----cont";
	return (cont);
}
