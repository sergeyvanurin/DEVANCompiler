//
// Created by deliza on 08.04.2021.
//

#include "PhysicalVariable.h"

PhysicalVariable::PhysicalVariable(Type type, size_t size) {
    if (type.is_array){
        std::get<Array>(value_).resize(size);
    } else {
        if (size != 1)
            throw std::runtime_error("Cringe! Dont' use PhysicalVariable() like this.");
        if (type == Type("int")){
            SetValue(0);
        } else if (type == Type("bool")){
            SetValue(false);
        } else {
            std::get<FieldsMap>(value_);
        }
    }
}

PhysicalVariable::PhysicalVariable(int init_val) {
    SetValue(init_val);
}

PhysicalVariable::PhysicalVariable(bool init_val) {
    SetValue(init_val);
}

int PhysicalVariable::GetInt() const {
    return std::get<int>(value_);
}

void PhysicalVariable::SetValue(int new_val) {
    value_ = new_val;
}

bool PhysicalVariable::GetBool() const {
    return std::get<bool>(value_);
}

void PhysicalVariable::SetValue(bool new_val) {
    value_ = new_val;
}

PhysicalVariable::variant_type PhysicalVariable::GetValue() const {
    return value_;
}

PhysicalVariable::PtrType PhysicalVariable::GetOnIndex(size_t i) {
    return std::get<Array>(value_)[i];
}

void PhysicalVariable::SetOnIndex(size_t i, PhysicalVariable::PtrType new_val) {
    std::get<Array>(value_)[i] = std::move(new_val);
}

void PhysicalVariable::SetField(const std::string &field_name, PhysicalVariable::PtrType new_val) {
    std::get<FieldsMap>(value_)[field_name] = std::move(new_val);
}

PhysicalVariable::PtrType PhysicalVariable::GetField(const std::string &field_name) const {
    return std::get<FieldsMap>(value_).at(field_name);
}

int PhysicalVariable::GetLength() const {
    return std::get<Array>(value_).size();
}

PhysicalVariable::PhysicalVariable() = default;
