#include "control.h"

string file = "texto.txt";

void load_file_in_list(string filename, ListaD<string> & L)
{
  // write  your code here
  fstream file;
    string word;
    file.open(filename.c_str());
    while(file>>word){
    	L.Add_Last(word);
    }
}

/*  El objetivo del test 1: Buscar las k palabras más similares a cada palabra del vector  word_list.  Las palabras similares deben ser guardadas en una lista de listas; de modo que el nodo 1  guarda la lista de las k palabras mas similares a papa, el nodo 2, la lista de as k palabras mas similares a tomate, y así por delante.
 Usted deberá buscar la palabra en la posición k/2 de cada lista y unirlas para formar una nueva palabra.
 Ejemplo. Si k = 5 y su lista de listas tiene la siguiente forma:
  
  papa->(papa, papá, papi, papas, papás) 
  tomate->(tomate,tomates,tomatodo,tomar,tomé) 
  cebolla->(cebolla,cebollas,sevilla,cebada, sebosa,cebadas)

Entonces  la palabra respuesta sería: papitomatodosevilla
 Recuerde: si k es impar debe tomar techo de k/2
¿Cuál es la palabra que se forma? */


void Test1(ListaD<string> & L)
{

    vector<string> word_list = {"papa","tomate","cebolla"};
    mt19937 mt(255);
    int k = mt()%20;
    ListaD< ListaD< string > * >  R = L.Create_K_Similar_Words(k, word_list);
    R.Print();

     
}



/*Para este test usted deberá imprimir el número de palabras que deberán ser cambiadas en el poema*/

void Test2(string file, ListaD<string> & spanish_words)
{
   
   // write your code here

    ListaD<string> prueba;
    load_file_in_list(file,prueba);

    prueba.Print();
    int num=prueba.m_size;

    for(int i=0;i<prueba.m_size;i++){
      if(spanish_words.find(prueba.Get_String(i))){
        num--;
      }
    }
    cout<<num<<endl;

}

/*Para el test3, usted deberá encontrar las 4 primeras  palabras, del poema, pero que  no se encuentran en la  lista de  palabras en castellano.
Luego, deberá buscar las 4 palabras más similares, a cada una de estas,  utilizando la distancia de levenshtein.
Recuerde, estas palabras estarán ordenadas de menor a mayor según la distancia. 
Ejemplo, tenemos las palabras con sus respectivas listas:

 papa->(papa, papá, papi, papas) 
 tomate->(tomate,tomates,tomatodo,tomar) 
 cebolla->(cebolla,cebollas,sevilla,cebada)

Se pide:
Escriba la palabra que se forma al unir las últimas palabras similares de cada lista.
En nuestro ejemplo, el resultado sería: papastomarcebada.
¿Qué palabra se forma al resolver el test3?*/


void Test3(string file, ListaD<string> & spanish_words)
{

  
}



int main()
{
    ListaD<string> L;
    load_file_in_list(file,L);
  
    cout<<"Resultado test 1:"<<endl;
    Test1(L);
    cout<<endl;
    cout<<endl;


  /*
    cout<<"Resultado test 2:"<<endl;
    string file_poema = "poema.txt" ;
    Test2(file_poema,L);
    cout<<endl;
*/
  
    /*
    cout<<"Resultado test 3:"<<endl;
    Test3(file_poema,L);
    cout<<endl;*/
    
    return 1;
}
