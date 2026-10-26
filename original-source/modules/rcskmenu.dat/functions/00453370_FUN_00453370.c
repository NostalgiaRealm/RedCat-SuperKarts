/*
 * FUN_00453370 at 00453370
 * int __register FUN_00453370(int param_1, uint param_2)
 * Address ranges: 00453370-004533bf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00453370(int param_1,uint param_2)

{
  int iVar1;
  
  if (6 < param_2) {
    FUN_00403b34("Assertion failure");
  }
  iVar1 = *(int *)(param_1 + 0x24 + (param_2 & 0x7f) * 4);
  (**(code **)(**(int **)(iVar1 + 0x10) + 0x3c))
            (*(int **)(iVar1 + 0x10),*(undefined1 *)(param_1 + 0x54));
  FUN_00452714(*(int **)(iVar1 + 0x10),*(char *)(param_1 + 0x55));
  FUN_004526fc(*(int **)(iVar1 + 0x10),*(int *)(param_1 + 0x58));
  return iVar1;
}

