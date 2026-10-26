/*
 * FUN_004060c0 at 004060c0
 * undefined FUN_004060c0(void)
 * Address ranges: 004060c0-0040613a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004060c0(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (DAT_0040e860 != 0) {
    (*DAT_004104a4)(*(undefined4 *)(param_1 + 0x38));
    (*DAT_004104c0)();
    (*DAT_004104bc)(*(undefined4 *)(param_1 + 0x38));
    (*DAT_004104c0)();
    (*DAT_00410480)(*(undefined4 *)(param_1 + 0x54));
    (*DAT_00410480)(*(undefined4 *)(param_1 + 0x58));
    if (param_1 == DAT_0040e860) {
      DAT_0040e860 = *(int *)(DAT_0040e860 + 0x34);
    }
    else {
      iVar1 = *(int *)(DAT_0040e860 + 0x34);
      iVar2 = DAT_0040e860;
      while (iVar1 != 0) {
        if (param_1 == *(int *)(iVar2 + 0x34)) {
          *(undefined4 *)(iVar2 + 0x34) = *(undefined4 *)(*(int *)(iVar2 + 0x34) + 0x34);
          return;
        }
        iVar2 = *(int *)(iVar2 + 0x34);
        iVar1 = *(int *)(iVar2 + 0x34);
      }
    }
  }
  return;
}

