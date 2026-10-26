/*
 * FUN_004116d0 at 004116d0
 * undefined FUN_004116d0(void)
 * Address ranges: 004116d0-00411726
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004116d0(undefined4 param_1,int param_2,int param_3,char param_4)

{
  int iVar1;
  char cVar2;
  int iVar3;
  
  if (((*(byte *)(param_2 * 0x50 + DAT_00680ae0) & 4) != 0) && (param_4 == '\0')) {
    return 0;
  }
  iVar3 = 0;
  if (0 < param_3) {
    do {
      iVar1 = *(int *)(param_2 * 0x50 + 0x20 + DAT_00680ae0);
      if (iVar1 == -1) {
        return 1;
      }
      cVar2 = FUN_00411680(iVar1);
      if (cVar2 == '\0') {
        return 0;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_3);
  }
  return 1;
}

