#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int age;

public:
    Student(string n, int a) : name(n), age(a) {}

    string GetName() const {
        return name;
    }

    int GetAge() const {
        return age;
    }

    void Print() const {
        cout << "Студент: " << name << ", Возраст: " << age << " лет\n";
    }
};

class Aspirant : public Student {
private:
    string thesisTopic;

public:
    Aspirant(string n, int a, string topic) : Student(n, a), thesisTopic(topic) {}

    string GetThesisTopic() const {
        return thesisTopic;
    }

    void Print() const {
        Student::Print();
        cout << "Тема кандидатской работы: " << thesisTopic << "\n";
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
        cout << "Заливка цветом: " << color << "\n";
    }
};

class SolidBrush : public Brush {
public:
    SolidBrush() {
        color = "Однородный цвет";
    }
};

class GradientBrush : public Brush {
public:
    GradientBrush() {
        color = "Градиентный цвет";
    }
};

class HatchBrush : public Brush {
public:
    HatchBrush() {
        color = "Цвет заливки с узором";
    }
};

class TextureBrush : public Brush {
public:
    TextureBrush() {
        color = "Цвет заливки с текстурой";
    }
};

class VisualBrush : public Brush {
public:
    VisualBrush() {
        color = "Цвет заливки с использованием визуального элемента";
    }
};

class LinearGradientBrush : public GradientBrush {
public:
    LinearGradientBrush() {
        color = "Градиентный цвет по линейной оси";
    }
};

class RadialGradientBrush : public GradientBrush {
public:
    RadialGradientBrush() {
        color = "Градиентный цвет по радиальной оси";
    }
};

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
    Font(int size) : fontSize(size) {}
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
  
}