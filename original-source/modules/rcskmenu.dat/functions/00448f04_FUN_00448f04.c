/*
 * FUN_00448f04 at 00448f04
 * undefined __register FUN_00448f04(int param_1, int param_2, int param_3)
 * Address ranges: 00448f04-00448f2e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00448f04(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = &stack0xfffffffc;
  if (param_2 == 0) {
    param_2 = *(int *)(*(int *)(param_1 + 100) + 8);
  }
  FUN_00448e9c(param_2,param_2,param_3,(int)&stack0xfffffffc);
  iVar1 = **(int **)(param_1 + 0x14);
  (**(code **)(iVar1 + 0x74))(*(int **)(param_1 + 0x14),iVar1,puVar2);
  return;
}

