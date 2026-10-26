/*
 * FUN_004432a0 at 004432a0
 * undefined FUN_004432a0(void)
 * Address ranges: 004432a0-00443411
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004432a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  DWORD DVar2;
  DWORD DVar3;
  int iVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_004cd630;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_00442fc0(param_1,param_4);
  FUN_004afce0(s__init_main__completed__004ede38);
  FUN_004afce0(s_Calling__start_game__004ede50);
  FUN_0042f930();
  FUN_004afce0(s_Entering_main_loop_004eded4);
  DVar2 = GetTickCount();
  while (DAT_0053b9bc != 0) {
    do {
      DVar3 = GetTickCount();
    } while (DVar3 - DVar2 < 0x19);
    DVar2 = GetTickCount();
    FUN_004afce0(s_Calling__handle_game__004edee8);
    FUN_0042f4c0();
    FUN_00473460();
    FUN_00473550();
    FUN_004afce0(s_Calling__handle_framecount_timin_004edf00);
    FUN_00430cd0();
    FUN_004afce0(s_Calling__my_handle_win_msg__004edf24);
    iVar4 = FUN_00442e80();
    if (iVar4 != 0) break;
    iVar4 = FUN_004b3830(0x11);
    if (iVar4 != 0) {
      iVar4 = FUN_004b3830(0x51);
      if (iVar4 != 0) {
        FUN_004afee0(s__s__d_____winmain____Emergency_e_004edf64,
                     s_D__work_rcsk_Code_game_Main_cpp_004edf44,0x1a5);
      }
    }
    iVar4 = FUN_004b3830(8);
    if (iVar4 != 0) {
      FUN_00443460();
    }
  }
  FUN_004afce0(s_Exiting_main_loop_004edf9c);
  FUN_004afce0(s_Calling__exit_main__004edfb0);
  FUN_00443150();
  local_8 = 0xffffffff;
  FUN_00477f10();
  FUN_00478000();
  cVar1 = FUN_004431b0();
  if (cVar1 != '\0') {
    FUN_004431e0();
  }
  ExceptionList = local_10;
  return 0;
}

