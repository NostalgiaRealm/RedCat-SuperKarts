/*
 * FUN_00451640 at 00451640
 * undefined FUN_00451640(void)
 * Address ranges: 00451640-004517e4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00451640(char *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 auStack_2c [4];
  int iStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined1 auStack_1c [4];
  int iStack_18;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_004cdc3a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_004afce0(s_CBonusController__Shoot_004f14fc);
  uVar3 = param_1;
  FUN_00430dd0(param_1,0,DAT_00508610,s_D__work_rcsk_Code_game_Bon_Main__004f1518,0x266);
  FUN_00452020(uVar3);
  iVar2 = FUN_0044fb40();
  if (iVar2 != 1) {
    iVar2 = FUN_0044fb50();
    if (iVar2 == 5) {
      FUN_004537f0(uVar3);
      cVar1 = FUN_00417e90(uVar3);
      if (cVar1 != '\0') {
        uVar3 = FUN_0044fbc0();
        uVar3 = FUN_004314a0(auStack_1c,uVar3);
        uStack_4 = 0;
        uVar3 = FUN_00412710(auStack_2c,s_FIRE_TURBO_004f153c,uVar3);
        uVar4 = 10;
        uStack_4 = CONCAT31(uStack_4._1_3_,1);
        FUN_004371f0(10,uVar3);
        FUN_00437b10(uVar4,uVar3);
        if (iStack_28 != 0) {
          cVar1 = *(char *)(iStack_28 + -1);
          if ((cVar1 == '\0') || (cVar1 == -1)) {
            FUN_004bc150((char *)(iStack_28 + -1));
          }
          else {
            *(char *)(iStack_28 + -1) = cVar1 + -1;
          }
        }
        iStack_28 = 0;
        uStack_24 = 0;
        uStack_20 = 0;
        uStack_4 = 0xffffffff;
        if (iStack_18 != 0) {
          cVar1 = *(char *)(iStack_18 + -1);
          if ((cVar1 != '\0') && (cVar1 != -1)) {
            *(char *)(iStack_18 + -1) = cVar1 + -1;
            FUN_0044fa70(1);
            ExceptionList = pvStack_c;
            return;
          }
          FUN_004bc150((char *)(iStack_18 + -1));
        }
      }
      FUN_0044fa70(1);
    }
    else {
      iVar2 = FUN_00451370();
      if (iVar2 == -1) {
        param_1 = s_No_free_shooter_bonuses_004f1548;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(&param_1,&DAT_004d5538);
      }
      FUN_0044fa70(1);
      FUN_00452280(iVar2);
      FUN_004560b0(uVar3);
      uVar3 = FUN_0044fbe0();
      FUN_0044faf0(uVar3);
      FUN_00455490();
    }
  }
  ExceptionList = pvStack_c;
  return;
}

