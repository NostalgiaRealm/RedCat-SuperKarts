/*
 * FUN_004b0800 at 004b0800
 * undefined FUN_004b0800(void)
 * Address ranges: 004b0800-004b089b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004b0800(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  piVar1 = DAT_006a64bc;
  iVar2 = DAT_006a64cc;
  if (((param_1 == (int *)0x0) ||
      (piVar1 = DAT_006a64c0, iVar2 = DAT_006a64d0, param_1 == (int *)0x1)) ||
     (piVar1 = DAT_006a64a0, iVar2 = DAT_006a64d4, param_1 == (int *)0x2)) {
    param_1 = piVar1;
    if (iVar2 == 0) {
      return;
    }
  }
  else {
    FUN_004afee0(s__s__d____unidentified_focus_erro_004ff408,
                 s_C__libraries_dxdraw_surface_cpp_004ff3e8,0x159,param_1);
  }
  FUN_004b08e0(param_1);
  iVar2 = (**(code **)(*param_1 + 0x80))(param_1,param_2);
  if (iVar2 != 0) {
    uVar3 = FUN_004b0190(iVar2);
    FUN_004afee0(s__s__d____could_not_unlock_surfac_004ff434,
                 s_C__libraries_dxdraw_surface_cpp_004ff3e8,0x161,uVar3);
  }
  return;
}

