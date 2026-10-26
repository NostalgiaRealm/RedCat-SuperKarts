/*
 * FUN_004513c0 at 004513c0
 * undefined FUN_004513c0(void)
 * Address ranges: 004513c0-0045144a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004513c0(void)

{
  char *local_1c;
  undefined1 local_18 [12];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cdc0b;
  local_c = ExceptionList;
  if (DAT_00543d24 == 0) {
    ExceptionList = &local_c;
    local_1c = operator_new(0x38);
    local_4 = 0;
    if (local_1c == (char *)0x0) {
      DAT_00543d24 = 0;
    }
    else {
      DAT_00543d24 = FUN_00450b70();
    }
    local_4 = 0xffffffff;
    if (DAT_00543d24 == 0) {
      local_1c = s_Unable_to_create_new_CBonusContr_004f1470;
      FUN_004bfdaf(&local_1c);
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_18,&DAT_004d6040);
    }
  }
  ExceptionList = local_c;
  return;
}

