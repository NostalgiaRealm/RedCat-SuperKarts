/*
 * FUN_004b9c30 at 004b9c30
 * undefined FUN_004b9c30(void)
 * Address ranges: 004b9c30-004b9d3d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004b9c30(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_8;
  undefined4 local_4;
  
  local_4 = DAT_004fead8;
  local_8 = DAT_004fead8;
  if (DAT_00501c90 == 1) {
    DAT_006ab97c = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    if (DAT_006ab97c == (HCURSOR)0x0) {
      FUN_004afee0(s__s__d_____init_mouse__Unable_to_l_00501d6c,
                   s_C__libraries_dxdraw_Mouse_cpp_00501cc8,0x7a);
    }
  }
  else if (DAT_00501c90 == 2) {
    if (DAT_00501c88 == -1) {
      FUN_004afee0(s__s__d_____init_mouse__No_mouse_a_00501dac,
                   s_C__libraries_dxdraw_Mouse_cpp_00501cc8,0x80);
    }
    DAT_006ab980 = (int *)FUN_004b0900(0x40,0x40);
    uVar1 = DAT_004fead8;
    if (DAT_006ab82c != 0) {
      if (DAT_006ab82c == 4) {
        uVar1 = FUN_004b5740(DAT_006a6500,0x18);
      }
      else {
        uVar1 = FUN_004b5740(DAT_004fead8,8);
      }
    }
    local_8 = uVar1;
    local_4 = uVar1;
    iVar2 = (**(code **)(*DAT_006ab980 + 0x74))(DAT_006ab980,8,&local_8);
    if (iVar2 != 0) {
      uVar1 = FUN_004b0190(iVar2);
      FUN_004afee0(s__s__d____failed_to_set_color_key_004ff660,
                   s_C__libraries_dxdraw_Mouse_cpp_00501cc8,0x9f,uVar1);
      DAT_006ab95c = 1;
      return;
    }
  }
  DAT_006ab95c = 1;
  return;
}

