/*
 * FUN_00450e64 at 00450e64
 * undefined __register FUN_00450e64(void)
 * Address ranges: 00450e64-00450fd3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00450e64(void)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  byte bVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  int in_stack_00000004;
  uint local_14;
  int local_10;
  byte local_5;
  
  pbVar7 = *(byte **)(*(int *)(in_stack_00000004 + -4) + 0x440);
  uVar6 = 0;
  bVar3 = false;
  local_10 = 0;
  do {
    bVar5 = pbVar7[1];
    pbVar8 = pbVar7 + 2;
    if (*pbVar7 == 0) {
      if (bVar5 == 0) {
        uVar6 = 0;
        bVar3 = false;
        local_10 = local_10 + 1;
      }
      else {
        if (bVar5 == 1) {
          return;
        }
        if (bVar5 == 2) {
          local_10 = local_10 + 2;
          pbVar8 = pbVar7 + 4;
        }
        else {
          iVar1 = *(int *)(*(int *)(in_stack_00000004 + -8) + 0x440);
          iVar2 = *(int *)(*(int *)(in_stack_00000004 + -8) + 0x480);
          local_5 = 0;
          local_14 = (uint)bVar5;
          if (-1 < (int)(local_14 - 1)) {
            bVar4 = false;
            do {
              if (bVar4) {
                local_5 = local_5 << 4;
              }
              else {
                local_5 = *pbVar8;
                pbVar8 = pbVar8 + 1;
              }
              pbVar7 = (byte *)((uVar6 >> 1) + iVar1 + iVar2 * local_10);
              if (bVar3) {
                *pbVar7 = *pbVar7 & 0xf0 | local_5 >> 4;
              }
              else {
                *pbVar7 = *pbVar7 & 0xf | local_5 & 0xf0;
              }
              uVar6 = uVar6 + 1;
              bVar3 = (bool)(bVar3 ^ 1);
              bVar4 = (bool)(bVar4 ^ 1);
              local_14 = local_14 - 1;
            } while (local_14 != 0);
          }
        }
      }
    }
    else {
      iVar1 = *(int *)(*(int *)(in_stack_00000004 + -8) + 0x440);
      iVar2 = *(int *)(*(int *)(in_stack_00000004 + -8) + 0x480);
      local_14 = (uint)*pbVar7;
      if (-1 < (int)(local_14 - 1)) {
        do {
          pbVar7 = (byte *)((uVar6 >> 1) + iVar1 + iVar2 * local_10);
          if (bVar3) {
            *pbVar7 = *pbVar7 & 0xf0 | bVar5 >> 4;
          }
          else {
            *pbVar7 = *pbVar7 & 0xf | bVar5 & 0xf0;
          }
          uVar6 = uVar6 + 1;
          bVar3 = (bool)(bVar3 ^ 1);
          bVar5 = bVar5 >> 4 | bVar5 << 4;
          local_14 = local_14 - 1;
        } while (local_14 != 0);
      }
    }
    pbVar7 = pbVar8 + ((uint)pbVar8 & 1);
  } while( true );
}

