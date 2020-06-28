#include <iostream>
#include <string>

using namespace std;

class TranspVehicle {
public:
	static TranspVehicle* start;
	TranspVehicle* next = NULL;

	static void ShowList() {
		TranspVehicle* p = start;
		while (p) {
			p->show();
			p = p->next;
		}
	}

	TranspVehicle() {
		cout << "--Default constructor--" << endl;
	}

	TranspVehicle(string newName, double newExperience, double newSpeed) {
		name = newName;
		experience = newExperience;
		speed = newSpeed;
	}

	virtual ~TranspVehicle() {
		cout << "--Default destructor--" << endl;
	}

	virtual void show() = 0;
	virtual void input() = 0;
	virtual void addToList() = 0;

protected:
	string name;
	double experience;
	double speed;
};

class Train :public TranspVehicle {
public:
	Train() : TranspVehicle() {};
	Train(string nameOfRailwayN, int numberN, double speedN,
		string nameN, double experienceN) {
		number = numberN;
		speed = speedN;
		name = nameN;
		experience = experienceN;
		nameOfRailway = nameOfRailwayN;
	}

	void show() {
		cout << "---Train---" << endl;
		cout << " The name of the railway: " << nameOfRailway << endl;	
		cout << " Number: " << number << endl;
		cout << " Max speed: " << speed << endl;
		cout << " Driver's name: " << name << endl;
		cout << " Experience of work: " << experience << endl;
		cout << endl;
	}

	void input() {
		cout << "---Train---" << endl;		
		cout << " Enter the name of the railway: "; cin >> nameOfRailway;
		cout << " Enter number: "; cin >> number;
		cout << " Enter max speed: "; cin >> speed;
		cout << " Enter driver's name: "; cin >> name;
		cout << " Enter experience of work: "; cin >> experience;
		cout << endl;
	}

	void addToList() {
		TranspVehicle* p = start;
		while (p->next) {
			p = p->next;
		}
		p->next = this;
	}

protected:
	int number;
	string nameOfRailway;
};

class Express :public Train {
public:
	Express() : Train() {};
	Express(string nameOfRailwayN, int numberN, double speedN,
		string nameOfOrganizationN, string nameN, double experienceN) {
		nameOfRailway = nameOfRailwayN;
		number = numberN;
		speed = speedN;
		nameOfOrganization = nameOfOrganizationN;
		name = nameN;
		experience = experienceN;
	}

	void show() {
		cout << "---Express---" << endl;
		cout << " The name of the railway:" << nameOfRailway << endl;	
		cout << " Number: " << number << endl;			
		cout << " Max speed: " << speed << endl;
		cout << " Name of organization: " << nameOfOrganization << endl;
		cout << " Driver's name: " << name << endl;
		cout << " Experience of work: " << experience << endl;
		cout << endl;
	}

	void input() {
		cout << "---Express---" << endl;
		cout << " Enter the name of the railway: "; cin >> nameOfRailway;
		cout << " Enter number: "; cin >> number;
		cout << " Enter max speed: "; cin >> speed;	
		cout << " Enter name of organization: "; cin >> nameOfOrganization;
		cout << " Enter driver's name: "; cin >> name;
		cout << " Enter experience of work: "; cin >> experience;
		cout << endl;
	}

	void addToList() {
		TranspVehicle* p = start;
		while (p->next) {
			p = p->next;
		}
		p->next = this;
	}

private:
	string nameOfOrganization;
};

class Car :public TranspVehicle {
public:
	Car() : TranspVehicle() {};
	Car(string typeN, string carBrandN, double speedN, string nameN, 
		double experienceN) {
		type = typeN;
		carBrand = carBrandN;
		speed = speedN;
		name = nameN;
		experience = experienceN;	
	}

	void show() {
		cout << "---Car---" << endl;
		cout << " Type of car: " << type << endl;
		cout << " Car brand: " << carBrand << endl;
		cout << " Max speed: " << speed << endl;
		cout << " Driver's name: " << name << endl;
		cout << " Experience of work: " << experience << endl;
		cout << endl;
	}

	void input() {
		cout << "---Car---" << endl;	
		cout << " Enter type of car: "; cin >> type;	
		cout << " Enter car brand: "; cin >> carBrand;
		cout << " Enter max speed: "; cin >> speed;
		cout << " Enter driver's name: "; cin >> name;
		cout << " Enter experience of work: "; cin >> experience;
		cout << endl;
	}

	void addToList() {
		TranspVehicle* p = start;
		while (p->next) {
			p = p->next;
		}
		p->next = this;
	}

protected:
	string type;
	string carBrand;
};

TranspVehicle* TranspVehicle::start = NULL;

int main() {
	Train* train;
	Car* car;
	Express* express;
	train = new Train();
	car = new Car();
	express = new Express();
	train->input();
	car->input();
	express->input();
	TranspVehicle::start = train;
	car->addToList();
	express->addToList();
	TranspVehicle::ShowList();
}