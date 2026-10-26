/*
 * FUN_00429930 at 00429930
 * undefined FUN_00429930(void)
 * Address ranges: 00429930-004299c4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00429930(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_00429220();
  iVar2 = FUN_00428df0();
  if (iVar2 != 3) {
    FUN_004afd70(0xfe);
  }
  FUN_00429410(param_1,param_2);
  if (iVar1 != 0) {
    FUN_004b5450(1);
  }
  FUN_00429480();
  FUN_004b2870(2,s_char_rc_pcx_004e88d4,0x1f);
  FUN_004294f0();
  FUN_004afce0(s_handle_win_msg_004e88e0);
  FUN_004baf00();
  FUN_00429540();
  if (DAT_004e7be4 == 1) {
    FUN_004afce0(s_Flipping_pages_004e88f0);
    FUN_004aff70();
  }
  DAT_004e7be8 = 1;
  return;
}

