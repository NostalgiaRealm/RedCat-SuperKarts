/*
 * FUN_0041383a at 0041383a
 * undefined4 __cdecl FUN_0041383a(LPCSTR param_1, int * param_2, int * param_3)
 * Address ranges: 0041383a-004138b7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_0041383a(LPCSTR param_1,int *param_2,int *param_3)

{
  FILE *pFVar1;
  undefined4 uVar2;
  char local_84 [4];
  short local_80;
  short local_7e;
  short local_7c;
  short local_7a;
  
  pFVar1 = (FILE *)FUN_00409d69(param_1);
  if (pFVar1 == (FILE *)0x0) {
    uVar2 = 1000;
  }
  else {
    FUN_0041f3be(local_84,0x80,1,(int *)pFVar1);
    *param_3 = ((int)local_7a - (int)local_7e) + 1;
    *param_2 = ((int)local_7c - (int)local_80) + 1;
    FUN_00409f20(pFVar1);
    uVar2 = 0;
  }
  return uVar2;
}

