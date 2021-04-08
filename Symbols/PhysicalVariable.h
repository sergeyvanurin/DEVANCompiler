//
// Created by deliza on 08.04.2021.
//

#ifndef DEVANCOMPILER_PHYSICALVARIABLE_H
#define DEVANCOMPILER_PHYSICALVARIABLE_H

#include <SymbolTable/ScopeLayer.h>

#include <utility>
#include "Type.h"

class PhysicalVariable {
public:
    using PtrType = std::shared_ptr<PhysicalVariable>;
    using FieldsMap = std::unordered_map<std::string, PtrType>;
    using Array = std::vector<PtrType>;
    using variant_type = std::variant<FieldsMap, int, bool, Array>;

    explicit PhysicalVariable(int init_val);

    explicit PhysicalVariable(bool init_val);

    explicit PhysicalVariable(Type type, size_t size = 1);

    int GetInt() const;

    void SetValue(int new_val);

    bool GetBool() const;

    void SetValue(bool new_val);

    variant_type GetValue() const;

    PtrType GetOnIndex(size_t i);

    void SetOnIndex(size_t i, PtrType new_val);

    void SetField(const std::string& field_name, PtrType new_val);

    PtrType GetField(const std::string& field_name) const;

    int GetLength() const;

private:
    PhysicalVariable();
    variant_type value_;
};


#endif //DEVANCOMPILER_PHYSICALVARIABLE_H
