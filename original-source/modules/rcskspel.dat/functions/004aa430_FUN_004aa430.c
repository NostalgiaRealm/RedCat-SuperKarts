/*
 * FUN_004aa430 at 004aa430
 * undefined FUN_004aa430(void)
 * Address ranges: 004aa430-004aa4a6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004aa430(int *param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (*param_1 != 1) {
    FUN_004afee0(s__s__d____mesh_is_not_of_requeste_004fa744,s___mesh_inl_004fd168,0x4b);
  }
  if (param_1[1] != 1) {
    FUN_004afee0(s__s__d____vertices_were_not__yet__004fa714,s___mesh_inl_004fd168,0x4e);
  }
  if ((param_3 < 0) || (param_1[0x1f] <= param_3)) {
    FUN_004afee0(s__s__d____index__d_is_out_of_VERT_004fa6e0,s___mesh_inl_004fd168,0x51,param_3,
                 param_1[0x1f]);
  }
  puVar2 = (undefined4 *)(param_1[0x1e] + param_3 * 0x20);
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_2 = *puVar2;
    puVar2 = puVar2 + 1;
    param_2 = param_2 + 1;
  }
  return;
}

