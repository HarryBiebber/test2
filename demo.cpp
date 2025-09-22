#include <iostream>
#include <string>
#include <vector>

// 使用我们之前定义的 Pin 结构体
struct Pin {
    std::string name;
    std::string direction;
};

// 1. 定义一个 StandardCell 类
class StandardCell {
// public: 部分是类的“对外接口”，任何地方都可以访问
public:
    // 构造函数：一个特殊的函数，在创建对象时自动被调用，用于初始化
    StandardCell(const std::string& cell_name, double cell_area) {
        name = cell_name;
        area = cell_area;
        std::cout << "一个名为 " << name << " 的标准单元被创建了！" << std::endl;
    }

    // 成员函数：定义了类的“行为”
    void add_pin(const Pin& new_pin) {
        pins.push_back(new_pin);
    }

    void print_info() {
        std::cout << "--- Cell Info ---" << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Area: " << area << std::endl;
        std::cout << "Pins: " << std::endl;
        for (const auto& p : pins) {
            std::cout << "  - " << p.name << " (" << p.direction << ")" << std::endl;
        }
    }

// private: 部分是类的“内部数据”，只能被自己的成员函数访问
private:
    std::string name;           // 成员变量 (属性)
    double area;                // 成员变量 (属性)
    std::vector<Pin> pins;      // 成员变量 (属性)
};

int main() {
    // 2. 根据 StandardCell 类蓝图，创建两个具体的对象
    StandardCell inv_x1("INV_X1", 1.2); // 调用构造函数创建反相器
    StandardCell nand2_x1("NAND2_X1", 1.8); // 创建与非门

    // 3. 使用对象的成员函数
    inv_x1.add_pin( {"A", "input"} );
    inv_x1.add_pin( {"Y", "output"} );
    
    nand2_x1.add_pin( {"A1", "input"} );
    nand2_x1.add_pin( {"A2", "input"} );
    nand2_x1.add_pin( {"Y", "output"} );

    // 4. 调用对象的行为来显示信息
    inv_x1.print_info();
    nand2_x1.print_info();

    return 0;
}