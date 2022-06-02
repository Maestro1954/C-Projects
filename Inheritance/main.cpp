#include <iostream>

using namespace std;

class Shape {
    public:
        Shape(double w, double h) {
            width = w;
            height = h;
        }
        
        void print() {
            cout << "Width: " << width << endl;
            cout << "Height: " << height << endl;
        }
    
    protected:
        double width;
        double height;
};

class Rectangle : public Shape/*, OtherClass, andAnotherClass*/ {
    public:
        Rectangle(double w, double h) : Shape(w, h)/*, OtherClass(w, h), andAnotherClass(w)*/ {
            
        }
        
        double area() {
            return (width * height);
        }
};

class Triangle : public Shape {
    public:
        Triangle(double w, double h) : Shape(w, h) {
            
        }
        
        double area() {
            return (0.5 * width * height);
        }
};

int main(int argc, char* argv[]) {
    
    Rectangle r(2.0, 4.0);
    Triangle t(2.0, 4.0);
    
    cout << "r area: " << r.area() << endl;
    cout << "t area: " << t.area() << endl;
    
    //r.print();
    
    return 0;
}
