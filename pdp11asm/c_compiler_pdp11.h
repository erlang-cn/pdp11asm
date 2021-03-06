// PDP11 Assembler (c) 08-01-2017 ALeksey Morozov (aleksey.f.morozov@gmail.com)

#pragma once

#include "c_asm_pdp11.h"
#include "c_tree.h"
#include "compiler.h"
#include "queue"

namespace C
{

class CompilerPdp11 {
public:
    class IfOpt {
    public:
        bool ifTrue;
        bool ok;
        unsigned label;
    };

    AsmPdp11 out;
    Compiler& compiler;
    Tree& tree;

    std::queue<size_t> writePtrs;

    Function* curFn;
    unsigned  inStack;
    unsigned  returnLabel;

    CompilerPdp11(Compiler& _compiler, Tree& _world);
    void pushAcc(char pf);
    void popAcc(char pf);
    void popAcc_A2D(char pf);
    bool compileArg(bool check, Arg11& ol, Arg11& oh, NodeVar* a, int d, int dr, char pf);
    bool compileDualArg(Arg11& al, Arg11& ah, Arg11& bl, Arg11& bh, bool s, unsigned d, NodeOperator *r, char pf);
    void compileJump(NodeVar* v, int d, bool ifTrue, unsigned label);
    void compileVar(Node* n, unsigned d, IfOpt* ifOpt=0);
    void compileBlock(Node* n);
    void compileFunction(Function* f);
    bool can_shift(NodeOperator *r);
    void shift(const Arg11& al, const Arg11& ah, const Arg11& bl, bool r, char pf);

public:
    void start(unsigned step);
};

}
