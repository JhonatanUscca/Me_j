#ifndef LISTAD_H_
#define LISTAD_H_

#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
#include<ctime> 
#include<random>
#include<stack>


using namespace std;


int levenshtein(const string &s1, const string &s2)
{
   int N1 = s1.size();
   int N2 = s2.size();
   int i, j;
   vector<int> T(N2+1);

   for ( i = 0; i <= N2; i++ )
      T[i] = i;

   for ( i = 0; i < N1; i++ ) 
   {
      T[0] = i+1;
      int corner = i;
      for ( j = 0; j < N2; j++ ) 
      {
         int upper = T[j+1];
         if ( s1[i] == s2[j] )
            T[j+1] = corner;
         else
            T[j+1] = min(T[j], min(upper, corner)) + 1;
         corner = upper;
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
   int       m_size;
   public:
	 ListaD()
	 {
		 m_pHead = m_pLast =0;
     m_size=0;
	 }
   int size(){return m_size;}

	 void Add_Last(T d)
	 {
     if(d=="FIN") return;
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




	 bool findR(T d, Nodo<T> * r)
	 {
		 if(r == 0){ return false;}
		 if(r->m_Dato == d){ return true;}
		 findR(d,r->m_pSig);
	 }


	 bool find(T d)
	 {
		 Nodo<T> * r = m_pHead;
		 while(r!=0)
		 {
			 if(r->m_Dato == d) return true;
			 r = r->m_pSig;
		 }
		 return false;
	 }

// Objetivo: Imprimir las k palabras con la menor distancia de levinsteing a la palabra word.
// La idea es computar la distancia de levenshtein de word contra todas las palabras en la lista
// y quedarse solo con las k mas pequenias.
// Tenga en cuenta que la lista de k palabras estan ordenadas de menor distancia a mayor distancia.
// Esto es importante para poder responder las preguntas de los test.
  void Similar_Find_R(string word, int k )
  {
		Nodo<T> * tmp = m_pHead;
		int values[m_size];
		int pos[m_size];

		for(int j = 0; j<m_size;j++)
		{
			values[j] = levenshtein(word,tmp->m_Dato);
			pos[j] = j;
			tmp = tmp->m_pSig;
		}

		for(int x = 1; x < m_size; x++)
		{
      
      int temp = values[x];
			int tempPos = pos[x];
			int j = x-1;
			while(j >= 0 && temp < values[j])
			{
				cout<<"Antes de actualizar values: "<<values[j+1]<<endl;
        cout<<values[j]<<endl;
        values[j+1] = values[j];
        cout<<"Antes de actualizar pos: "<<pos[j+1]<<endl;
        cout<<pos[j]<<endl;
				pos[j+1] = pos[j];
				j--;
			}
      cout<<temp<<"\n"<<tempPos<<endl;
			values[j+1] = temp;
			pos[j+1] = tempPos;
		}
		for(int i = 0;i<k;i++)
		{
			cout<<values[i]<<": ";
			cout<<Get_String(pos[i])<<endl;
		}
  }

  // Objetivo: Dado un valor entero p, retornar la palabra que está en el nodo p iniciando en la cola de la lista.
	// El primero nodo esta en la posición 1, no en 0. 
	// Ejemplo, si p es 3, contamos desde el último 3 nodos hacia la izquierda. 
  string Get_Value(int p)
  {
		 Nodo<T> * temp = m_pLast;
		 string rep;
		 for(int i = 0; i<p; i++)
			 temp = temp->m_pAnt;
		return temp->m_Dato;
  } 


  // Objetivo: Dado un valor entero p, retornar la palabra que está en el nodo p iniciando en la cabeza de la lista.
	// El primero nodo esta en la posicion 1, no en 0. 
	// Ejemplo, si p es 3, contamos desde el último 3 nodos hacia la derecha. 
  
  string Get_String(int p)
  {

		Nodo<T> * tmp = m_pHead;
		 for(int i = 0; i<p; i++)
			 tmp = tmp->m_pSig;
		return tmp->m_Dato;
  } 


};

#endif /* LISTAD_H_ */
