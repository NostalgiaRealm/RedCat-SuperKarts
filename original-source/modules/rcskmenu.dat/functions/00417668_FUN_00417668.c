/*
 * FUN_00417668 at 00417668
 * undefined __register FUN_00417668(int param_1, undefined4 * param_2)
 * Address ranges: 00417668-0041767f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00417668(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = (undefined4 *)(*(int *)(param_1 + 0x10) + 0x10);
  puVar3 = param_2;
  for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *param_2 = 0;
  return;
}

