#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo *sig;
};

class ListaEnlazada{
    private:
        Nodo *inicio;
    public: 
        Nodo* crearNodo(int valor){
            Nodo *n = new Nodo;
            n -> dato = valor;
            n -> sig = nullptr;
            return n;
        }
        
        void mostrarListaR(Nodo *temp){
            if(temp->sig){
                cout<<temp -> dato<<", ";
                mostrarListaR(temp->sig);
            }else{
                cout<<temp->dato;
            }
        }
        
        void mostrarLista(){
            mostrarListaR(inicio);
        }
        
        void agregarElemento(int valor){
            Nodo *n = crearNodo(valor), *temp;
            if(!inicio){
                inicio = n;
            }else{
                for(temp = inicio; temp -> sig; temp = temp -> sig);
                temp -> sig = n;
            }
        }
        
        float getPromedio(int dimensionLista){
            Nodo *temp = inicio;
            float aux;
            if (!inicio){
                cout << "La lista no posee elementos"<<endl;
            } else {
                while (temp){
                    aux = aux + temp->dato;
                    temp = temp -> sig;
                }
                cout<<endl;
            }
            aux = aux/dimensionLista;
            return aux;
        }
        
        int getDatoEnPos(int posicion){
            Nodo *temp = inicio;
            int contador = 0;
            while (contador < posicion){
                //aux = aux + temp->dato;
                temp = temp -> sig;
                contador++;
            }
            return temp -> dato;
        }
        
        ListaEnlazada(){
            inicio = nullptr;
        }
};

ListaEnlazada mayorQuePromedio(ListaEnlazada listaBase, int cantidad, float promedio){
    ListaEnlazada listaRevisada;
    int datoAux;
    
    for(int i=0; i<cantidad; i++){
        datoAux = listaBase.getDatoEnPos(i);
        if(datoAux>promedio){
            listaRevisada.agregarElemento(datoAux);
        }
    }
    
    return listaRevisada;
}

int main(int argc, char** argv) {
    ListaEnlazada lista, nuevaLista;
    
    int cantidad, dato;
    float promedio;
    
    cout <<"A continuación se procederá a rellenar una lista de números enteros."<<endl;
    cout <<"Cantidad de datos a ingresar: ";
    cin >>cantidad;
    
    for(int i=0; i<cantidad; i++){
        cout<<"Ingrese el dato "<<i+1<<": ";
        cin>>dato;
        lista.agregarElemento(dato);
    }
    
    cout<<endl;
    
    cout <<"La lista es la siguiente: "<<endl;
    lista.mostrarLista();
    
    cout<<endl;
    
    promedio = lista.getPromedio(cantidad);
    cout<<"El promedio de los elementos es: "<<promedio<<endl;
    
    cout<<endl;
    
    nuevaLista = mayorQuePromedio(lista, cantidad, promedio);
    cout <<"Los elementos que sobrepasan el promedio son: "<<endl;
    nuevaLista.mostrarLista();
    
    return 0;
}
