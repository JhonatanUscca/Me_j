#include<iostream>
#include<queue>
#include<stack>


using namespace std;

template<class T>
class Nodo
{
    typedef Nodo<T>*   pNodo; 
    public:
    T      m_Dato;
    pNodo  m_pSon[2];

    public:
    Nodo(T d)
    {
      m_Dato = d;
      m_pSon[0]=m_pSon[1]=0;
    }

    void Matate()
    {
        if(m_pSon[0]) m_pSon[0]->Matate();
        if(m_pSon[1]) m_pSon[1]->Matate();
        delete this;

    }
      
};



template<class T>
class Tree
{
typedef Nodo<T> *    pNodo;
private:
    pNodo m_pRoot;

    pNodo m_Current;
public:
    Tree(){m_Current=m_pRoot=nullptr;};
    ~Tree(){  if(m_pRoot) m_pRoot->Matate();}
private:
    bool find(pNodo  p,  T d)
    {
        if(!p) return false;
        if (p->m_Dato == d) return true;
        return find(p->m_pSon[p->m_Dato > d],d);
    
    } 
    bool insert(pNodo & p , T d)
    {
         if(!p) {p= new Nodo<T>(d); return true;}
         if(p->m_Dato == d) return false;
          
         return insert(p->m_pSon[p->m_Dato < d],d);           
      

    }

    void print(pNodo p, ostream & os)
    {
        
        if(!p) return;
        os<<p->m_Dato<<endl;
        print(p->m_pSon[0],os);
        print(p->m_pSon[1],os);
    }


public:
   bool find(T d){return find(m_pRoot);}
   bool insert(T d){return insert(m_pRoot,d);}
   void print(ostream & os)    {  	print(m_pRoot,os);  }

   friend ostream & operator<<(ostream & os ,Tree<T> & A)
   {
      A.print(os);
      return os;
   }
   Tree<T> & operator<<(T d)
   {
       insert(d);
       return *this;
   } 

   // Implementa las funciones necesarias para que los test sean funcionales y retornen la respueta correcta.
   pNodo father(T d)
    {

        pNodo p = m_pRoot;
        pNodo q = nullptr;
        while(p){
          if(p->m_Dato == d) break;
		    	q=p;
    			p = p->m_pSon[p->m_Dato<d];
        }
        return q;

    }

    pNodo sibling(T d)
    {
        pNodo p = father(d);
                
        if(p->m_pSon[0]->m_Dato == d){
        	return p->m_pSon[1];
		} else {
			return p->m_pSon[0];
		}
        
        return 0;
    }

    pNodo Uncle(T d)
    {
        pNodo p = father(d);
        pNodo q = father(p->m_Dato);

		if(q->m_pSon[0]->m_Dato == p->m_Dato){
        	return q->m_pSon[1];
		} else {
			return q->m_pSon[0];
		}
		
        return 0;
    }

    pNodo grandParent(T d)
    {
        pNodo p = father(d);
        pNodo q = father(p->m_Dato);
        return q;
    } 

    void NivelCantidad (pNodo & p,int d)
    //void NivelCantidad(T p, T d)
    {
      p = m_pRoot;
      if(p != NULL){
        if(d == 0){
          cout<<p->m_Dato<<"";
        }
        NivelCantidad(p->m_pSon[0], d-1);
        NivelCantidad(p->m_pSon[1], d-1);
      }
    }
/*
    void printPorNivel(int n){
        pNodo temp = m_pRoot;
        T dato = temp->m_Dato;

      for(int i = 0;i<n;n++){
        cout<<temp->m_Dato<<endl;
      }
    }*/


    pNodo Begin(){	
  		pNodo temp = this->m_pRoot;
      //pNodo tmp = this->m_Current;
      //cout<<"Current: "<<tmp->m_Dato<<endl;
  		//out<<"temp "<<temp->m_Dato<<endl;
  		while(temp->m_pSon[0]){
  			temp = temp->m_pSon[0];
  		}
  		this->m_Current = temp;
  		//cout<<"dato: "<<m_Current->m_Dato<<endl;
  		return  0;
	}
    pNodo End(){
		  pNodo temp = this->m_pRoot;
  		cout<<"temp "<<temp->m_Dato<<endl;
  		while(temp->m_pSon[1]){
  			temp = temp->m_pSon[1];
  		}
  		this->m_Current = temp;
  		cout<<"dato: "<<m_Current->m_Dato<<endl;
        
        return 0;
    }
    
    
    pNodo Next(){

      pNodo temp = this->m_Current;
      //cout<<"this->current: "<<this->m_Current->m_Dato<<endl;
      T dato = temp->m_Dato;
      //while(temp->m_pSon[temp->m_Dato < dato]){
      if(temp->m_pSon[temp->m_Dato <= dato]){
        while(temp->m_pSon[temp->m_Dato <= dato]){
            //temp = temp->m_pSon(temp->m_Dato < dato);
            temp = temp->m_pSon[temp->m_Dato <= dato];
            if(temp->m_pSon[temp->m_Dato < dato]){
              if(temp->m_pSon[temp->m_Dato < dato]->m_Dato > dato)
                temp = temp->m_pSon[temp->m_Dato < dato];
              }
          }
        }
        else{        
        	pNodo aux = father(dato);
          if(aux->m_Dato > dato)
            temp=aux;
	    	  else if(aux->m_Dato < dato){
    	    	while(aux->m_Dato < dato){
              aux = father(aux->m_Dato);
              if(aux == Begin())
                return 0;
            }
            temp=aux;
    			}
        }
      m_Current = temp;
      cout<<m_Current->m_Dato<<endl;
      return 0;
    }




    pNodo Anterior(){

      pNodo temp = this->m_Current;
      //cout<<"this->current: "<<this->m_Current->m_Dato<<endl;
      T dato = temp->m_Dato;
      //while(temp->m_pSon[temp->m_Dato < dato]){
      if(temp->m_pSon[temp->m_Dato >= dato]){
        while(temp->m_pSon[temp->m_Dato >= dato]){
            //temp = temp->m_pSon(temp->m_Dato < dato);
            temp = temp->m_pSon[temp->m_Dato >= dato];
            if(temp->m_pSon[temp->m_Dato < dato]){
              if(temp->m_pSon[temp->m_Dato > dato]->m_Dato < dato)
                temp = temp->m_pSon[temp->m_Dato > dato];
              }
          }
        }
        else{
        	temp = father(dato);
	    	  if(temp->m_Dato > dato){
    	    		temp=grandParent(dato);
    			}
        }
      
      
      m_Current = temp;
      cout<<m_Current->m_Dato<<endl;
      return 0;
    }
   
    T  GetData()
    {
        return m_Current->m_Dato;
    }
    
};

// No cambiar el codigo dentre de test 1.
void Test1(Tree<int> & A)
{
    cout<<"Test uncle ..."<<endl;
    int a = A.Uncle(3134)->m_Dato;
    int b = A.Uncle(8854)->m_Dato;
    int c = A.Uncle(816)->m_Dato;
    cout<<a<<endl<<b<<endl<<c<<endl;
    cout<<"El valor del tio con el dato mas grade es :"<<"12422"<<endl;
}


// No cambiar el codigo dentre de test 2.
void Test2(Tree<int> & A)
{
    cout<<"Test sibling ..."<<endl;
    cout<<A.sibling(1288)->m_Dato<<endl;
    cout<<A.sibling(723)->m_Dato<<endl;;
    cout<<A.sibling(1071)->m_Dato<<endl;
    cout<<"El valor del hermano con el dato mas pequeño es  :"<<"721"<<endl;
   
}

// No cambiar el codigo dentre de test 3.
void Test3(Tree<int> & A)
{

    cout<<"Test grandParent ..."<<endl;
    cout<<A.grandParent(5389)->m_Dato<<endl;
    cout<<A.grandParent(5211)->m_Dato<<endl;
    cout<<A.grandParent(1288)->m_Dato<<endl;
    cout<<"La suma de los abuelos es   :"<<"_________"<<endl;
    
}


// No cambiar el codigo dentre de test 4.
void Test4(Tree<int> & A)
{
    A.Begin();
    for(int i=0;i<30;i++)
        A.Next();
    cout<<A.GetData()<<" ";
    cout<<"El valor correcto que imprimir este codigo es:"<<"__________"<<endl;   
    
}

int main()
{
  /*
    srand (345);
    
    Tree<int> A;
    const int N = 1000;
    for(int i=1;i<=N;i++)
        A<<rand()%10000;
 	
 	

 	
    cout<<"Iniciando resultados de los test .."<<endl;

	
    Test1(A);
    Test2(A);
    Test3(A);
    Test4(A);*/
    
    
	//cout<<A;
  
  Tree<int> A;
 	A<<20<<10<<25<<15<<8<<12<<9<<19<<16<<22<<28;
  cout<<A.father(9)->m_Dato<<endl;
	cout<<A.sibling(8)->m_Dato<<endl;
	cout<<A.Uncle(9)->m_Dato<<endl;
	cout<<A.grandParent(9)->m_Dato<<endl;
  //cout<<A.m_Current->m_Dato<<endl;
	A.Begin();
  A.Next();
  A.Next();
  A.Next();
  A.Next();
  A.Next();
  A.Next();
  A.Next();
  A.Next();
  A.Next();
  A.Next();
  A.Next();
  
  /*
  A.Anterior();
  A.Anterior();
  A.Anterior();
  A.Anterior();
  A.Anterior();
  A.Anterior();*/

  
  //A.NivelCantidad(20,2);
	//cout<<A.;

    return 0;
}
