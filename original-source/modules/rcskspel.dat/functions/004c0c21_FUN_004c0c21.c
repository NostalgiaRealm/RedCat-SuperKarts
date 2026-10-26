/*
 * FUN_004c0c21 at 004c0c21
 * undefined FUN_004c0c21(void)
 * Address ranges: 004c0c21-004c0c9d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004c0c21(uchar *param_1)

{
  int iVar1;
  size_t _MaxCount;
  size_t sVar2;
  int *piVar3;
  
  if (((DAT_006b7dc8 != 0) &&
      ((DAT_006b6710 != (int *)0x0 ||
       (((DAT_006b6718 != 0 && (iVar1 = FUN_004c8787(), iVar1 == 0)) && (DAT_006b6710 != (int *)0x0)
        ))))) && (piVar3 = DAT_006b6710, param_1 != (uchar *)0x0)) {
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

