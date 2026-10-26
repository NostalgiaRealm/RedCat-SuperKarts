/*
 * FUN_00413500 at 00413500
 * undefined4 __cdecl FUN_00413500(LPCSTR param_1, int param_2)
 * Address ranges: 00413500-00413621
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00413500(LPCSTR param_1,int param_2)

{
  FILE *pFVar1;
  undefined4 uVar2;
  char local_308 [768];
  int local_8;
  
  pFVar1 = (FILE *)FUN_00409d69(param_1);
  if (pFVar1 == (FILE *)0x0) {
    uVar2 = 1000;
  }
  else {
    FUN_00409b18((int *)pFVar1,-0x300,2);
    FUN_0041f3be(local_308,0x300,1,(int *)pFVar1);
    if ((pFVar1->_flag & 0x20U) != 0) {
      FUN_0040187a((byte *)s__s__d____error_reading_00434c64);
    }
    for (local_8 = 0; local_8 < 0x100; local_8 = local_8 + 1) {
      *(char *)((int)DAT_0043d760 + local_8 * 4) = local_308[local_8 * 3];
      *(char *)((int)DAT_0043d760 + local_8 * 4 + 1) = local_308[local_8 * 3 + 1];
      *(char *)((int)DAT_0043d760 + local_8 * 4 + 2) = local_308[local_8 * 3 + 2];
    }
    if (param_2 != 0) {
      FUN_0040e96f(DAT_0043d760,DAT_0043d760,0,0x100);
    }
    FUN_00409f20(pFVar1);
    uVar2 = 0;
  }
  return uVar2;
}

