/*
 * _SmackColorRemap@16 at 0040333c
 * undefined __stdcall _SmackColorRemap@16(int param_1, int param_2, uint param_3, uint param_4)
 * Address ranges: 0040333c-00403449
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void _SmackColorRemap_16(int param_1,int param_2,uint param_3,uint param_4)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  int iVar7;
  int iVar8;
  undefined1 auStack_134 [256];
  int local_34;
  uint local_30;
  byte *local_2c;
  int local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  undefined1 local_18;
  byte local_14;
  
                    /* 0x333c  25  _SmackColorRemap@16 */
  if (param_1 != 0) {
    if (0x100 < param_3) {
      param_3 = 0x100;
    }
    if ((param_4 & 8) == 0) {
      iVar8 = ((param_4 & 1) != 0) + 3;
    }
    else {
      iVar8 = 8;
    }
    local_24 = param_4 & 0xe;
    local_2c = (byte *)(param_1 + 0x6c);
    local_28 = local_24 * 4;
    local_30 = 0;
    do {
      pbVar6 = local_2c + 1;
      local_20 = 0xffffffff;
      bVar1 = *local_2c;
      local_14 = local_2c[2];
      local_2c = local_2c + 3;
      local_1c = 0;
      uVar5 = local_30;
      if (param_3 != 0) {
        do {
          if (local_24 < 7) {
                    /* WARNING: Could not recover jumptable at 0x00403443. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (**(code **)((int)&PTR_FUN_00403320 + local_28))();
            return;
          }
          iVar7 = uVar5 * iVar8;
          iVar2 = (uint)bVar1 - ((int)(uint)*(byte *)(param_2 + 2 + iVar7) >> 2);
          iVar4 = (uint)*pbVar6 - ((int)(uint)*(byte *)(param_2 + 4 + iVar7) >> 2);
          local_34 = iVar2 * iVar2 + iVar4 * iVar4;
          iVar2 = (uint)local_14 - ((int)(uint)*(byte *)(param_2 + 6 + iVar7) >> 2);
          uVar3 = iVar2 * iVar2 + local_34;
          if (uVar3 < local_20) {
            local_18 = (undefined1)uVar5;
            local_20 = uVar3;
            if (uVar3 == 0) break;
          }
          uVar5 = uVar5 + 1;
          if (uVar5 == 0x100) {
            uVar5 = 0;
          }
          local_1c = local_1c + 1;
        } while (local_1c < param_3);
      }
      auStack_134[local_30] = local_18;
      local_30 = local_30 + 1;
    } while (local_30 < 0x100);
    FUN_0040d660(*(int **)(param_1 + 0x39c),auStack_134);
  }
  return;
}

