/*
 * FUN_00431338 at 00431338
 * undefined __register FUN_00431338(int param_1, int param_2)
 * Address ranges: 00431338-00431397
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00431338(int param_1,int param_2)

{
  if (param_2 == *(int *)(param_1 + 0x38)) {
    *(undefined4 *)(param_1 + 0x38) = 0;
  }
  if (param_2 == *(int *)(param_1 + 0x3c)) {
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  if (param_2 == *(int *)(DAT_0047d774 + 0x58)) {
    *(undefined4 *)(DAT_0047d774 + 0x58) = 0;
  }
  if (param_2 == *(int *)(DAT_0047d774 + 0x5c)) {
    *(undefined4 *)(DAT_0047d774 + 0x5c) = 0;
    *(undefined4 *)(DAT_0047d774 + 0x60) = 0;
  }
  if (param_2 == *(int *)(DAT_0047d774 + 0x6c)) {
    *(undefined4 *)(DAT_0047d774 + 0x6c) = 0;
  }
  if (param_2 == *(int *)(param_1 + 0x50)) {
    *(undefined4 *)(param_1 + 0x50) = 0;
  }
  FUN_004301fc(DAT_0047d774);
  return;
}

