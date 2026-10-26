/*
 * FUN_004ac3c0 at 004ac3c0
 * undefined FUN_004ac3c0(void)
 * Address ranges: 004ac3c0-004ac3f3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004ac3c0(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)*DAT_006a64a4)(DAT_006a64a4,&DAT_004d4110,&DAT_006a62dc);
  if (iVar1 != 0) {
    uVar2 = FUN_004aaa00(iVar1);
    FUN_004afee0(s__s__d____D3DError____s_004fcc58,s_D__work_libs_DX3D_D3dlib_cpp_004fdc08,0x22,
                 uVar2);
  }
  return;
}

