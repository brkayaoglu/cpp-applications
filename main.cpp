#include<iostream>
#include<fstream> //for the ifstream
#include<stdlib.h>
#include "Vector.h"
#include "Polynomial.h"

using namespace std;

void arayuz(){
    cout << "Possible Actions:" << endl;
    cout << "1. Print Polynomial and Vector lists" << endl;
    cout << "2. Do a polynomial operation" << endl;
    cout << "3. Do a vector operation" << endl;
    cout << "4. Help: Print possible actions" << endl;
    cout << "0. Exit the program" << endl << endl << endl;
    cout << "Enter an option: ";
}

int main(int argc, char **argv){
	cout << "Polynomial and Vector List Program!" << endl;
	cout << "Polynomials and Vectors are read from text files!" << endl << endl;
	int choose; // tell to the program which actions will be execute
	int terminal1, terminal2; //input1 and input2 of operation
	char operation; //+ or * operation
	Vector** vectors;   //we create an array for the vector object
	Polynomial** polynomials;	//we create an array for the polynomial object
	int vnumber, pnumber; //number of vectors and polynomials
	int i, j; //counter of loops
	int vdimension, pdegree; //dimension of vector and degree of poly
	int coefficient; // coefficients of vecs and polys
	//--------------READ VECTOR FILE------------------
	ifstream vectorFile("Vector.txt");
	if(vectorFile.is_open()){
		vectorFile >> vnumber; //we obtain the first number as a number of vector from file
		vectors = new Vector*[vnumber]; // we allocate memory for vector array. And we know the addresses of this array
		for(i=0;i<vnumber;i++){
			vectorFile >> vdimension; //first number of the lines is dimension
			int* valueVec = new int[vdimension]; //we open array for the keep values of each vector
			for(j=0;j<vdimension;j++){
				vectorFile >> coefficient; // coming after the first number, they are values of vecs
				valueVec[j] = coefficient; //keep in vectors array
			}
			vectors[i] = new Vector(vdimension, valueVec); //array of vector initiliazed.
		}
	}
	//--------------READ POLYNOMIAL FILE------------------
	ifstream polynomialFile("Polynomial.txt");
	if(polynomialFile.is_open()){
		polynomialFile >> pnumber; //we obtain the first number as a number of polynomial from file
		polynomials = new Polynomial*[pnumber]; // we allocate memory for polynomial array. And we know the addresses of this array
		for(i=0;i<pnumber;i++){
			polynomialFile >> pdegree; //first number of the lines is dimension
			int* valuePol = new int[pdegree]; //we open array for the keep values of each polynomial
			for(j=0;j<=pdegree;j++){
				polynomialFile >> coefficient; // coming after the first number, they are values of polynomial
				valuePol[j] = coefficient; //keep in polynomial array
			}
			polynomials[i] = new Polynomial(pdegree, valuePol); //array of polynomial initiliazed.
		}
	}
	arayuz();
	//--------END OF READ PROCESS-------------
	do{

		cin >> choose;  //we get an obtion from user
		switch(choose){
			case 1:
				//---------PRINT VECTORS---------
				cout << "Vectors:" <<endl;
				for(i=1;i<=vnumber;i++){
					cout << i << ". " << *vectors[i-1] << endl;
				}
				cout << endl;
				//---------PRINT POLYNOMIALS---------
				cout << "Polynomials:" << endl;
				for(i=1;i<=pnumber;i++){
					cout << i << ". " << *polynomials[i-1] << endl;
				}
				cout << endl;
				break;
			case 2:
				cout << "Which polynomial operation would you like to do?(+:addition, *:multiplication):" << endl;
				cin >> terminal1 >> operation >> terminal2;
				//--------------ADD OPERATION-------------
				if(operation == '+'){
					Polynomial result = *polynomials[--terminal1] + *polynomials[--terminal2]; //because of array starts at 0, first we decrement value of inputs
					cout << "(" << *polynomials[terminal1] << ") + (" << *polynomials[terminal2] << ") = " << result << endl;
				}
				//-------------MULTIPLICATION OPERATION-----
				else if(operation == '*'){
					Polynomial result1;
					result1 = *polynomials[--terminal1] * *polynomials[--terminal2]; //because of array starts at 0, first we decrement value of inputs
					cout << "(" << *polynomials[terminal1] << ") * (" << *polynomials[terminal2] << ") = " << result1 << endl;
				}
				cout << endl;
				break;
			case 3:
				cout << "Which vector operation would you like to do?(+:addition, *:multiplication, .:dot product):" << endl;
				cin >> terminal1 >> operation >> terminal2;

				 //Result for the dot product operation
				//--------------ADD OPERATION-------------
				if(operation == '+'){
					Vector result2 = *vectors[--terminal1] + *vectors[--terminal2];
					cout << *vectors[terminal1] << " + " << *vectors[terminal2] << " = " << result2 << endl;
				}
				//------------- DOT PRODUCT -----
				else if(operation == '.'){
					int dotResult = *vectors[--terminal1] * *vectors[--terminal2];
					cout << *vectors[terminal1] << " . " << *vectors[terminal2] << " = " << dotResult << endl;
				}
				//-------------SCALAR MULTIPLICATION OPERATION-----
				else if(operation == '*'){
					Vector result3 = *vectors[--terminal1] * terminal2 ;
					cout << *vectors[terminal1] << " * " << terminal2 << " = " << result3 << endl;
				}
				cout << endl;
				break;
			case 4:
			    arayuz();
				cout << endl;
				continue;
			case 0:
				break;
			default:
				break;
		}if(choose!=0)cout << "Enter an option: ";
	}while(choose!=0);
	return EXIT_SUCCESS;
}
