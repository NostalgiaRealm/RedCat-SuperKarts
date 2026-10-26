/*
 * FUN_0041f210 at 0041f210
 * undefined __fastcall FUN_0041f210(int * param_1)
 * Address ranges: 0041f210-0041f240
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0041f210(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_0041f0f0((int)(param_1 + 1));
  if (iVar1 != 0) {
    iVar1 = FUN_0041f0f0((int)(param_1 + 6));
    if (iVar1 != 0) {
      (**(code **)*param_1)();
      (**(code **)(*param_1 + 4))();
      (**(code **)(*param_1 + 8))();
    }
  }
  return;
}

