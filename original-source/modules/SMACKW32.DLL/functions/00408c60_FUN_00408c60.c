/*
 * FUN_00408c60 at 00408c60
 * longlong __fastcall FUN_00408c60(undefined4 param_1, uint param_2)
 * Address ranges: 00408c60-00408c73;00408cfc-00408d24
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

longlong __fastcall FUN_00408c60(undefined4 param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  (*(code *)PTR_FUN_0040ef60)();
  piVar3 = DAT_0040e864;
  while (piVar3 != (int *)0x0) {
    iVar2 = *piVar3;
    piVar1 = piVar3 + 9;
    piVar3 = (int *)piVar3[2];
    if (iVar2 + -0x2c == *(int *)*piVar1) {
      FUN_00408cd2(iVar2 + -0x2c);
    }
  }
  (*(code *)PTR_FUN_0040ef68)();
  return (ulonglong)param_2 << 0x20;
}

