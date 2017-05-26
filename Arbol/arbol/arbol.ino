/* estructura autoreferenciada */
typedef struct NodoArbol{ 
 struct NodoArbol *dash; /*puntero a izquierda*/ 
 char simbolo;
 struct NodoArbol *dot; /*puntero a derecha*/
};
 
/*Variables Globales */
NodoArbol arbol;
NodoArbol *raiz= &arbol;
NodoArbol *actual;

/* metodos de insersion*/
void inicializar(char valor);
void insertarDash(NodoArbol *nuevoNodo);
void insertarDot(NodoArbol *nuevoNodo);
/*metodos de recorrido*/
void irRaiz();
void dash();
void dot();
char verSimbolo();

/*implementacion de metodos */
void inicializar(char valor){
  (*raiz).simbolo=valor;
  *actual=*raiz;

}

void insertarDash(NodoArbol *nuevoNodo){
   (*actual).dash= nuevoNodo;
   *actual=*nuevoNodo;
}

void insertarDot(NodoArbol *nuevoNodo){
   (*actual).dot= nuevoNodo;
   *actual=*nuevoNodo;
}

void irRaiz(){
  *actual=*raiz;
}

void dash(){
 NodoArbol *auxPtr;
 *auxPtr=*((*actual).dash);
 *actual=*auxPtr;
 free(auxPtr);
}
void dot(){
 NodoArbol *auxPtr;
 *auxPtr=*((*actual).dot);
 *actual=*auxPtr;
 free(auxPtr);
}

char verSimbolo(){
return (*actual).simbolo;
}

void setup(){
Serial.begin(9600);
inicializar('a');
NodoArbol nodo;
nodo.simbolo='b';
insertarDash(&nodo);

}
void  loop(){

delay(1000);
Serial.println((*raiz).simbolo);

Serial.println((*raiz).simbolo);
 }
