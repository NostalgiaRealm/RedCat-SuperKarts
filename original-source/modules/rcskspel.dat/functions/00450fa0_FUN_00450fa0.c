/*
 * FUN_00450fa0 at 00450fa0
 * undefined FUN_00450fa0(void)
 * Address ranges: 00450fa0-004510a9;004510d9-004510e9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00450fa0(int param_1)

{
  void *pvVar1;
  int iVar2;
  char *local_20;
  int local_1c;
  char *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004cdbd7;
  local_10 = ExceptionList;
  local_14 = &stack0xffffffcc;
  ExceptionList = &local_10;
  FUN_004afce0(s_CBonusController__Init_004f12ac);
  local_8 = 0;
  iVar2 = 0;
  while( true ) {
    if (DAT_00508610 < iVar2) {
      FUN_00455470();
      iVar2 = 0;
      while( true ) {
        if (0x28 < iVar2) {
          ExceptionList = local_10;
          return;
        }
        pvVar1 = operator_new(0x40);
        local_8._0_1_ = 2;
        if (pvVar1 == (void *)0x0) {
          local_1c = 0;
        }
        else {
          local_1c = FUN_00455420();
        }
        local_8 = (uint)local_8._1_3_ << 8;
        if (local_1c == 0) break;
        FUN_00455450();
        FUN_00459170(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 8),1,&local_1c);
        iVar2 = iVar2 + 1;
      }
      local_20 = s_CBonusController__Init__Unable_t_004f12fc;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&local_20,&DAT_004d5538);
    }
    pvVar1 = operator_new(0x24);
    local_8._0_1_ = 1;
    if (pvVar1 == (void *)0x0) {
      local_1c = 0;
    }
    else {
      local_1c = FUN_004536f0();
    }
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_1c == 0) break;
    FUN_00453710();
    FUN_00459170(*(undefined4 *)(*(int *)(param_1 + 0x24) + 8),1,&local_1c);
    iVar2 = iVar2 + 1;
  }
  local_18 = s_CBonusController__Init__Unable_t_004f12c4;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(&local_18,&DAT_004d5538);
}

