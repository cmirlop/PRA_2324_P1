#include <iostream>
#include "List.h"
template <typename T>

class ListLinked:public List<T>{
	private:
		Node<T>* first;
		int n;
	public:
		//Metodos heredados
		virtual void insert(int pos, T e) = 0;
		virtual void append( T e) = 0;
		virtual void prepend( T e) = 0;
		virtual T remove(int pos){
		
		
		}

		virtual T get(int pos){
			if(pos>n){
				throw out_of_range("Posicion invalida");
			}
			Node<T> aux=first;
			for( int x=0;x<n;x++){
				if(x==pos){
					return aux.data;
				}
				aux=aux->next;
			
			}
			return nullptr;
		
		}

		virtual int search( T e){
			Node<T> aux=first;
			for(int x=0;x<n;x++){
				if(aux.data == e){
					return x;
				}
				aux=aux->next;
		
			}

			return -1
		
		
		}
		
		
		virtual bool empty(){
			if(n==0){
				return true;
			}
		}

		virtual int size(){
			return n;
		}

		//Metodos de la clase
		ListLinked(){
			first=nullptr;
			n=0;
		}
		~ListLinked(){
			Node<T> aux;
			for(int x=n;x>0;x--){
			aux=first->next;
			n--;
			delete first;
			first=aux
			}
		}
		T operator[](int pos){
			if(pos>n){
				throw out_of_range("fuera de rango");
			}
			Node<T> aux=first;
			for(x=0;x<n;x++){
				if(n==pos){
					return aux.data;
				}
				aux=aux.next;
			}
			return nullptr;
		
			
		
		}
		
		friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
			for(ListLinked p : list){
				out<<p.data<<std::endl;
			}
			return out;
		}



};
