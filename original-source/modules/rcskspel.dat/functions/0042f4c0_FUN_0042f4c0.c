/*
 * FUN_0042f4c0 at 0042f4c0
 * undefined FUN_0042f4c0(void)
 * Address ranges: 0042f4c0-0042f738
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042f4c0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  float10 fVar4;
  undefined4 auStack_48 [6];
  undefined4 uStack_30;
  char *pcStack_2c;
  char *pcStack_28;
  char *pcStack_24;
  int iStack_20;
  char *pcStack_1c;
  char *pcStack_18;
  char *pcStack_14;
  char *pcStack_10;
  char *pcStack_c;
  
  pcStack_c = s_handle_game___004ead84;
  pcStack_10 = (char *)0x42f4cc;
  FUN_004afce0();
  pcStack_10 = s_calling__>_gt_update_timer___004ead94;
  pcStack_14 = (char *)0x42f4d6;
  FUN_004afce0();
  pcStack_c = (char *)0x42f4e3;
  FUN_0048f3e0();
  pcStack_c = (char *)0x42f4e8;
  FUN_00428cc0();
  pcStack_c = (char *)0x42f4ed;
  FUN_00431750();
  pcStack_c = (char *)0x42f4f4;
  FUN_004318a0();
  pcStack_c = (char *)0x42f4f9;
  FUN_00457730();
  pcStack_c = (char *)0x42f500;
  FUN_00457b60();
  pcStack_c = s_calling__>_rceng_handle_objects__004eadb4;
  pcStack_10 = (char *)0x42f50a;
  FUN_004afce0();
  pcStack_10 = (char *)DAT_0053be28;
  pcStack_14 = (char *)(DAT_0053b9d0 * 2);
  pcStack_18 = *(char **)(DAT_0053be28 * 0xd0 + 0x1c + DAT_0067ee20);
  pcStack_1c = (char *)0x42f532;
  FUN_00491530();
  pcStack_1c = s_calling__>_ai_check_cars_outside_004eadd8;
  iStack_20 = 0x42f53c;
  FUN_004afce0();
  iStack_20 = DAT_0053be28;
  pcStack_24 = (char *)0x42f548;
  FUN_004107e0();
  pcStack_24 = s_calling__>_handle_game_cameras___004eae0c;
  pcStack_28 = (char *)0x42f552;
  FUN_004afce0();
  pcStack_28 = (char *)0x42f557;
  FUN_0041d920();
  pcStack_28 = s_calling__>_UpdateSoundListener___004eae30;
  pcStack_2c = (char *)0x42f561;
  FUN_004afce0();
  pcStack_2c = (char *)0x42f566;
  FUN_0043b660();
  pcStack_2c = s_calling__>_UpdateParticleSystems_004eae54;
  uStack_30 = 0x42f570;
  FUN_004afce0();
  puVar2 = (undefined4 *)
           (DAT_006a5c38 + *(int *)(DAT_0053be28 * 0xd0 + 0xc + DAT_0067ee20) * 0xa9 + 0x10);
  puVar3 = auStack_48;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  fVar4 = (float10)FUN_0048f4e0();
  FUN_00482020((float)fVar4);
  FUN_004afce0(s_calling__>_CVoiceController__Get_004eae78);
  pcStack_c = (char *)0x42f5cf;
  FUN_004371f0();
  pcStack_c = (char *)0x42f5d6;
  FUN_00437c10();
  pcStack_c = s_calling__>_handle_slippen_004eaeb0;
  pcStack_10 = (char *)0x42f5e0;
  FUN_004afce0();
  pcStack_10 = (char *)0x42f5e5;
  FUN_00432240();
  pcStack_10 = (char *)DAT_0050728c;
  pcStack_14 = (char *)DAT_0053be28;
  pcStack_18 = (char *)0x42f5f8;
  FUN_00426aa0();
  pcStack_18 = s_calling__>_HandleSquashedObjects_004eaecc;
  pcStack_1c = (char *)0x42f602;
  FUN_004afce0();
  pcStack_c = (char *)0x42f60a;
  FUN_0048e210();
  pcStack_c = (char *)0x42f611;
  FUN_0048e970();
  pcStack_c = (char *)0x42f616;
  FUN_0048da90();
  pcStack_c = (char *)0x42f61d;
  FUN_0048db00();
  pcStack_c = (char *)0x42f622;
  FUN_00486370();
  pcStack_c = (char *)0x42f629;
  FUN_004863e0();
  pcStack_c = (char *)0x42f62e;
  FUN_0048a480();
  pcStack_c = (char *)0x42f635;
  FUN_0048a4f0();
  pcStack_c = (char *)0x42f63a;
  FUN_00488a90();
  pcStack_c = (char *)0x42f641;
  FUN_00488b00();
  pcStack_c = (char *)0x42f646;
  FUN_00487950();
  pcStack_c = (char *)0x42f64d;
  FUN_004879c0();
  pcStack_c = (char *)0x42f652;
  FUN_00485690();
  pcStack_c = (char *)0x42f659;
  FUN_004856e0();
  pcStack_c = s_calling__>_render_game___004eaef0;
  pcStack_10 = (char *)0x42f663;
  FUN_004afce0();
  pcStack_10 = (char *)0x42f668;
  FUN_00430020();
  pcStack_10 = (char *)0x42f66d;
  FUN_00429a90();
  pcStack_10 = s_calling__>_check_game_keys___004eaf0c;
  pcStack_14 = (char *)0x42f677;
  FUN_004afce0();
  pcStack_c = (char *)0x42f67f;
  FUN_0042f9c0();
  pcStack_c = (char *)0x42f684;
  FUN_004513c0();
  pcStack_c = (char *)0x42f68b;
  FUN_00451200();
  pcStack_c = (char *)0x42f690;
  FUN_00445900();
  pcStack_c = (char *)0x42f695;
  FUN_004458c0();
  pcStack_c = s_calling__>_handle_game_actions___004eaf2c;
  pcStack_10 = (char *)0x42f69f;
  FUN_004afce0();
  pcStack_10 = (char *)0x42f6a4;
  FUN_00420cf0();
  pcStack_10 = (char *)0x42f6a9;
  FUN_0042f170();
  pcStack_10 = s_calling__>_check_player_damage___004eaf50;
  pcStack_14 = (char *)0x42f6b3;
  FUN_004afce0();
  pcStack_14 = (char *)0x42f6b8;
  FUN_0042f1f0();
  pcStack_14 = s_calling__>_update_game_screen___004eaf74;
  pcStack_18 = (char *)0x42f6c2;
  FUN_004afce0();
  pcStack_c = (char *)0x42f6ca;
  FUN_00430470();
  pcStack_c = (char *)0x42f6cf;
  FUN_0042f470();
  if (DAT_0053b9f8 != 0) {
    pcStack_c = (char *)DAT_0053be28;
    pcStack_10 = (char *)(DAT_0053b9d0 * 2);
    pcStack_14 = *(char **)(DAT_0053be28 * 0xd0 + 0x1c + DAT_0067ee20);
    pcStack_18 = (char *)0x42f700;
    FUN_00491530();
    pcStack_c = (char *)0x42f708;
    FUN_00430020();
    pcStack_c = (char *)0x42f70d;
    FUN_00430470();
    pcStack_c = (char *)0x42f712;
    FUN_0042f350();
    DAT_0053b9f8 = 0;
  }
  pcStack_c = s_end_of_handle_game___004eaf98;
  DAT_0053b9fc = DAT_0053b9fc + 1;
  pcStack_10 = (char *)0x42f733;
  FUN_004afce0();
  return;
}

