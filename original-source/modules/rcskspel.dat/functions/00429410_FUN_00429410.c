/*
 * FUN_00429410 at 00429410
 * undefined FUN_00429410(void)
 * Address ranges: 00429410-0042947b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00429410(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  if (DAT_0053ba5c != 0) {
    FUN_004b5460(1);
  }
  FUN_004afce0(s_init_xvga_lib_004e8594);
  iVar1 = FUN_004b14e0(param_1,param_2,s_Davilex_Entertainment_004e85a4,s_Davilex_Game_004e7b74);
  if (iVar1 == 0) {
    FUN_004afce0(s_error___couldn_t_initialize_prog_004e85bc);
    FUN_004afee0(s__s__d____Function___s____init_xv_004e8608,
                 s_D__work_rcsk_Code_game_gm_body_c_004e85e4,0x1e0,s_skelet2d_init_2d_lib___004e857c
                );
  }
  _DAT_0053a254 = param_1;
  return;
}

