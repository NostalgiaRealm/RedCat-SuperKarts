/*
 * FUN_0041cf14 at 0041cf14
 * undefined __register FUN_0041cf14(int param_1)
 * Address ranges: 0041cf14-0041cf23
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041cf14(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x20);
  if (*(int *)(iVar1 + 8) == 0) {
    *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar1 + 0x14);
  }
  return;
}

