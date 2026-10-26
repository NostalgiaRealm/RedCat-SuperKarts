/*
 * FUN_004b7ee0 at 004b7ee0
 * undefined FUN_004b7ee0(void)
 * Address ranges: 004b7ee0-004b8335
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b7ee0(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined2 *puVar8;
  int iVar9;
  short sStack_2a;
  int iStack_28;
  undefined2 *puStack_24;
  int local_20;
  int iStack_1c;
  int *local_18;
  int local_14;
  undefined4 local_10;
  uint uStack_c;
  uint uStack_8;
  uint uStack_4;
  
  if (DAT_006ab88c != 0) {
    iVar4 = FUN_004bf445(param_1,&DAT_005012c0);
    if (iVar4 == 0) {
      return 1000;
    }
    local_14 = FUN_004bf445(param_2,&DAT_005012c0);
    if (local_14 == 0) {
      FUN_004bf2c5(iVar4);
      return 1000;
    }
    DAT_006ab884 = 0;
    iVar7 = *param_3;
    iVar9 = local_14;
    piVar2 = param_3;
    piVar1 = param_3;
    piVar6 = local_18;
    while (local_18 = piVar2, param_3 = piVar1, local_14 = iVar9, -1 < iVar7) {
      FUN_004c0331(iVar9,*local_18 * 4 + -2,0);
      if ((*(byte *)(iVar9 + 0xc) & 0x20) != 0) {
        FUN_004afee0(s__s__d____index_file_seek_error___00501284,
                     s_C__libraries_dxdraw_Sprite_cpp_00501114,0x1df,piVar1[local_20]);
      }
      FUN_004bf930(&local_10,1,4,iVar9);
      if (((*(byte *)(iVar9 + 0xc) & 0x20) != 0) ||
         (FUN_004c0331(iVar4,local_10,0), (*(byte *)(iVar4 + 0xc) & 0x20) != 0)) {
        FUN_004bf2c5(iVar4);
        return 0x3e9;
      }
      iVar7 = *local_18;
      iVar9 = iVar7 * 0x20;
      local_20 = iVar7;
      FUN_004bf930(iVar9 + 8 + DAT_006ab880,1,2,iVar4);
      FUN_004bf930(iVar9 + 0xc + DAT_006ab880,1,2,iVar4);
      FUN_004bf930(&sStack_2a,1,2,iVar4);
      *(int *)(iVar9 + 0x10 + DAT_006ab880) = (int)sStack_2a;
      FUN_004bf930(&sStack_2a,1,2,iVar4);
      *(int *)(iVar9 + 0x14 + DAT_006ab880) = (int)sStack_2a;
      DAT_006ab884 = DAT_006ab884 +
                     *(int *)(iVar9 + 0xc + DAT_006ab880) * *(int *)(iVar9 + 8 + DAT_006ab880);
      FUN_004b7b50(iVar7);
      FUN_004b7e20(iVar7,&iStack_1c);
      puVar8 = *(undefined2 **)(iVar9 + DAT_006ab880);
      puStack_24 = puVar8;
      switch(DAT_006ab82c) {
      case 0:
        FUN_004afce0(s_pf_none_00501228);
        iStack_28 = 0;
        if (0 < *(int *)(iVar9 + 0xc + DAT_006ab880)) {
          do {
            FUN_004bf930(puVar8,1,*(undefined4 *)(iVar9 + 8 + DAT_006ab880),iVar4);
            puVar8 = (undefined2 *)((int)puVar8 + iStack_1c);
            iStack_28 = iStack_28 + 1;
          } while (iStack_28 < *(int *)(iVar9 + 0xc + DAT_006ab880));
        }
        break;
      case 1:
        FUN_004afce0(s_converting_to_16_bits_0050124c);
        iStack_28 = 0;
        iVar5 = DAT_006ab880;
        if (0 < *(int *)(iVar9 + 0xc + DAT_006ab880)) {
          do {
            iVar7 = 0;
            if (0 < *(int *)(iVar9 + 8 + iVar5)) {
              do {
                FUN_004bf930(&uStack_8,1,1,iVar4);
                uVar3 = FUN_004b5740(uStack_8 & 0xff,8);
                *puVar8 = uVar3;
                puVar8 = puVar8 + 1;
                iVar7 = iVar7 + 1;
                iVar5 = DAT_006ab880;
              } while (iVar7 < *(int *)(iVar9 + 8 + DAT_006ab880));
            }
            puVar8 = (undefined2 *)((int)puStack_24 + iStack_1c);
            iStack_28 = iStack_28 + 1;
            iVar7 = local_20;
            puStack_24 = puVar8;
          } while (iStack_28 < *(int *)(iVar9 + 0xc + iVar5));
        }
        break;
      case 2:
        FUN_004afce0(s_converting_to_24_bits_00501234);
        iStack_28 = 0;
        iVar5 = DAT_006ab880;
        if (0 < *(int *)(iVar9 + 0xc + DAT_006ab880)) {
          do {
            iVar7 = 0;
            if (0 < *(int *)(iVar9 + 8 + iVar5)) {
              do {
                FUN_004bf930(&uStack_4,1,1,iVar4);
                FUN_004b5910(uStack_4 & 0xff,8,puVar8);
                puVar8 = (undefined2 *)((int)puVar8 + 3);
                iVar7 = iVar7 + 1;
                iVar5 = DAT_006ab880;
              } while (iVar7 < *(int *)(iVar9 + 8 + DAT_006ab880));
            }
            puVar8 = (undefined2 *)((int)puStack_24 + iStack_1c);
            iStack_28 = iStack_28 + 1;
            iVar7 = local_20;
            puStack_24 = puVar8;
          } while (iStack_28 < *(int *)(iVar9 + 0xc + iVar5));
        }
        break;
      case 4:
        FUN_004afce0(s_converting_from_24_to_16_bits_00501264);
        iStack_28 = 0;
        iVar5 = DAT_006ab880;
        if (0 < *(int *)(iVar9 + 0xc + DAT_006ab880)) {
          do {
            iVar7 = 0;
            if (0 < *(int *)(iVar9 + 8 + iVar5)) {
              do {
                FUN_004bf930(&uStack_c,1,1,iVar4);
                FUN_004bf930(&param_2,1,1,iVar4);
                FUN_004bf930(&param_1,1,1,iVar4);
                uVar3 = FUN_004b5740((uint)CONCAT11((undefined1)param_1,(undefined1)param_2) << 8 |
                                     uStack_c & 0xff,0x18);
                *puVar8 = uVar3;
                puVar8 = puVar8 + 1;
                iVar7 = iVar7 + 1;
                iVar5 = DAT_006ab880;
              } while (iVar7 < *(int *)(iVar9 + 8 + DAT_006ab880));
            }
            puVar8 = (undefined2 *)((int)puStack_24 + iStack_1c);
            iStack_28 = iStack_28 + 1;
            iVar7 = local_20;
            puStack_24 = puVar8;
          } while (iStack_28 < *(int *)(iVar9 + 0xc + iVar5));
        }
      }
      FUN_004b7e90(iVar7);
      piVar6 = local_18 + 1;
      iVar9 = local_14;
      piVar2 = piVar6;
      piVar1 = param_3;
      iVar7 = *piVar6;
    }
    local_18 = piVar6;
    FUN_004bf2c5(iVar9);
    FUN_004bf2c5(iVar4);
  }
  return 0;
}

