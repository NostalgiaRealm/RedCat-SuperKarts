/*
 * FUN_004b6ec0 at 004b6ec0
 * undefined FUN_004b6ec0(void)
 * Address ranges: 004b6ec0-004b7111
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004b6ec0(int *param_1,int *param_2,int *param_3,int param_4,int *param_5,int param_6,
                 byte param_7)

{
  undefined4 uVar1;
  int iVar2;
  int *unaff_retaddr;
  int *piVar3;
  int *piStack_108;
  int *piStack_104;
  undefined4 *puStack_100;
  int local_fc;
  int *piStack_f8;
  int *piStack_f4;
  int *piStack_f0;
  int *piStack_ec;
  int *piStack_e0;
  int *piStack_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  int iStack_74;
  undefined4 *puStack_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 uStack_c;
  int *piStack_8;
  int *piStack_4;
  
  local_d4 = 6;
  local_68 = 6;
  puStack_100 = &local_d8;
  local_d8 = 0x6c;
  local_6c = 0x6c;
  piStack_104 = param_1;
  local_fc = 0x1000000;
  piStack_108 = (int *)0x4b6f00;
  piStack_108 = (int *)(**(code **)(*param_1 + 0x58))();
  if (piStack_108 != (int *)0x0) {
    uVar1 = FUN_004b0190();
    FUN_004afee0(s__s__d____DDError__blt_surf_2_sur_00500f64,
                 s_C__libraries_dxdraw_Clipblit_cpp_00500ce0,0x570,uVar1);
  }
  piStack_108 = &iStack_74;
  piVar3 = unaff_retaddr;
  iVar2 = (**(code **)(*unaff_retaddr + 0x58))(unaff_retaddr);
  if (iVar2 != 0) {
    uVar1 = FUN_004b0190(iVar2);
    FUN_004afee0(s__s__d____DDError__blt_surf_2_sur_00500f1c,
                 s_C__libraries_dxdraw_Clipblit_cpp_00500ce0,0x574,uVar1);
  }
  if ((param_7 & 8) != 0) {
    piVar3 = (int *)0x1008000;
  }
  if ((int)piStack_4 < 0) {
    piStack_4 = (int *)0x0;
  }
  if ((int)unaff_retaddr < 0) {
    unaff_retaddr = (int *)0x0;
  }
  if ((int)param_3 < 0) {
    param_3 = (int *)0x0;
  }
  if (param_4 < 0) {
    param_4 = 0;
  }
  if ((((0 < (int)param_1) && (0 < (int)param_2)) && ((int)piStack_4 <= (int)piStack_dc)) &&
     ((((int)unaff_retaddr <= (int)piStack_e0 && (0 < (int)param_5)) &&
      ((0 < param_6 && (((int)param_3 <= (int)puStack_70 && (param_4 <= iStack_74)))))))) {
    if ((int)piStack_dc < (int)param_1) {
      param_1 = piStack_dc;
    }
    if ((int)piStack_e0 < (int)param_2) {
      param_2 = piStack_e0;
    }
    if ((int)puStack_70 < (int)param_5) {
      param_5 = puStack_70;
    }
    if (iStack_74 < param_6) {
      param_6 = iStack_74;
    }
    if ((((piStack_4 != param_1) && (unaff_retaddr != param_2)) && (param_3 != param_5)) &&
       (param_4 != param_6)) {
      piStack_f8 = piStack_4;
      piStack_108 = param_3;
      piStack_104 = (int *)param_4;
      if (((0 < (int)param_5) && (0 < param_6)) && ((0 < (int)param_1 && (0 < (int)param_2)))) {
        puStack_100 = param_5;
        local_fc = param_6;
        piStack_f4 = unaff_retaddr;
        piStack_f0 = param_1;
        piStack_ec = param_2;
        iVar2 = (**(code **)(*piStack_8 + 0x14))
                          (piStack_8,&piStack_108,uStack_c,&piStack_f8,piVar3,0);
        if (iVar2 != 0) {
          uVar1 = FUN_004b0190(iVar2);
          FUN_004afee0(s__s__d____blt_surf_2_surf_blittin_004fcc74,
                       s_C__libraries_dxdraw_Clipblit_cpp_00500ce0,0x5af,uVar1);
        }
      }
    }
  }
  return;
}

