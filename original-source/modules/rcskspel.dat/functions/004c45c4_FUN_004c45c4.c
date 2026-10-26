/*
 * FUN_004c45c4 at 004c45c4
 * undefined FUN_004c45c4(void)
 * Address ranges: 004c45c4-004c45dd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_004c45c4(undefined4 *param_1)

{
  int *piVar1;
  byte bVar2;
  uint uVar3;
  
  piVar1 = param_1 + 1;
  *piVar1 = *piVar1 + -1;
  if (-1 < *piVar1) {
    bVar2 = *(byte *)*param_1;
    *param_1 = (byte *)*param_1 + 1;
    return (uint)bVar2;
  }
  uVar3 = FUN_004c4a82(param_1);
  return uVar3;
}

