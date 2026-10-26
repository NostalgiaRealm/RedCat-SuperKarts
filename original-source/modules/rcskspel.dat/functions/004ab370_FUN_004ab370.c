/*
 * FUN_004ab370 at 004ab370
 * undefined FUN_004ab370(void)
 * Address ranges: 004ab370-004ab450
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall
FUN_004ab370(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  int iVar1;
  undefined4 uVar2;
  
  *(undefined4 *)(param_1 + 0x260) = param_2;
  *(undefined4 *)(param_1 + 0x264) = param_3;
  *(undefined4 *)(param_1 + 0x268) = param_4;
  *(undefined4 *)(param_1 + 0x26c) = param_5;
  FUN_004afce0(s_Creating_d3d_device_with_GUID__d_004fd970,param_2,param_3,param_4,param_5);
  iVar1 = *(int *)(param_1 + 0x270);
  if (iVar1 == 0) {
    uVar2 = (**(code **)(*DAT_006a62dc + 0x20))(DAT_006a62dc,&param_2,DAT_006a64bc,param_1 + 0x25c);
    return uVar2;
  }
  if (iVar1 != 1) {
    if (iVar1 != 2) {
      FUN_004afee0(s__s__d____Illegal_focus_for_3d_de_004fd948,
                   s_D__work_libs_DX3D_D3dev_cpp_004fd92c,0xb5);
      return 0;
    }
    uVar2 = (**(code **)(*DAT_006a62dc + 0x20))(DAT_006a62dc,&param_2,DAT_006a64a0,param_1 + 0x25c);
    return uVar2;
  }
  uVar2 = (**(code **)(*DAT_006a62dc + 0x20))(DAT_006a62dc,&param_2,DAT_006a64c0,param_1 + 0x25c);
  return uVar2;
}

