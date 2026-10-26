/*
 * FUN_0046f6e0 at 0046f6e0
 * undefined FUN_0046f6e0(void)
 * Address ranges: 0046f6e0-0046f752
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0046f6e0(int param_1)

{
  byte bVar1;
  undefined4 extraout_EDX;
  
  FUN_0046f5f4(param_1);
  FUN_0046f848();
  FUN_0046fb28();
  *(undefined1 *)(param_1 + 0x338) =
       *(undefined1 *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80) + 0x25);
  bVar1 = *(byte *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80) + 0x24);
  *(byte *)(param_1 + 0x339) = bVar1;
  if (2 < bVar1) {
    *(undefined1 *)(param_1 + 0x339) = 0;
    *(undefined1 *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80) + 0x24) = 0;
  }
  FUN_0046fa2c(param_1);
  FUN_0046f84c(param_1,extraout_EDX);
  return 1;
}

