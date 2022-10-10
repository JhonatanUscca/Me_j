#include "control.h"

//string file = "/content/drive/MyDrive/Algoritmos y Estructuras /txt_control/texto.txt";
string file = "texto.txt";


// Objetivo de la función: Cargar las palabras del archivo en la estructura de datos.
void load_file_in_list(string filename, ListaD<string> & L)
{
    /*ifstream file(filename);
    string linea;
    while(getline(file,linea)){
      //istringstream comp(linea);
      //if(comp>>n)
      L.Add_Last(linea);
    }*/
    fstream file;
    string word;
    file.open(filename.c_str());
    while(file>>word){
    	L.Add_Last(word);
	}
}


// 7 puntos
/*Test1: En este test, se toman 5 valores random, cada valor, representa una posición de un nodo de la lista doble; iniciando en la cola de la estructura de datos.
Por ejemplo, en la lista:  carro -> moto -> auto -> terno -> control , si la posición random fuera 4, la palabra que retornaría sería moto.
Dicho esto, se pide imprimir las 5 palabras que se encuentran en estas pociones random de la lista doble.
Pregunta: ¿Qué palabra se forma si unimos la primera con  última palabra que imprime el test1?
Nota: Su respuesta debe estar escrita toda en minúsculas y sin espacios en blanco. */

void Test1(ListaD<string> & L ){
    mt19937 mt(255);
    for(int i=0;i<5;i++) 
    {
      int pos = mt()%1000;
      cout<<L.Get_Value(pos)<<endl;
    }   
}


/*
Test2: En el test 2, se busca encontrar las 10 palabras con menor distancia (las mas similares) a otra palabra tomada de manera aleatoria de la lista doble.
Se generan 3 experimentos y, en cada experimento, se imprimen las 10 primeras palabras ordenadas por el valor de su distancia.
Por ejemplo, si las palabras son: mama->manu->madri->mamá y la palabra a buscar es mamá, la salida serí
mamá,mama, manu, mari.
Recuerde, las palabras más similares están ordenadas de acuerdo a la distancia de levinsteing; por lo tanto, sólo hay una respuesta posible para cada experimento.
¿Qué palabra se forma si tomamos la quinta palabra de la lista de cada experimento y las unimos?
Por ejemplo, si la quinta palabra del experimento 1 fue mamá, la quinta del experimento dos fue pepe, y la quinta del experimento 3 fue ambrosio.
La respueta sería mamápepeambrosio.*/


// 7 puntos
void Test2(ListaD<string> & L)
{
    mt19937 mt(255);
    // Este for indica que son 3 experimentos. 
    for(int i=0;i<1;i++) 
    {
      // pos es un entero random menor a 1000 y  representa la posición del nodo donde se encuentra la palabra  que usaremos
      // para hallar las 10 palabras más similares. 
      int pos = mt()%1000;

      cout<<pos<<endl;
      //cout<<"Palabra: "<<L.Get_String(pos-1)<<endl;
      cout<<"Palabras: Jirafa"<<endl;
      //L.Similar_Find_R(L.Get_String(pos-1),10);
      L.Similar_Find_R("jirafa",5);
      cout<<endl;

      // write your code here to find 10 more similar words  to the word in the position pos. 
      // print the 10 word more similar for each experiment. 
       
    }

}

// 7 puntos
/*Test3: En este test se busca copiar las  últimas  number_word palabras de la Lista L a una Pila y luego eliminar, de la pila,   del_size palabras. Luego, se imprime  la
palabra que queda en el tope de la pila.
TIPS:
-  number_word : Es un número random menor a 10000.
-  del_size    : Es un número random menor a 5000.
-  Recuerde que la idea es copiar las últimas "number_word" palabras de la lista. Es decir, copiar de derecha a izquierda (desde la cola hasta la palabra en la posición number_word )
Objetivo: Imprimir la palabra que queda en el tope de la pila. */

void Test3(ListaD<string> & L)
{
   mt19937 mt(255);
   stack<string> pila;
   int number_word =  mt()%10000;
   cout<<"n: "<<number_word<<endl;
   for(int i=1;i<=number_word;i++)
   {
       // write your code for insert words in the stack
     //cout<<"pal: "<<L.Get_Value(i-1)<<endl;  
     pila.push(L.Get_Value(i-1));
   }

   int del_size = mt()%5000;
   cout<<"del_size: "<<del_size<<endl;
   for(int i=1;i<=del_size;i++)
   {
       // write your code for delet words from  the stack
         pila.pop();

   }

   cout<<"El elemento que queda en la pila es:"<<pila.top()<<endl;

}




int main()
{
    ListaD<string> L;
    load_file_in_list(file,L);
    //cout<<"Resultado test 1:"<<endl;
    //Test1(L);
    cout<<"Resultado test 2:"<<endl;
    //Test2(L);
    cout<<"Resultado test 3:"<<endl;
    Test3(L);
    
    //string a="rinoceronte",b="rinocemoy";
    
    //cout<<levenshtein(a,b);
    
    return 1;
}
