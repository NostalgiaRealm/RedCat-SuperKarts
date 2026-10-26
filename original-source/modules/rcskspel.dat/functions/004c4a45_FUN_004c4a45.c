/*
 * FUN_004c4a45 at 004c4a45
 * undefined FUN_004c4a45(void)
 * Address ranges: 004c4a45-004c4a81
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004c4a45(int param_1,undefined4 *param_2)

{
  if (param_1 == 0) {
    if ((*(byte *)((int)param_2 + 0xd) & 0x10) != 0) {
      FUN_004c1305(param_2);
    }
  }
  else if ((*(byte *)((int)param_2 + 0xd) & 0x10) != 0) {
    FUN_004c1305(param_2);
    *(byte *)((int)param_2 + 0xd) = *(byte *)((int)param_2 + 0xd) & 0xee;
    param_2[6] = 0;
    *param_2 = 0;
    param_2[2] = 0;
    return;
  }
  return;
}

