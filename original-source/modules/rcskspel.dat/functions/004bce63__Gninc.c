/*
 * std::basic_streambuf<char,std::char_traits<char>_>::_Gninc at 004bce63
 * char * __thiscall _Gninc(basic_streambuf<char,std::char_traits<char>_> * this)
 * Address ranges: 004bce63-004bce72
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  protected: char * __thiscall std::basic_streambuf<char,struct std::char_traits<char> >::_Gninc(void)  Library: Visual Studio 2003 Release
 */

/* Library Function - Single Match
    protected: char * __thiscall std::basic_streambuf<char,struct std::char_traits<char>
   >::_Gninc(void)
   
   Library: Visual Studio 2003 Release */

char * __thiscall
std::basic_streambuf<char,std::char_traits<char>_>::_Gninc
          (basic_streambuf<char,std::char_traits<char>_> *this)

{
  char *pcVar1;
  
  **(int **)(this + 0x2c) = **(int **)(this + 0x2c) + -1;
  pcVar1 = (char *)**(int **)(this + 0x1c);
  **(int **)(this + 0x1c) = (int)(pcVar1 + 1);
  return pcVar1;
}

