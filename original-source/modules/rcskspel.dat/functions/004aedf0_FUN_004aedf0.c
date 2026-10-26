/*
 * FUN_004aedf0 at 004aedf0
 * undefined FUN_004aedf0(void)
 * Address ranges: 004aedf0-004aeffe
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004aedf0(void)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined *puVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  
  FUN_004afce0(s______Device_description______004fe770);
  iVar1 = FUN_004aea50();
  if (iVar1 == 0) {
    iVar1 = FUN_004ae830();
    if (iVar1 == 0) {
      pcVar7 = s_Type___SOFTWARE_RAMP_driver_004fe6c8;
    }
    else {
      pcVar7 = s_Type___HARDWARE_RAMP_driver_004fe6f4;
    }
  }
  else {
    iVar1 = FUN_004ae830();
    if (iVar1 == 0) {
      pcVar7 = s_Type___SOFTWARE_RGB_driver_004fe720;
    }
    else {
      pcVar7 = s_Type___HARDWARE_RGB_driver_004fe748;
    }
  }
  FUN_004afce0(pcVar7);
  iVar1 = FUN_004aeb10(0x20);
  pcVar7 = s_32_bpp_004fe6c0;
  if (iVar1 == 0) {
    pcVar7 = &DAT_004fcacc;
  }
  iVar1 = FUN_004aeb10(0x18);
  pcVar5 = s_24_bpp_004fe6b8;
  if (iVar1 == 0) {
    pcVar5 = &DAT_004fb9f8;
  }
  iVar1 = FUN_004aeb10(0x10);
  pcVar6 = s_16_bpp_004fe6b0;
  if (iVar1 == 0) {
    pcVar6 = &DAT_004fb9f8;
  }
  iVar1 = FUN_004aeb10(8);
  pcVar2 = s_8_bpp_004fe6a8;
  if (iVar1 == 0) {
    pcVar2 = &DAT_004fb9f8;
  }
  FUN_004afce0(s_Render_bitdepths____s__s__s__s_004fe688,pcVar2,pcVar6,pcVar5,pcVar7);
  uVar3 = FUN_004aeab0();
  FUN_004afce0(s_Zbuffer_bitdepth____d_bpp_004fe66c,uVar3);
  FUN_004afce0(s______Light_information______004fe64c);
  uVar3 = FUN_004aec20();
  FUN_004afce0(s_Maximum_lights____d_004fe634,uVar3);
  FUN_004afce0(s_Allowed_types___004fe620);
  iVar1 = FUN_004aed90();
  if (iVar1 != 0) {
    FUN_004afce0(&DAT_004fe618);
  }
  iVar1 = FUN_004aed30();
  if (iVar1 != 0) {
    FUN_004afce0(s___point_004fe610);
  }
  iVar1 = FUN_004aecd0();
  if (iVar1 != 0) {
    FUN_004afce0(s___parallel_004fe604);
  }
  iVar1 = FUN_004aec70();
  if (iVar1 == 0) {
    pcVar7 = s_lights_004fe5e4;
  }
  else {
    pcVar7 = s___directional_lights_004fe5ec;
  }
  FUN_004afce0(pcVar7);
  FUN_004afce0(s______Texture_information______004fe5c4);
  iVar1 = FUN_004ae940();
  if (iVar1 != 0) {
    FUN_004afce0(s_Texture_memory___SYSTEM_004fe5a8);
  }
  iVar1 = FUN_004ae9a0();
  if (iVar1 != 0) {
    FUN_004afce0(s_Texture_memory___VIDEO_004fe58c);
  }
  uVar3 = FUN_004ae8c0();
  uVar3 = FUN_004ae840(uVar3);
  FUN_004afce0(s_Min_texture_size_____d__d__004fe570,uVar3);
  uVar3 = FUN_004ae900();
  uVar3 = FUN_004ae880(uVar3);
  FUN_004afce0(s_Max_texture_size_____d__d__004fe554,uVar3);
  FUN_004afce0(s______Miscellaneous______004fe538);
  iVar1 = FUN_004aea00();
  puVar4 = &DAT_004fe534;
  if (iVar1 == 0) {
    puVar4 = &DAT_004fe530;
  }
  FUN_004afce0(s_Clipping____s_004fe518,puVar4);
  return;
}

