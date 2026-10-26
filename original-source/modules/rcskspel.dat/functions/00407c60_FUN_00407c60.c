/*
 * FUN_00407c60 at 00407c60
 * undefined FUN_00407c60(void)
 * Address ranges: 00407c60-00407ca7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_00407c60(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = 0;
  if (DAT_00505108 != param_1) {
    puVar2 = &DAT_00505108;
    do {
      if (0x50580f < (int)puVar2) break;
      piVar1 = puVar2 + 9;
      puVar2 = puVar2 + 9;
      iVar3 = iVar3 + 1;
    } while (*piVar1 != param_1);
    if (iVar3 == 0x32) {
      return (uint)puVar2 & 0xffffff00;
    }
  }
  (&DAT_00505108)[iVar3 * 9] = 0xffffffff;
  (&DAT_0050510c)[iVar3 * 9] = 0xffffffff;
  return CONCAT31((int3)((uint)(iVar3 * 0x24) >> 8),1);
}

