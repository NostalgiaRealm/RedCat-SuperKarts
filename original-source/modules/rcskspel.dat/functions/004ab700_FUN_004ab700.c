/*
 * FUN_004ab700 at 004ab700
 * undefined FUN_004ab700(void)
 * Address ranges: 004ab700-004ab796
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004ab700(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  char *pcStack_1a4;
  undefined4 *puStack_1a0;
  undefined4 local_198 [48];
  undefined1 auStack_d8 [12];
  char local_cc [204];
  
  if (*(int *)(param_1 + 0x274) != 1) {
    puStack_1a0 = (undefined4 *)0xb8;
    pcStack_1a4 = s___d3dev_h_004fc8d4;
    FUN_004afee0(s__s__d____device_was_not_initiali_004fc8ac);
  }
  puStack_1a0 = local_198;
  local_cc[0] = -0x34;
  local_cc[1] = '\0';
  local_cc[2] = '\0';
  local_cc[3] = '\0';
  local_198[0] = 0xcc;
  pcStack_1a4 = local_cc;
  iVar1 = (**(code **)(**(int **)(param_1 + 0x25c) + 0xc))(*(int **)(param_1 + 0x25c));
  if (iVar1 != 0) {
    uVar2 = FUN_004aaa00(iVar1);
    FUN_004afee0(s__s__d____error_getting_device_ca_004fd9c0,s_D__work_libs_DX3D_D3dev_cpp_004fd92c,
                 0x130,uVar2);
  }
  FUN_004ae7f0(auStack_d8,&pcStack_1a4);
  FUN_004aedf0();
  return;
}

