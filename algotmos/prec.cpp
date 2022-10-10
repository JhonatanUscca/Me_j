/*
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

struct Nodo 
{
    int dato;
    Nodo* siguiente;
}* primero, *ultimo;

void insertarNodo_ini(int  n){
    Nodo* nuevo_nodo =  new Nodo();
    nuevo_nodo->dato = n;
    if(primero == NULL){
        nuevo_nodo = primero;
        nuevo_nodo->siguiente = NULL;
        primero = ultimo;
    } else {
        nuevo_nodo->siguiente  = primero;
        primero = nuevo_nodo;
    }
}

void prim(){
    Nodo* aux = new Nodo();
    aux = primero;
    while(aux != NULL){
        cout << aux->dato << " -> ";
        aux=aux->siguiente;
    }
}

int main(){
    insertarNodo_ini(1);
    insertarNodo_ini(2);
    insertarNodo_ini(3);
    insertarNodo_ini(4);
    insertarNodo_ini(5);
    insertarNodo_ini(6);
    insertarNodo_ini(7);
    prim();
    cout << "sdsdf";



}
*/


#include <iostream>

using namespace std;

struct Nodo {
    int data;
    struct Nodo *next;
    struct Nodo *prev;
};

void push(Nodo** head_ref, int new_data){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->next = NULL;
    //nuevo_nodo = (*head_ref);
    nuevo_nodo->data =  new_data;
    if((*head_ref) == NULL){
       (*head_ref) = nuevo_nodo;

    } else {
        nuevo_nodo->next = (*head_ref);
        (*head_ref) = nuevo_nodo; 
    }


}


void printList(Nodo** head_ref){
    Nodo* aux = new Nodo();
    aux = *head_ref;
    if(head_ref!=NULL){
            do{
                cout << aux->data << " -> ";
                aux =  aux->next;
           }while(aux!=NULL);
    } else {
        cout << "la lista esta vacia.";
    } 

}


void  printList_ant(Nodo** head_ref,int new_data){
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->data = new_data;
    nuevo_nodo->next = NULL;

    if((*head_ref) == NULL){
        (*head_ref) = nuevo_nodo;
    } else {
        Nodo* aux = new Nodo();
        aux =  *head_ref;
        while(aux != NULL){
            aux =  aux->next;
        }
        
        aux->next = nuevo_nodo;
        
 
       
    }
}


int main(){
    Nodo **pri;
    /*
    push(pri,2);
    push(pri,3);
    push(pri,4);
    push(pri,5);
    push(pri,6);
    push(pri,7);
    push(pri,8);
    push(pri,9);
    push(pri,10);
    push(pri,11);
    push(pri,12);
    */
    printList_ant(pri,13);
    printList_ant(pri,14);
    printList_ant(pri,15);
    printList_ant(pri,16);
    printList_ant(pri,17);


    printList(pri);
}
