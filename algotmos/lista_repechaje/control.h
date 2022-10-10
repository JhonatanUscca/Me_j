
#ifndef LISTAD_H_
#define LISTAD_H_

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <ctime> 
#include <random>
#include <stack>
#include <cmath>


using namespace std;

struct word_l{
    string w;
    int n;
};

bool comp(word_l a, word_l b){
    return a.n < b.n; 
}


int levenshtein(const string &s1, const string &s2)
{
   int N1 = s1.size();//Devuelve el tamaño del contenedor o numero de elementos
   int N2 = s2.size();
   int i, j;
   vector<int> T(N2+1);

   for ( i = 0; i <= N2; i++ )
      T[i] = i;

   for ( i = 0; i < N1; i++ ) 
   {
      T[0] = i+1;
      int esquina = i;
      for ( j = 0; j < N2; j++ ) 
      {
         int superior = T[j+1];
         if ( s1[i] == s2[j] )
            T[j+1] = esquina;
         else
            T[j+1] = min(T[j], min(superior, esquina)) + 1;
         esquina = superior;
      }
   }
   return T[N2];
}



template<class T>
class Nodo
{

public:
	 T    m_Dato;
	 Nodo<T> * m_pSig;
	 Nodo<T> * m_pAnt;
  public:
	 Nodo(T d)
	 {
		 m_Dato = d;
		 m_pSig = 0;
		 m_pAnt = 0;
	 }
};

template<class T>
class ListaD
{

public:
	 Nodo<T> * m_pHead;
	 Nodo<T> * m_pLast;
	 Nodo<T> * m_Current;
	 
   int       m_size;
   public:
	 ListaD()
	 {
		 m_pHead = m_pLast =0;
		 m_Current=0;
     m_size=0;
	 }

   int size(){return m_size;}

	 void Add_Last(T d)
	 {
     //if(d=="FIN") return;
   	 Nodo<T> * pNuevo = new Nodo<T>(d);
		 if (!m_pHead)
		   m_pHead = m_pLast = pNuevo;
		 else
		 {
			 m_pLast->m_pSig =pNuevo;
			 pNuevo->m_pAnt = m_pLast;
			 m_pLast = pNuevo;
		 }
     m_size++;
	 }

void Print()
{
		 Nodo<T> * tmp = m_pHead;
		 while(tmp!=0)
		 {
			 cout<<tmp->m_Dato<<endl;
			 tmp = tmp->m_pSig;
		 }
}


bool find(T d)
{
		 Nodo<T> * tmp = m_pHead;
		 while(tmp!=0)
		 {
			 if(tmp->m_Dato==d) return true;
			 tmp = tmp->m_pSig;
		 }
		 return false;
}




ListaD<string> * Similar_Find_R(string word, int k )
{
        Nodo<string> * r = m_pHead;
        vector<word_l> words;
        
        while(r != 0)
         {
            word_l w;
            w.w = r->m_Dato;
            w.n = levenshtein(word,r->m_Dato);
            words.push_back(w);
            r = r->m_pSig;
         }

        sort(words.begin(), words.end(), comp);
        ListaD<string> similar_words;
        int i = 0;
        for(const word_l wo : words){
            cout<<wo.w<<endl;
            similar_words.Add_Last(wo.w);
            if(i == k) break;
            i++;
        }

        cout<<endl;
        return & similar_words;
  
}




/* Objetivo: Retorna una lista de punteros a listas. Es decir, cada nodo en la lista principal
 tiene la direccion de memoria de otra lista que contiene las k palabras mas similares a una proporsionada.
 Por ejemplo si k = 2 y words tiene las palabras {"madre","amigo"}, esta función debería
 retornar una lista con dos nodos y cada nodo tener una lista con las palabras similares a madre 
 y amigo respectivamente. Vea el ejemplo. 

madre-> (mama),(mamá)
amigo-> (amiga),(amigas)

Nota: No cambie los parámetros de ingreso ni salida de la función, solo añada en código 
necesario dentro del cuerpo
de la función.
*/




     

ListaD< ListaD<string> * >   Create_K_Similar_Words(int  k, vector<string> & words)
{
  ListaD< ListaD<string> * >  tmp;
  for(const string w : words){
    tmp.Add_Last(Similar_Find_R(w,k));
  }
  return tmp;
} 


string Get_Value(int p)
{
     Nodo<T> * r = m_pLast;
		 for(int i=1;i<p && r!=0;r = r->m_pAnt,++i);
     if (!r) return "No encontrado";
     return r->m_Dato;
} 

string Get_String(int p)
{
     Nodo<T> * r = m_pHead;
		 for(int i=1;i<p && r!=0;r = r->m_pSig,i++);
     if (!r) return "No encontrado";
     return r->m_Dato;
} 


void Next() {m_Current = m_Current->m_pSig;}
void Previus() {m_Current = m_Current->m_pAnt;}
void End() {m_Current =  m_pLast;}
void Begin() {m_Current =  m_pHead;}
bool Is_Finish(){  return m_Current==0; }
bool Is_FinishR(){  return m_Current->m_pAnt==0; }
T Get_Data() { 	 return m_Current->m_Dato;  }

};

#endif /* LISTAD_H_ */
