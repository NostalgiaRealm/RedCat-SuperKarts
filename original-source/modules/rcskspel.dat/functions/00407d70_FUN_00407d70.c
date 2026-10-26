/*
 * FUN_00407d70 at 00407d70
 * undefined FUN_00407d70(void)
 * Address ranges: 00407d70-00407f41
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_00407d70(char *param_1,undefined4 *param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  bool bVar7;
  uint local_2c;
  int local_28;
  int *local_24;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  char local_10 [4];
  int local_c [2];
  undefined4 local_4;
  
  uVar1 = *(uint *)(&DAT_00505114 + (int)param_1 * 0x24);
  bVar7 = (uVar1 & 0x1000) != 0;
  if ((uVar1 & 0x20) == 0) {
    if ((uVar1 & 0x40) == 0) {
      local_28 = (-(uint)((uVar1 & 0x80) != 0) & 0xfffffffe) + 2;
    }
    else {
      local_28 = 1;
    }
  }
  else {
    local_28 = 3;
  }
  FUN_00407cf0(param_1,&local_1c,&local_18,&local_14);
  iVar2 = (&DAT_00505108)[(int)param_1 * 9];
  local_2c = 0;
  local_10[0] = '\0';
  local_10[1] = 0;
  local_10[2] = 0;
  local_24 = local_c;
  pcVar4 = local_10 + 2;
  local_c[0] = *(int *)(iVar2 * 0xd0 + 0x24 + DAT_0067ee20);
  param_1 = local_10 + 1;
  pcVar5 = local_10;
  iVar6 = local_c[0];
  do {
    iVar3 = FUN_00411730(iVar2,iVar6,local_1c,local_28,bVar7);
    if (*pcVar5 == '\x01') {
      iVar3 = -1;
    }
    *pcVar5 = '\x01';
    if (iVar3 == -1) {
      iVar3 = FUN_00411730(iVar2,iVar6,local_18,local_28,bVar7);
      if (*param_1 == '\x01') {
        iVar3 = -1;
      }
      *pcVar5 = '\x01';
      if (iVar3 != -1) goto LAB_00407ea9;
      iVar3 = FUN_00411730(iVar2,iVar6,local_14,local_28,bVar7);
      if (*pcVar4 == '\x01') {
        iVar3 = -1;
      }
      *pcVar4 = '\x01';
      if (iVar3 != -1) goto LAB_00407ea9;
      if ((int)local_2c < 1) {
        return local_2c & 0xffffff00;
      }
      local_2c = local_2c - 1;
      param_1 = param_1 + -8;
      pcVar5 = pcVar5 + -8;
      pcVar4 = pcVar4 + -8;
      local_24 = local_24 + -2;
      iVar3 = iVar6;
    }
    else {
LAB_00407ea9:
      local_2c = local_2c + 1;
      param_1 = param_1 + 8;
      pcVar5 = pcVar5 + 8;
      pcVar4 = pcVar4 + 8;
      local_24 = local_24 + 2;
      if ((int)local_2c < 2) {
        *pcVar5 = '\0';
        *param_1 = '\0';
        *pcVar4 = '\0';
        *local_24 = iVar3;
      }
    }
    iVar6 = iVar3;
    if (1 < (int)local_2c) {
      *param_2 = local_4;
      *param_3 = iVar3;
      return CONCAT31((int3)((uint)local_4 >> 8),1);
    }
  } while( true );
}

