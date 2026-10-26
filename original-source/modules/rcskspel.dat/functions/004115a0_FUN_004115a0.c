/*
 * FUN_004115a0 at 004115a0
 * undefined FUN_004115a0(void)
 * Address ranges: 004115a0-00411675
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_004115a0(int param_1,int param_2,char param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  char local_1;
  
  local_1 = '\0';
  param_2 = param_2 * 0x50;
  if (((*(byte *)(param_2 + DAT_00680ae0) & 4) != 0) && (param_3 == '\0')) {
    return DAT_00680ae0 & 0xffffff00;
  }
  iVar2 = *(int *)(param_2 + 0x24 + DAT_00680ae0);
  uVar4 = DAT_00680ae0;
  if ((0 < iVar2) && (iVar5 = 0, 0 < iVar2)) {
    do {
      uVar4 = DAT_00680ae0;
      if (local_1 != '\0') goto LAB_00411666;
      iVar2 = FUN_004944a0(iVar5);
      iVar3 = FUN_00407cb0(iVar2);
      bVar1 = false;
      if ((iVar3 != -1) && ((&DAT_0050510c)[iVar3 * 9] == 1)) {
        bVar1 = true;
      }
      if ((*(float *)(param_1 * 0xd0 + 0xa4 + DAT_0067ee20) <=
           *(float *)(iVar2 * 0xd0 + 0xa4 + DAT_0067ee20)) || (bVar1)) {
        iVar5 = iVar5 + 1;
      }
      else {
        local_1 = '\x01';
      }
    } while (iVar5 < *(int *)(param_2 + 0x24 + DAT_00680ae0));
    uVar4 = CONCAT31((int3)(DAT_00680ae0 >> 8),local_1);
    if (local_1 != '\0') {
LAB_00411666:
      return uVar4 & 0xffffff00;
    }
  }
  return CONCAT31((int3)(uVar4 >> 8),1);
}

