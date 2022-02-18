#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <sstream> //for std::stringstream 
#include <string>  //for std::string

using namespace std; 

int menu(); //Para mostrar y escanear las opciones del menu  

void crearVector (int arreglo[], int size); //Opcion 1 -> Crear el vector de numeros enteros

void imprimirVector(int arreglo[], int size); //Opcion 2 -> Imprimir el vector de numeros enteros

void imprimirDirecciones(int arreglo[], int size); //Opcion 3 -> Imprimir las direcciones del vector de numeros enteros

void crearVectorDirecciones (int arreglo[], int size, string dir[]); //Opcion 4 -> Crear un vector direcciones

void imprimirVectorDirecciones (int size, string dir[]); //Opcion 5 -> Imprimir el vector de las direcciones. **no es necesario arreglo[]

void imprimirVectorNumeros(int size, string dir[]); //Opcion 6-> Imprimir el vector de numeros desde el vector de direcciones

void ordenarVector(int arreglo[], int size, string dir[]); //Opcion 7 -> Ordenar el vector de apuntadores teniendo como criterio el vector de numeros

void imprimirVectorOrdenado (int size, int *ubicacion[]); //Opcion 8 -> Imprimir el vector numeros a partir del vector de apuntadores


int main(){
	int op, max=10;
	int vector[max], *direcciones[max];
	string dir[max];
    

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
			    crearVectorDirecciones(vector,max,dir);	    	
	    		break;
	    	case 5:
	    		imprimirVectorDirecciones (max,dir);
	    		break;
	    	case 6:
	    		imprimirVectorNumeros(max,dir);
	    		break;
	    	case 7:
	    		ordenarVector (vector,max,dir);
	    		break;
	    	case 8:
	    		imprimirVectorNumeros(max,dir);
	    		break;
	    }
   }while(op!=9);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int menu(){
	
	int x;
	
	cout<<endl<<"************************************************************************************************************************";
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
	cout<<"Opcion: ";
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
	
	for(int i=0; i<size;i++){
		cout<<"El numero "<<*(arreglo + i)<<" tiene la direccion "<<&*(arreglo + i)<<endl;
	}	
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void crearVectorDirecciones (int arreglo[], int size, string dir[]){
	
	string a;
	string b[size];
	const void * address;
	for(int i=0; i<size; i++){
		address = static_cast<const void*>(arreglo + i);
		std::stringstream ss;
		ss << address;  
		std::string name = ss.str(); 
		dir[i] = name;
		//a = &*(arreglo + i);
		//cout<<name<<dir[i];
		//*(ubicacion + i)= (arreglo + i);
	}


}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void imprimirVectorDirecciones (int size, string dir[]){
	
	/*std::string adr = "0x7fff40602780";
	unsigned long b = stoul(address, nullptr, 16);
	int *ptr = reinterpret_cast<int*>(b);
*/
	for(int i=0; i<size; i++){
		/*int b = stoul(dir[i], nullptr, 16);
		int *ptr = reinterpret_cast<int*>(b);*/
		cout<<dir[i]<<" ";
	}
		
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void imprimirVectorNumeros(int size, string dir[]){
	
	stringstream ss;
	int j;
	int *x;
	int * i_ptr;
	
    for(int i=0; i<size;i++){
    
    ss<<dir[i];
    ss>>std::hex>>j;
    i_ptr=reinterpret_cast<int *>(j+i);
    cout<< *i_ptr<<" ";
    cout<< dir[i]<<" ";

	}
}

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
// A function to implement bubble sort 
void bubbleSort(int arr[], string dir[], int n) 
{

    int i, j; 
    int *x, *y;
    for (i = 0; i < n-1; i++)     
      
    // Last i elements are already in place 
    for (j = 0; j < n-i-1; j++){
    	/*x= *(arr2 + i);
    	y= *(arr2 + i + 1);
    	cout<<"x "<<*x<<" y "<<*y<<" ";*/
    	 if (arr[j] > arr[j+1]) 
            swap(&arr[j], &arr[j+1]); 
	} 
        
	}


	
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ordenarVector(int arreglo[], int size, string dir[]){

	//bubbleSort(arreglo, ubicacion, size );
}

