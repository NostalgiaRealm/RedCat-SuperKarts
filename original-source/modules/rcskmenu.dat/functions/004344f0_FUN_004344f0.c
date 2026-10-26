/*
 * FUN_004344f0 at 004344f0
 * undefined FUN_004344f0(void)
 * Address ranges: 004344f0-00434534
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004344f0(int param_1,int *param_2)

{
  bool bVar1;
  code *pcVar2;
  code *pcVar3;
  int iVar4;
  
  FUN_00414b00(param_1,param_2);
  pcVar3 = FUN_0043485c;
  pcVar2 = FUN_004348e4;
  iVar4 = param_1;
  bVar1 = FUN_00434494();
  (**(code **)(*param_2 + 8))(param_2,"Bitmap",bVar1,pcVar2,param_1,pcVar3,iVar4);
  return;
}

