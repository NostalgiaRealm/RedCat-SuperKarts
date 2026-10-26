/*
 * FUN_00406050 at 00406050
 * undefined FUN_00406050(void)
 * Address ranges: 00406050-004060b8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00406050(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  
  if (0x8000 < param_2) {
    param_2 = 0x8000;
  }
  uVar1 = ((int)(((ulonglong)param_2 * 0x4f6) / 0x8000) + 5U) / 10;
  (*DAT_00410488)(*(undefined4 *)(param_3 + 0x38),uVar1);
  (*DAT_004104c4)(*(undefined4 *)(param_1 + 0x38),
                  ((int)(((ulonglong)uVar1 * 0x4f6) / 0x10000) + 5U) / 10);
  return;
}

