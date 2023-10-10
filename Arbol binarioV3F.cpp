#include <iostream>
#include <random>
#include <ctime>
//librerias para numero al azar
using namespace std;
//ALFREDO NAVARRETE MONTES
//FERNANDO MORALES CILIA

class NodoABB{
	public:
		int dato;
		NodoABB* izq;
		NodoABB* der;
		NodoABB(int _dato) : dato(_dato), izq(nullptr), der(nullptr) {}
};

class ArbolBinario{	

public:
	NodoABB* raiz;
	 ArbolBinario() : raiz(nullptr) {}
	 
	bool esVacio()
	{
		if(raiz==nullptr)
		{
			return true;
		}
		return false;
	}
	void insertar(int _dato)
	{
		raiz = insertarRecursivo(raiz,_dato);
	}
	bool buscaDato( int _dato)
	{
		return buscaDatoRecursivo(raiz,_dato);
	}
	void eliminar(int dato )
	{
		raiz = eliminarRecursivo(raiz, dato);
	} 
	void mostrarPreorden()
	{
		preorden(raiz);
		cout<< "\n" ;
	}
	void mostrarInorden()
	{
		inorden(raiz);
		cout<< "\n" ;
	}
	void mostrarPostOrden()
	{
		postorden(raiz);
		cout<< "\n" ;
	}
private:
	NodoABB* insertarRecursivo(NodoABB* nodo, int dato)
{
    if (nodo == nullptr)//caso de que el arbol esta vacio se inserta directamente
    {
        return new NodoABB(dato);
    }
    if (nodo->dato==dato){//caso de que el dato esta repetido, NO SE INSERTA, SE DA UN AVISO
    	cout<<"dato repetido "<<dato<<" no se ha insertado"<<endl;
	}
    if (dato < nodo->dato)//funciones para recorrer el arbol dependiendo si el dato es mayor o menor
    {
        nodo->izq = insertarRecursivo(nodo->izq, dato);
    }
    else if (dato > nodo->dato)
    {
        nodo->der = insertarRecursivo(nodo->der, dato);
    }
    return nodo;//SE REGRESA EL NODO (POSICION) PARA QUE SE INSERTE EL NODO CON EL DATO
}
	
	bool buscaDatoRecursivo(NodoABB* nodo, int dato)
	{
        if (nodo == nullptr) //caso de que el dato no se encuentre se regresa false
		{
			//cout <<"no esta \n";
            return false;
        }

        if (dato == nodo->dato) //caso de que el dato buscado sea encontrado se regresa true
		{
			//cout<<" si esta \n";
        	return true;
        } else 	
				if (dato < nodo->dato) //funciones para recorrer el arbol en busca del dato
				{
					return buscaDatoRecursivo(nodo->izq, dato);
				}else 
				{
					return buscaDatoRecursivo(nodo->der, dato);
				}
    }
    
     NodoABB* encontrarMinimo(NodoABB* nodo) 
	 {
        while (nodo->izq != nullptr) 
		{
            nodo = nodo->izq;
        }
        return nodo;
    }
    
    NodoABB* encontrarMax(NodoABB* nodo) 
     {
        while (nodo->der != nullptr) 
        {
            nodo = nodo->der;
        }
        return nodo;
    }
    
    NodoABB* eliminarRecursivo(NodoABB* nodo, int dato) 
	{
		if(!buscaDato(dato)){//para saber si el dato a eliminar existe o no
			cout<<"no existe el dato a eliminar"<<endl;
			return nodo;
		}
        if (nodo == nullptr) //en caso de que el arbol este vacio no se hace nada
		{
            return nodo;
        }

        if (dato < nodo->dato) //funcion para recorrer el arbol dependiendo si el dato es mayor o menor
		{
            nodo->izq = eliminarRecursivo(nodo->izq, dato);
        } else if (dato > nodo->dato) {
            nodo->der = eliminarRecursivo(nodo->der, dato);
        } else {
            if (nodo->izq == nullptr) { //funcion para eliminar los datos dependiendo de que lado tenga el hijo (caso solo tiene un hijo)
                NodoABB* temp = nodo->der;
                nodo = nullptr;
                return temp;
            } else if (nodo->der == nullptr) {
                NodoABB* temp = nodo->izq;
                nodo= nullptr;
                return temp;
            }
            
            srand(time(nullptr));//funcion para eliminar los datos (caso tiene dos hijos)
            if(rand()%2==0){//se utiliza un numero al azar para determinar de que subarbol se sustituye el dato
            	NodoABB* temp = encontrarMinimo(nodo->der);
            	nodo->dato = temp->dato;
            	nodo->der = eliminarRecursivo(nodo->der, temp->dato);
            	cout<<"Dato sustituido del subarbol derecho"<<endl;
			}
			else{
				NodoABB* temp = encontrarMax(nodo->izq);
            	nodo->dato = temp->dato;
            	nodo->izq = eliminarRecursivo(nodo->izq, temp->dato);
            	cout<<"Dato sustituido del subarbol izquierdo"<<endl;
				
			}
				
            
        }
        return nodo;
    }
    
     void preorden(NodoABB* nodo) {
        if (nodo != nullptr) {
            std::cout << nodo->dato << " ";
            preorden(nodo->izq);
            preorden(nodo->der);
        }
    }
    
    void inorden(NodoABB* nodo) {
        if (nodo != nullptr) {
            inorden(nodo->izq);
            std::cout << nodo->dato << " ";
            inorden(nodo->der);
        }
    }
    
    void postorden(NodoABB* nodo) {
        if (nodo != nullptr) {
            postorden(nodo->izq);
            postorden(nodo->der);
            std::cout << nodo->dato << " ";
        }
    }
};


int main() {
    /*ArbolBinario arbol;

     arbol.insertar(30);
    arbol.insertar(70);
    arbol.insertar(20);
    arbol.insertar(40);
    arbol.insertar(60);
    arbol.insertar(80);

    cout << "Preorden: ";
    arbol.mostrarPreorden();

    cout << "Inorden: ";
    arbol.mostrarInorden();

    cout << "Postorden: ";
    arbol.mostrarPostOrden();

	cout<<"buscando el 40 \n";
    arbol.buscaDato(40);
    cout<<"buscando el 90 \n";
    arbol.buscaDato(90);
    cout<<"eliminando el 30 y mostrando";
    arbol.eliminar(30);
    arbol.mostrarInorden();*/

	int op;
	bool salir=false;
	ArbolBinario a;
	
	do{
		cout<<"A R B O L  B I N A R I O  D E  B U S Q U E D A"<<endl;
		cout<<"1. Verificar que este vacio"<<endl;
		cout<<"2. Insertar nodo"<<endl;
		cout<<"3. Buscar elemento"<<endl;
		cout<<"4. Eliminar Nodo"<<endl;
		cout<<"5. Mostrar en preorden"<<endl;
		cout<<"6. Mostrar en inorden"<<endl;
		cout<<"7. Mostrar en postorden"<<endl;
		cout<<"8. Salir"<<endl;
		
		cout<<"Elija una opcion: ";cin>>op;
		
		switch(op){
			
			case 1:{
				if(a.esVacio())
					cout<<"Es Vacio"<<endl;
				else
					cout<<"NO es vacio"<<endl;
				
				break;
			}
			
			case 2:{
				int da;
				cout<<"Escriba el dato a insertar "<<endl;
				cin>>da;
				a.insertar(da);
				cout<<"Dato insertado"<<endl;
				break;
			}
			
			case 3:{
				int da;
				cout<<"Escriba el dato a buscar "<<endl;
				cin>>da;
				if(a.buscaDato(da))
					cout<<"si existe"<<endl;
				else
					cout<<"no existe"<<endl;
				break;
			}
			
			case 4:{
				int da;
				cout<<"Escriba el dato a eliminar "<<endl;
				cin>>da;
				a.eliminar(da);
				//cout<<"Dato eliminado "<<endl;
				break;
			}
			
			case 5:{
				cout<<"Mostrando en PREORDEN "<<endl;
				a.mostrarPreorden();
				break;
			}
			
			case 6:{
				cout<<"Mostrando en INORDEN "<<endl;
				a.mostrarInorden();
				break;
			}
			
			case 7:{
				cout<<"Mostrando en POSTORDEN "<<endl;
				a.mostrarPostOrden();
				break;
			}
			
			case 8:{
				cout<<"adios"<<endl;
				salir=true;
				break;
			}
			
			default: {
				
				cout<<"Opcion no valida"<<endl;
				break;
			}
		}
	}while(salir==false);

    return 0;
}