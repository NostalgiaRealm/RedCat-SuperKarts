/*
 * FUN_004042d0 at 004042d0
 * undefined __stdcall FUN_004042d0(void)
 * Address ranges: 004042d0-00404553
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004042d0(void)

{
  int iVar1;
  int *piVar2;
  int in_EAX;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  uint local_2c;
  uint local_20;
  byte local_1c;
  
  if ((*(int *)(in_EAX + 0x420) != -1) && (*(int *)(in_EAX + 0x428) == 0)) {
    if (*(int *)(in_EAX + 0x400) != 0) {
      *(undefined4 *)(in_EAX + 0x424) = 1;
    }
    iVar1 = *(int *)(*(int *)(in_EAX + 0x420) * 4 + in_EAX + 0x404);
    *(int *)(iVar1 + 0x20) = *(int *)(iVar1 + 0x20) + *(int *)(iVar1 + 0x1c);
    *(int *)(iVar1 + 0x24) = *(int *)(iVar1 + 0x24) + *(int *)(iVar1 + 0x1c);
    local_2c = *(uint *)(in_EAX + 900);
    local_1c = 0;
    uVar3 = 0x2000;
    do {
      if ((uVar3 & local_2c) != 0) {
        local_2c = local_2c & ~uVar3;
        goto LAB_0040436e;
      }
      local_1c = local_1c + 1;
      uVar3 = uVar3 * 2;
    } while (local_1c < 7);
    local_1c = 0xff;
LAB_0040436e:
    iVar4 = (uint)local_1c * 4 + in_EAX;
    piVar7 = *(int **)(iVar4 + 0x3c4);
    if (piVar7 == (int *)0x0) {
      local_20 = 0;
    }
    else if ((*(byte *)(iVar4 + 0x4b) & 0x80) == 0) {
      local_20 = *piVar7 - 4;
    }
    else {
      local_20 = piVar7[1];
    }
    *(uint *)(*(int *)((uint)local_1c * 4 + in_EAX + 0x404) + 0x44) = (uint)(local_20 == 0);
    if ((local_20 == 0) == 0) {
      if (DAT_0040e83c != 0) {
        (*DAT_00410474)();
      }
LAB_004043d9:
      piVar2 = *(int **)((uint)local_1c * 4 + in_EAX + 0x404);
      if ((uint)piVar2[6] < piVar2[4] + local_20) {
        local_20 = piVar2[6] - piVar2[4];
        piVar2[0xb] = piVar2[0xb] + 1;
      }
      if ((*(byte *)((uint)local_1c * 4 + in_EAX + 0x4b) & 0x80) == 0) {
        piVar8 = (int *)piVar2[3];
        piVar7 = piVar7 + 1;
        uVar3 = local_20;
        if ((undefined1 *)piVar2[1] < (undefined1 *)(local_20 + (int)piVar8)) {
          uVar5 = piVar2[1] - (int)piVar8;
          piVar6 = piVar7;
          for (uVar3 = uVar5 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *piVar8 = *piVar6;
            piVar6 = piVar6 + 1;
            piVar8 = piVar8 + 1;
          }
          for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *(char *)piVar8 = (char)*piVar6;
            piVar6 = (int *)((int)piVar6 + 1);
            piVar8 = (int *)((int)piVar8 + 1);
          }
          piVar8 = (int *)*piVar2;
          piVar7 = piVar7 + (piVar2[1] - piVar2[3]);
          uVar3 = local_20 - (piVar2[1] - piVar2[3]);
        }
        for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *piVar8 = *piVar7;
          piVar7 = piVar7 + 1;
          piVar8 = piVar8 + 1;
        }
        for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
          *(char *)piVar8 = (char)*piVar7;
          piVar7 = (int *)((int)piVar7 + 1);
          piVar8 = (int *)((int)piVar8 + 1);
        }
      }
      else {
        FUN_0040ccf0((uint *)(piVar7 + 2),local_20,DAT_0040e840,(uint *)*piVar2,(uint *)piVar2[1],
                     (uint *)piVar2[3]);
      }
      piVar2[10] = piVar2[10] + local_20;
      piVar2[4] = piVar2[4] + local_20;
      local_20 = piVar2[3] + local_20;
      piVar2[3] = local_20;
      if ((uint)piVar2[1] <= local_20) {
        piVar2[3] = *piVar2 + (local_20 - piVar2[1]);
      }
      uVar3 = 0x2000;
      local_1c = 0;
      do {
        if ((uVar3 & local_2c) != 0) {
          local_2c = local_2c & ~uVar3;
          goto LAB_004044f0;
        }
        local_1c = local_1c + 1;
        uVar3 = uVar3 * 2;
      } while (local_1c < 7);
      local_1c = 0xff;
LAB_004044f0:
      if (local_1c != 0xff) {
        iVar4 = (uint)local_1c * 4 + in_EAX;
        piVar7 = *(int **)(iVar4 + 0x3c4);
        if (piVar7 == (int *)0x0) {
          local_20 = 0;
        }
        else if ((*(byte *)(iVar4 + 0x4b) & 0x80) == 0) {
          local_20 = *piVar7 - 4;
        }
        else {
          local_20 = piVar7[1];
        }
        goto LAB_004043d9;
      }
    }
    if (*(uint *)(iVar1 + 0x28) < *(uint *)(iVar1 + 0x20) >> 7) {
      *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x28) << 7;
    }
  }
  return;
}

