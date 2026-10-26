/*
 * FUN_004b83b0 at 004b83b0
 * undefined FUN_004b83b0(void)
 * Address ranges: 004b83b0-004b880d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b83b0(undefined4 param_1,int param_2)

{
  uint uVar1;
  undefined2 uVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined2 *puVar9;
  undefined1 local_2b;
  short local_2a;
  short local_28;
  short local_26;
  short local_24;
  short local_22;
  int local_20;
  undefined2 *local_1c;
  int local_18;
  int local_14;
  int local_10;
  uint local_c;
  uint local_8;
  uint local_4;
  
  iVar4 = FUN_004bf445(param_1,&DAT_005012c0);
  if (iVar4 == 0) {
    return 1000;
  }
  FUN_004c0a0a(iVar4);
  FUN_004bf930(&local_26,1,2,iVar4);
  DAT_00501110 = local_26 + 1;
  FUN_004afce0(s__s_maxmemimages____d_00501310,param_1,DAT_00501110);
  uVar1 = (uint)(((byte)param_2 & 1) == 1);
  iVar5 = param_2 - uVar1;
  iVar6 = FUN_004b7aa0(DAT_00501110,iVar5);
  if (iVar6 != 0) {
    return 2000;
  }
  if (uVar1 == 0) {
    if ((DAT_006ab888 != 0) && (iVar6 = 0, 0 < DAT_00501110)) {
      iVar8 = 0;
      do {
        iVar6 = iVar6 + 1;
        *(undefined4 *)(iVar8 + DAT_006ab880) = 0;
        *(undefined4 *)(iVar8 + 0x1c + DAT_006ab880) = 0;
        *(int *)(iVar8 + 0x18 + DAT_006ab880) = iVar5;
        iVar8 = iVar8 + 0x20;
      } while (iVar6 < DAT_00501110);
    }
  }
  else {
    DAT_006ab88c = 1;
    FUN_004afce0(s__s_allocating_images_005012f8,param_1);
    local_10 = 0;
    if (0 < DAT_00501110) {
      local_18 = 0;
      do {
        iVar6 = local_10;
        iVar5 = local_18;
        FUN_004afce0(s__s_allocating_image__d_005012e0,param_1,local_10);
        FUN_004bf930(&local_28,1,2,iVar4);
        FUN_004bf930(&local_2a,1,2,iVar4);
        FUN_004bf930(&local_24,1,2,iVar4);
        FUN_004bf930(&local_22,1,2,iVar4);
        *(int *)(DAT_006ab880 + 8 + iVar5) = (int)local_28;
        *(int *)(DAT_006ab880 + 0xc + iVar5) = (int)local_2a;
        *(int *)(DAT_006ab880 + 0x10 + iVar5) = (int)local_24;
        *(int *)(DAT_006ab880 + 0x14 + iVar5) = (int)local_22;
        FUN_004b7b50(iVar6);
        FUN_004b7e20(iVar6,&local_14);
        puVar9 = *(undefined2 **)(DAT_006ab880 + iVar5);
        local_1c = puVar9;
        switch(DAT_006ab82c) {
        case 0:
          local_20 = 0;
          if (0 < local_2a) {
            do {
              FUN_004bf930(puVar9,1,(int)local_28,iVar4);
              puVar9 = (undefined2 *)((int)puVar9 + local_14);
              local_20 = local_20 + 1;
            } while (local_20 < local_2a);
          }
          break;
        case 1:
          local_20 = 0;
          sVar3 = local_28;
          if (0 < local_2a) {
            do {
              iVar5 = 0;
              local_1c = puVar9;
              if (0 < sVar3) {
                do {
                  FUN_004bf930(&local_8,1,1,iVar4);
                  uVar2 = FUN_004b5740(local_8 & 0xff,8);
                  *puVar9 = uVar2;
                  puVar9 = puVar9 + 1;
                  iVar5 = iVar5 + 1;
                  sVar3 = local_28;
                } while (iVar5 < local_28);
              }
              puVar9 = (undefined2 *)((int)local_1c + local_14);
              local_20 = local_20 + 1;
              iVar6 = local_10;
              iVar5 = local_18;
              local_1c = puVar9;
            } while (local_20 < local_2a);
          }
          break;
        case 2:
          local_20 = 0;
          sVar3 = local_28;
          if (0 < local_2a) {
            do {
              iVar5 = 0;
              local_1c = puVar9;
              if (0 < sVar3) {
                do {
                  FUN_004bf930(&local_4,1,1,iVar4);
                  FUN_004b5910(local_4 & 0xff,8,puVar9);
                  puVar9 = (undefined2 *)((int)puVar9 + 3);
                  iVar5 = iVar5 + 1;
                  sVar3 = local_28;
                } while (iVar5 < local_28);
              }
              puVar9 = (undefined2 *)((int)local_1c + local_14);
              local_20 = local_20 + 1;
              iVar6 = local_10;
              iVar5 = local_18;
              local_1c = puVar9;
            } while (local_20 < local_2a);
          }
          break;
        case 4:
          FUN_004afce0(s_converting_from_24_to_16_bits_00501264);
          local_20 = 0;
          if (0 < *(int *)(DAT_006ab880 + 0xc + iVar5)) {
            iVar8 = iVar5 + 8;
            iVar7 = DAT_006ab880;
            do {
              iVar5 = 0;
              if (0 < *(int *)(iVar8 + iVar7)) {
                iVar8 = local_18 + 8;
                do {
                  FUN_004bf930(&local_c,1,1,iVar4);
                  FUN_004bf930(&local_2b,1,1,iVar4);
                  FUN_004bf930(&param_2,1,1,iVar4);
                  uVar2 = FUN_004b5740((uint)CONCAT11((undefined1)param_2,local_2b) << 8 |
                                       local_c & 0xff,0x18);
                  *puVar9 = uVar2;
                  puVar9 = puVar9 + 1;
                  iVar5 = iVar5 + 1;
                  iVar7 = DAT_006ab880;
                } while (iVar5 < *(int *)(iVar8 + DAT_006ab880));
              }
              puVar9 = (undefined2 *)((int)local_1c + local_14);
              local_20 = local_20 + 1;
              iVar6 = local_10;
              iVar5 = local_18;
              local_1c = puVar9;
            } while (local_20 < *(int *)(local_18 + 0xc + iVar7));
          }
        }
        FUN_004b7e90(iVar6);
        if ((*(byte *)(iVar4 + 0xc) & 0x20) != 0) {
          DAT_006ab88c = 0;
          FUN_004bf2c5(iVar4);
          return 0x3e9;
        }
        local_10 = iVar6 + 1;
        local_18 = iVar5 + 0x20;
      } while (local_10 < DAT_00501110);
    }
    FUN_004afce0(s__s_allocating_images_done_005012c4,param_1);
  }
  FUN_004bf2c5(iVar4);
  DAT_006ab88c = 1;
  return 0;
}

