#include<iostream>
using namespace std;
#include<queue>

class Car {
	
	public :
		string name;
		int x;
		int y;
		
		Car(string name, int x, int y) {
			this->name = name;
			this->x = x; 
			this->y = y; 
		}
		
		int distance() const{
			return x*x + y*y;
		}
		
		
		
};

class  compare{
	public :
		bool operator()(Car const &A, Car const &B) {
			return A.distance() < B.distance();
		}
};

void printNearestCars(vector<Car> cars, int k) {
	priority_queue<Car, vector<Car>, compare> heap(cars.begin(), cars.begin() + k);
	for(int i = k; i < cars.size(); i++) {
		if(cars[i].distance() < heap.top().distance()) {
			heap.pop();
			heap.push(cars[i]);
		}
	}
	while(!heap.empty()) {
		cout << heap.top().name << " ";
		heap.pop();
	}
}

int main() {
	int N,K;
	cin >> N >> K;
	string name;
	int x,y;
	
	vector<Car> cars;
	for(int i = 0; i < N; i++) {
		cin >> name >> x >> y;
		Car car(name,x,y);
		cars.push_back(car);
	}
	printNearestCars(cars, K);
}
