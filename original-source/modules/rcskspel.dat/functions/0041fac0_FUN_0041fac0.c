/*
 * FUN_0041fac0 at 0041fac0
 * undefined FUN_0041fac0(void)
 * Address ranges: 0041fac0-0041fb28
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041fac0(void)

{
  DAT_005086a0 = DAT_005086a0 + 1;
  DAT_00508698 = DAT_004e3064;
  DAT_00508694 = DAT_00508670;
  if (DAT_004e3064 == 3) {
    *(undefined4 *)(DAT_0053be28 * 0xd0 + 0x3c + DAT_0067ee20) = 1;
  }
  FUN_0041f9b0();
  FUN_0041f7d0();
  DAT_0050869c = 0;
  FUN_0041f900();
  _DAT_00508690 = GetTickCount();
  return;
}

