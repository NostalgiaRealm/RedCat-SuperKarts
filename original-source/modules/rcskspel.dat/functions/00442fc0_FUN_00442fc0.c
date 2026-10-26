/*
 * FUN_00442fc0 at 00442fc0
 * undefined FUN_00442fc0(void)
 * Address ranges: 00442fc0-00443147
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00442fc0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_004295f0(s_game_ini_004edb78);
  FUN_004b1d60(s_game_ini_004edb84);
  FUN_004b1e70(s_PROGRAM_004edb98,s_RESTART_004edb90,0);
  FUN_00473460();
  iVar1 = FUN_00473550();
  if (iVar1 == 1) {
    FUN_00473460();
    FUN_00473700();
    FUN_004afce0(s__s__d____Recovering_to_safe_scre_004edbc0,
                 s_D__work_rcsk_Code_game_Main_cpp_004edba0,0x9e);
  }
  FUN_00477f10();
  FUN_00477f60();
  FUN_00475360();
  FUN_004764b0();
  FUN_00442fa0();
  FUN_00443b70();
  FUN_0042ac40();
  FUN_0042b220();
  FUN_004afce0(s_Initing_2d_skelet_004edbec);
  FUN_004291a0(DAT_0053b9f0 == 0);
  FUN_00429930(param_1,param_2);
  iVar1 = FUN_00429210();
  if (iVar1 == 1) {
    FUN_004afce0(s_GOING_TO_BACKSCREEN_3D_INIT_004edc00);
    uVar2 = 1;
  }
  else {
    if (iVar1 != 2) {
      FUN_004afee0(s__s__d_____init_main____Illegal_r_004edc60,
                   s_D__work_rcsk_Code_game_Main_cpp_004edc40,0xe0);
      goto LAB_004430d7;
    }
    FUN_004afce0(s_GOING_TO_BUFFERSCREEN_3D_INIT_004edc20);
    uVar2 = 2;
  }
  FUN_004ac410(uVar2,10,10,0x1000);
LAB_004430d7:
  FUN_00424dc0();
  FUN_004afce0(s_Initing_game_004edc90);
  FUN_0042d7d0();
  FUN_004afce0(s_Initing_game_timer__004edca0);
  FUN_0048f2c0();
  FUN_004afce0(s_Calling__handle_progress_bar__004edcb8);
  FUN_00424ec0();
  FUN_004afce0(s_Calling__end_progress_bar__004edcd8);
  FUN_00424df0();
  FUN_004afce0(s_Calling__start_framecount_timing_004edcf4);
  FUN_00430cb0();
  uVar2 = DAT_006a64b4;
  FUN_00431750(param_1,DAT_006a64b4);
  FUN_00431780(param_1,uVar2);
  return;
}

