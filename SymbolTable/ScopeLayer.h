//
// Created by deliza on 05.04.2021.
//

#ifndef DEVANCOMPILER_SCOPELAYER_H
#define DEVANCOMPILER_SCOPELAYER_H

#include "Symbols/BaseSymbol.h"
#include "Objects/Object.h"

#include <unordered_map>
#include <string>
#include <stack>
#include <memory>
#include <vector>
#include <Symbols/STVariable.h>
#include <Symbols/STMethod.h>
#include <Symbols/STClass.h>

class ScopeLayer {
public:
    explicit ScopeLayer(ScopeLayer* parent);
    ScopeLayer();

    void DeclareVariable(const STVariable& symbol);

    ScopeLayer* AddChild(ScopeLayer* child);

    ScopeLayer* GetChild(size_t index);
    ScopeLayer* GetParent() const;

    void DeclareClass(const STClass& class_decl);

    bool HasVariableAtLayer(const std::string& var_name) const;

    void EnterClass(const STClass* cur_class);
    void EnterMethod(const STMethod* cur_method);

    const STClass* GetCurrentClass() const;
    const STMethod* GetCurrentMethod() const;

    STClass* GetClassByName(const std::string& class_name);

    STVariable* GetVariableByName(const std::string& var_name);

private:
    std::unordered_map<STVariable, std::shared_ptr<Object>> values_;

    std::unordered_map<std::string, STVariable> variables_;
    std::unordered_map<std::string, STClass> classes_;

    const STClass* current_class_ = nullptr;
    const STMethod* current_method_ = nullptr;

    //std::vector<BaseSymbol> symbols_;
    //std::string name_;

    ScopeLayer* parent_;
    std::vector<ScopeLayer*> children_;
};


#endif //DEVANCOMPILER_SCOPELAYER_H
