#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

struct Word 
{
    string                    m_palabra;
    vector<int>               n_linea;
    vector< vector <int> >    m_position;

    Word(string p)
    {
       m_palabra = p; 
    }
    void Insert_Linea(int l, vector<int > & index)
    {
        n_linea.push_back(l);
        m_position.push_back(index);
    }

    bool operator==(Word & w)
    {
        return m_palabra == w.m_palabra;
    }

     bool operator==(string palabra)
    {
        return m_palabra == palabra;
    }
    
};

vector<string> tokenizar(string linea)
{
   // write your code here
   vector<string>  tmp;
   return tmp;
}

 vector<int> find(string palabra,string linea)
 {
     // write your code here
   vector<int> tmp;
   return tmp;

 }

// procesar es una función que procesar una linea
void procesar(string linea, int n_line, list<Word>  & ds)
{
    // dividir la linea en palabras sin repetición. 
    vector<string>  palabras = tokenizar(linea);
    // cada palabra puede estar varias veces en una linea, por lo tanto
    // una palabra puede tener varios lugares en la columna.
    for (int i=0;i<palabras.size(); i++)
    {
       // la función find busca la palabra i en el string linea y retorna
       // la columna en la que se encuentra.
        vector<int>   index = find(palabras[i],linea);

        
        Word w(palabras[i]);
        w.Insert_Linea(n_line,index);
        list<Word>::iterator it  = std::find(ds.begin(), ds.end(), palabras[i]);
        if(it==ds.end()) // si no existe
           ds.push_back(w);
        else  // si ya existe, it es un puntero al nodo que tiene esa palabra i
            it->Insert_Linea(n_line,index);
    }

}

// leer un archivo, procesar linea a linea
void Read_File(string file_name,list<Word>  & ds)
{
   ifstream A(file_name);
   char buffer[1000];
   int n_linea=0;
   while(!A.eof())
   {
       A.getline(buffer,1000);
       procesar(buffer,n_linea, ds);
    

       n_linea++;
   }
}

int main() 
{
    list<Word>  DS;
    Read_File("main.cpp", DS);
    cout<<"Proceso terminado ..."<<endl;
    //print(DS);

    return 0;  
}
