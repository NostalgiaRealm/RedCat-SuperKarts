/*
 * FUN_00453fd0 at 00453fd0
 * undefined FUN_00453fd0(void)
 * Address ranges: 00453fd0-0045408b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00453fd0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  float10 fVar4;
  char *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004cdd6a;
  local_10 = ExceptionList;
  local_14 = &stack0xffffffd8;
  ExceptionList = &local_10;
  fVar4 = (float10)FUN_0048f4e0();
  local_8 = 0;
  *(float *)(param_1 + 0x1c) = (float)(fVar4 + (float10)*(float *)(param_1 + 0x1c));
  iVar2 = FUN_0044fb40();
  if (iVar2 == 1) {
    iVar2 = FUN_0044fb50();
    if ((iVar2 != 6) && (_DAT_00543d50 <= *(float *)(param_1 + 0x1c))) {
      uVar3 = FUN_0044fb50();
      cVar1 = FUN_00454560(uVar3);
      if (cVar1 != '\0') {
        FUN_00454260();
        ExceptionList = local_10;
        return;
      }
    }
  }
  else {
    if (iVar2 != 2) {
      local_18 = s_Invalid_state_004f1e30;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&local_18,&DAT_004d5538);
    }
    FUN_004540c0();
  }
  ExceptionList = local_10;
  return;
}

