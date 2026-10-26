/*
 * FUN_004c12ca at 004c12ca
 * undefined FUN_004c12ca(void)
 * Address ranges: 004c12ca-004c1304
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004c12ca(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = flsall(0);
    return iVar1;
  }
  iVar1 = FUN_004c1305(param_1);
  if (iVar1 != 0) {
    return -1;
  }
  if ((*(byte *)(param_1 + 0xd) & 0x40) != 0) {
    iVar1 = FUN_004c8b25(*(undefined4 *)(param_1 + 0x10));
    return -(uint)(iVar1 != 0);
  }
  return 0;
}

