/*
 * FUN_00441b30 at 00441b30
 * undefined __register FUN_00441b30(int * param_1, byte param_2, undefined4 param_3, int param_4)
 * Address ranges: 00441b30-00441cfa;00441d02-00441e0e;00441ec4-00441eca
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00441b30(int *param_1,byte param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  uint *in_FS_OFFSET;
  undefined1 local_2c [8];
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  uint local_10;
  byte local_9;
  int *local_8;
  
  local_9 = param_2;
  local_8 = param_1;
  if ((param_2 == 0) || ((&DAT_0047b900)[param_2] != *(char *)((int)param_1 + 0x51))) {
    if ((param_1[0x20] != 0) && (param_1[0x21] != 0)) {
      iVar4 = param_1[0xc];
      iVar6 = param_1[0xd];
      local_10 = param_1[0xe];
      local_14 = param_1[0xf];
      bVar2 = FUN_00445a20(param_1[9]);
      if (bVar2) {
        (**(code **)(*(int *)local_8[9] + 0x40))((int *)local_8[9],local_2c);
        local_1c = local_24;
        local_18 = local_20;
      }
      else {
        FUN_0040ebd0(*(undefined4 *)(local_8[9] + 0x38),*(undefined4 *)(local_8[9] + 0x3c),&local_1c
                    );
      }
      if ((*(byte *)((int)local_8 + 0x51) & 4) == 0) {
        if ((*(byte *)((int)local_8 + 0x51) & 1) == 0) {
          iVar4 = MulDiv(local_8[0x1e],local_1c,local_8[0x20]);
          iVar3 = (int)local_10 >> 1;
          if (iVar3 < 0) {
            iVar3 = iVar3 + (uint)((local_10 & 1) != 0);
          }
          iVar4 = iVar4 - iVar3;
        }
      }
      else if ((*(byte *)((int)local_8 + 0x51) & 1) == 0) {
        iVar4 = local_1c - (local_8[0x20] - local_8[0x1e]);
      }
      else {
        local_10 = local_1c - (local_8[0x20] - local_8[0x1e]);
      }
      if ((*(byte *)((int)local_8 + 0x51) & 8) == 0) {
        if ((*(byte *)((int)local_8 + 0x51) & 2) == 0) {
          iVar6 = MulDiv(local_8[0x1f],local_18,local_8[0x21]);
          iVar3 = (int)local_14 >> 1;
          if (iVar3 < 0) {
            iVar3 = iVar3 + (uint)((local_14 & 1) != 0);
          }
          iVar6 = iVar6 - iVar3;
        }
      }
      else if ((*(byte *)((int)local_8 + 0x51) & 2) == 0) {
        iVar6 = local_18 - (local_8[0x21] - local_8[0x1f]);
      }
      else {
        local_14 = local_18 - (local_8[0x21] - local_8[0x1f]);
      }
      *(undefined1 *)((int)local_8 + 0x52) = 1;
      *in_FS_OFFSET = (uint)&stack0xffffffbc;
      (**(code **)(*local_8 + 0x7c))(local_8,iVar4,iVar6,local_14,local_10);
      *in_FS_OFFSET = local_14;
      *(undefined1 *)((int)local_8 + 0x52) = 0;
      return;
    }
    if (param_2 == 0) {
      return;
    }
  }
  local_10 = *(int *)(*(int *)(param_4 + -4) + 8) - **(int **)(param_4 + -4);
  if (((int)local_10 < 0) || ((byte)(param_2 - 3) < 2)) {
    local_10 = param_1[0xe];
  }
  local_14 = *(int *)(*(int *)(param_4 + -4) + 0xc) - *(int *)(*(int *)(param_4 + -4) + 4);
  if (((int)local_14 < 0) || ((byte)(param_2 - 1) < 2)) {
    local_14 = param_1[0xf];
  }
  uVar5 = **(undefined4 **)(param_4 + -4);
  uVar7 = *(undefined4 *)(*(int *)(param_4 + -4) + 4);
  if (param_2 == 1) {
    piVar1 = (int *)(*(int *)(param_4 + -4) + 4);
    *piVar1 = *piVar1 + local_14;
  }
  else if (param_2 == 2) {
    piVar1 = (int *)(*(int *)(param_4 + -4) + 0xc);
    *piVar1 = *piVar1 - local_14;
    uVar7 = *(undefined4 *)(*(int *)(param_4 + -4) + 0xc);
  }
  else if (param_2 == 3) {
    **(int **)(param_4 + -4) = **(int **)(param_4 + -4) + local_10;
  }
  else if (param_2 == 4) {
    piVar1 = (int *)(*(int *)(param_4 + -4) + 8);
    *piVar1 = *piVar1 - local_10;
    uVar5 = *(undefined4 *)(*(int *)(param_4 + -4) + 8);
  }
  *(undefined1 *)((int)param_1 + 0x52) = 1;
  *in_FS_OFFSET = (uint)&stack0xffffffbc;
  (**(code **)(*param_1 + 0x7c))(param_1,uVar5,uVar7,local_14,local_10);
  *in_FS_OFFSET = local_14;
  *(undefined1 *)((int)local_8 + 0x52) = 0;
  return;
}

