/*
 * FUN_00458480 at 00458480
 * undefined FUN_00458480(void)
 * Address ranges: 00458480-004584b4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __thiscall FUN_00458480(uint param_1,int param_2)

{
  char *_Str2;
  int iVar1;
  char *_Str1;
  
  _Str2 = *(char **)(param_1 + 0x38);
  if (_Str2 == (char *)0x0) {
    _Str2 = "";
  }
  _Str1 = *(char **)(param_2 + 4);
  if (_Str1 == (char *)0x0) {
    _Str1 = "";
  }
  iVar1 = __strcmpi(_Str1,_Str2);
  return ~-(uint)(iVar1 != 0) & param_1;
}

