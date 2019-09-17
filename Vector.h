#include <iostream>

using namespace std;

class Vector {
    int dimension; //vector's dimension shows us how many dimension our vector have
    int* coordinates; //values of dimensions
public:
    Vector(); //default constructor with no parameter
    Vector(int ,const int*); //constructor with get dimension and values
    Vector(const Vector&); //copy constructor
    Vector operator+(const Vector&); //plus opertor with returns object
    int operator*(const Vector&); //multiplication operator with returns int for dot product
    Vector operator*(int); //for scalar multiplication
    friend ostream& operator<<(ostream&, const Vector&); //friend mean this operator overloading process acces the objects data
};

Vector::Vector(){   //if the constructor have not a parameter, set to dimension and coordinates to zero.
    dimension = 0;
    //coordinates = nullptr;   //let pointer be nullptr
}

Vector::Vector(int vdimension, const int *valueVec){ //constructor sets to objects data's
    dimension = vdimension;
    coordinates = new int[dimension];  //for example if line is 3 4 2 1, dimension 3 and in coordinates array there are 4 2 and 1
    for(int i=0;i<vdimension;i++){
        coordinates[i] = valueVec[i];
    }
}

Vector::Vector(const Vector& copy){ //copy constructor --  Vector newVec = beforeVec  //  Vector newVec(beforeVec)
    dimension = copy.dimension;
    coordinates = new int[dimension];
    for(int i=0; i<dimension;i++){
        coordinates[i] = copy.coordinates[i];
    }
}

Vector Vector::operator+(const Vector& plus){  //we obtain a new object with the name Vector
    if(dimension == plus.dimension){
        int *newCoor = new int[dimension];
        for(int i=0;i<dimension;i++){
            newCoor[i] = coordinates[i] + plus.coordinates[i];
        }
        return Vector(dimension, newCoor); //we use same dimension because if we add two same dimension , we obtain the same dimension
    }else {
        return Vector(); //there is an error, return value is default constructor
    }
}

int Vector::operator*(const Vector& dotProdObj){
    if(dimension == dotProdObj.dimension){ //again the condition is dimension equality
        int result = 0;
        for(int i=0;i<dimension;i++){
            result += coordinates[i] * dotProdObj.coordinates[i];
        }
        return result;
    }else {
        return 0; //this is an error, return value is zero
    }
}

Vector Vector::operator*(int scalarNum){ //we should return same size vector so it is object
    int *newCoor = new int[dimension];
    for(int i=1;i<=dimension;i++){
        newCoor[i-1] = scalarNum * coordinates[i-1];
    }
    return Vector(dimension, newCoor); //return the new vector.
}

ostream& operator<<(ostream& out, const Vector& obj){   //we set the << operator and print object
    for (int i=0;i<obj.dimension;i++) {
        if(i == 0){
            out << "(";        //begin with the fist paranthesis
        }
          //then print the vectors first dimension
        if(i != obj.dimension-1){  //check the kama condition until the last value of vectors
        	out << obj.coordinates[i] << ", ";
		}else{
			out << obj.coordinates[i];
		}
    }
    out << ")";  //last one is the closing paranthesis.
    return out;
}






