/*
 * FUN_004b0680 at 004b0680
 * undefined FUN_004b0680(void)
 * Address ranges: 004b0680-004b0761
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b0680(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 unaff_ESI;
  undefined4 local_6c [4];
  undefined4 uStack_5c;
  undefined4 *puStack_c;
  
  if (param_1 == (int *)0x0) {
    param_1 = DAT_006a64bc;
    if (DAT_006a64cc == 0) {
      return 0;
    }
  }
  else if (param_1 == (int *)0x1) {
    param_1 = DAT_006a64c0;
    if (DAT_006a64d0 == 0) {
      return 0;
    }
  }
  else if (param_1 == (int *)0x2) {
    param_1 = DAT_006a64a0;
    if (DAT_006a64d4 == 0) {
      return 0;
    }
  }
  else {
    FUN_004afee0(s__s__d____unidentified_focus_erro_004ff408,
                 s_C__libraries_dxdraw_surface_cpp_004ff3e8,0xc4,param_1);
  }
  puVar3 = (undefined4 *)&stack0xffffff90;
  for (iVar2 = 0x1b; puVar3 = puVar3 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
  }
  local_6c[0] = 0x6c;
  FUN_004b08e0(param_1);
  iVar2 = (**(code **)(*param_1 + 100))(param_1,0,local_6c,1,0);
  if (iVar2 != 0) {
    uVar1 = FUN_004b0190(iVar2);
    FUN_004afee0(s__s__d____could_not_lock_surface___004ff3c0,
                 s_C__libraries_dxdraw_surface_cpp_004ff3e8,0xcf,uVar1);
  }
  *puStack_c = unaff_ESI;
  return uStack_5c;
}

