/*
 * FUN_004bd778 at 004bd778
 * undefined FUN_004bd778(void)
 * Address ranges: 004bd778-004bd8bf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __thiscall FUN_004bd778(int param_1,uint param_2)

{
  uint uVar1;
  short sVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  int local_14;
  undefined4 *local_10;
  int local_c;
  undefined4 local_8;
  
  if ((short)param_2 == -1) {
    return 0;
  }
  uVar1 = **(uint **)(param_1 + 0x20);
  if ((uVar1 != 0) && (uVar1 < uVar1 + **(int **)(param_1 + 0x30) * 2)) {
    psVar3 = (short *)FUN_004bdcf1();
    *psVar3 = (short)param_2;
    return param_2 & 0xffff;
  }
  if (*(int *)(param_1 + 0x50) == 0) {
    return 0xffff;
  }
  if (*(int *)(param_1 + 0x38) == 0) {
    sVar2 = FUN_004c1438(param_2,*(int *)(param_1 + 0x50));
LAB_004bd871:
    if (sVar2 != -1) {
      return param_2;
    }
  }
  else {
    local_8 = param_2;
    FUN_004478a0(0,0xffffffff);
    FUN_0045b1e0(8,0);
    iVar4 = *(int *)(param_1 + 0x44);
    FUN_0044da90();
    iVar5 = *(int *)(param_1 + 0x44);
    local_c = *(int *)(iVar4 + 4);
    FUN_0044da90();
    iVar4 = (**(code **)(**(int **)(param_1 + 0x38) + 0x14))
                      (param_1 + 0x40,&local_8,(int)&local_8 + 2,&local_10,
                       *(undefined4 *)(iVar5 + 4),
                       -(uint)(local_c != 0) & *(int *)(iVar4 + 8) + local_c,&local_14);
    if (iVar4 != 0) {
      if (iVar4 != 1) {
        if (iVar4 != 3) {
          return 0xffff;
        }
        sVar2 = FUN_004c1438(local_8,*(undefined4 *)(param_1 + 0x50));
        goto LAB_004bd871;
      }
      if (local_10 == &local_8) {
        return 0xffff;
      }
    }
    iVar4 = *(int *)(param_1 + 0x44);
    FUN_0044da90();
    iVar5 = local_14 - *(int *)(iVar4 + 4);
    iVar4 = *(int *)(param_1 + 0x44);
    FUN_0044da90();
    iVar4 = FUN_004bf31b(*(undefined4 *)(iVar4 + 4),iVar5,1,*(undefined4 *)(param_1 + 0x50));
    if (iVar4 == iVar5) {
      return param_2;
    }
  }
  return 0xffff;
}

