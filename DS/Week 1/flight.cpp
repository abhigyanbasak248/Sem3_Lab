#include <iostream>
using namespace std;

class flight {
    int flight_no;
    char dest[50];
    float dist;
    float fuel;
    float calculate_fuel(float dist) {
        if (dist<=1000) {
            fuel=500;
        }
        else if (dist<=2000) {
            fuel=1100;
        }
        else if (dist>2000) {
            fuel=2200;
        }
        return fuel;
    }
    public:
    flight() {
        fuel=13.2;
    }
    void info_entry() {
        cout<<"Enter flight number: ";
        cin>>flight_no;
        fflush(stdin);
        cout<<"Enter destination: ";
        cin.get(dest,50);
        cout<<"Enter distance: ";
        cin>>dist;
        fuel=flight::calculate_fuel(dist);
    }
    void display() {
        cout<<"FLight details: "<<endl;
        cout<<"Flight Number: "<<flight_no<<endl;
        cout<<"FLight destination: "<<dest<<endl;
        cout<<"FLight distance: "<<dist<<endl;
        cout<<"Fuel Used: "<<fuel<<" Litres"<<endl;
    }
};
int main() {
    flight f;
    f.info_entry();
    f.display();
    return 0;
}