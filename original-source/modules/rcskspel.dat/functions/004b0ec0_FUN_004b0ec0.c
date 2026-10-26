/*
 * FUN_004b0ec0 at 004b0ec0
 * undefined FUN_004b0ec0(void)
 * Address ranges: 004b0ec0-004b14d5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004b0ec0(void)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  int *piStack_90;
  int *piStack_8c;
  int **ppiStack_88;
  int *local_7c;
  undefined4 uStack_78;
  int *local_74;
  int *local_70;
  int local_6c [5];
  int local_58;
  undefined4 local_4;
  
  local_7c = (int *)0x0;
  local_70 = DAT_004fead8;
  local_74 = DAT_004fead8;
  cVar1 = FUN_004afcb0();
  if (cVar1 != '\0') {
    DAT_004fe940 = 0;
  }
  if (DAT_006a64e0 == 0) {
    while( true ) {
      piVar3 = local_6c;
      for (iVar4 = 0x1b; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar3 = 0;
        piVar3 = piVar3 + 1;
      }
      local_6c[0] = 0x6c;
      if (DAT_004fe940 == 0) {
        local_4 = 0x2200;
        local_6c[1] = 1;
      }
      else {
        local_6c[1] = 0x21;
        local_4 = 0x2218;
      }
      ppiStack_88 = (int **)s_creating_004ff734;
      piStack_8c = (int *)0x4b0f56;
      local_58 = DAT_004fe940;
      FUN_004afce0();
      piStack_90 = local_6c;
      ppiStack_88 = (int **)0x0;
      piStack_8c = (int *)&DAT_006a64bc;
      iVar4 = (**(code **)(*DAT_006a649c + 0x18))(DAT_006a649c);
      if (iVar4 != 0) {
        uVar2 = FUN_004b0190(iVar4);
        FUN_004afee0(s__s__d____could_not_create_primar_004ff700,
                     s_C__libraries_dxdraw_Initlib_cpp_004feb14,0x715,uVar2);
      }
      iVar4 = (**(code **)*DAT_006a64bc)(DAT_006a64bc,&DAT_004d34b0,&DAT_006a6450);
      if (iVar4 != 0) {
        uVar2 = FUN_004b0190(iVar4);
        FUN_004afee0(s__s__d____could_not_create_dd2_su_004ff6cc,
                     s_C__libraries_dxdraw_Initlib_cpp_004feb14,0x718,uVar2);
      }
      FUN_004afce0(s_locking_004ff6c0);
      iVar4 = FUN_004b0b50(0);
      if (iVar4 != 0) break;
      if ((DAT_004fe940 == 0) || (DAT_006a64f0 != 0)) goto LAB_004b1051;
      (**(code **)(*DAT_006a64bc + 8))(DAT_006a64bc);
      (**(code **)(*DAT_006a6450 + 8))(DAT_006a6450);
      DAT_004fe940 = 0;
    }
    DAT_006a64cc = 1;
    uVar2 = FUN_004b0770(DAT_006a64bc,&DAT_006a643c);
    FUN_004afce0(s_locking_inter_004ff6b0);
    FUN_004b08a0(DAT_006a64bc,uVar2);
    FUN_004afce0(s_locking_done_004ff6a0);
LAB_004b1051:
    FUN_004afce0(s_getting_pixel_format_004ff688);
    FUN_004b5ad0();
    piVar3 = DAT_004fead8;
    if (DAT_006ab82c != 0) {
      if (DAT_006ab82c == 4) {
        piVar3 = (int *)FUN_004b5740(DAT_006a6500,0x18);
      }
      else {
        piVar3 = (int *)FUN_004b5740(DAT_004fead8,8);
      }
    }
    piStack_90 = piVar3;
    piStack_8c = piVar3;
    iVar4 = (**(code **)(*DAT_006a64bc + 0x74))(DAT_006a64bc,8,&piStack_90);
    if (iVar4 != 0) {
      ppiStack_88 = (int **)0x4b10c1;
      ppiStack_88 = (int **)FUN_004b0190();
      piStack_8c = (int *)0x74b;
      piStack_90 = (int *)s_C__libraries_dxdraw_Initlib_cpp_004feb14;
      FUN_004afee0(s__s__d____failed_to_set_color_key_004ff660);
    }
    DAT_006a64e0 = 1;
  }
  if (DAT_006a64e4 != 0) goto LAB_004b12f0;
  if (DAT_004fe940 == 0) {
    ppiStack_88 = (int **)0x4b11d5;
    FUN_004afce0();
    ppiStack_88 = (int **)0x4b11da;
    cVar1 = FUN_004afcb0();
    ppiStack_88 = (int **)((-(uint)(cVar1 != '\0') & 0x3800) + 0x800 | 0x2000);
    piStack_8c = DAT_004fe934;
    piStack_90 = DAT_004fe930;
    DAT_006a64c0 = (int *)FUN_004b0980();
    ppiStack_88 = (int **)&DAT_004d34b0;
    piStack_90 = (int *)0x4b1216;
    piStack_8c = DAT_006a64c0;
    iVar4 = (**(code **)*DAT_006a64c0)();
    if (iVar4 != 0) {
      uVar2 = FUN_004b0190(iVar4);
      FUN_004afee0(s__s__d____unable_to_create_attach_004ff61c,
                   s_C__libraries_dxdraw_Initlib_cpp_004feb14,0x774,uVar2);
    }
    iVar4 = FUN_004b0b50(1);
    if (iVar4 != 0) {
      DAT_006a64d0 = 1;
      uVar2 = FUN_004b0770(DAT_006a64c0,&DAT_006a64a8);
      FUN_004b08a0(DAT_006a64c0,uVar2);
      pcVar5 = s_back_screen_locking_done2_004ff5bc;
      goto LAB_004b126d;
    }
  }
  else {
    ppiStack_88 = (int **)0x4b110b;
    FUN_004afce0();
    ppiStack_88 = (int **)&uStack_78;
    uStack_78 = 4;
    piStack_8c = DAT_006a64bc;
    piStack_90 = (int *)0x4b112b;
    piStack_90 = (int *)(**(code **)(*DAT_006a64bc + 0x30))();
    if (piStack_90 != (int *)0x0) {
      uVar2 = FUN_004b0190();
      FUN_004afee0(s__s__d____unable_to_create_attach_004ff61c,
                   s_C__libraries_dxdraw_Initlib_cpp_004feb14,0x758,uVar2);
    }
    piStack_90 = (int *)&DAT_006a64c8;
    iVar4 = (**(code **)*DAT_006a64c0)(DAT_006a64c0,&DAT_004d34b0);
    if (iVar4 != 0) {
      uVar2 = FUN_004b0190(iVar4);
      FUN_004afee0(s__s__d____unable_to_create_attach_004ff61c,
                   s_C__libraries_dxdraw_Initlib_cpp_004feb14,0x75c,uVar2);
    }
    FUN_004afce0(s_back_screen_locking_1_004ff604);
    iVar4 = FUN_004b0b50(1);
    if (iVar4 != 0) {
      DAT_006a64d0 = 1;
      uVar2 = FUN_004b0770(DAT_006a64c0,&DAT_006a64a8);
      FUN_004b08a0(DAT_006a64c0,uVar2);
      pcVar5 = s_back_screen_locking_done1_004ff5e8;
LAB_004b126d:
      FUN_004afce0(pcVar5);
    }
  }
  piVar3 = DAT_004fead8;
  if (DAT_006ab82c != 0) {
    if (DAT_006ab82c == 4) {
      piVar3 = (int *)FUN_004b5740(DAT_006a6500,0x18);
    }
    else {
      piVar3 = (int *)FUN_004b5740(DAT_004fead8,8);
    }
  }
  piStack_8c = piVar3;
  ppiStack_88 = (int **)piVar3;
  iVar4 = (**(code **)(*DAT_006a64c0 + 0x74))(DAT_006a64c0,8,&piStack_8c);
  if (iVar4 != 0) {
    ppiStack_88 = (int **)0x4b12d2;
    ppiStack_88 = (int **)FUN_004b0190();
    piStack_8c = (int *)0x79b;
    piStack_90 = (int *)s_C__libraries_dxdraw_Initlib_cpp_004feb14;
    FUN_004afee0(s__s__d____failed_to_set_color_key_004ff660);
  }
  DAT_006a64e4 = 1;
LAB_004b12f0:
  if (DAT_006a64e8 == 0) {
    ppiStack_88 = (int **)DAT_004fe934;
    piStack_8c = DAT_004fe930;
    piStack_90 = (int *)0x4b1314;
    DAT_006a64a0 = (int *)FUN_004b0980();
    ppiStack_88 = (int **)&DAT_004d34b0;
    piStack_90 = (int *)0x4b132b;
    piStack_8c = DAT_006a64a0;
    piStack_90 = (int *)(**(code **)*DAT_006a64a0)();
    if (piStack_90 != (int *)0x0) {
      uVar2 = FUN_004b0190();
      FUN_004afee0(s__s__d____query_interface_for_sur_004ff588,
                   s_C__libraries_dxdraw_Initlib_cpp_004feb14,0x7a4,uVar2);
    }
    piStack_90 = (int *)0x2;
    iVar4 = FUN_004b0b50();
    if (iVar4 != 0) {
      piStack_90 = &DAT_006a64b8;
      DAT_006a64d4 = 1;
      uVar2 = FUN_004b0770(DAT_006a64a0);
      FUN_004b08a0(DAT_006a64a0,uVar2);
    }
    piVar3 = DAT_004fead8;
    if (DAT_006ab82c != 0) {
      if (DAT_006ab82c == 4) {
        piStack_90 = (int *)0x18;
        piVar3 = (int *)FUN_004b5740(DAT_006a6500);
      }
      else {
        piStack_90 = (int *)0x8;
        piVar3 = (int *)FUN_004b5740(DAT_004fead8);
      }
    }
    piStack_90 = (int *)&stack0xffffff80;
    local_7c = piVar3;
    iVar4 = (**(code **)(*DAT_006a64a0 + 0x74))(DAT_006a64a0,8);
    if (iVar4 != 0) {
      ppiStack_88 = (int **)0x4b13dd;
      ppiStack_88 = (int **)FUN_004b0190();
      piStack_8c = (int *)0x7c9;
      piStack_90 = (int *)s_C__libraries_dxdraw_Initlib_cpp_004feb14;
      FUN_004afee0(s__s__d____failed_to_set_color_key_004ff660);
    }
    DAT_006a64e8 = 1;
  }
  cVar1 = FUN_004afcb0();
  if (cVar1 != '\0') {
    ppiStack_88 = &local_7c;
    piStack_8c = (int *)0x0;
    piStack_90 = (int *)0x4b1416;
    piStack_90 = (int *)DirectDrawCreateClipper();
    if (piStack_90 != (int *)0x0) {
      uVar2 = FUN_004b0190();
      FUN_004afee0(s__s__d____failed_create_Clipper_o_004ff558,
                   s_C__libraries_dxdraw_Initlib_cpp_004feb14,0x7d5,uVar2);
    }
    piStack_90 = DAT_006a64b4;
    piVar3 = (int *)0x0;
    iVar4 = (*(code *)(*ppiStack_88)[8])(ppiStack_88);
    if (iVar4 != 0) {
      uVar2 = FUN_004b0190(iVar4);
      FUN_004afee0(s__s__d____failed_set_Clipper_HWND_004ff530,
                   s_C__libraries_dxdraw_Initlib_cpp_004feb14,0x7dc,uVar2);
    }
    iVar4 = (**(code **)(*DAT_006a64bc + 0x70))(DAT_006a64bc);
    if (iVar4 != 0) {
      uVar2 = FUN_004b0190(iVar4);
      FUN_004afee0(s__s__d____failed_set_Prim_surf_Cl_004ff500,
                   s_C__libraries_dxdraw_Initlib_cpp_004feb14,0x7e3,uVar2);
    }
    (**(code **)(*piVar3 + 8))(piVar3);
  }
  ppiStack_88 = (int **)0x4b14b3;
  FUN_004afce0();
  ppiStack_88 = (int **)0x4b14b8;
  FUN_004b2160();
  ppiStack_88 = (int **)0x0;
  piStack_8c = (int *)0x2;
  piStack_90 = (int *)0x4b14c1;
  FUN_004b0e90();
  piStack_90 = (int *)0x0;
  FUN_004b0e90(1);
  FUN_004aff70();
  return;
}

