/*
 * FUN_004b0900 at 004b0900
 * undefined FUN_004b0900(void)
 * Address ranges: 004b0900-004b097a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b0900(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_6c [24];
  undefined4 uStack_c;
  undefined4 local_4;
  
  puVar1 = local_6c;
  for (iVar3 = 0x1b; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  local_6c[2] = param_2;
  local_6c[3] = param_1;
  local_6c[0] = 0x6c;
  local_6c[1] = 7;
  local_4 = 0x800;
  iVar3 = (**(code **)(*DAT_006a649c + 0x18))(DAT_006a649c,local_6c,&param_1,0);
  if (iVar3 != 0) {
    uVar2 = FUN_004b0190(iVar3);
    FUN_004afee0(s__s__d____could_not_create_surfac_004ff460,
                 s_C__libraries_dxdraw_surface_cpp_004ff3e8,0x1cf,uVar2);
  }
  return uStack_c;
}

