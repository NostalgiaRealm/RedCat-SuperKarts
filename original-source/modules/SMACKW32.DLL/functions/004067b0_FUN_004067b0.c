/*
 * FUN_004067b0 at 004067b0
 * undefined FUN_004067b0(void)
 * Address ranges: 004067b0-0040680e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004067b0(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (DAT_0040e890 != 0) {
    FUN_00406bc0(param_1);
    FUN_00402c10();
    if (param_2 == DAT_0040e890) {
      DAT_0040e890 = *(undefined4 *)(DAT_0040e890 + 0x34);
      return;
    }
    iVar1 = *(int *)(DAT_0040e890 + 0x34);
    iVar2 = DAT_0040e890;
    while (iVar1 != 0) {
      if (param_2 == *(int *)(iVar2 + 0x34)) {
        *(undefined4 *)(iVar2 + 0x34) = *(undefined4 *)(*(int *)(iVar2 + 0x34) + 0x34);
        return;
      }
      iVar2 = *(int *)(iVar2 + 0x34);
      iVar1 = *(int *)(iVar2 + 0x34);
    }
  }
  return;
}

