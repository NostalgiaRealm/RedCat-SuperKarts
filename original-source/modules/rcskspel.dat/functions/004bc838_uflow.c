/*
 * std::basic_streambuf<char,std::char_traits<char>_>::uflow at 004bc838
 * int __thiscall uflow(basic_streambuf<char,std::char_traits<char>_> * this)
 * Address ranges: 004bc838-004bc854
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  protected: virtual int __thiscall std::basic_streambuf<char,struct std::char_traits<char> >::uflow(void)  Library: Visual Studio 2003 Release
 */

/* Library Function - Single Match
    protected: virtual int __thiscall std::basic_streambuf<char,struct std::char_traits<char>
   >::uflow(void)
   
   Library: Visual Studio 2003 Release */

int __thiscall
std::basic_streambuf<char,std::char_traits<char>_>::uflow
          (basic_streambuf<char,std::char_traits<char>_> *this)

{
  int iVar1;
  byte *pbVar2;
  
  iVar1 = (**(code **)(*(int *)this + 0x10))();
  if (iVar1 == -1) {
    return -1;
  }
  pbVar2 = (byte *)_Gninc(this);
  return (uint)*pbVar2;
}

