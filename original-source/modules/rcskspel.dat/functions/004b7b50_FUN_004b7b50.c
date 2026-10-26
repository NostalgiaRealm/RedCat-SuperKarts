/*
 * FUN_004b7b50 at 004b7b50
 * undefined FUN_004b7b50(void)
 * Address ranges: 004b7b50-004b7d50
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b7b50(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  HLOCAL pvVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  SIZE_T uBytes;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if ((param_1 < 0) || (DAT_00501110 <= param_1)) {
    FUN_004afee0(s__s__d____index_out_of_mem_image_a_00501004,
                 s_C__libraries_dxdraw_Sprite_cpp_00501114,0x116,param_1);
  }
  iVar7 = param_1 * 0x20;
  iVar6 = *(int *)(iVar7 + 8 + DAT_006ab880);
  if (iVar6 < 1) {
    FUN_004afee0(s__s__d____illegal_mem_xsize____d___005011fc,
                 s_C__libraries_dxdraw_Sprite_cpp_00501114,0x11a,param_1,iVar6);
  }
  iVar6 = *(int *)(iVar7 + 0xc + DAT_006ab880);
  if (iVar6 < 1) {
    FUN_004afee0(s__s__d____illegal_mem_ysize____d___005011d0,
                 s_C__libraries_dxdraw_Sprite_cpp_00501114,0x11d,param_1,iVar6);
  }
  iVar6 = *(int *)(iVar7 + 0xc + DAT_006ab880);
  iVar1 = *(int *)(iVar7 + 8 + DAT_006ab880);
  iVar2 = *(int *)(iVar7 + 0x18 + DAT_006ab880);
  uBytes = iVar6 * iVar1;
  if (iVar2 == 2) {
    if (DAT_006ab874 == 0) {
      uVar5 = FUN_004b0900(iVar1,iVar6);
      *(undefined4 *)(iVar7 + 4 + DAT_006ab880) = uVar5;
      if (*(int *)(iVar7 + 4 + DAT_006ab880) == 0) {
        return 2000;
      }
    }
    else {
      uVar5 = FUN_004b0900(iVar1,iVar6);
      *(undefined4 *)(iVar7 + 4 + DAT_006ab880) = uVar5;
      if (DAT_006ab87c == 0) {
        return 2000;
      }
    }
    uStack_8 = DAT_004fead8;
    if (DAT_006ab82c != 0) {
      if (DAT_006ab82c == 4) {
        uStack_8 = FUN_004b5740(DAT_006a6500,0x18);
      }
      else {
        uStack_8 = FUN_004b5740(DAT_004fead8,8);
      }
    }
    piVar3 = *(int **)(iVar7 + 4 + DAT_006ab880);
    uStack_4 = uStack_8;
    iVar6 = (**(code **)(*piVar3 + 0x74))(piVar3,8,&uStack_8);
    if (iVar6 != 0) {
      uVar5 = FUN_004b0190(iVar6);
      FUN_004afee0(s__s__d____failed_to_set_color_key_004ff660,
                   s_C__libraries_dxdraw_Sprite_cpp_00501114,0x14d,uVar5);
    }
  }
  else {
    if (iVar2 != 4) {
      FUN_004afee0(s__s__d____illegal_alloc_type__d_f_0050119c,
                   s_C__libraries_dxdraw_Sprite_cpp_00501114,0x152,iVar2,param_1);
      return 0;
    }
    if ((int)uBytes < 1) {
      FUN_004afee0(s__s__d____error_illegal_mem_image_00501168,
                   s_C__libraries_dxdraw_Sprite_cpp_00501114,0x127,uBytes,iVar1,iVar6);
    }
    pvVar4 = LocalAlloc(0x40,uBytes);
    *(HLOCAL *)(iVar7 + DAT_006ab880) = pvVar4;
    if (*(int *)(iVar7 + DAT_006ab880) == 0) {
      return 2000;
    }
  }
  *(undefined4 *)(iVar7 + 0x1c + DAT_006ab880) = 1;
  return 0;
}

