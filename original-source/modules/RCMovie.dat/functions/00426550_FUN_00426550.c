/*
 * FUN_00426550 at 00426550
 * int __cdecl FUN_00426550(uchar * param_1)
 * Address ranges: 00426550-004265cc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_00426550(uchar *param_1)

{
  int iVar1;
  size_t _MaxCount;
  size_t sVar2;
  int *piVar3;
  
  if (((DAT_0043f924 != 0) &&
      ((DAT_0043e2e8 != (int *)0x0 ||
       (((DAT_0043e2f0 != 0 && (iVar1 = FUN_0042712b(), iVar1 == 0)) && (DAT_0043e2e8 != (int *)0x0)
        ))))) && (piVar3 = DAT_0043e2e8, param_1 != (uchar *)0x0)) {
    _MaxCount = _strlen((char *)param_1);
    for (; (char *)*piVar3 != (char *)0x0; piVar3 = piVar3 + 1) {
      sVar2 = _strlen((char *)*piVar3);
      if (((_MaxCount < sVar2) && (((uchar *)*piVar3)[_MaxCount] == '=')) &&
         (iVar1 = __mbsnbicoll((uchar *)*piVar3,param_1,_MaxCount), iVar1 == 0)) {
        return *piVar3 + 1 + _MaxCount;
      }
    }
  }
  return 0;
}

