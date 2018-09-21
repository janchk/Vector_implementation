#include iostream

template <typename T>
	class Vector{
		private:
			T *buffer;
			size_type _size;
			size_type _capacity;
			T* data;
			//unsigned int capacity;
			
			Static T*
			allocate(size_type, size)
			{
				return static_cast<T*>(malloc(sizeof(T) * size));
			}
			static void
			copyRange(T* begin, T* end, T* dest)
			{
				while(begin != end)
				{
					new((void*)dest) T(*begin);
					++begin;
					++dest;
				}
			}
			static void
			deleteRange(T* begin, T* end)
			{
				while(begin != end)
				{
				begin->~T();
				++begin;
				}
			}
		public:
			typedef T* iterator;
			typedef T value_type;

			Vector()
			{
				_size = 0;
				_capacity = 0;
				_data = 0;
			}
			~Vector()
			{
				deleteRange(_data, _data + _size);
				free(_data);
			}
//			Vector(const Vector &asv){
//				int i;
//				capacity=asv.getCapacity();
//				buffer=new T[asv.getCapacity()];
//			        for (i=0; i<capacity; i++){
//					buffer[i]=asv[i];
//				}
//			~Vector(){
//			
//				delete []buffer;
			void push_back(const T& value)
			{
					
			}		
			void pop_back()
			{
			
			}
			void erase()
			{
			
			}
	}
