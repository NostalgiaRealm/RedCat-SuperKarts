/*
 * FUN_004163bf at 004163bf
 * int __cdecl FUN_004163bf(int param_1, int param_2, int param_3, int param_4, int param_5, byte * param_6)
 * Address ranges: 004163bf-00416427
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_004163bf(int param_1,int param_2,int param_3,int param_4,int param_5,byte *param_6)

{
  int iVar1;
  byte local_194 [400];
  
  iVar1 = FUN_0041f64a(local_194,param_6,(undefined4 *)&stack0x0000001c);
  FUN_004161c8(param_1,param_2,param_3,param_4,param_5,local_194);
  return iVar1;
}

