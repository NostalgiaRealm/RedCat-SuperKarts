/*
 * FUN_0041635e at 0041635e
 * int __cdecl FUN_0041635e(int param_1, int param_2, int param_3, byte * param_4)
 * Address ranges: 0041635e-004163be
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_0041635e(int param_1,int param_2,int param_3,byte *param_4)

{
  int iVar1;
  byte local_194 [400];
  
  iVar1 = FUN_0041f64a(local_194,param_4,(undefined4 *)&stack0x00000014);
  FUN_0041603c(param_1,param_2,param_3,local_194);
  return iVar1;
}

