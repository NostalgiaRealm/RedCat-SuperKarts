/*
 * FUN_00438084 at 00438084
 * undefined4 __register FUN_00438084(int param_1)
 * Address ranges: 00438084-00438091
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00438084(int param_1)

{
  if (*(int *)(param_1 + 0x50) == 0) {
    return 0;
  }
  return *(undefined4 *)(*(int *)(param_1 + 0x50) + 8);
}

