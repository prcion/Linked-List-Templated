#pragma once

template <typename T> class LinkedList;

template <typename T>

class Node {
	friend class LinkedList<T>;
private:
	T data;
	Node* next;
public:
	//constructor pentru nod
	Node();
	//destructor pentru nod
	~Node();
};

template <typename T>
class LinkedList
{
	friend class Node<T>;
private:
	Node<T>* head;
	Node<T>* tail;
	int l;
public:
	//constructor pentru lista 
	LinkedList();
	//constructor pentru copiere
	LinkedList(const LinkedList&);
	//returneaza dimensiunea listei
	int size()const;
	//adauga la sfarsit un element
	void push_back(T);
	//returneaza o referinta la elemenetul de la sfarsitul listei
	T& back() const;
	//sterge si returneaza elementul de la sfarsitul listei
	T pop_back();
	//returneaza al elementul de pe pozitia data
	T& at(int) const;
	//destructor de lista
	~LinkedList();
};

template<typename T>
Node<T>::Node() {
	data = T();
	next = nullptr;
}

template<typename T>
Node<T>::~Node() {

}
template<typename T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
	tail = nullptr;
	l = 0;
}
template<typename T>
LinkedList<T>::LinkedList(const LinkedList& previous) {
	
	Node<T>* current=previous.head;
	for (int i = 0; i < previous.l; i++) {
		this->push_back(current->data);
		current = current->next;
	}
}

template<typename T>
int LinkedList<T>::size() const{
	return l;
}

template<typename T>
void LinkedList<T>::push_back(T elem) {
	if (head == nullptr) {
		head = new Node < T > ;
		head->data = elem;
		tail = head;
	}
	else {
		Node<T>* temp = new Node<T>;
		temp->data = elem;
		tail->next = temp;
		tail = tail->next;

	}
	l++;
}

template<typename T>
T& LinkedList<T>::back() const {
	return tail->data;
}

template<typename T>
T LinkedList<T>::pop_back() {
	T elem = tail->data;
	Node<T>* temp = head;
	if (head != tail) {
		while (temp->next != tail) {
			temp = temp->next;
		}
		tail = temp;
		temp = temp->next;
		tail->next = nullptr;
		delete temp;
	}
	else {
		delete tail;
		head = nullptr;
		tail = nullptr;
	}
	l--;
	return elem;
}


template<typename T>

T& LinkedList<T>::at(int i) const {
	int j = 0;
	Node<T>* current = head;
	while (j != i) {
		current = current->next;
		j++;
	}
	return current->data;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	Node<T>* current=head;
	Node<T>* next;
	while (current != nullptr) {
		next = current->next;
		delete current;
		current = next;
	}
	l = 0;
	head = nullptr;
	tail = nullptr;
}



