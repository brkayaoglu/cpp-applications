#include <iostream>

class Polynomial{
    int degree;   //keep degree of polynomial
    int* coefficients; //and keep variable's coefficients

public:
    Polynomial();  //default constructor
    Polynomial(int, const int*);	//here is constructor with two parameter, degree and coefficients
    Polynomial(const Polynomial&);		// copy constructor
    Polynomial operator+(const Polynomial&);	//adding operator overloading
    Polynomial operator*(const Polynomial&);  //multiplication operator overloading
    friend ostream& operator<<(ostream&, const Polynomial&);   //overload the print operator, friend means it can access the data's.
};

Polynomial::Polynomial() {  //default constructor
    degree = 0;			//set to data's zero
    //coefficients = nullptr;	 //pointer ==> null

}

Polynomial::Polynomial(int pdegree, const int* coefs){ //contsructor with two parameter
    degree = pdegree;
    coefficients = new int[degree+1]; //degree + 1 because of the last term
    for(int i = 0; i<= pdegree; i++){ //we use 'less than or equal to' because last term is only coefficient
        coefficients[i] = coefs[i];
    }
}

Polynomial::Polynomial(const Polynomial& copy) {  //copy constructor
    degree = copy.degree;
    coefficients = new int[degree+1];
    for(int i = 0; i <= degree; i++){
        coefficients[i] = copy.coefficients[i];
    }
}

Polynomial Polynomial::operator+(const Polynomial& plus){ //return variable is Polynomial object.
    int newDegree; //define new degree
    if(degree>=plus.degree){  //determine the input1 and input2's degrees and keep it
    	newDegree = degree;
	}else{
		newDegree = plus.degree;
	}
	int* newCoefficients = new int[newDegree+1]; //create new array for return object
	if(degree>=plus.degree){
		for(int i=0;i<=degree;i++){
			newCoefficients[i] = coefficients[i];
			if(i>=(degree-plus.degree)){
				newCoefficients[i] += plus.coefficients[i-(degree-plus.degree)];
			}
		}
	}else{
		for(int i=0;i<=plus.degree;i++){
			newCoefficients[i] = plus.coefficients[i];
			if(i>=(plus.degree-degree)){
				newCoefficients[i] += coefficients[i-(plus.degree-degree)];
			}
		}
	}
	return Polynomial(newDegree, newCoefficients); //return result Polynomial
}

Polynomial Polynomial::operator*(const Polynomial& multip){ // return  type is Polynomial
    int newDegree = degree + multip.degree; //find the degree of result
    int temp = 0;
    int *newCoefficients = new int[newDegree+1]; //create an array for coefficients
    for(int i = 0; i <= newDegree; i++){
        for(int j = 0; j <= degree; j++){
            for(int k = 0; k <= multip.degree; k++){
                if(j + k == i){ //lets assume that newdegree 5, and then [0]->x^5 [1]->x^4 [2]-> x^3 ..
                	temp += coefficients[j]*multip.coefficients[k]; //let degree 2 and multip.degree 3,
				}											//degree => [0]->x^2 [1]->x^1.. multip.degree => [0]->x^3 [1]->x^2..
            }											//then the condition will be add of two keys of array.
        }
        newCoefficients[i] = temp;				//[0]->x^2 * [0]->x^3 // [0]->x^5
        temp = 0; //reset the temp value
    }
    return Polynomial(newDegree, newCoefficients); //return the result object
}

ostream& operator<<(ostream& out, const Polynomial& obj){ //overload the printing object
    for(int i=0;i<=obj.degree-2;i++){
        if (obj.coefficients[i] !=0 ){
            if(obj.coefficients[i] == 1) out << "x^" << obj.degree-i << " + ";
            else{
                out << obj.coefficients[i] <<"x^" << obj.degree-i << " + ";
            }
        }
    }
    out << obj.coefficients[obj.degree-1] << "x + " <<obj.coefficients[obj.degree];
    return out;
}




