/*
 * FUN_00451450 at 00451450
 * undefined FUN_00451450(void)
 * Address ranges: 00451450-004514da
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00451450(void)

{
  char *local_1c;
  undefined1 local_18 [12];
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_004cdc20;
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
      local_1c = s_Unable_to_create_new_CBonusContr_004f1498;
      FUN_004bfdaf(&local_1c);
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_18,&DAT_004d6040);
    }
  }
  ExceptionList = local_c;
  return;
}

