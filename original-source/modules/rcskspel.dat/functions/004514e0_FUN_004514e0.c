/*
 * FUN_004514e0 at 004514e0
 * undefined FUN_004514e0(void)
 * Address ranges: 004514e0-00451636
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004514e0(char *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  bool bVar7;
  
  FUN_004afce0(s_CBonusController__PickUp_004f14c0);
  iVar2 = FUN_0044fb40();
  uVar5 = param_2;
  if (iVar2 != 2) {
    param_1 = s_Picking_up_from_idle_state____004f14dc;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&param_1,&DAT_004d5538);
  }
  FUN_004106b0(param_2);
  FUN_00452020(uVar5);
  iVar2 = FUN_0044fb50();
  iVar3 = FUN_0044fb50();
  if (iVar3 == 7) {
    iVar2 = FUN_004be6c9();
    iVar2 = iVar2 % 5 + 1;
  }
  if (iVar2 == 6) {
    FUN_00451f60();
    uVar4 = FUN_0044fbe0();
    FUN_0040d610(uVar5,uVar4);
    FUN_0044fa70(1);
    return;
  }
  iVar3 = FUN_0044fb40();
  if (iVar3 != 1) {
    iVar3 = FUN_0044fb50();
    if (iVar3 == iVar2) {
      FUN_00453740();
      goto LAB_004515ce;
    }
  }
  uVar4 = FUN_0044fbe0();
  FUN_0044faf0(uVar4);
  iVar3 = FUN_0044fb50();
  if (iVar3 == 7) {
    FUN_0044fb60(iVar2);
  }
LAB_004515ce:
  cVar1 = FUN_00417e90(uVar5);
  if (cVar1 == '\0') {
    uVar4 = FUN_0044fbe0();
    FUN_0040d610(uVar5,uVar4);
    FUN_00453740();
    uVar6 = FUN_004be6c9();
    uVar6 = uVar6 & 0x80000001;
    bVar7 = uVar6 == 0;
    if ((int)uVar6 < 0) {
      bVar7 = (uVar6 - 1 | 0xfffffffe) == 0xffffffff;
    }
    if (!bVar7) {
      FUN_00453740();
    }
  }
  else {
    uVar5 = FUN_0044fbe0();
    FUN_004362f0(uVar5);
  }
  FUN_0044fa70(1);
  FUN_0044fa70(2);
  return;
}

