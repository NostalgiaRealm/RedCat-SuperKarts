/*
 * exception::~exception at 004bfe36
 * void __thiscall ~exception(exception * this)
 * Address ranges: 004bfe36-004bfe4b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  public: virtual __thiscall exception::~exception(void)  Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release
 */

/* Library Function - Single Match
    public: virtual __thiscall exception::~exception(void)
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

void __thiscall exception::~exception(exception *this)

{
  *(undefined ***)this = &PTR_FUN_004d373c;
  if (*(int *)(this + 8) != 0) {
    FUN_004bc150(*(undefined4 *)(this + 4));
  }
  return;
}

