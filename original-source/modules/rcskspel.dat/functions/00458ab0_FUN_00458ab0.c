/*
 * FUN_00458ab0 at 00458ab0
 * undefined FUN_00458ab0(void)
 * Address ranges: 00458ab0-00458b19
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_00458ab0(int param_1,int param_2)

{
  char *_Str2;
  int iVar1;
  int iVar2;
  char *_Str1;
  int iVar3;
  
  _Str2 = *(char **)(param_1 + 0x38);
  if (_Str2 == (char *)0x0) {
    _Str2 = "";
  }
  _Str1 = *(char **)(param_2 + 4);
  if (_Str1 == (char *)0x0) {
    _Str1 = "";
  }
  iVar1 = __strcmpi(_Str1,_Str2);
  if (iVar1 != 0) {
    iVar1 = (*(code *)**(undefined4 **)(param_1 + 0x74))();
    iVar3 = 0;
    if (0 < iVar1) {
      do {
        iVar2 = (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 0x78) + 4) + iVar3 * 4) + 0xc))
                          (param_2);
        if (iVar2 != 0) {
          return iVar2;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar1);
    }
    return 0;
  }
  return param_1;
}

