/*
 * FUN_004ac410 at 004ac410
 * undefined FUN_004ac410(void)
 * Address ranges: 004ac410-004ac56b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004ac410(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_004afce0(s_init_3d_library__version__d_004fdd38,s_Sep_30_1999_004fc344);
  FUN_004a1510(param_4);
  FUN_004ac3c0();
  FUN_004afce0(s_init_z_buffer_004fdd28);
  iVar1 = FUN_004ac570(param_1,0x10,DAT_004fe930,DAT_004fe934);
  if (iVar1 == 0) {
    FUN_004afee0(s__s__d____D3D___Error_creating_Z__004fdcfc,s_D__work_libs_DX3D_D3dlib_cpp_004fdc08
                 ,0x40);
  }
  FUN_004afce0(s_z_buffer_initialized____d_004fdce0,DAT_006a62e0);
  FUN_004afce0(s_init_d3d_device_004fdccc);
  if (DAT_006a62e4 == 0) {
    FUN_004aacd0(param_1);
  }
  else {
    FUN_004aace0(param_1,3);
  }
  FUN_004afce0(s_setting_palette_004fdcb8);
  FUN_004b2340(DAT_006ab468,0,0x100);
  FUN_004afce0(s_enum_texture_formats_004fdca0);
  FUN_004ae490();
  if (DAT_004fe938 < 9) {
    uVar2 = 2;
  }
  else {
    uVar2 = 3;
  }
  FUN_004ae5e0(uVar2);
  FUN_004afce0(s_init_lights_004fdc90);
  FUN_004afa10(param_2);
  FUN_004afce0(s_init_materials_004fdc80);
  FUN_004ab8f0(param_3);
  FUN_004afce0(s_init_viewport_004fdc70);
  FUN_004ac910(10);
  FUN_004afce0(s_add_a_viewport_004fdc60);
  uVar2 = FUN_004acb90();
  FUN_004acc90(uVar2);
  FUN_004afce0(s_init_viewport_ok_004fdc4c);
  FUN_004afce0(s_clear_z_buffer_004fdc3c);
  FUN_004ac6e0();
  FUN_004afce0(s_clear_z_buffer_ok_004fdc28);
  return 1;
}

