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
			static void
			swap()
			{
			
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
//				delete []bufferi;
			
			//TODO Thik about this method
			void push_back(T&& value) //Is it right type?
			{
				if (_size >= _capacity)
				{
					reserve((_capacity = 0) ? (1) : (_capacity * 2)); // ........
				}
				data[_size] = value;		
				++size;
			}		
			void pop_back()
			{
				size--;
			}
			void erase()
			{
			
			}
			void swap
			{
			
			}
	}
