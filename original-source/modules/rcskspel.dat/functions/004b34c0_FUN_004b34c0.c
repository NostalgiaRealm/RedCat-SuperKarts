/*
 * FUN_004b34c0 at 004b34c0
 * undefined FUN_004b34c0(void)
 * Address ranges: 004b34c0-004b3559
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004b34c0(undefined4 param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (param_2 < param_5) {
    iVar1 = FUN_004b34a0(param_1,param_2 + 1,param_3,param_5);
    iVar2 = FUN_004b34a0(param_1,param_2,param_3,param_5);
    if (iVar2 == iVar1) {
      do {
        if ((param_4 <= iVar3) || (0x3e < iVar3)) break;
        iVar3 = iVar3 + 1;
        iVar1 = FUN_004b34a0(param_1,iVar3 + param_2 + 1,param_3,param_5);
        iVar2 = FUN_004b34a0(param_1,iVar3 + param_2,param_3,param_5);
      } while (iVar2 == iVar1);
      if (iVar3 != 0) {
        return iVar3;
      }
    }
  }
  return 1;
}

