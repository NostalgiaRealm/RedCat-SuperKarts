/*
 * FUN_00432e8c at 00432e8c
 * undefined __register FUN_00432e8c(int param_1)
 * Address ranges: 00432e8c-00432eb2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00432e8c(int param_1)

{
  if (*(int *)(param_1 + 0x50) != 0) {
    FUN_00432e50(param_1);
    *(undefined4 *)(param_1 + 0x50) = 0;
    *(undefined1 *)(param_1 + 0x48) = 0;
    FUN_00430e2c();
    FUN_00432cf0(param_1);
  }
  return;
}

