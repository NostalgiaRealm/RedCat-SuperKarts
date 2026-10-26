/*
 * FUN_00450440 at 00450440
 * undefined FUN_00450440(void)
 * Address ranges: 00450440-0045045f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00450440(int param_1)

{
  char *local_4;
  
  if (*(int *)(param_1 + 8) == -1) {
    local_4 = s_Invalid_object_in_CBonusData__Ch_004f11a0;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&local_4,&DAT_004d5538);
  }
  return;
}

