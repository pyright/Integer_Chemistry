//
//  main.cpp
//  MolFormToCompNum
//
//  Created by Michael Campos on 8/16/16.
//  Copyright (c) 2016 Polygon3d Printing. All rights reserved.
//

#include <iostream>
using namespace std;

//##############
//##############
// PROTOTYPES ##
//##############
//##############

int getCompositeIdentity(string);
int getAtomicPrime(string);

//##########
//##########
// MAIN ####
//##########
//##########

int main() {

    string molecule = "";

    //get user input
    cout << "Enter a molecular formula: ";
    cin >> molecule;
    cout << "Molecule " << molecule << " has a composite identity of: ";
    cout << getCompositeIdentity(molecule) << "\n";


    return 0;
}

//#############
//#############
// FUNCTIONS ##
//#############
//#############

int getCompositeIdentity(string molecule){

    int compositeIdentity = 1; //Updated composite identity for molecular formula

    //Variables for working with subscript
    string subscriptStr;
    int subscriptInt;

    //Variable for a found atom
    string atomStr;
    int coefficient;
    string atomChar1, atomChar2, atomChar3;

    //##########
    //##########
    //##########
    //##########
    //Begin indexing and calculating

    for (int i = 0; i <= molecule.length()-1; i++) {

        cout << "\nindex: " << i <<"\n"; //test output

        //Clear atomStr and atomChars
        atomStr = "";
        atomChar1 = "";
        atomChar2 = "";
        atomChar3 = "";

        //Reset coefficient
        coefficient = 1;

        //index
        int indexStart, indexEnd;

        // Begin char checking
        // When atom and subscript are found, write code for compositeIdentity multiplication
        // Then, code for index increment (move index "i" while considering for-loop's i++)

        //Need a chunk of code for finding subscript value

        //Need a chunk of code for dealing with parenthesis
        //First, find ')'
        //Then find subscript (consider index after subscript ends)
        //Next, string between '(' and ')' will be calculated
        //Next, clear ParenthesisSubscriptStr and ParenthesisSubscriptInt

        if (isupper(molecule[i])) {             //Check if CURRENT is UPPER

            if (isupper(molecule[i+1])) { //FOUND atom and FOUND subscript *****************
                //No need to increment index
                //Set atomStr to currentChar
                //Then multiply compositeIdentity by getAtomicPrime(AtomStr);
                atomStr = molecule[i];
                compositeIdentity = compositeIdentity * getAtomicPrime(atomStr);
            }

            else if (islower(molecule[i+1])) { //If Upper proceeded by Lower, atom and subscript have NOT been found

                if (isupper(molecule[i+2])) { //FOUND ************

                        //set coefficient
                        coefficient = 1;
                        //store atomstr
                        atomChar1 = molecule[i];
                        atomChar2 = molecule[i+1];
                        atomStr = atomChar1 + atomChar2;

                        cout << "atomStr at " << i << "+1: " << atomStr;
                        //Set compositeIdentity to compositeIdentity * atomic prime * coefficient
                        compositeIdentity = compositeIdentity * getAtomicPrime(atomStr) * coefficient;
                        //update index by 1
                        i++;
                }

                else if (islower(molecule[i+2])) { //NOT FOUND

                    if (isupper(molecule[i+3])) { //FOUND
                    }

                    else if (islower(molecule[i+3])) { //WTF???

                    }

                    else if (isdigit(molecule[i+3])) { //Atom FOUND, Subscript NOT FOUND

                        //Find subscript code

                    }

                    else if (molecule[i+3] == '('){ //Atom and Subscript FOUND, start parenthesis

                        //Parenthesis code

                    }

                    else if (molecule[i+3] == ')'){ //WTF???

                    }

                    else {
                        break;
                    }

                }

                else if (isdigit(molecule[i+2])) {

                }

                else if (molecule[i+2] == '('){

                }

                else if (molecule[i+2] == ')'){

                }

                else {
                    break;
                }
            }

            else if (isdigit(molecule[i+1])) {


            }

            else if (molecule[i+1] == '('){

            }

            else if (molecule[i+1] == ')'){

            }

            else { //FOUND

                atomStr = molecule[i];

                compositeIdentity = compositeIdentity * getAtomicPrime(atomStr);

                break;
            }
        }

        //##########
        //##########

        else if (islower(molecule[i])) {        //Check if CURRENT is LOWER

            if (isupper(molecule[i+1])) {  //FOUND
            }

            else if (islower(molecule[i+1])) { //Atom FOUND

                if (isupper(molecule[i+2])) {  // FOUND
                }

                else if (islower(molecule[i+2])) { //WTF???

                }

                else if (isdigit(molecule[i+2])) { //Atom FOUND, Subscript Start
                    //find subscript
                }

                else if (molecule[i+2] == '('){ //FOUND, start parenthesis

                }

                else if (molecule[i+2] == ')'){ //FOUND, end parenthesis

                }

                else {
                    break;
                }

            }

            else if (isdigit(molecule[i+1])) { //Atom Found, start finding subscript

            }

            else if (molecule[i+1] == '('){ //FOUND, start parenthesis

            }

            else if (molecule[i+1] == ')'){ //FOUND, end parenthesis

            }

            else {
                break;
            }

        }

        else if (isdigit(molecule[i])) {  //Atom FOUND, find subscript      //Check if CURRENT is DIGIT
            //Find subscript
            //keep track of previous alphas to get proper AtomStr
        }

        else if (molecule[i] == '(') {     //FOUND, start parenthesis     //Check if CURRENT is OPEN PARENTHESIS
            //Find the closing parenthesis, move the string between '(' and ')' into parenthesisStr
            //Run calculateParanthesis on parenthesis. Calculate parenthesis similar to calculate
        }

        else if(molecule[i] == ')') { //SPECIAL, found parenthesis closer, find subscript next          //Check if CURRENT is CLOSE PARENTHESIS
            //Indicates close of parenthesis. Get the subscript next, then exit current recursion level
        }

        else {   //FOUND???, check if symbol, then determine is subscript == 1.     //If CURRENT is NONE OF THE ABOVE

        }
    }

    //Return the Composite Identity of the molecular formula
    return compositeIdentity;

}

//Recieves string input and returns Atomic Prime
int getAtomicPrime(string atomStr) {

    if( atomStr == "H") {
        return 2;
    }

    else if( atomStr == "He") {
        return 3;
    }

    else if( atomStr == "Li") {
        return 5;
    }

    else if( atomStr == "Be") {
        return 7;
    }

    else if( atomStr == "B") {
        return 11;
    }

    else if( atomStr == "C") {
        return 13;
    }

    else if( atomStr == "N") {
        return 17;
    }

    else if( atomStr == "O") {
        return 19;
    }

    else if( atomStr == "F") {
        return 23;
    }

    else if( atomStr == "Ne") {
        return 29;
    }

    else if( atomStr == "Na") {
        return 31;
    }

    else if( atomStr == "Mg") {
        return 37;
    }

    else if( atomStr == "Al") {
        return 41;
    }

    else if( atomStr == "Si") {
        return 43;
    }

    else if( atomStr == "P") {
        return 47;
    }

    else if( atomStr == "S") {
        return 53;
    }

    else if( atomStr == "Cl") {
        return 59;
    }

    else if( atomStr == "Ar") {
        return 61;
    }

    else if( atomStr == "K") {
        return 67;
    }

    else if( atomStr == "Ca") {
        return 71;
    }

    else if( atomStr == "Sc") {
        return 73;
    }

    else if( atomStr == "Ti") {
        return 79;
    }

    else if( atomStr == "V") {
        return 83;
    }

    else if( atomStr == "Cr") {
        return 89;
    }

    else if( atomStr == "Mn") {
        return 97;
    }

    else if( atomStr == "Fe") {
        return 101;
    }

    else if( atomStr == "Co") {
        return 103;
    }

    else if( atomStr == "Ni") {
        return 107;
    }

    else if( atomStr == "Cu") {
        return 109;
    }

    else if( atomStr == "Zn") {
        return 113;
    }

    else if( atomStr == "Ga") {
        return 127;
    }

    else if( atomStr == "Ge") {
        return 131;
    }

    else if( atomStr == "As") {
        return 137;
    }

    else if( atomStr == "Se") {
        return 139;
    }

    else if( atomStr == "Br") {
        return 149;
    }

    else if( atomStr == "Kr") {
        return 151;
    }

    else if( atomStr == "Rb") {
        return 157;
    }

    else if( atomStr == "Sr") {
        return 163;
    }

    else if( atomStr == "Y") {
        return 167;
    }

    else if( atomStr == "Zr") {
        return 173;
    }

    else if( atomStr == "Nb") {
        return 179;
    }

    else if( atomStr == "Mo") {
        return 181;
    }

    else if( atomStr == "Tc") {
        return 191;
    }

    else if( atomStr == "Ru") {
        return 193;
    }

    else if( atomStr == "Rh") {
        return 197;
    }

    else if( atomStr == "Pd") {
        return 199;
    }

    else if( atomStr == "Ag") {
        return 211;
    }

    else if( atomStr == "Cd") {
        return 223;
    }

    else if( atomStr == "In") {
        return 227;
    }

    else if( atomStr == "Sn") {
        return 229;
    }

    else if( atomStr == "Sb") {
        return 233;
    }

    else if( atomStr == "Te") {
        return 239;
    }

    else if( atomStr == "I") {
        return 241;
    }

    else if( atomStr == "Xe") {
        return 251;
    }

    else if( atomStr == "Cs") {
        return 257;
    }

    else if( atomStr == "Ba") {
        return 263;
    }

    else if( atomStr == "La") {
        return 269;
    }

    else if( atomStr == "Ce") {
        return 271;
    }

    else if( atomStr == "Pr") {
        return 277;
    }

    else if( atomStr == "Nd") {
        return 281;
    }

    else if( atomStr == "Pm") {
        return 283;
    }

    else if( atomStr == "Sm") {
        return 293;
    }

    else if( atomStr == "Eu") {
        return 307;
    }

    else if( atomStr == "Gd") {
        return 311;
    }

    else if( atomStr == "Tb") {
        return 313;
    }

    else if( atomStr == "Dy") {
        return 317;
    }

    else if( atomStr == "Ho") {
        return 331;
    }

    else if( atomStr == "Er") {
        return 337;
    }

    else if( atomStr == "Tm") {
        return 347;
    }

    else if( atomStr == "Yb") {
        return 349;
    }

    else if( atomStr == "Lu") {
        return 353;
    }

    else if( atomStr == "Hf") {
        return 359;
    }

    else if( atomStr == "Ta") {
        return 367;
    }

    else if( atomStr == "W") {
        return 373;
    }

    else if( atomStr == "Re") {
        return 379;
    }

    else if( atomStr == "Os") {
        return 383;
    }

    else if( atomStr == "Ir") {
        return 389;
    }

    else if( atomStr == "Pt") {
        return 397;
    }

    else if( atomStr == "Au") {
        return 401;
    }

    else if( atomStr == "Hg") {
        return 409;
    }

    else if( atomStr == "Tl") {
        return 419;
    }

    else if( atomStr == "Pb") {
        return 421;
    }

    else if( atomStr == "Bi") {
        return 431;
    }

    else if( atomStr == "Po") {
        return 433;
    }

    else if( atomStr == "At") {
        return 439;
    }

    else if( atomStr == "Rn") {
        return 443;
    }

    else if( atomStr == "Fr") {
        return 449;
    }

    else if( atomStr == "Ra") {
        return 457;
    }

    else if( atomStr == "Ac") {
        return 461;
    }

    else if( atomStr == "Th") {
        return 463;
    }

    else if( atomStr == "Pa") {
        return 467;
    }

    else if( atomStr == "U") {
        return 479;
    }

    else if( atomStr == "Np") {
        return 487;
    }

    else if( atomStr == "Pu") {
        return 491;
    }

    else if( atomStr == "Am") {
        return 499;
    }

    else if( atomStr == "Cm") {
        return 503;
    }

    else if( atomStr == "Bk") {
        return 509;
    }

    else if( atomStr == "Cf") {
        return 521;
    }

    else if( atomStr == "Es") {
        return 523;
    }

    else if( atomStr == "Fm") {
        return 541;
    }

    else if( atomStr == "Md") {
        return 547;
    }

    else if( atomStr == "No") {
        return 557;
    }

    else if( atomStr == "Lr") {
        return 563;
    }

    else if( atomStr == "Rf") {
        return 569;
    }

    else if( atomStr == "Db") {
        return 571;
    }

    else if( atomStr == "Sg") {
        return 577;
    }

    else if( atomStr == "Bh") {
        return 587;
    }

    else if( atomStr == "Hs") {
        return 593;
    }

    else if( atomStr == "Mt") {
        return 599;
    }

    else if( atomStr == "Ds") {
        return 601;
    }

    else if( atomStr == "Rg") {
        return 607;
    }

    else if( atomStr == "Cn") {
        return 613;
    }

    else if( atomStr == "Uut") {
        return 617;
    }

    else if( atomStr == "Uuq") {
        return 619;
    }

    else if( atomStr == "Uup") {
        return 631;
    }

    else if( atomStr == "Uuh") {
        return 641;
    }

    else if( atomStr == "Uus") {
        return 643;
    }

    else if( atomStr == "Uuo") {
        return 647;
    }

    else return 1;

}

//Recieves a string and the position of
