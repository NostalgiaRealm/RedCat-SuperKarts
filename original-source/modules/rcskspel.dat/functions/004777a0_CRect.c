/*
 * CRect::CRect at 004777a0
 * undefined __thiscall CRect(CRect * this, int param_1, int param_2, int param_3, int param_4)
 * Address ranges: 004777a0-004777bf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  public: __thiscall CRect::CRect(int,int,int,int)  Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release
 */

/* Library Function - Single Match
    public: __thiscall CRect::CRect(int,int,int,int)
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release */

void __thiscall CRect::CRect(CRect *this,int param_1,int param_2,int param_3,int param_4)

{
  *(int *)this = param_1;
  *(int *)(this + 4) = param_2;
  *(int *)(this + 8) = param_3;
  *(int *)(this + 0xc) = param_4;
  return;
}

