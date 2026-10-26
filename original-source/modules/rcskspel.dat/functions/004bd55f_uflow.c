/*
 * uflow at 004bd55f
 * undefined uflow(void)
 * Address ranges: 004bd55f-004bd57f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Multiple Matches With Same Base Name  protected: virtual unsigned short __thiscall std::basic_streambuf<unsigned short,struct std::char_traits<unsigned short> >::uflow(void)  protected: virtual unsigned short __thiscall std::basic_streambuf<wchar_t,struct std::char_traits<wchar_t> >::uflow(void)  Library: Visual Studio 2003 Release
 */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual unsigned short __thiscall std::basic_streambuf<unsigned short,struct
   std::char_traits<unsigned short> >::uflow(void)
    protected: virtual unsigned short __thiscall std::basic_streambuf<wchar_t,struct
   std::char_traits<wchar_t> >::uflow(void)
   
   Library: Visual Studio 2003 Release */

undefined2 __fastcall uflow(int *param_1)

{
  short sVar1;
  undefined2 *puVar2;
  
  sVar1 = (**(code **)(*param_1 + 0x10))();
  if (sVar1 == -1) {
    return 0xffff;
  }
  puVar2 = (undefined2 *)Gninc();
  return *puVar2;
}

