/*
 * FUN_00401000 at 00401000
 * undefined4 __cdecl FUN_00401000(LPCSTR param_1)
 * Address ranges: 00401000-00401082
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00401000(LPCSTR param_1)

{
  FILE *pFVar1;
  int iVar2;
  
  pFVar1 = (FILE *)FUN_0041f4c6(param_1,&DAT_0042c09c);
  if (pFVar1 == (FILE *)0x0) {
    return 0;
  }
  FUN_0041f3be((char *)&param_1,3,1,(int *)pFVar1);
  FUN_0041f368(pFVar1);
  iVar2 = _strncmp((char *)&param_1,&DAT_0042c098,3);
  if (iVar2 == 0) {
    FUN_004015a6((byte *)s__s__d__MovieFormat_of__s___SMK_0042c060);
    return 1;
  }
  FUN_004015a6((byte *)s__s__d__MovieFormat_of__s___AVI_0042c040);
  return 2;
}

