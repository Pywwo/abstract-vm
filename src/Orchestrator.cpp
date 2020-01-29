#include "../include/Orchestrator.hpp"
#include "VMException.hpp"

AbstractVM::Orchestrator::Orchestrator(std::string &av, AbstractVM::Memory &memory, AbstractVM::CPU &cpu,
                                       AbstractVM::InputOutputManager &io) 
: _memory(memory),
  _cpu(cpu),
  _io(io),
  _av(av),
  _hasExit(false)
{
    _list["push"] = &Orchestrator::push;
    _list["pop"] = &Orchestrator::pop;
    _list["clear"] = &Orchestrator::clear;
    _list["dup"] = &Orchestrator::dup;
    _list["swap"] = &Orchestrator::swap;
    _list["dump"] = &Orchestrator::dump;
    _list["assert"] = &Orchestrator::assert;
    _list["add"] = &Orchestrator::add;
    _list["sub"] = &Orchestrator::sub;
    _list["mul"] = &Orchestrator::mul;
    _list["div"] = &Orchestrator::div;
    _list["mod"] = &Orchestrator::mod;
    _list["load"] = &Orchestrator::load;
    _list["store"] = &Orchestrator::store;
    _list["print"] = &Orchestrator::print;
    _list["exit"] = &Orchestrator::exit;
}
AbstractVM::Orchestrator::~Orchestrator() = default;

void AbstractVM::Orchestrator::run() {

    if (_av.empty())
        _io.setMode(INPUT);
    else
        _io.setMode(FILE);
    _io.setAv(_av);
    this->startInputManager();
    execByLine();
}

void AbstractVM::Orchestrator::startInputManager() {

    _listCommands = _io.readInput();
}

std::string AbstractVM::Orchestrator::concatLine(const std::string &toParse)
{
    std::string::size_type pos = toParse.find(" ", 0);

    if (pos != std::string::npos)
        return (toParse.substr(pos + 1));
    return std::string("");
}

std::string AbstractVM::Orchestrator::concatLineComment(const std::string &toParse)
{
    std::string::size_type pos = 0;
    std::string::size_type commentPos = toParse.find(";", 0);
    std::string uncommentedLine;

    if (toParse.at(commentPos - 1) == ' ')
        commentPos -= 1;
    uncommentedLine = toParse.substr(0, commentPos);
    pos = uncommentedLine.find(" ", 0);
    if (pos != std::string::npos)
        uncommentedLine = uncommentedLine.substr(pos + 1);
    else
        uncommentedLine = "";
    return uncommentedLine;
}

void AbstractVM::Orchestrator::execByLine() {

    std::regex regexOnlyComment("^([;]+)");
    std::regex regexDecimal("^(push|assert|load|store) (float|double|bigdecimal)\\(([-]?[0-9]+[.]?[0-9]*)\\)$");
    std::regex regexNonDecimal("^(push|assert|load|store) (int8|int16|int32)\\(([-]?[0-9]+)\\)$");
    std::regex regexOneInstruction("^(pop|clear|dup|swap|dump|add|sub|mul|div|mod|exit|print)$");
    std::regex regexDecimalComment("^(push|assert|load|store) (float|double|bigdecimal)\\(([-]?[0-9]+[.]?[0-9]*)\\)([ ]?[;])");
    std::regex regexNonDecimalComment("^(push|assert|load|store) (int8|int16|int32)\\(([-]?[0-9]+)\\)([ ]?[;])");
    std::regex regexOneInstructionComment("^(pop|clear|dup|swap|dump|add|sub|mul|div|mod|exit|print)([ ]?[;])");
    std::smatch match;

    for (auto it : _listCommands) {
        if (std::regex_search(it, match, regexOnlyComment))
            continue;
        if (std::regex_search(it, match, regexNonDecimal) or std::regex_search(it, match, regexDecimal)) {
            std::string end = concatLine(it);
            (this->*(_list[match[1]]))(end);
        } else if (std::regex_search(it, match, regexOneInstruction)) {
            std::string end = concatLine(it);
            (this->*(_list[match[0]]))(end);
        } else if (std::regex_search(it, match, regexDecimalComment) or std::regex_search(it, match, regexNonDecimalComment)) {
            std::string end = concatLineComment(it);
            (this->*(_list[match[1]]))(end);
        } else if (std::regex_search(it, match, regexOneInstructionComment)) {
            std::string end = concatLineComment(it);
            (this->*(_list[match[1]]))(end);
        } else {
            throw OrchestratorException("Wrong line : " + it);
        }
    }
    if (_hasExit == false)
        throw OrchestratorException("Error : no exit at the end");
}

AbstractVM::eOperandType AbstractVM::Orchestrator::getRightType(const std::string &type) {
    if (type == "int8") {
        return eOperandType::INT8;
    } else if (type == "int16") {
        return eOperandType::INT16;
    } else if (type == "int32") {
        return eOperandType::INT32;
    } else if (type == "double") {
        return eOperandType::DOUBLE;
    } else if (type == "float") {
        return eOperandType::FLOAT;
    } else if (type == "bigdecimal") {
        return eOperandType::BIGDECIMAL;
    } else
        throw OrchestratorException("Invalid behavior on type");
}

bool AbstractVM::Orchestrator::isOverflowOrUnderflow(AbstractVM::eOperandType type, const std::string &number)
{
    double test = std::atof(number.c_str());

    if (type == INT8) {
        if (std::numeric_limits<int8_t>::max() >= test && std::numeric_limits<int8_t>::min() <= test)
            return false;
    } else if (type == INT16) {
        if (std::numeric_limits<int16_t>::max() >= test && std::numeric_limits<int16_t>::min() <= test)
            return false;
    } else if (type == INT32) {
        if (std::numeric_limits<int32_t>::max() >= test && std::numeric_limits<int32_t>::min() <= test)
            return false;
    } else if (type == DOUBLE) {
        if (std::numeric_limits<double>::max() >= test && std::numeric_limits<double>::max() * -1 <= test)
            return false;
    } else if (type == FLOAT) {
        if (std::numeric_limits<float>::max() >= test && std::numeric_limits<float>::max() * -1 <= test)
            return false;
    } else if (type == BIGDECIMAL) {
        if (std::numeric_limits<float>::max() >= test && std::numeric_limits<float>::max() * -1 <= test)
            return false;
    } else
        throw OrchestratorException("Invalid behavior on type");
    return true;
}

void AbstractVM::Orchestrator::push(std::string &value) {
    std::string type = value.substr(0, value.find_first_of('('));
    std::string number = value.substr(value.find_first_of('(') + 1);

    number.pop_back();
    eOperandType typeEnum = getRightType(type);
    if (isOverflowOrUnderflow(typeEnum, number))
        throw OrchestratorException("Overflow or underflow");
    IOperand *toPush = Factory::createOperand(typeEnum, number);
    _memory.push(toPush);
}

void AbstractVM::Orchestrator::pop(std::string &value) {
    IOperand *top = _memory.pop();
    delete top;
    value = value;
}

void AbstractVM::Orchestrator::clear(std::string &value) {
    _memory.clear();
    value = value;
}

void AbstractVM::Orchestrator::dup(std::string &value) {
    _memory.dup();
    value = value;
}

void AbstractVM::Orchestrator::swap(std::string &value) {
    _memory.swap();
    value = value;
}

void AbstractVM::Orchestrator::dump(std::string &value) {
    std::stack<IOperand *> stackCopy = _memory.getStack();
    _io.displayFullStack(stackCopy);
    value = value;
}

void AbstractVM::Orchestrator::assert(std::string &value) {
    std::string type = value.substr(0, value.find_first_of('('));
    std::string number = value.substr(value.find_first_of('(') + 1);

    number.pop_back();
    number = _io.deleteUselessZeros(number);
    if (!_memory.assert(number, type))
        throw OrchestratorException("Assertion failed");
}

void AbstractVM::Orchestrator::add(std::string &value) {
    IOperand *first = _memory.pop();
    IOperand *second = _memory.pop();
    IOperand *result = _cpu.add(first, second);

    _memory.push(result);
    value = value;
}

void AbstractVM::Orchestrator::sub(std::string &value) {
    IOperand *first = _memory.pop();
    IOperand *second = _memory.pop();
    IOperand *result = _cpu.sub(first, second);

    _memory.push(result);
    value = value;
}

void AbstractVM::Orchestrator::mul(std::string &value) {
    IOperand *first = _memory.pop();
    IOperand *second = _memory.pop();
    IOperand *result = _cpu.mul(first, second);

    _memory.push(result);
    value = value;
}

void AbstractVM::Orchestrator::div(std::string &value) {
    IOperand *first = _memory.pop();
    IOperand *second = _memory.pop();
    IOperand *result = _cpu.div(first, second);

    _memory.push(result);
    value = value;
}

void AbstractVM::Orchestrator::mod(std::string &value) {
    IOperand *first = _memory.pop();
    IOperand *second = _memory.pop();
    IOperand *result = _cpu.mod(first, second);

    _memory.push(result);
    value = value;
}

void AbstractVM::Orchestrator::load(std::string &value) {
    std::string type = value.substr(0, value.find_first_of('('));
    std::string number = value.substr(value.find_first_of('(') + 1);

    number.pop_back();
    IOperand *newTop = _cpu.loadFromRegister(std::atoi(number.c_str()));
    _memory.push(newTop);
}

void AbstractVM::Orchestrator::store(std::string &value) {
    std::string type = value.substr(0, value.find_first_of('('));
    std::string number = value.substr(value.find_first_of('(') + 1);

    number.pop_back();
    IOperand *first = _memory.pop();
    if (first->getType() != getRightType(type))
        throw OrchestratorException("invalid Type to store");
    _cpu.storeInRegister(std::atoi(number.c_str()), first);
}

void AbstractVM::Orchestrator::print(std::string &) {
    IOperand *check = _memory.getFirstValueOfStack();
    if (check->getType() != INT8)
        throw OrchestratorException("You tried to use print on more than 8-bit int. Sorry but you can't");
    _io.printOperand(check);
}

void AbstractVM::Orchestrator::exit(std::string &) {
    _hasExit = true;
}