/*
 * FUN_00407370 at 00407370
 * undefined FUN_00407370(void)
 * Address ranges: 00407370-004073ce
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00407370(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (DAT_0040e894 != 0) {
    FUN_004077a0();
    FUN_00402c10();
    if (param_1 == DAT_0040e894) {
      DAT_0040e894 = *(undefined4 *)(DAT_0040e894 + 0x34);
      return;
    }
    iVar1 = *(int *)(DAT_0040e894 + 0x34);
    iVar2 = DAT_0040e894;
    while (iVar1 != 0) {
      if (param_1 == *(int *)(iVar2 + 0x34)) {
        *(undefined4 *)(iVar2 + 0x34) = *(undefined4 *)(*(int *)(iVar2 + 0x34) + 0x34);
        return;
      }
      iVar2 = *(int *)(iVar2 + 0x34);
      iVar1 = *(int *)(iVar2 + 0x34);
    }
  }
  return;
}

