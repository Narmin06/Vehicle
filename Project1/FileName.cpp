#include<iostream>
#include<stack>
using namespace std;

class Engine {
	string company;
	double volume;
	int engine_no;

public:
	Engine() {
		company = " ";
		volume = 0.0;
		engine_no = 0;
	}

	Engine(string company, double volume, int engine_no) {
		this->company = company;
		this->volume = volume;
		this->engine_no = engine_no;
	}

	Engine(const Engine& object) {
		SetCompany(object.company);
		SetVolume(object.volume);
		engine_no = object.engine_no;
	}

	Engine& operator=(const Engine& object) {
		SetCompany(object.company);
		SetVolume(object.volume);
		engine_no = object.engine_no;
		return *this;
	}

	string GetCompany() const {
		return this->company;
	}

	void SetCompany(string company) {
		if (company.length() < 3) {
			cout << "Wrong company" << endl;
		}
		else {
			this->company = company;
		}
	}

	double GetVolume() const {
		return this->volume;
	}

	void SetVolume(double volume) {
		if ((volume < 4) || (volume>12)) {
			cout << "Wrong volume" << endl;
		}
		else {
			this->volume= volume;
		}
	}

	int GetEngineNO() const {
		return this->engine_no;
	}
};

class Vehicle {
	Engine engine;
	string model;
	string vendor;
	int id;
	static int static_id;
public:
	Vehicle(Engine engine, string model, string vendor) {
		this->engine = engine;
		SetModel(model);
		SetVendor(vendor);
		static_id++;
		this->id = static_id;
	}

	string GetModel() const {
		return this->model;
	}

	void SetModel(string model) {
		if (model.length() > 3) {
			this->model = model;
		}
		else {
			cout << "Model is short" << endl;
		}
	}

	string GetVendor() const {
		return this->vendor;
	}

	void SetVendor(string vendor) {
		if (vendor.length() > 3) {
			this->vendor = vendor;
		}
		else {
			cout << "Vendor is short" << endl;
		}
	}
	int GetID() const {
		return this->id;
	}

	friend ostream& operator<<(ostream& out, const Vehicle& object) {
		out << "ID: " << object.GetID() << endl;
		out << "Model: " << object.GetModel() << endl;
		out << "Vendor: " << object.GetVendor() << endl;
		return out;
	}
};

int Vehicle::static_id = 0;



class Car : public Vehicle {
	bool hasSpoiler;
public:
	Car(Engine engine, string model, string vendor, bool hasSpoiler, int id) : Vehicle(engine, model, vendor) {
		this->hasSpoiler = hasSpoiler;
	}

	bool GetHasSpoiler() const {
		return this->hasSpoiler;
	}

	friend ostream& operator<<(ostream& out, const Car& object) {
   	out << "ID: " << object.GetID() << endl;
   	out << "Car model: " << object.GetModel() << endl;
   	out << "Car vendor: " << object.GetVendor() << endl;
   	out << "Car spoiler: " << object.GetHasSpoiler() << endl;
   	return out;
    }
};

class Ship : public Vehicle {
	bool hasSail;
public:
	Ship(Engine engine, string model, string vendor, bool hasSail, int id) : Vehicle(engine, model, vendor) {
		this->hasSail = hasSail;
	}

	bool GetHasSail() const {
		return this->hasSail;
	}

	friend ostream& operator<<(ostream& out, const Ship& object) {
		out << "ID: " << object.GetID() << endl;
		out << "Ship model: " << object.GetModel() << endl;
		out << "Ship vendor: " << object.GetVendor() << endl;
		out << "Ship sail: " << object.GetHasSail() << endl;
		return out;
	}
};


class Airplane : public Vehicle {
	int engine_count;
	int passengers_capacity;

public:
	Airplane(Engine engine, string model, string vendor, int engine_count, int passengers_capacity, int id) : Vehicle(engine, model, vendor) {
		this->engine_count = engine_count;
		this->passengers_capacity = passengers_capacity;
	}

	int GetEngineCount() const {
		return this->engine_count;
	}

	void SetEngineCount(int engine_count) {
		if (engine_count < 1) {
			cout << "Wrong engine count" << endl;
		}
		else {
			this->engine_count = engine_count;
		}
	}

	int GetPassengersCapacity() const {
		return this->passengers_capacity;
	}

	void SetPassengersCapacity(int passengers_capacity) {
		if (passengers_capacity < 1) {
			cout << "Wrong passengers capacity" << endl;
		}
		else {
			this->passengers_capacity = passengers_capacity;
		}
	}

	friend ostream& operator<<(ostream& out, const Airplane& object) {
		out << "ID: " << object.GetID() << endl;
		out << "Airplane model: " << object.GetModel() << endl;
		out << "Airplane vendor: " << object.GetVendor() << endl;
		out << "Airplane engine count: " << object.GetEngineCount() << endl;
		out << "Airplane passengers capacity : " << object.GetPassengersCapacity() << endl;
		return out;
	}
};


class VehicleDepo {
	stack <Car> cars;
	stack <Ship> ships;
	stack <Airplane> airplanes;
public:
	void AddCar(const Car& car) {
		cars.push(car);
	}

	void AddShip(const Ship& ship) {
		ships.push(ship);
	}

	void AddAirplane(const Airplane& airplane) {
		airplanes.push(airplane);
	}

	void ShowAllVehicles() {
		cout << "   All Cars   " << endl;
		stack <Car> tempCars = cars; 
		while (!tempCars.empty()) {
			cout << tempCars.top() << endl;
			tempCars.pop();
		}

		cout << "   All Ships   " << endl;
		stack <Ship> tempShips = ships; 
		while (!tempShips.empty()) {
			cout << tempShips.top() << endl;
			tempShips.pop();
		}

		cout << "   All Airplanes   " << endl;
		stack <Airplane> tempPlanes = airplanes; 
		while (!tempPlanes.empty()) {
			cout << tempPlanes.top() << endl;
			tempPlanes.pop();
		}
	}
};


void main() {
	Engine engine("Company", 10, 1);

	Car car1(engine, "Car1", "Vendor1", 0, 1);
	//cout << car1 << endl;	
	
	Ship ship1(engine, "Ship1", "Vendor1", 1, 1);
	//cout << ship1 << endl;

	Airplane airplane1(engine, "Airplane1", "Vendor1", 10, 300, 1);
	//cout << airplane1 << endl;

	VehicleDepo vehicle_depo;
	vehicle_depo.AddCar(car1);
	vehicle_depo.AddShip(ship1);
	vehicle_depo.AddAirplane(airplane1);

	vehicle_depo.ShowAllVehicles();

}