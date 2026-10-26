/*
 * FUN_004ab5c0 at 004ab5c0
 * undefined FUN_004ab5c0(void)
 * Address ranges: 004ab5c0-004ab6ca
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_004ab5c0(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x270) = param_2;
  *(int *)(param_1 + 0x278) = param_3;
  if (param_3 == 1) {
    iVar1 = FUN_004ab370(0x84e63de0,0x11cf46aa,0x6f81,0x6e1520c0);
    if (iVar1 != 0) {
      return 0;
    }
  }
  else if (param_3 == 3) {
    iVar1 = FUN_004ab370(0xa4665c60,0x11cf2673,0xaa001aa3,0x5633b900);
    if (iVar1 != 0) {
      return 0;
    }
  }
  else if (param_3 == 4) {
    iVar1 = FUN_004ab370(0xf2086b20,0x11cf259f,0xaa001aa3,0x5633b900);
    if (iVar1 != 0) {
      return 0;
    }
  }
  else {
    FUN_004afee0(s__s__d____requested_unknown_devic_004fd994,s_D__work_libs_DX3D_D3dev_cpp_004fd92c,
                 0x110);
  }
  *(undefined4 *)(param_1 + 0x274) = 1;
  FUN_004ab700();
  FUN_004aaef0();
  return 1;
}

