/*
 * FUN_00409140 at 00409140
 * undefined FUN_00409140(void)
 * Address ranges: 00409140-004091ae
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00409140(int param_1)

{
  uint uVar1;
  
  if (*(float *)(&DAT_00505124 + param_1 * 0x24) < 0.0) {
    uVar1 = *(uint *)(&DAT_00505114 + param_1 * 0x24) & 3;
    if (uVar1 == 1) {
      (&DAT_0050510c)[param_1 * 9] = 0;
    }
    else if (uVar1 == 2) {
      (&DAT_0050510c)[param_1 * 9] = 4;
    }
    else if (uVar1 == 3) {
      (&DAT_0050510c)[param_1 * 9] = 5;
    }
    *(undefined4 *)((&DAT_00505108)[param_1 * 9] * 0xd0 + 0x48 + DAT_0067ee20) = 1;
  }
  return;
}

