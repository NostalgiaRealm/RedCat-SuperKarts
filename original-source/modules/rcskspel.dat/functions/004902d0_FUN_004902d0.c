/*
 * FUN_004902d0 at 004902d0
 * undefined FUN_004902d0(void)
 * Address ranges: 004902d0-004903bc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004902d0(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int local_8;
  
  local_8 = 0;
  if (0 < *(int *)(param_1 + 0x8c)) {
    piVar2 = (int *)(param_1 + 100);
    iVar4 = param_2;
    iVar7 = DAT_006a5ee0;
    do {
      piVar5 = (int *)(DAT_006a5c38 + *piVar2 * 0xa9);
      if (*(int *)((int)piVar5 + 0xa5) != 2) {
        if (*piVar5 == 1) {
          iVar4 = *(int *)((int)piVar5 + 0x99);
        }
        else if (*piVar5 == 2) {
          iVar4 = *(int *)(*(int *)(*(int *)(piVar5[1] * 9 + 4 + DAT_006a5f78) + piVar5[2] * 4) *
                           0x10 + DAT_006a5f30);
        }
        if (*(int *)((int)piVar5 + 0xa5) != 1) {
          iVar3 = 0;
          iVar1 = iVar4 * 0xbc;
          if (0 < *(int *)(iVar1 + 0x84 + iVar7)) {
            iVar6 = 0;
            do {
              iVar3 = iVar3 + 1;
              *(int *)(*(int *)(iVar1 + 0x80 + iVar7) + 0x10 + iVar6) = param_2;
              iVar6 = iVar6 + 0x20;
              iVar7 = DAT_006a5ee0;
            } while (iVar3 < *(int *)(iVar1 + 0x84 + DAT_006a5ee0));
          }
        }
      }
      local_8 = local_8 + 1;
      piVar2 = piVar2 + 1;
    } while (local_8 < *(int *)(param_1 + 0x8c));
  }
  return;
}

