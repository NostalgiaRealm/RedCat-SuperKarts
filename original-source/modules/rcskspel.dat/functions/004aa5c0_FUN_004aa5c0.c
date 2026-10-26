/*
 * FUN_004aa5c0 at 004aa5c0
 * undefined FUN_004aa5c0(void)
 * Address ranges: 004aa5c0-004aa6c0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall
FUN_004aa5c0(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 in_stack_00000020;
  undefined4 in_stack_00000024;
  
  if (param_1[1] == 0) {
    FUN_004afee0(s__s__d____mesh_has_not_been_initi_004fd30c,s___mesh_inl_004fd168,0x76);
  }
  if (*param_1 == 1) {
    if ((param_2 < 0) || (param_1[0x1f] <= param_2)) {
      FUN_004afee0(s__s__d____error__d_out_of_mesh_LV_004fa6a0,s___mesh_inl_004fd168,0x82,param_2,
                   param_1[0x21]);
    }
    param_2 = param_2 * 0x20;
    *(undefined4 *)(param_1[0x1e] + param_2) = param_3;
    *(undefined4 *)(param_1[0x1e] + 4 + param_2) = param_4;
    *(undefined4 *)(param_1[0x1e] + 8 + param_2) = param_5;
    *(undefined4 *)(param_1[0x1e] + 0xc + param_2) = param_3;
    *(undefined4 *)(param_1[0x1e] + 0x10 + param_2) = param_4;
    *(undefined4 *)(param_1[0x1e] + 0x14 + param_2) = param_5;
    *(undefined4 *)(param_1[0x1e] + 0x18 + param_2) = in_stack_00000020;
    *(undefined4 *)(param_1[0x1e] + 0x1c + param_2) = in_stack_00000024;
  }
  else if (*param_1 == 2) {
    if ((param_2 < 0) || (param_1[0x21] <= param_2)) {
      FUN_004afee0(s__s__d____error__d_out_of_mesh_LV_004fa6a0,s___mesh_inl_004fd168,0x7c,param_2,
                   param_1[0x21]);
    }
    puVar2 = &param_3;
    puVar3 = (undefined4 *)(param_1[0x20] + param_2 * 0x20);
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    return;
  }
  return;
}

