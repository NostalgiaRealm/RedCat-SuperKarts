/*
 * FUN_004062b0 at 004062b0
 * undefined FUN_004062b0(void)
 * Address ranges: 004062b0-00406315
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004062b0(int param_1)

{
  int iVar1;
  
  (&DAT_00503ff8)[param_1 * 0x11c] = 0;
  iVar1 = *(int *)(DAT_00504f98 + 0x60 + param_1 * 0x6c) - DAT_0053be70;
  if (*(int *)(&DAT_004d2330 + DAT_0053b9f4 * 0xc) < iVar1) {
    FUN_00405fd0(param_1,iVar1);
    return;
  }
  if (iVar1 < -*(int *)(&DAT_004d2308 + DAT_0053b9f4 * 0xc)) {
    FUN_00406100(param_1,iVar1);
  }
  return;
}

