/*
 * FUN_004ac010 at 004ac010
 * undefined FUN_004ac010(void)
 * Address ranges: 004ac010-004ac3a0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004ac010(int param_1,uint *param_2,uint *param_3,int param_4,undefined4 *param_5)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  uint **ppuVar7;
  int iVar8;
  undefined2 *puVar9;
  uint *puStack_5c;
  uint uStack_58;
  char *pcStack_54;
  undefined1 *puStack_50;
  uint *puStack_4c;
  char *pcStack_48;
  int *piStack_44;
  char *pcStack_40;
  char local_29;
  undefined1 uStack_28;
  byte bStack_27;
  undefined1 uStack_26;
  undefined1 local_25;
  uint uStack_24;
  uint uStack_20;
  uint uStack_1c;
  uint uStack_18;
  uint uStack_14;
  uint uStack_10;
  uint local_c;
  int iStack_8;
  undefined1 *puStack_4;
  
  pcStack_40 = (char *)DAT_006ab81c;
  piStack_44 = (int *)DAT_006ab80c;
  pcStack_48 = s_Rshift___d__Rpos___d_004fdbf0;
  puStack_4c = (uint *)0x4ac02e;
  FUN_004afce0();
  puStack_4c = (uint *)DAT_006ab820;
  puStack_50 = (undefined1 *)DAT_006ab810;
  pcStack_54 = s_Gshift___d__Gpos___d_004fdbd8;
  uStack_58 = 0x4ac045;
  FUN_004afce0();
  uStack_58 = DAT_006ab824;
  puStack_5c = DAT_006ab814;
  FUN_004afce0(s_Bshift___d__Bpos___d_004fdbc0);
  puVar6 = param_5;
  ppuVar7 = &puStack_5c;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppuVar7 = (uint *)*puVar6;
    puVar6 = puVar6 + 1;
    ppuVar7 = ppuVar7 + 1;
  }
  FUN_004b5c20();
  iVar3 = FUN_004b96d0(param_1);
  if (iVar3 == 0) {
    return param_4;
  }
  pcStack_40 = s_Reading_TGA_file_004fdbac;
  piStack_44 = (int *)0x4ac095;
  FUN_004afce0();
  pcStack_48 = (char *)0x1;
  puStack_50 = &local_25;
  puStack_4c = (uint *)0x1;
  pcStack_54 = (char *)0x4ac0a4;
  piStack_44 = (int *)iVar3;
  FUN_004bf930();
  uStack_58 = 1;
  puStack_5c = (uint *)0x1;
  pcStack_54 = (char *)iVar3;
  FUN_004bf930(&local_29);
  if (local_29 != '\0') {
    pcStack_40 = (char *)0x28;
    piStack_44 = (int *)s_D__work_libs_DX3D_Tga_cpp_004fdb90;
    pcStack_48 = s__s__d____TGA_cannot_be_colormapp_004fdb6c;
    puStack_4c = (uint *)0x4ac0cf;
    FUN_004afee0();
  }
  piStack_44 = (int *)0x1;
  puStack_4c = &local_c;
  pcStack_48 = (char *)0x1;
  puStack_50 = (undefined1 *)0x4ac0e1;
  pcStack_40 = (char *)iVar3;
  FUN_004bf930();
  if ((char)local_c != '\x02') {
    pcStack_40 = (char *)(local_c & 0xff);
    piStack_44 = (int *)0x2e;
    pcStack_48 = s_D__work_libs_DX3D_Tga_cpp_004fdb90;
    puStack_4c = (uint *)s__s__d____No_RGB_uncompressed_TGA_004fdb44;
    puStack_50 = (undefined1 *)0x4ac103;
    FUN_004afee0();
  }
  iVar8 = 5;
  do {
    piStack_44 = (int *)0x1;
    puStack_4c = (uint *)&uStack_28;
    pcStack_48 = (char *)0x1;
    puStack_50 = (undefined1 *)0x4ac11a;
    pcStack_40 = (char *)iVar3;
    FUN_004bf930();
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  iVar8 = 4;
  do {
    piStack_44 = (int *)0x1;
    puStack_4c = (uint *)&uStack_28;
    pcStack_48 = (char *)0x1;
    puStack_50 = (undefined1 *)0x4ac134;
    pcStack_40 = (char *)iVar3;
    FUN_004bf930();
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  piStack_44 = (int *)0x1;
  puStack_4c = &uStack_1c;
  pcStack_48 = (char *)0x2;
  puStack_50 = (undefined1 *)0x4ac149;
  pcStack_40 = (char *)iVar3;
  FUN_004bf930();
  pcStack_54 = (char *)0x1;
  puStack_5c = &uStack_24;
  uStack_58 = 2;
  puStack_50 = (undefined1 *)iVar3;
  FUN_004bf930();
  FUN_004bf930(&uStack_20,1,1,iVar3);
  FUN_004bf930(&bStack_27,1,1,iVar3);
  if (((char)uStack_20 != ' ') && ((char)uStack_20 != '\x18')) {
    pcStack_40 = (char *)(uStack_20 & 0xff);
    piStack_44 = (int *)s_ERROR__load_tga___not_a_32_or_24_004fdb0c;
    pcStack_48 = (char *)0x4ac195;
    FUN_004afce0();
    return 0;
  }
  pcStack_40 = (char *)(uStack_24 & 0xffff);
  *param_2 = uStack_1c & 0xffff;
  *param_3 = (uint)pcStack_40;
  piStack_44 = (int *)*param_2;
  pcStack_48 = s_creating_surface__d__d_004fdaf4;
  puStack_4c = (uint *)0x4ac1d0;
  FUN_004afce0();
  pcStack_54 = (char *)*param_3;
  uStack_58 = *param_2;
  puStack_4c = param_5;
  puStack_50 = (undefined1 *)param_4;
  puStack_5c = (uint *)0x4ac1e2;
  iVar8 = FUN_004b0a10();
  if ((bStack_27 & 0x20) == 0x20) {
    param_2 = (uint *)0x1;
    param_1 = 0;
  }
  else {
    param_2 = (uint *)0xffffffff;
    param_1 = (uStack_24 & 0xffff) - 1;
  }
  piStack_44 = (int *)0x4ac223;
  pcStack_40 = (char *)iVar8;
  FUN_004b08e0();
  piStack_44 = &iStack_8;
  puStack_4c = (uint *)0x4ac22e;
  pcStack_48 = (char *)iVar8;
  pcStack_40 = (char *)FUN_004b0770();
  param_3 = (uint *)0x0;
  uVar2 = uStack_1c;
  puStack_4 = pcStack_40;
  if ((short)uStack_24 != 0) {
    do {
      iVar4 = 0;
      puVar9 = (undefined2 *)(pcStack_40 + iStack_8 * param_1);
      puVar5 = pcStack_40;
      if ((short)uVar2 != 0) {
        do {
          piStack_44 = (int *)0x1;
          puStack_4c = &uStack_18;
          pcStack_48 = (char *)0x1;
          puStack_50 = (undefined1 *)0x4ac276;
          pcStack_40 = (char *)iVar3;
          FUN_004bf930();
          pcStack_54 = (char *)0x1;
          puStack_5c = &uStack_14;
          uStack_58 = 1;
          puStack_50 = (undefined1 *)iVar3;
          FUN_004bf930();
          FUN_004bf930(&uStack_10,1,1,iVar3);
          if ((char)uStack_20 == ' ') {
            piStack_44 = (int *)0x1;
            puStack_4c = (uint *)&uStack_26;
            pcStack_48 = (char *)0x1;
            puStack_50 = (undefined1 *)0x4ac2ae;
            pcStack_40 = (char *)iVar3;
            FUN_004bf930();
          }
          if (DAT_004fe938 == 8) {
            *puVar5 = 0;
            puVar5 = puVar5 + 1;
          }
          if (DAT_004fe938 == 0x10) {
            if (((char)uStack_20 == ' ') && ((*(byte *)(param_5 + 1) & 1) != 0)) {
              pcStack_40 = (char *)0x20;
              piStack_44 = (int *)(((uint)CONCAT11(uStack_26,(undefined1)uStack_10) << 8 |
                                   uStack_14 & 0xff) << 8 | uStack_18 & 0xff);
            }
            else {
              pcStack_40 = (char *)0x18;
              piStack_44 = (int *)((uint)CONCAT11((undefined1)uStack_18,(undefined1)uStack_14) << 8
                                  | uStack_10 & 0xff);
            }
            pcStack_48 = (char *)0x4ac325;
            uVar1 = FUN_004b5740();
            *puVar9 = uVar1;
            puVar9 = puVar9 + 1;
          }
          iVar4 = iVar4 + 1;
          uVar2 = uStack_1c;
          pcStack_40 = puStack_4;
        } while (iVar4 < (int)(uStack_1c & 0xffff));
      }
      param_1 = param_1 + (int)param_2;
      param_3 = (uint *)((int)param_3 + 1);
    } while ((int)param_3 < (int)(uStack_24 & 0xffff));
  }
  pcStack_48 = (char *)0x4ac37b;
  piStack_44 = (int *)iVar8;
  FUN_004b08a0();
  puStack_4c = (uint *)0x4ac381;
  pcStack_48 = (char *)iVar3;
  FUN_004b9840();
  pcStack_40 = (char *)0x4ac389;
  FUN_004b5ad0();
  return iVar8;
}

