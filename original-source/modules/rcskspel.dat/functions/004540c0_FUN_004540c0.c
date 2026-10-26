/*
 * FUN_004540c0 at 004540c0
 * undefined FUN_004540c0(void)
 * Address ranges: 004540c0-0045425f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004540c0(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  float10 fVar5;
  undefined1 *puVar6;
  undefined1 auStack_2c [4];
  int iStack_28;
  undefined1 auStack_1c [4];
  int iStack_18;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_004cdd84;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_004513c0();
  iVar2 = FUN_0044fff0();
  fVar5 = (float10)FUN_0048f4e0();
  iVar3 = FUN_004504f0();
  *(float *)(iVar2 + 4) = (float)iVar3 * (float)fVar5 + *(float *)(iVar2 + 4);
  FUN_004500c0();
  FUN_004a09e0();
  iVar3 = FUN_0044fb50();
  iVar2 = 0;
  if (iVar3 == 6) {
    iVar2 = DAT_00508610;
  }
  if (DAT_00508610 < iVar2) {
    ExceptionList = pvStack_c;
    return;
  }
  while ((cVar1 = FUN_00410650(iVar2), cVar1 == '\0' || (cVar1 = FUN_0044fc80(iVar2), cVar1 == '\0')
         )) {
    iVar2 = iVar2 + 1;
    if (DAT_00508610 < iVar2) {
      ExceptionList = pvStack_c;
      return;
    }
  }
  FUN_004514e0(param_1,iVar2);
  cVar1 = FUN_00417e90(iVar2);
  if (cVar1 == '\0') {
    ExceptionList = pvStack_c;
    return;
  }
  uVar4 = FUN_0044fb50();
  FUN_004542c0(auStack_2c,uVar4);
  puVar6 = auStack_2c;
  uStack_4 = 0;
  uVar4 = 10;
  FUN_004371f0(10,puVar6);
  FUN_00437b10(uVar4,puVar6);
  uVar4 = FUN_00438270(auStack_1c);
  uStack_4 = CONCAT31(uStack_4._1_3_,1);
  FUN_004387a0(DAT_00508610,uVar4);
  if (iStack_18 != 0) {
    cVar1 = *(char *)(iStack_18 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150((char *)(iStack_18 + -1));
    }
    else {
      *(char *)(iStack_18 + -1) = cVar1 + -1;
    }
  }
  if (iStack_28 == 0) {
    ExceptionList = pvStack_c;
    return;
  }
  cVar1 = *(char *)(iStack_28 + -1);
  if ((cVar1 != '\0') && (cVar1 != -1)) {
    *(char *)(iStack_28 + -1) = cVar1 + -1;
    ExceptionList = pvStack_c;
    return;
  }
  FUN_004bc150(iStack_28 + -1);
  ExceptionList = pvStack_c;
  return;
}

