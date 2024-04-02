#include <iostream>
#include "../include/utilidades/ArbolAlv.h"

// funcion que asigna un nuevo nodo
NodoGraph *instanciaar_nodo(int llava,string dato){
    NodoGraph *nodo = new NodoGraph();
    nodo->llave=llava;
    nodo->derecha=NULL;
    nodo->izquierda=NULL;
    nodo->dato=dato;
    nodo->altura=1;
    return nodo;
}
// funcion para tener una nueva  padre nodo
int nueva_altura(NodoGraph *nodo){
    if(nodo==NULL){
        return 0;
    }
    else{
        return nodo->altura;
    }
}

//funcionar  para balanciar
int balanciar(NodoGraph *nodo){
    if(nodo==NULL){
        return 0;
    }
    else{ return nueva_altura(nodo->izquierda)- nueva_altura(nodo->derecha);}
}

NodoGraph *girar_derecha(NodoGraph *y){
    NodoGraph *x = y->izquierda;
    NodoGraph *T2 = x->derecha;
    x->derecha = y;
    y->izquierda = T2;
    y->altura = max(nueva_altura(y->izquierda), nueva_altura(y->derecha)) + 1;
    x->altura = max(nueva_altura(x->izquierda), nueva_altura(x->derecha)) + 1;
    return x;
}

NodoGraph *girar_izquierda(NodoGraph *x){
    NodoGraph *y = x->derecha;
    NodoGraph *T2 = y->izquierda;
    //rotacion
    y->izquierda = x;
    x->derecha = T2;
    x->altura = max(nueva_altura(x->izquierda),nueva_altura(x->derecha)) + 1;
    y->altura =max(nueva_altura(x->izquierda),nueva_altura(x->derecha)) + 1;
    return y;
}



NodoGraph *ArbolAlv::insert(NodoGraph *nodo, int llave, string campo) {
    /* realizar insercion*/
    if (nodo == NULL)
        return(instanciaar_nodo(llave,campo));

    if (llave < nodo->llave)
        nodo->izquierda = insert(nodo->izquierda, llave,campo);
    else if (llave > nodo->llave)
        nodo->derecha = insert(nodo->derecha, llave,campo);
    else
        return nodo;

    /* actualizar la altura */
    nodo->altura = 1 + max(nueva_altura(nodo->izquierda),nueva_altura(nodo->derecha));

    /* balanciar */
    int balan = balanciar(nodo);

    //nodo por izquierdo
    if (balan > 1 && llave < nodo->izquierda->llave)
        return girar_derecha(nodo);

    if (balan < -1 && llave > nodo->derecha->llave)
        return girar_izquierda(nodo);

    // nodod por derecha
    if (balan > 1 && llave > nodo->izquierda->llave)
    {
        nodo->izquierda = girar_izquierda(nodo->izquierda);
        return  girar_derecha(nodo);
    }

    // Right Left Case
    if (balan < -1 && llave < nodo->derecha->llave)
    {
        nodo->derecha = girar_derecha(nodo->derecha);
        return girar_izquierda(nodo);
    }
    return nodo;
}
