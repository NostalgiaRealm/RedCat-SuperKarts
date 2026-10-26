/*
 * FUN_004bc9af at 004bc9af
 * undefined FUN_004bc9af(void)
 * Address ranges: 004bc9af-004bcae4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_004bc9af(int param_1,int param_2)

{
  uint uVar1;
  char *pcVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  int local_14;
  char *local_10;
  int local_c;
  char local_5;
  
  if (param_2 == -1) {
    return 0;
  }
  uVar1 = **(uint **)(param_1 + 0x20);
  cVar4 = (char)param_2;
  if ((uVar1 != 0) && (uVar1 < **(int **)(param_1 + 0x30) + uVar1)) {
    pcVar2 = (char *)FUN_004bce73();
    *pcVar2 = cVar4;
    return param_2;
  }
  if (*(int *)(param_1 + 0x50) == 0) {
    return -1;
  }
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar3 = FUN_004c11fe((int)cVar4,*(int *)(param_1 + 0x50));
joined_r0x004bca9a:
    if (iVar3 != -1) {
      return param_2;
    }
  }
  else {
    local_5 = cVar4;
    FUN_004478a0(0,0xffffffff);
    FUN_0045b1e0(8,0);
    iVar3 = *(int *)(param_1 + 0x44);
    FUN_0044da90();
    iVar5 = *(int *)(param_1 + 0x44);
    local_c = *(int *)(iVar3 + 4);
    FUN_0044da90();
    iVar3 = (**(code **)(**(int **)(param_1 + 0x38) + 0x14))
                      (param_1 + 0x40,&local_5,&stack0xfffffffc,&local_10,*(undefined4 *)(iVar5 + 4)
                       ,-(uint)(local_c != 0) & *(int *)(iVar3 + 8) + local_c,&local_14);
    if (iVar3 != 0) {
      if (iVar3 != 1) {
        if (iVar3 != 3) {
          return -1;
        }
        iVar3 = FUN_004c11fe((int)local_5,*(undefined4 *)(param_1 + 0x50));
        goto joined_r0x004bca9a;
      }
      if (local_10 == &local_5) {
        return -1;
      }
    }
    iVar3 = *(int *)(param_1 + 0x44);
    FUN_0044da90();
    iVar5 = local_14 - *(int *)(iVar3 + 4);
    iVar3 = *(int *)(param_1 + 0x44);
    FUN_0044da90();
    iVar3 = FUN_004bf31b(*(undefined4 *)(iVar3 + 4),iVar5,1,*(undefined4 *)(param_1 + 0x50));
    if (iVar3 == iVar5) {
      return param_2;
    }
  }
  return -1;
}

