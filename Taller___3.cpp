#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std; 

int menu(); //Para mostrar y escanear las opciones del menu  

void crearVector (int arreglo[], int size); //Opcion 1 -> Crear el vector de numeros enteros

void imprimirVector(int arreglo[], int size); //Opcion 2 -> Imprimir el vector de numeros enteros

void imprimirDirecciones(int arreglo[], int size); //Opcion 3 -> Imprimir las direcciones del vector de numeros enteros

void crearVectorDirecciones (int arreglo[], int size, int *ubicacion[]); //Opcion 4 -> Crear un vector direcciones

void imprimirVectorDirecciones (int arreglo[], int size, int *ubicacion[]); //Opcion 5 -> Imprimir el vector de las direcciones

void imprimirVectorNumeros(int arreglo[], int size, int *ubicacion[]); //Opcion 6-> Imprimir el vector de numeros desde el vector de direcciones

void ordenarVector(int arreglo[], int size, int *ubicacion[]); //Opcion 7 -> Ordenar el vector de apuntadores teniendo como criterio el vector de numeros

void imprimirVectorOrdenado (int arreglo[], int size, int *ubicacion[]); //Opcion 8 -> Imprimir el vector numeros a partir del vector de apuntadores


int main(){
	int op, max=10;
	int vector[max], *direcciones[max];
    

	do{
	    op= menu();
	    switch(op){
	    	case 1:
	    		crearVector(vector, max);
	    		break;
	    	case 2:
	    		imprimirVector(vector, max);
	    		break;
	    	case 3:
	    		imprimirDirecciones(vector, max);
	    		break;
	    	case 4:
			    crearVectorDirecciones(vector,max,direcciones);	    	
	    		break;
	    	case 5:
	    		imprimirVectorDirecciones (vector,max,direcciones);
	    		break;
	    	case 6:
	    		imprimirVectorNumeros(vector,max,direcciones);
	    		break;
	    	case 7:
	    		ordenarVector (vector,max,direcciones);
	    		break;
	    	case 8:
	    		imprimirVectorOrdenado (vector,max,direcciones);
	    		break;
	    }
   }while(op!=9);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int menu(){
	
	int x;
	
	cout<<endl<<"Bienvenido al menu"<<endl<<endl;
	cout<<"Ingrese 1 para crear el vector de numeros enteros de 10 elementos aleatoriamente."<<endl<<endl;
	cout<<"Ingrese 2 para imprimir el contenido del vector de numeros creado anteriormente."<<endl<<endl;
	cout<<"Ingrese 3 para imprimir las direcciones donde se encuentra cada elemento del vector de numeros."<<endl<<endl;
	cout<<"Ingrese 4 para crear un vector direcciones donde almacene en cada posicion la direccion donde se encuentra cada elemento del vector numeros."<<endl<<endl;
	cout<<"Ingrese 5 para imprimir el contenido del vector de direcciones."<<endl<<endl;
	cout<<"Ingrese 6 para imprimir el contenido del vector numeros a partir del vector de direcciones"<<endl<<endl;
	cout<<"Ingrese 7 para ordenar el vector de apuntadores teniendo como criterio de ordenacion el vector numeros"<<endl<<endl;
	cout<<"Ingrese 8 para imprimir el vector numeros a partir del vector de direcciones ordenado"<<endl<<endl;
	cout<<"Ingrese 9 para salir del programa"<<endl<<endl;
	cin>>x;
	
	return x;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void crearVector (int arreglo[], int size){
	
	srand(time(NULL));
	for(int i=0; i<size; i++) {
		*(arreglo + i)=1 + rand()%10;
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void imprimirVector(int arreglo[], int size){
	
	for(int i=0; i<size; i++){
		cout<<" ["<<*(arreglo + i)<<"] ";
	}
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void imprimirDirecciones(int arreglo[], int size){
	int *p;
	
	for(int i=0; i<size;i++){
		p=&*(arreglo + i);
		cout<<"El numero "<<*(arreglo + i)<<" tiene la direccion "<<p<<endl;
	}	
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void crearVectorDirecciones (int arreglo[], int size, int *ubicacion[]){
	
	for(int i=0; i<size; i++){
	*(ubicacion + i)= (arreglo + i);
	}
	
	

}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void imprimirVectorDirecciones (int arreglo[], int size, int *ubicacion[]){
	
	for(int i=0; i<size; i++){
		cout<<" ["<<*(arreglo + i)<<"] ";
	}
	
	cout<<endl;
	
	for(int i=0; i<size; i++){
		cout<<" ["<<*(ubicacion + i)<<"] ";	
	}
	
	
		
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Aqui debo usar doble apuntador -> Apuntador apuntando a otro 
void imprimirVectorNumeros(int arreglo[], int size, int *ubicacion[]){
	int **p;

    for(int i=0; i<size;i++){
    	**p=**(ubicacion+i);
		cout<<p;
	}
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ordenarVector(int arreglo[], int size, int *ubicacion[]){ //Usar el método burbuja en vez de este -> Los numeros se pueden repetir
	int *aux;
	
	for(int i=0; i<size;i++){
		
		for(int j=0;j<size;j++){
			
			if((arreglo+j)>(arreglo+(j+1))){
				aux=*(ubicacion+j);
				*(ubicacion+j)=*(ubicacion+j+1);
				*(ubicacion+j+1)=aux;
			}
		}
	}
	

}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void imprimirVectorOrdenado (int arreglo[], int size, int *ubicacion[]){
	
	for(int i=0; i<size;i++){
		cout<<" ["<<*(ubicacion+i)<<"] ";
	}
}


