/*
 * thunk_FUN_0048faf0 at 00493180
 * undefined thunk_FUN_0048faf0(void)
 * Address ranges: 00493180-00493184
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to FUN_0048faf0
 */

void thunk_FUN_0048faf0(void)

{
  if (DAT_0067ee2c == 1) {
    FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,&DAT_0067ee4d,&DAT_0067ee34,
                 DAT_0067ee24);
    if (DAT_0067ee20 != 0) {
      FUN_004bc150(DAT_0067ee20 + -4);
    }
  }
  if (DAT_0067ee2c != 0) {
    FUN_004bc150(DAT_0067ee30);
    DAT_0067ee2c = 0;
  }
  FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  return;
}

