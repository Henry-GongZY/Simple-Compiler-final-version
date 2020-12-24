#include "type.h"

Type::Type(ValueType valueType) {
    this->type = valueType;
}

string Type::getTypeInfo() {
    switch(this->type) {
        case VALUE_BOOL:
            return "bool";
        case VALUE_INT:
            return "int";
        case VALUE_CHAR:
            return "char";
        case VALUE_STRING:
            return "string";
        case VALUE_DOUBLE:
            return "double";
        case VALUE_VOID:
            return "void";
        default:
            cerr << "shouldn't reach here, typeinfo";
            return "no type or error";
    }
    return "?";
}