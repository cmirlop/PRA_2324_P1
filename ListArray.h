#include "List.h"
#include <iostream>
#include <exception>
template <typename T>
class ListArray : public List<T>{
	private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE;
		
		void resize( int new_size){
			T* newarr = new ListArray[new_size]; //Creamos nuevo array
			if(new_size < n){
				throw "No se puede";
			}
			for(int x=0;x<n;x++){
				newarr[x]=arr[x];
			}
			max=new_size;
			delete[] arr;
			arr = newarr;
			newarr = nullptr;
			delete newarr;
		
		}


	public:
		//Metodos heredados y que hay que sobreescribir
		void insert(int pos, T e) override{
			if(size()==max){
				resize(size()*2);
				max=size()*2;
			}
			
			
			if(pos==1){
				prepend(e);
			
			}else if(pos==size()){
				append(e);
			}else{
				for(int x=size();x>=pos;x--){
					arr[x]=arr[x-1];
				}
				arr[pos-1]=e;
				n++;
			
			}
				
		
		
		}
		void append(T e) override{
			if(size()==max){
				resize(size()*2);
				max=size()*2;
			}
			arr[size()]=e;	
			n++;
		}

		void prepend(T e) override{
			if(size()==max){
				resize(size()*2);
				max=size()*2;
			
			}

			for(int x=size();x>0;x--){
				arr[x]=arr[x-1];
		
			}
			arr[0]=e;
			n++;
		
		}
		T remove(int pos) override{
			if(pos> (size()-1)){
				throw std::out_of_range("fuera de rango");
			} else {
				
				T x=arr[pos];
				
				delete arr[pos];
				if(pos<(max-1) && pos<size()-1){
					for(int y=pos;y<size()-1;y++){
						arr[y]=arr[y+1];
					
					}
				
				}
				n--;
				return x; 
			}
		}
	
		T get(int pos) override{
			if(pos > (size()-1)){
				throw std::out_of_range("fuera de rango");
			
			}else{
				return arr[pos-1];
		
			}
		}

		int search( T e) override{
		
			for(int x=0;x<(size()-1);x++){
				if(arr[x]==e){
					return x;
				}
			
			}
			return -1;
		}

		bool empty() override{
			if(n==0){
				return true;
			}else{
				return false;
			}
		
		}
		
		int size() override{
			return n;
		
		}
	
	
		//Metodos de la clase ListArray
		ListArray(){
			MINSIZE=2;
			arr = new ListArray[MINSIZE];  // Constructor 
			max=MINSIZE;
			n=0;
		}


		~ListArray(){
			delete[] arr;
		}


		T operator[](int pos){
			if(pos > n || pos<0 ){
				throw std::out_of_range("fuera de rango");		
			
			}else{
				return arr[pos];
			}
		
		}

		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
			for(int x=0; x<size();x++){
			
				out<<list[x]<<std::endl;
			
			}
			return out;	
		}

											
		


};
