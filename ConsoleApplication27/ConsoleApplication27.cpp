#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int age;

public:
    Student(string n, int a) {
        SetName(n);
        SetAge(a);
    }

    string GetName() const {
        return name;
    }

    void SetName(string n) {
        name = n;
    }

    int GetAge() const {
        return age;
    }

    void SetAge(int a) {
        age = a;
    }

    void Print() const {
        cout << "Студент: " << GetName() << ", Возраст: " << GetAge() << " лет\n";
    }
};

class Aspirant : public Student {
private:
    string thesisTopic;

public:
    Aspirant(string n, int a, string topic) : Student(n, a) {
        SetThesisTopic(topic);
    }

    string GetThesisTopic() const {
        return thesisTopic;
    }

    void SetThesisTopic(string topic) {
        thesisTopic = topic;
    }

    void Print() const {
        Student::Print();
        cout << "Тема кандидатской работы: " << GetThesisTopic() << "\n";
    }
};

class Transport {
public:
    virtual void CalculateTripDetails() const = 0;
};

class Car : public Transport {
public:
    void CalculateTripDetails() const override {
        cout << "Расчет поездки на автомобиле\n";
    }
};

class Rap {
public:
    void Draw() const {
        cout << "Рисование контура в стиле рэп\n";
    }
};

class Brush {
protected:
    string color;

public:
    void Fill() const {
        cout << "Заливка цветом: " << GetColor() << "\n";
    }

    string GetColor() const {
        return color;
    }

    void SetColor(string c) {
        color = c;
    }
};

class SolidBrush : public Brush {};
class GradientBrush : public Brush {};
class HatchBrush : public Brush {};
class TextureBrush : public Brush {};
class VisualBrush : public Brush {};

class LinearGradientBrush : public GradientBrush {};
class RadialGradientBrush : public GradientBrush {};

class Geometry {
protected:
    string penType;
    Brush* brush;

public:
    Geometry(string type, Brush* b) : penType(type), brush(b) {}

    virtual void Draw() const = 0;
};

class Rectangle : public Geometry {
public:
    Rectangle(string type, Brush* b) : Geometry(type, b) {}

    void Draw() const override {
        cout << "Рисование прямоугольника\n";
        brush->Fill();
    }
};

class Ellipse : public Geometry {
public:
    Ellipse(string type, Brush* b) : Geometry(type, b) {}

    void Draw() const override {
        cout << "Рисование эллипса\n";
        brush->Fill();
    }
};

class Polyline : public Geometry {
public:
    Polyline(string type, Brush* b) : Geometry(type, b) {}

    void Draw() const override {
        cout << "Рисование линии\n";
        brush->Fill();
    }
};

class Font {
private:
    int fontSize;

public:
    Font(int size) {
        SetFontSize(size);
    }

    int GetFontSize() const {
        return fontSize;
    }

    void SetFontSize(int size) {
        fontSize = size;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    Student student("Иван", 20);
    cout << "Имя студента: " << student.GetName() << ", Возраст: " << student.GetAge() << " лет\n";

    Aspirant aspirant("Петр", 25, "Исследование алгоритмов");
    cout << "Имя аспиранта: " << aspirant.GetName() << ", Возраст: " << aspirant.GetAge() << " лет\n";
    cout << "Тема кандидатской работы: " << aspirant.GetThesisTopic() << "\n";

    student.Print();

    aspirant.Print();

    Car car;
    car.CalculateTripDetails();

    Rap rap;
    rap.Draw();

    SolidBrush solidBrush;
    GradientBrush gradientBrush;
    HatchBrush hatchBrush;
    TextureBrush textureBrush;
    VisualBrush visualBrush;

    solidBrush.Fill();
    gradientBrush.Fill();
    hatchBrush.Fill();
    textureBrush.Fill();
    visualBrush.Fill();

    LinearGradientBrush linearGradientBrush;
    RadialGradientBrush radialGradientBrush;

    Rectangle rectangle("Прямоугольник", &solidBrush);
    Ellipse ellipse("Эллипс", &gradientBrush);
    Polyline polyline("Линия", &hatchBrush);

    rectangle.Draw();
    ellipse.Draw();
    polyline.Draw();

    Font font(12);

    return 0;
}