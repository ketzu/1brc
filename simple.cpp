#include <iostream>
#include <fstream>
#include <unordered_map>

// Essentially uses the same approach as the python one
class measurement {
public:
    double min;
    double max;
    uint64_t count;
    double total;
};

int main() {
    std::unordered_map<std::string, measurement> measurements;
    std::string line;
    // Yes, still hardcoded
    std::ifstream file(R"(D:\dev\1brc\measurements.txt)");
    while (getline(file, line) ) {
        // line format: "name;value"
        auto pos = line.find(';');
        double value = std::stod(line.substr(pos + 1));
        auto name = line.substr(0, pos);
        if(!measurements.contains(name)) {
            measurements[name] = measurement{value, value, 1, value};
        }else{
            auto& m = measurements[name];
            m.min = std::min(m.min, value);
            m.max = std::max(m.max, value);
            m.count++;
            m.total += value;
        }
    }
    // I was too lazy to add sorting as required for the original challenge
    for (const auto& [name, m] : measurements) {
        std::cout << name << " min: " << m.min << " max: " << m.max << " avg: " << m.total / m.count << "\n";
    }
}
