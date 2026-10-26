/*
 * FUN_00403b34 at 00403b34
 * undefined __register FUN_00403b34(undefined4 param_1)
 * Address ranges: 00403b34-00403b4d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00403b34(undefined4 param_1)

{
  if (DAT_0047d018 != (code *)0x0) {
    (*DAT_0047d018)();
    return;
  }
  FUN_004027a0(CONCAT31((int3)((uint)param_1 >> 8),0x15));
  return;
}

