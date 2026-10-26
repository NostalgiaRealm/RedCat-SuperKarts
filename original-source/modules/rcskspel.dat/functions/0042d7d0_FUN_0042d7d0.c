/*
 * FUN_0042d7d0 at 0042d7d0
 * undefined FUN_0042d7d0(void)
 * Address ranges: 0042d7d0-0042df8f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042d7d0(void)

{
  char cVar1;
  float *pfVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint3 uVar9;
  int iVar7;
  undefined1 *puVar8;
  int iVar10;
  undefined4 extraout_ECX;
  uint3 uVar12;
  int iVar11;
  uint uVar13;
  undefined4 *puVar14;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  float *pfVar15;
  undefined8 uVar16;
  undefined4 *puVar17;
  int iVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  char *pcVar23;
  char *local_88;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  int iStack_74;
  undefined1 auStack_70 [4];
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined1 auStack_60 [32];
  float local_40 [4];
  float local_30;
  float local_20;
  
  FUN_004afce0();
  CoInitialize((LPVOID)0x0);
  FUN_004afce0();
  FUN_0042d1d0();
  local_88 = (char *)0x42d801;
  FUN_004afce0();
  local_88 = (char *)0x42d806;
  FUN_0042ad70();
  local_88 = s_init_3d_library_____004ea728;
  FUN_004afce0();
  FUN_0042ccf0();
  if (DAT_0053b9f4 == 0) {
    _DAT_004e0198 = 5;
    _DAT_004e019c = 7;
  }
  else {
    _DAT_004e0198 = 10;
    _DAT_004e019c = 0xe;
  }
  local_88 = s_set_game_render_states_____004ea740;
  FUN_004afce0();
  FUN_0042cff0();
  FUN_004afce0(s_set_game_input_____004ea75c);
  FUN_0042ce10();
  local_88 = (char *)0x3fb4f4ab;
  pfVar2 = (float *)FUN_004a1a40(local_40,0x3fc00000,0x46435000);
  pfVar15 = local_40;
  for (iVar10 = 0x10; iVar10 != 0; iVar10 = iVar10 + -1) {
    *pfVar15 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfVar15 = pfVar15 + 1;
  }
  if ((&DAT_0053a734)[DAT_0053b9b4 * 0x25] == 1) {
    local_40[0] = -local_40[0];
    local_88 = (char *)0x2;
    local_30 = -local_30;
    local_20 = -local_20;
    (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x16);
  }
  local_88 = (char *)&DAT_006a615c;
  pfVar2 = local_40;
  pfVar15 = (float *)&DAT_006a615c;
  for (iVar10 = 0x10; iVar10 != 0; iVar10 = iVar10 + -1) {
    *pfVar15 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfVar15 = pfVar15 + 1;
  }
  iVar10 = (**(code **)(*DAT_006a621c + 0x68))(DAT_006a621c,3);
  if (iVar10 != 0) {
    uVar3 = FUN_004aaa00(iVar10);
    FUN_004afee0(s__s__d_____FOG__error_setting_tra_004e300c,
                 s____Libs_win3dlib_Include_d3dev_i_004e3040,0x59,uVar3);
  }
  FUN_004afce0(s_init_game_info___004ea770);
  FUN_0042d470();
  FUN_004afce0(s_init_2d_graphics_____004ea784);
  FUN_004242f0();
  FUN_004afce0(s_init_3d_anim_config_____004ea79c);
  FUN_0042cdf0();
  FUN_0044cfe0();
  FUN_0044a1f0();
  FUN_004101a0();
  FUN_00424ec0();
  FUN_004afce0(s_init_color_key_bufferscreen___004ea7b8);
  FUN_0042d420();
  FUN_004afce0(s_init_ascii_fonts___004ea7d8);
  FUN_004229a0();
  FUN_004afce0(s_init_moving_sky____004ea7ec);
  FUN_004270f0();
  FUN_004afce0(s_init_game_actions___004ea800);
  FUN_00420b20();
  FUN_0043b450();
  FUN_004182d0(0,s_Motor_Sound_004ea818);
  FUN_0041fc20();
  FUN_00424ec0();
  FUN_004afce0(s_init_3d_anim_config_____004ea824);
  FUN_00449d70(s_anmtypes_ini_004ea840);
  FUN_004afce0(s_check_texture_copy_____004ea850);
  FUN_004afce0(s_rceng_init_engine_____004ea868);
  uVar3 = FUN_0049b300(&DAT_0053a6b6 + DAT_0053b9b4 * 0x94,DAT_0053b9f0,1);
  uVar4 = FUN_0049b300(&DAT_0053a6c4 + DAT_0053b9b4 * 0x94,DAT_0053b9f0,1);
  uVar5 = FUN_0049b300(&DAT_0053a6e0 + DAT_0053b9b4 * 0x94,DAT_0053b9f0,1);
  uVar6 = FUN_0049b300(&DAT_0053a6d2 + DAT_0053b9b4 * 0x94,DAT_0053b9f0,1);
  FUN_0042d480();
  FUN_00493070(5000,uVar3,uVar4,uVar5,uVar6);
  FUN_00424ec0();
  FUN_004afce0(s_init_track_object_types___004ea880);
  FUN_0043df30();
  FUN_004afce0(s_init_all_triggers___004ea89c);
  FUN_00441970();
  FUN_004afce0(s_clear_car_list_____004ea8b4);
  FUN_004165d0();
  FUN_004afce0(s_init_car_shadow_object_____004ea8c8);
  FUN_00416270();
  FUN_004264c0();
  FUN_004afce0(s_init_ai_states____004ea8e4);
  FUN_004031f0(0x32);
  FUN_004afce0(s_init_cop_ai_states____004ea8f8);
  FUN_004afce0(s_rceng_load_etappe_____004ea910);
  FUN_00493140(&DAT_0053a6a8 + DAT_0053b9b4 * 0x25);
  if (DAT_0053b9cc == 0) {
    DAT_0053b9cc = FUN_00442380();
  }
  FUN_00415d70();
  FUN_0042df90();
  FUN_0042e910();
  FUN_00493120(DAT_0053b9ec == 0);
  FUN_004afce0(s_init_3d_paths___004ea928);
  FUN_00444e00();
  FUN_004afce0(s_init_particle_emitters___004ea93c);
  FUN_004afce0(s_init_sparks___004ea958);
  FUN_00427c40();
  FUN_004afce0(s_init_clouds___004ea968);
  FUN_004288b0();
  FUN_004afce0(s_init_finish_flag___004ea978);
  FUN_00423590();
  FUN_004afce0(s_init_skidmarks___004ea98c);
  FUN_00426c20();
  uStack_6c = DAT_0067da60;
  iVar10 = 0;
  uStack_68 = DAT_0067da64;
  uStack_64 = DAT_0067da68;
  if (DAT_00508610 != -1 && -1 < DAT_00508610 + 1) {
    puVar14 = &DAT_005081bc;
    do {
      cVar1 = FUN_00417e90(iVar10);
      uVar3 = DAT_0053be28;
      if (cVar1 == '\0') {
        uVar3 = *puVar14;
      }
      uVar4 = uVar3;
      FUN_0048a480(uVar3);
      uVar16 = FUN_0048a890(uVar4);
      uVar9 = (uint3)((ulonglong)uVar16 >> 8);
      uVar4 = CONCAT31(uVar9,1);
      uVar12 = (uint3)((uint)extraout_ECX >> 8);
      uVar5 = CONCAT31(uVar12,1);
      uVar13 = (uint)((ulonglong)uVar16 >> 0x20) & 0xffffff00;
      iVar7 = (uint)uVar9 << 8;
      iVar11 = (uint)uVar12 << 8;
      uVar6 = 0x41a00000;
      puVar17 = &DAT_0067da60;
      iVar18 = iVar10;
      FUN_0048a480(uVar3,&DAT_0067da60,iVar11,iVar10,iVar7,uVar13,0x41a00000,uVar5,uVar4);
      FUN_0048a570(uVar3,puVar17,iVar11,iVar18,iVar7,uVar13,uVar6,uVar5,uVar4);
      iVar10 = iVar10 + 1;
      puVar14 = puVar14 + 0x1c;
    } while (iVar10 < DAT_00508610 + 1);
  }
  uVar4 = 1;
  uVar22 = 1;
  uVar21 = 0x41a00000;
  uVar20 = 0;
  uVar19 = 0;
  uVar6 = 2;
  puVar14 = &uStack_6c;
  uVar5 = 0;
  uVar3 = DAT_0053be28;
  FUN_0048a480(DAT_0053be28,puVar14,0,2,0,0,0x41a00000,1,1);
  FUN_0048a570(uVar3,puVar14,uVar5,uVar6,uVar19,uVar20,uVar21,uVar22,uVar4);
  iVar10 = 0;
  if (0 < DAT_00508610) {
    puVar14 = &DAT_005081bc;
    do {
      cVar1 = FUN_00417e90(iVar10);
      uVar3 = DAT_0053be28;
      if (cVar1 == '\0') {
        uVar3 = *puVar14;
      }
      uVar4 = 1;
      puVar17 = &uStack_6c;
      uVar21 = 1;
      uVar20 = 0x41a00000;
      uVar19 = 0;
      uVar6 = 0;
      uVar5 = 0;
      iVar18 = iVar10;
      FUN_0048a480(uVar3,puVar17,0,iVar10,0,0,0x41a00000,1,1);
      FUN_0048a570(uVar3,puVar17,uVar5,iVar18,uVar6,uVar19,uVar20,uVar21,uVar4);
      iVar10 = iVar10 + 1;
      puVar14 = puVar14 + 0x1c;
    } while (iVar10 < DAT_00508610);
  }
  FUN_00424ec0();
  FUN_004afce0(s_init_bkg____004ea9a0);
  FUN_00422ed0();
  FUN_004afce0(s_init_game_cars_____004ea9b0);
  iVar10 = 0;
  if (0 < DAT_00508610) {
    do {
      FUN_0044a700(iVar10);
      uVar3 = FUN_0044cab0();
      FUN_004afce0(s__s__d_____d_contestant_has_004ea9e8,s_D__work_rcsk_Code_game_gm_init_c_004ea9c4
                   ,0x456,uVar3);
      FUN_0044a700(iVar10);
      uVar3 = FUN_0044cab0();
      uVar3 = FUN_004103d0(uVar3);
      FUN_004afce0(s_ai_id__d_004eaa04,uVar3);
      FUN_0044a700(iVar10);
      FUN_0044caa0(uVar3);
      iVar10 = iVar10 + 1;
    } while (iVar10 < DAT_00508610);
  }
  FUN_004afce0(s_init_etappe_timer___004eaa10);
  FUN_0042d360();
  FUN_00424ec0();
  FUN_004afce0(s_init_game_cameras_____004eaa28);
  FUN_0041d280();
  FUN_004afce0(s_init_all_config_textures_004eaa40);
  FUN_00442a30();
  FUN_004513c0();
  FUN_00450fa0();
  FUN_0042abf0(&uStack_78,&uStack_7c,&stack0xffffff80,&stack0xffffff7c,&local_88);
  pcVar23 = local_88;
  FUN_004513c0(uStack_78,uStack_7c,unaff_ESI,unaff_EDI,local_88);
  FUN_00450e30(uStack_78,uStack_7c,unaff_ESI,unaff_EDI,pcVar23);
  iStack_74 = (int)(short)(&DAT_0053a72a)[DAT_0053b9b4 * 0x4a];
  FUN_00493b10((float)iStack_74,(float)(int)(short)(&DAT_0053a72c)[DAT_0053b9b4 * 0x4a],
               (float)(int)(short)(&DAT_0053a72e)[DAT_0053b9b4 * 0x4a]);
  uVar3 = FUN_004acd70();
  FUN_004acda0(uVar3,0,0,DAT_004fe930,DAT_004fe934);
  FUN_004acc90(uVar3);
  FUN_004bea92(auStack_60,s_rclemu_02d_dat_004eaa5c,DAT_0053b9b4);
  FUN_0048ed60(DAT_006a64b4,auStack_60);
  FUN_004afce0(s_RVD___volume_percent_is__d_004eaa6c,DAT_0053b9a4);
  uVar3 = FUN_00431610(DAT_0053b9a4);
  FUN_0048f010(uVar3);
  uVar3 = FUN_00431610(DAT_0053b9a4);
  FUN_004afce0(s_RVD___setting_volume_to__d_004eaa88,uVar3);
  if (DAT_0053b9a4 != 0) {
    FUN_0048edc0();
    FUN_0048ec20(1);
  }
  FUN_004818c0(DAT_0053b9b4);
  FUN_004bf48c(auStack_70);
  uVar3 = FUN_004bf81d(auStack_70);
  FUN_004315a0(s_Starting_game_at__s_004eaaa4,uVar3);
  FUN_004315a0(s__________________________________004eaabc);
  iVar10 = FUN_0042abc0(DAT_0053b9b4 + 1);
  FUN_004315a0(s_Level__d_GameType__d__004eaaf0,iVar10 + 1);
  FUN_0044a700(DAT_00508610);
  iVar10 = FUN_0044f530();
  puVar8 = *(undefined1 **)(iVar10 + 4);
  if (puVar8 == (undefined1 *)0x0) {
    puVar8 = &DAT_004d2404;
  }
  FUN_004315a0(s_Character__s_004eab08,puVar8);
  return;
}

