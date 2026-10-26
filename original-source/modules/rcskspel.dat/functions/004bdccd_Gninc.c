/*
 * Gninc at 004bdccd
 * undefined Gninc(void)
 * Address ranges: 004bdccd-004bdcdc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Multiple Matches With Same Base Name  protected: unsigned short * __thiscall std::basic_streambuf<unsigned short,struct std::char_traits<unsigned short> >::_Gninc(void)  protected: wchar_t * __thiscall std::basic_streambuf<wchar_t,struct std::char_traits<wchar_t> >::_Gninc(void)  Library: Visual Studio 2003 Release
 */

/* Library Function - Multiple Matches With Same Base Name
    protected: unsigned short * __thiscall std::basic_streambuf<unsigned short,struct
   std::char_traits<unsigned short> >::_Gninc(void)
    protected: wchar_t * __thiscall std::basic_streambuf<wchar_t,struct std::char_traits<wchar_t>
   >::_Gninc(void)
   
   Library: Visual Studio 2003 Release */

void __fastcall Gninc(int param_1)

{
  **(int **)(param_1 + 0x2c) = **(int **)(param_1 + 0x2c) + -1;
  **(int **)(param_1 + 0x1c) = **(int **)(param_1 + 0x1c) + 2;
  return;
}

