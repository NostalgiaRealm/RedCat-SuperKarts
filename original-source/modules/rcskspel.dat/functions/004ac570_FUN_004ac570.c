/*
 * FUN_004ac570 at 004ac570
 * undefined FUN_004ac570(void)
 * Address ranges: 004ac570-004ac6d7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004ac570(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 local_6c [6];
  undefined4 local_54;
  undefined4 local_4;
  
  puVar3 = local_6c;
  for (iVar2 = 0x1b; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  local_6c[0] = 0x6c;
  local_6c[1] = 0x47;
  local_4 = 0x20000;
  local_6c[2] = param_4;
  local_6c[3] = param_3;
  local_54 = param_2;
  if (param_1 == 2) {
    local_4 = 0x20800;
  }
  iVar2 = (**(code **)(*DAT_006a649c + 0x18))(DAT_006a649c,local_6c,&DAT_006a62d8,0);
  if (iVar2 != 0) {
    uVar1 = FUN_004aaa00(iVar2);
    FUN_004afee0(s__s__d____D3DError_Z_buffer_creat_004fde30,s_D__work_libs_DX3D_D3dlib_cpp_004fdc08
                 ,0x8c,uVar1);
  }
  if (param_1 == 0) {
    iVar2 = (**(code **)(*DAT_006a64bc + 0xc))(DAT_006a64bc,DAT_006a62d8);
    if (iVar2 == 0) {
      DAT_006a62e0 = 1;
      return;
    }
    uVar1 = FUN_004aaa00(iVar2);
    uVar5 = 0x97;
    pcVar4 = s__s__d____D3DError_Z_buffer_attac_004fdd58;
  }
  else if (param_1 == 1) {
    iVar2 = (**(code **)(*DAT_006a64c0 + 0xc))(DAT_006a64c0,DAT_006a62d8);
    if (iVar2 == 0) {
      DAT_006a62e0 = 1;
      return;
    }
    uVar1 = FUN_004aaa00(iVar2);
    uVar5 = 0x9e;
    pcVar4 = s__s__d____D3DError_Z_buffer_attac_004fdd90;
  }
  else {
    if (param_1 != 2) {
      FUN_004afee0(s__s__d____Illegal_focus_for_z_buf_004fde08,
                   s_D__work_libs_DX3D_D3dlib_cpp_004fdc08,0xaa);
      DAT_006a62e0 = 1;
      return;
    }
    iVar2 = (**(code **)(*DAT_006a64a0 + 0xc))(DAT_006a64a0,DAT_006a62d8);
    if (iVar2 == 0) {
      DAT_006a62e0 = 1;
      return;
    }
    uVar1 = FUN_004aaa00(iVar2);
    uVar5 = 0xa5;
    pcVar4 = s__s__d____D3DError_Z_buffer_attac_004fddcc;
  }
  FUN_004afee0(pcVar4,s_D__work_libs_DX3D_D3dlib_cpp_004fdc08,uVar5,uVar1);
  DAT_006a62e0 = 1;
  return;
}

