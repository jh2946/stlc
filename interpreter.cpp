#include <iostream>
#include <vector>

typedef uint64_t Param; // variables in traditional stlc
typedef uint64_t Global; // similar to global variables in c++. substitute in before beta-redn in full evaluation
typedef uint64_t TypeIndex;
typedef uint64_t ExpressionIndex;

enum BaseType {
    u64,
    b1,
};

struct BaseValue {
    BaseType form;
    union {
        uint64_t u64_val;
        bool b1_val;
    } content;
};

enum TyD { // tag for `Type`
    atom,
    arrow,
};

struct Type {
    TyD form;
    union {
        BaseType atom; // e.g. u64, b1
        struct { Type* a; Type* b; } arrow; // e.g. u64 -> u64, u64 -> u64 -> b1
    } content;
};

enum ExpD { // tag for `Expression`
    val,
    efunc,
    param,
    glob,
    appl,
    abst,
};

struct BaseFunction { // stores implementation of function
    Type* type;
    Expression (*implement)(std::vector<Expression>);
};

struct EffectiveFunction { // 
    BaseFunction* src;
    std::vector<Expression> args;
};

struct World {
    std::vector<Expression> globals; // enforce that all global expressions are valid; see `can_be_global`
};

struct Expression {
    const ExpD form;
    const union {
        BaseValue val; // see `BaseValue`
        EffectiveFunction efunc; // see `EffectiveFunction`
        Param param; // see `Param`
        uint64_t glob;
        struct { Expression* m; Expression* n; } appl; // two expressions side-by-side for potential beta-redn
        struct { Param x; Expression* m; } abst; // lambda func definition
    } content;
    const Type* type;
};

bool is_closed(const Expression &exp) {
    // TODO: implement
    return true;
}

bool can_be_global(const Expression &exp) {
    if (!is_closed(exp)) return false;
    // TODO: implement
    return true;
}

Expression full_evaluation(const Expression &exp) {

}
