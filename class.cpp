	#include <iostream>
	#include <iomanip>
	#include <string> 
	using namespace std;

	class mass {

	public:
		mass() {}
		mass(int _count) {
			count = _count;
			data = new int[count];
		}
		void setter(int _count) {
			count = _count;
			data = new int[count];
		}
		mass(const mass& obj) {
			count = obj.count;
			data = new int[count];
			for (int i = 0; i < count; i++)
				data[i] = obj.data[i];
		}
		~mass() {
			delete[] data;
		}
		void show() {
			for (int i = 0; i < count; i++)
				cout << data[i] << " ";
		}
		bool write(int num, int x) {
			if (num >= count || num < 0)return false;
			data[num] = x;
			return true;
		}
		int read(int num) {
			if (num >= count || num < 0)return 0;
			return data[num];
		}
		void sort(bool order = true) {
			int step = count / 2;
			while (step > 0)
			{
				for (int i = 0; i < (count - step); i++) {
					int j = i;
					while (j >= 0 && (data[j] > data[j + step])^order){
						int temp = data[j];
						data[j] = data[j + step];
						data[j + step] = temp;
						j--;
					}
				}
				step = step / 2;
			}
		}
		int& operator[] (const int index);


		friend ostream& operator<< (ostream& out, const mass& mas);
		mass operator&(mass obj)
		{
			mass temp(count + obj.count);
			for (int i = 0; i < count; i++)
				temp[i] = data[i];
			for (int i = 0; i < obj.count; i++)
				temp[count + i] = obj.data[i];
			return temp;
		}

	private:
		int count;
		int* data;
	};

	ostream& operator<< (ostream& out, const mass& mas)
	{
		for (int i = 0; i < mas.count; i++)
			out << mas.data[i] << " ";
		return out;
	}

	int& mass::operator[] (const int index)
	{
		return data[index];
	}
	int main() {
		mass a1(5), a2(5);
		for (int i = 0; i < 5; i++)a1[i] = i;
		for (int i = 0; i < 5; i++)a2.write(i, 5 - i);
		cout << a1;
		cout << '\n';
		a2.show();
		cout << '\n';
	
		mass* b1 = new mass(5);
		for (int i = 0; i < 5; i++)b1->write(i, i + 5);
		mass* b2 = new mass(*b1); 
	
		for (int i = 0; i < 5; i++)(*b1)[i] = -(*b1)[i];
		cout << "original: " << *b1 << "\ncopy: " << *b2<<'\n';
	
		cout <<"sum: "<< (*b1 & *b2)<<'\n';
	
		(*b2).sort();
		cout << "sort " << *b2 << '\n';
	
		delete b1, b2, a1, a2;

		mass* arr = new mass[2]();
		arr[0].setter(3);
		for (int i = 0; i < 3; i++)arr[0][i] = rand() % 10;
		arr[1].setter(4);
		for (int i = 0; i < 4; i++)arr[1][i] = rand() % 10;
		cout << "array "<<arr[1];
		delete[] arr;
	}
