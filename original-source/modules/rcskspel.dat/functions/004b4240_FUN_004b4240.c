/*
 * FUN_004b4240 at 004b4240
 * undefined FUN_004b4240(void)
 * Address ranges: 004b4240-004b42ae
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004b4240(char *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  if (param_3 < DAT_006ab78c) {
    iVar2 = param_3 * 0x44;
    do {
      if ((*(int *)((char *)(DAT_006ab798 + iVar2) + 0x30) != 0) &&
         (iVar1 = __strcmpi((char *)(DAT_006ab798 + iVar2),param_1), iVar1 == 0)) {
        if (param_4 == 0) {
          return param_3;
        }
        iVar1 = FUN_004b3f30(param_3);
        if (iVar1 == 0) {
          return param_3;
        }
      }
      param_3 = param_3 + 1;
      iVar2 = iVar2 + 0x44;
    } while (param_3 < DAT_006ab78c);
  }
  return -1;
}

