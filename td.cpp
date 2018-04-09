//============================================================================
// Name        : td.cpp
// Author      : sirg
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

#define maxDimension 10

class vecteur {
    protected:
        int maxDim;
        int *tab;
        int index=0;
    public:
        vecteur(){
            tab = new int[maxDimension];
            maxDim = 0;
        };

       vecteur(int max) {
    	   if (max >= 1) {
    		   maxDim = max ;
               tab = new int[maxDim];
            }
        };

       int GetDim(){
           return maxDim ;
       };

       int AddElem (int val) {

    	  if(index>=maxDim)
    		  return -1;
    	  else {
    		  tab[index]=val;
    		  index++;
    		  return 1;
    	  }

       }

        int SetValue(int pos, int value) {
            if ( pos  > 0 && pos < maxDim) {
                tab[pos] = value;
                return 0;
            } else {
            	return -1 ; //erreur

            }
        };

        int GetValue(int position){
        	if ( position  > 0 && position < maxDim) {
        		return tab[position];

        	   } else {
        		   	   return -1 ; //erreur
        	   }
        };

        //operateur d'indicage
        int operator [](int i){
            return tab[i];
        };

        //operateur d'affectation
        vecteur & operator = (vecteur & v1){
        	maxDim = v1.GetDim();
            for(int i=0; i <= maxDim; i++ ){
                tab[i] =  v1.GetValue(i);
            }

        };
}; // end vecteur class



//classe vecteur_intel
class vecteur_intel : public vecteur {

	//operateur =
	vecteur_intel & operator = ( vecteur_intel & v1) {
	int maxDimV1 = v1.GetDim();

	if(maxDim >maxDimV1){

		for(int i=0;i<maxDimV1;i++){
			tab[i]=v1[i];
		}
		for(int i=maxDimV1;i<maxDim;i++){
			tab[i]=0;  // si on veux change le valeurs a 0
		}
	}
	else {

		for(int i=0;i<maxDim;i++){
			tab[i]=v1[i]; // =v1.tab[i]

		}

		for(int i=maxDim;i<maxDimV1;i++){
			AddElem(v1[i]);

				}

	}

		return (*this);
	}



	//ajoute un element au tableau
	//@overwrite
    int AddElem( int val) {   //-1 if error , 1 if not no error
	if ( index >= maxDim) {
    	int *new_tab = new int[index+1];    //cree un nouvaux tableau/ ajouter tab[maxDim*2]
		// mettre a joure la dimension max

                 for(int i=0; i<maxDim; i++){
                    new_tab[i] = tab[i];
                  }


                  delete []tab ;
                  tab = new_tab;
                  maxDim=index+1;

                }
      //ajouter  un element
      tab[index] = val;

       index++;

       return 1;
        };




   /*
operator+(int, vecteur_intel);
1 + v1;
1.operator+(v1)
*/


//operateur addition pour la class vecteur_intel
vecteur_intel operator + (vecteur_intel & v1 ){
	if (){

	}
	vector_intel v(v1) ;
	return (v+ = v2) ;
}

//operateur += pour la class vecteur_intel
vecteur_intel operator += (vecteur_intel & v1){
	vecteur_intel tamp(v1) ;
	return (tamp+ = v2);
}

};// fin classe vecteru_intel



main() {
    vector vect = vector();

    for(int i=0; i<14; i++){

       vect.AddElem(i*i);

       cout << "Value of vect1 for " <<i <<" is " << vect[i] << "\n";
    }

    vector vect2(24);

    vect2=vect;

    for(int i=0;i<vect2.GetPos();i++){

       cout << "Value of vect 2 for " <<i <<" is " << vect2[i] << "\n";
    }


    return 0;
}


