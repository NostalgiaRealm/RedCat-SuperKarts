/*
 * std::locale::facet::_Decref at 004bc804
 * facet * __thiscall _Decref(facet * this)
 * Address ranges: 004bc804-004bc81f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  public: class std::locale::facet * __thiscall std::locale::facet::_Decref(void)  Library: Visual Studio 2003 Release
 */

/* Library Function - Single Match
    public: class std::locale::facet * __thiscall std::locale::facet::_Decref(void)
   
   Library: Visual Studio 2003 Release */

facet * __thiscall std::locale::facet::_Decref(facet *this)

{
  int iVar1;
  
  iVar1 = *(int *)(this + 4);
  if ((iVar1 != 0) && (iVar1 != -1)) {
    *(int *)(this + 4) = iVar1 + -1;
  }
  return (facet *)(~-(uint)(*(int *)(this + 4) != 0) & (uint)this);
}

