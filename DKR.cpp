// Основний клас Quadrilateral
class Quadrilateral {
protected:
    double side1, side2, side3, side4;

public:
    // Конструктори для ініціалізації
    Quadrilateral() : side1(0), side2(0), side3(0), side4(0) {}
    Quadrilateral(double s1, double s2, double s3, double s4)
        : side1(s1), side2(s2), side3(s3), side4(s4) {}

    // Методи встановлення та отримання сторін
    void setSides(double s1, double s2, double s3, double s4) {
        side1 = s1;
        side2 = s2;
        side3 = s3;
        side4 = s4;
    }

    void getSides(double& s1, double& s2, double& s3, double& s4) const {
        s1 = side1;
        s2 = side2;
        s3 = side3;
        s4 = side4;
    }

    // Віртуальні методи для обчислення площі та периметра
    virtual double area() const {
        // За замовчуванням для довільного чотирикутника (необхідно перевизначити в похідних класах)
        return 0;
    }

    virtual double perimeter() const {
        return side1 + side2 + side3 + side4;
    }

    // Метод для представлення об'єкта у вигляді рядка
    virtual std::string toString() const {
        std::ostringstream oss;
        oss << "Sides: " << side1 << ", " << side2 << ", " << side3 << ", " << side4;
        return oss.str();
    }

    // Перевантаження оператора << для виведення об'єкта на консоль
    friend std::ostream& operator<<(std::ostream& out, const Quadrilateral& q) {
        out << q.toString();
        return out;
    }

    // Віртуальний метод для отримання типу чотирикутника
    virtual std::string getType() const {
        return "Quadrilateral";
    }
};

// Похідний клас Rectangle
class Rectangle : public Quadrilateral {
public:
    Rectangle(double width, double height)
        : Quadrilateral(width, height, width, height) {}

    // Перевизначення методу для обчислення площі
    double area() const override {
        return side1 * side2;
    }

    // Перевизначення методу для отримання типу чотирикутника
    std::string getType() const override {
        return "Rectangle";
    }
};

// Похідний клас Square
class Square : public Quadrilateral {
public:
    Square(double side)
        : Quadrilateral(side, side, side, side) {}

    // Перевизначення методу для обчислення площі
    double area() const override {
        return side1 * side1;
    }

    // Перевизначення методу для отримання типу чотирикутника
    std::string getType() const override {
        return "Square";
    }
};

// Похідний клас Rhombus
class Rhombus : public Quadrilateral {
private:
    double diagonal1, diagonal2;
public:
    Rhombus(double side, double d1, double d2)
        : Quadrilateral(side, side, side, side), diagonal1(d1), diagonal2(d2) {}

    // Перевизначення методу для обчислення площі
    double area() const override {
        return (diagonal1 * diagonal2) / 2;
    }

    // Перевизначення методу для отримання типу чотирикутника
    std::string getType() const override {
        return "Rhombus";
    }
};

// Клас Logger для логування
class Logger {
private:
    std::ofstream logFile;

public:
    // Конструктор відкриває файл для запису
    Logger(const std::string& filename) {
        logFile.open(filename, std::ios::app);
    }

    // Деструктор закриває файл, якщо він відкритий
    ~Logger() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }

    // Метод для запису повідомлення у файл
    void log(const std::string& message) {
        if (logFile.is_open()) {
            logFile << message << std::endl;
        }
    }
};

// Функція для шифрування повідомлень
std::string encrypt(const std::string& data) {
    std::string encrypted = data;
    for (char& c : encrypted) {
        c += 1;
    }
    return encrypted;
}

// Функція для аналізу чотирикутників у векторі
void analyzeQuadrilaterals(const std::vector<Quadrilateral*>& shapes, Logger& logger) {
    int squares = 0, rectangles = 0, rhombuses = 0, generic = 0;
    Quadrilateral* minAreaSquare = nullptr, * maxAreaSquare = nullptr;
    Quadrilateral* minPerimeterSquare = nullptr, * maxPerimeterSquare = nullptr;
    Quadrilateral* minAreaRectangle = nullptr, * maxAreaRectangle = nullptr;
    Quadrilateral* minPerimeterRectangle = nullptr, * maxPerimeterRectangle = nullptr;
    Quadrilateral* minAreaRhombus = nullptr, * maxAreaRhombus = nullptr;
    Quadrilateral* minPerimeterRhombus = nullptr, * maxPerimeterRhombus = nullptr;
    Quadrilateral* minAreaGeneric = nullptr, * maxAreaGeneric = nullptr;
    Quadrilateral* minPerimeterGeneric = nullptr, * maxPerimeterGeneric = nullptr;

    for (const auto& shape : shapes) {
        double area = shape->area();
        double perimeter = shape->perimeter();

        if (shape->getType() == "Square") {
            squares++;
            if (!minAreaSquare || area < minAreaSquare->area()) minAreaSquare = shape;
            if (!maxAreaSquare || area > maxAreaSquare->area()) maxAreaSquare = shape;
            if (!minPerimeterSquare || perimeter < minPerimeterSquare->perimeter()) minPerimeterSquare = shape;
            if (!maxPerimeterSquare || perimeter > maxPerimeterSquare->perimeter()) maxPerimeterSquare = shape;
        }
        else if (shape->getType() == "Rectangle") {
            rectangles++;
            if (!minAreaRectangle || area < minAreaRectangle->area()) minAreaRectangle = shape;
            if (!maxAreaRectangle || area > maxAreaRectangle->area()) maxAreaRectangle = shape;
            if (!minPerimeterRectangle || perimeter < minPerimeterRectangle->perimeter()) minPerimeterRectangle = shape;
            if (!maxPerimeterRectangle || perimeter > maxPerimeterRectangle->perimeter()) maxPerimeterRectangle = shape;
        }
        else if (shape->getType() == "Rhombus") {
            rhombuses++;
            if (!minAreaRhombus || area < minAreaRhombus->area()) minAreaRhombus = shape;
            if (!maxAreaRhombus || area > maxAreaRhombus->area()) maxAreaRhombus = shape;
            if (!minPerimeterRhombus || perimeter < minPerimeterRhombus->perimeter()) minPerimeterRhombus = shape;
            if (!maxPerimeterRhombus || perimeter > maxPerimeterRhombus->perimeter()) maxPerimeterRhombus = shape;
        }
        else {
            generic++;
            if (!minAreaGeneric || area < minAreaGeneric->area()) minAreaGeneric = shape;
            if (!maxAreaGeneric || area > maxAreaGeneric->area()) maxAreaGeneric = shape;
            if (!minPerimeterGeneric || perimeter < minPerimeterGeneric->perimeter()) minPerimeterGeneric = shape;
            if (!maxPerimeterGeneric || perimeter > maxPerimeterGeneric->perimeter()) maxPerimeterGeneric = shape;
        }
    }

    logger.log("Squares: " + std::to_string(squares));
    logger.log("Rectangles: " + std::to_string(rectangles));
    logger.log("Rhombuses: " + std::to_string(rhombuses));
    logger.log("Generic Quadrilaterals: " + std::to_string(generic));

    if (minAreaSquare) logger.log("Min Area Square: " + minAreaSquare->toString());
    if (maxAreaSquare) logger.log("Max Area Square: " + maxAreaSquare->toString());
    if (minPerimeterSquare) logger.log("Min Perimeter Square: " + minPerimeterSquare->toString());
    if (maxPerimeterSquare) logger.log("Max Perimeter Square: " + maxPerimeterSquare->toString());

    if (minAreaRectangle) logger.log("Min Area Rectangle: " + minAreaRectangle->toString());
    if (maxAreaRectangle) logger.log("Max Area Rectangle: " + maxAreaRectangle->toString());
    if (minPerimeterRectangle) logger.log("Min Perimeter Rectangle: " + minPerimeterRectangle->toString());
    if (maxPerimeterRectangle) logger.log("Max Perimeter Rectangle: " + maxPerimeterRectangle->toString());

    if (minAreaRhombus) logger.log("Min Area Rhombus: " + minAreaRhombus->toString());

