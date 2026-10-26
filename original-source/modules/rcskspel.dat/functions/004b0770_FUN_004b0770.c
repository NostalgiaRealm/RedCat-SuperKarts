/*
 * FUN_004b0770 at 004b0770
 * undefined FUN_004b0770(void)
 * Address ranges: 004b0770-004b07f2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b0770(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 unaff_ESI;
  undefined4 *puVar3;
  undefined4 local_6c [4];
  undefined4 uStack_5c;
  undefined4 *puStack_c;
  
  puVar3 = local_6c;
  for (iVar2 = 0x1b; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  local_6c[0] = 0x6c;
  FUN_004b08e0(param_1);
  iVar2 = (**(code **)(*param_1 + 100))(param_1,0,local_6c,1,0);
  if (iVar2 != 0) {
    uVar1 = FUN_004b0190(iVar2);
    FUN_004afee0(s__s__d____could_not_lock_surface___004ff3c0,
                 s_C__libraries_dxdraw_surface_cpp_004ff3e8,0x100,uVar1);
    *puStack_c = unaff_ESI;
    return uStack_5c;
  }
  *puStack_c = unaff_ESI;
  return uStack_5c;
}

