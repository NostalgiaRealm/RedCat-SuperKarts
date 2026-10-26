/*
 * FUN_004b0b50 at 004b0b50
 * undefined FUN_004b0b50(void)
 * Address ranges: 004b0b50-004b0c00
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_004b0b50(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 local_6c [27];
  
  if ((DAT_006a64f0 != 0) && (param_1 == (int *)0x0)) {
    return false;
  }
  piVar3 = DAT_006a64bc;
  if (((param_1 != (int *)0x0) && (piVar3 = DAT_006a64c0, param_1 != (int *)0x1)) &&
     (piVar3 = DAT_006a64a0, param_1 != (int *)0x2)) {
    FUN_004afee0(s__s__d____unidentified_focus_erro_004ff408,
                 s_C__libraries_dxdraw_surface_cpp_004ff3e8,0x440,param_1);
    piVar3 = param_1;
  }
  puVar2 = (undefined4 *)&stack0xffffff90;
  for (iVar1 = 0x1b; puVar2 = puVar2 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
  }
  local_6c[0] = 0x6c;
  FUN_004b08e0(piVar3);
  iVar1 = (**(code **)(*piVar3 + 100))(piVar3,0,local_6c,1,0);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*piVar3 + 0x80))(piVar3,0);
    return iVar1 == 0;
  }
  return false;
}

