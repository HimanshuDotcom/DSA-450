
template<typename T>
class MapNode {
	public:
	string key;
	T value;
	MapNode<T>* next;
	MapNode(string key, T value) {
		this->key = key;
		this->value = value;
		next = NULL;
	}
	~MapNode() {
		delete next;
	}
};

template<typename T>
class Map {
	MapNode<T>** bucket;
	int size;
	int bucketSize;
	Map() {
		size = 0;
		bucketSize = 10;
		bucket = new MapNode<T>*(size);
		for(int i = 0; i < size; i++)
			bucket[i] = NULL;
	}
	~Map() {
		for(int i = 0; i < bucketSize; i++) {
			delete bucket[i];
		}
		delete [] bucket;
	}
	int getSize() {
		return size;
	}
	int hashFunction(string key) {
		int hashKey = 0;
		int currCoff = 1;
		for(int i = key.length(); i >=0; i--) {
			hashKey += key[i] * currCoff;
			hashKey %= bucketSize;
			currCoff *= 37;   // For better distribution we use prime number
			currCoff %= bucketSize;
		}
		return hashKey % bucketSize;
	}
	void insert(string key, T value) {
		int index = hashFunction(key);
		MapNode<T>* curr = bucket[index];
		while(curr != NULL) {
			if(curr -> key == key) {
				curr -> value = value;
				return;
			}
			curr = curr -> next;	
		}
		curr = bucket[index];
		MapNode<T>* newPair = new MapNode<T>(key, value);
		newPair -> next = curr;
		bucket[index] = newPair;
		size++;		 	
	}
	
	void remove(string key) {
		int index = hashFunction(key);
		MapNode<T>* curr = bucket[index], prev = NULL;
	
		while(curr != NULL) {
			if(curr -> key == key) {
				if(prev == NULL)
					bucket[index] = curr -> next;
				else
					prev -> next = curr -> next;
				curr -> next = NULL;
				size--;
				delete curr;
				return;
			}
			prev = curr;
			curr = curr -> next;
		}
		cout << "Key is not present" << endl;
	}
	
	T getValue(string key) {
		int index = hashFunction(key);
		MapNode<T>* curr = bucket[index];
		while(curr != NULL) {
			if(curr -> key == key)
				return curr -> data;
			curr = curr -> next;
		}
		return 0; // if key is not in the hashmap as default return 0
	}
	
};
int main () {
}
