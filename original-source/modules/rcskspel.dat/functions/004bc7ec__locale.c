/*
 * std::locale::~locale at 004bc7ec
 * void __thiscall ~locale(locale * this)
 * Address ranges: 004bc7ec-004bc803
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  public: __thiscall std::locale::~locale(void)  Library: Visual Studio 2003 Release
 */

/* Library Function - Single Match
    public: __thiscall std::locale::~locale(void)
   
   Library: Visual Studio 2003 Release */

void __thiscall std::locale::~locale(locale *this)

{
  facet *pfVar1;
  
  if (*(facet **)this != (facet *)0x0) {
    pfVar1 = facet::_Decref(*(facet **)this);
    if (pfVar1 != (facet *)0x0) {
      (*(code *)**(undefined4 **)pfVar1)(1);
    }
  }
  return;
}

