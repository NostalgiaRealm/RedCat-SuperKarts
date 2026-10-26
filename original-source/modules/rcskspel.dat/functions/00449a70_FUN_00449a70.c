/*
 * FUN_00449a70 at 00449a70
 * undefined FUN_00449a70(void)
 * Address ranges: 00449a70-00449ad6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_00449a70(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = *(int *)(DAT_006a5c38 + *(int *)(param_2 * 0xd0 + 0xc + DAT_0067ee20) * 0xa9 + 4);
  if (0 < param_1[1]) {
    do {
      iVar2 = FUN_004a6200(*(undefined4 *)(*param_1 + iVar3 * 4));
      if (iVar1 == iVar2) {
        return 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_1[1]);
  }
  return 0;
}

