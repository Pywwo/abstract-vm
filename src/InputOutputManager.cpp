#include "InputOutputManager.hpp"
#include "VMException.hpp"

AbstractVM::InputOutputManager::InputOutputManager() {

}

AbstractVM::InputOutputManager::~InputOutputManager() {

}

void AbstractVM::InputOutputManager::setMode() {

}

std::vector<std::string> AbstractVM::InputOutputManager::readInput() {

    std::string line;
    std::vector<std::string> filledVec;
    std::ifstream file;

    if (this->getMode() == FILE) {
        file.open(this->getAv());
        if (!file)
            throw InputOutputException("Can't open file given in argument");
        while (std::getline(file, line))
            filledVec.push_back(line);
        file.close();
    } else {
        while (std::getline(std::cin, line)) {
            if (line == ";;")
                break;
            filledVec.push_back(line);
        }
    }
    return filledVec;
}

void AbstractVM::InputOutputManager::outputDisplay() {
    //to delete ?
}

std::string AbstractVM::InputOutputManager::deleteUselessZeros(const std::string &toRevert) {
    if (toRevert.find(".") == std::string::npos)
        return toRevert;
    std::string revert(toRevert);
    std::reverse(revert.begin(), revert.end());
    while (revert.at(0) == '0')
        revert.erase(0, 1);
    std::reverse(revert.begin(), revert.end());
    return revert;
}

void AbstractVM::InputOutputManager::displayFullStack(std::stack<IOperand *> &stack) {
    while (stack.size() > 0) {
        std::cout << deleteUselessZeros(stack.top()->toString()) << std::endl;
        stack.pop();
    }
}

void AbstractVM::InputOutputManager::printOperand(IOperand *operand) {
    char ascii = std::atoi(operand->toString().c_str());
    std::cout << ascii << std::endl;
}

const std::string &AbstractVM::InputOutputManager::getAv() const {
    return _av;
}

void AbstractVM::InputOutputManager::setAv(const std::string &av) {
    _av = av;
}

AbstractVM::MODE AbstractVM::InputOutputManager::getMode() const {
    return _mode;
}

void AbstractVM::InputOutputManager::setMode(AbstractVM::MODE mode) {
    _mode = mode;
}
