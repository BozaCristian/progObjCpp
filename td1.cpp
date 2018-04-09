

#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;
        
#define maxDimension 10

    class vector {
    private:
        int pos;
        int posMax;
        int *array;


    public:

        vector(){
            array = new int[maxDimension];
            posMax=maxDimension-1;
            pos=0;
        };

       vector(int max) {
            if (max >= 1) {
                array = new int[max];
                pos = 0;
                posMax=max-1;
               
            } else {
                
            }
        };

        int AddElem( int val) {   //-1 if error , 1 if not no error 
            
                if (pos > posMax) {
                    int *arrayNew = new int[posMax];    //cree un nouvaux tableau
                   // array= MoveValues(array,posMax,arrayNew);   //metre a jour le nouvaux dimension
                    
                    for(int i=0;i<posMax;i++){
                        arrayNew[i]=array[i];        
                    }
                    
                    posMax=(pos + 1)*2;
                    
                    delete []array;//effacer l'espace memoire unnecessaire
                    array=arrayNew;
                 
                }
                
                array[pos] = val;
                
                pos++;
                
                return 1;
            
        }; // verifie si le position donne e >=0 et si il e plus grande que le position MAX 

        int SetValue(int position, int val) {
            if (position > 0 && position < posMax) {
                array[position] = val;
                return 1;
            }
            else if (position>posMax-1){
                
                return AddElem(val);
             
            }else
            {  
                return -1;
            }

        };
        int GetPos(){
        
            return pos;
        };

        int GetValue(int position){
            return array[position];
        };
        
        int operator [](int i){
            return array[i];
        };
        
        void operator =(vector v){
            pos=0;
            for(int i=0;i<=v.GetPos();i++ ){
                
                AddElem(v.GetValue(i));
                
            }
        };
        
 
        
    };
    
main() {


    vector vect = vector();

    for(int i=0;i<14;i++){
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



