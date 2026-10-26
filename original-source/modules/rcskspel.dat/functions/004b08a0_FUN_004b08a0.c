/*
 * FUN_004b08a0 at 004b08a0
 * undefined FUN_004b08a0(void)
 * Address ranges: 004b08a0-004b08df
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004b08a0(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_004b08e0(param_1);
  iVar1 = (**(code **)(*param_1 + 0x80))(param_1,param_2);
  if (iVar1 != 0) {
    uVar2 = FUN_004b0190(iVar1);
    FUN_004afee0(s__s__d____could_not_unlock_surfac_004ff434,
                 s_C__libraries_dxdraw_surface_cpp_004ff3e8,0x178,uVar2);
  }
  return;
}

