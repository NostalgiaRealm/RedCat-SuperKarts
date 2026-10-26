/*
 * FUN_00409fc5 at 00409fc5
 * undefined4 __cdecl FUN_00409fc5(LPCSTR param_1)
 * Address ranges: 00409fc5-0040a087
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00409fc5(LPCSTR param_1)

{
  FILE *pFVar1;
  undefined4 uVar2;
  int iVar3;
  int local_8;
  
  if ((DAT_0043d468 == 0) || (DAT_0043d46c == 1)) {
    pFVar1 = (FILE *)FUN_0041f4c6(param_1,&DAT_004313c8);
    if (pFVar1 == (FILE *)0x0) {
      uVar2 = 0;
    }
    else {
      FUN_0041f368(pFVar1);
      uVar2 = 1;
    }
  }
  else {
    for (local_8 = 0; local_8 < DAT_0043d45c; local_8 = local_8 + 1) {
      iVar3 = __strcmpi((char *)(DAT_0043d460 + local_8 * 0x1c),param_1);
      if (iVar3 == 0) {
        return 1;
      }
    }
    pFVar1 = (FILE *)FUN_0041f4c6(param_1,&DAT_004313cc);
    if (pFVar1 == (FILE *)0x0) {
      uVar2 = 0;
    }
    else {
      FUN_0041f368(pFVar1);
      uVar2 = 1;
    }
  }
  return uVar2;
}

