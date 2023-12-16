#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int age;

public:
    void SetName(const string& n) {
        name = n;
    }

    const string& GetName() const {
        return name;
    }

    void SetAge(int a) {
        age = a;
    }

    int GetAge() const {
        return age;
    }

    void Print() const {
        cout << "Студент: " << GetName() << ", Возраст: " << GetAge() << " лет\n";
    }
};

class Aspirant : public Student {
private:
    string thesisTopic;

public:
    void SetThesisTopic(const string& topic) {
        thesisTopic = topic;
    }

    const string& GetThesisTopic() const {
        return thesisTopic;
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
    void SetColor(const string& c) {
        color = c;
    }

    const string& GetColor() const {
        return color;
    }

    void Fill() const {
        cout << "Заливка цветом: " << GetColor() << "\n";
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
    void SetFontSize(int size) {
        fontSize = size;
    }

    int GetFontSize() const {
        return fontSize;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    Student student;
    student.SetName("Иван");
    student.SetAge(20);

    cout << "Имя студента: " << student.GetName() << ", Возраст: " << student.GetAge() << " лет\n";

    Aspirant aspirant;
    aspirant.SetName("Петр");
    aspirant.SetAge(25);
    aspirant.SetThesisTopic("Исследование алгоритмов");

    cout << "Имя аспиранта: " << aspirant.GetName() << ", Возраст: " << aspirant.GetAge() << " лет\n";
    cout << "Тема кандидатской работы: " << aspirant.GetThesisTopic() << "\n";

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

    Font font;
    font.SetFontSize(12);

    return 0;
}
