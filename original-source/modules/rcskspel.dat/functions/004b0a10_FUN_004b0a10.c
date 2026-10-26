/*
 * FUN_004b0a10 at 004b0a10
 * undefined FUN_004b0a10(void)
 * Address ranges: 004b0a10-004b0aa4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4
FUN_004b0a10(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_6c [18];
  undefined4 local_24 [8];
  undefined4 local_4;
  
  puVar3 = local_6c;
  for (iVar2 = 0x1b; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  local_6c[2] = param_2;
  local_6c[3] = param_1;
  local_4 = param_3;
  local_6c[0] = 0x6c;
  local_6c[1] = 0x1007;
  puVar3 = param_4;
  puVar4 = local_24;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  iVar2 = (**(code **)(*DAT_006a649c + 0x18))(DAT_006a649c,local_6c,&param_3,0);
  if (iVar2 != 0) {
    uVar1 = FUN_004b0190(iVar2);
    FUN_004afee0(s__s__d____could_not_create_surfac_004ff460,
                 s_C__libraries_dxdraw_surface_cpp_004ff3e8,0x341,uVar1);
  }
  return local_4;
}

