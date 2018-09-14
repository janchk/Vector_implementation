#include iostream

template <typename T>
	class Vector{
		private:
			T *buffer;
			unsigned int capacity;
		public:
			Vector(){
				capacity=0;
				buffer=new T[capacity]
				}
			Vector(const Vector &asv){
				int i;
				capacity=asv.getCapacity();
				buffer=new T[asv.getCapacity()];
			        for (i=0; i<capacity; i++){
					buffer[i]=asv[i];
				}
			}
			~Vector(){
				delete []buffer;
			}
			void push_back(T_obj){
				Vector oldSV(*this)
			}
	}
