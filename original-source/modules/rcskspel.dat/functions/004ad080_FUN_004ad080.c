/*
 * FUN_004ad080 at 004ad080
 * undefined FUN_004ad080(void)
 * Address ranges: 004ad080-004ad0e1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004ad080(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  local_10 = *(int *)(param_1 + 4);
  local_c = *(int *)(param_1 + 8);
  local_8 = *(int *)(param_1 + 0xc) + local_10;
  local_4 = *(int *)(param_1 + 0x10) + local_c;
  iVar1 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x30))
                    (*(int **)(param_1 + 0x2c),1,&local_10,param_2);
  if (iVar1 != 0) {
    uVar2 = FUN_004aaa00(iVar1);
    FUN_004afee0(s__s__d___D3DError_Clearing_z_buff_004fe080,
                 s_D__work_libs_DX3D_Viewport_cpp_004fdf34,0xe1,uVar2);
  }
  return;
}

