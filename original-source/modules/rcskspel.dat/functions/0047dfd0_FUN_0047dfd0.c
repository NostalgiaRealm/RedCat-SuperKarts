/*
 * FUN_0047dfd0 at 0047dfd0
 * undefined FUN_0047dfd0(void)
 * Address ranges: 0047dfd0-0047e022
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0047dfd0(int param_1)

{
  int *piVar1;
  char *_Str1;
  int iVar2;
  char *_Str2;
  int *piVar3;
  
  if (DAT_00544fd8 != 0) {
    piVar3 = &DAT_00544fd4;
    do {
      _Str2 = "";
      if ((char *)*piVar3 != (char *)0x0) {
        _Str2 = (char *)*piVar3;
      }
      _Str1 = *(char **)(param_1 + 4);
      if (_Str1 == (char *)0x0) {
        _Str1 = "";
      }
      iVar2 = __strcmpi(_Str1,_Str2);
      if (iVar2 == 0) {
        return 1;
      }
      piVar1 = piVar3 + 6;
      piVar3 = piVar3 + 5;
    } while (*piVar1 != 0);
  }
  return 0;
}

