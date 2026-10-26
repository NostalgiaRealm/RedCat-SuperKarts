/*
 * FUN_004639f0 at 004639f0
 * undefined FUN_004639f0(void)
 * Address ranges: 004639f0-00463b04
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004639f0(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uStack_30;
  undefined1 auStack_2c [4];
  int iStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined1 auStack_1c [4];
  int iStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_004cf589;
  pvStack_c = ExceptionList;
  iVar3 = 0;
  ExceptionList = &pvStack_c;
  if (0 < *(int *)(param_1 + 0x98)) {
    do {
      uVar2 = FUN_00463d20(auStack_1c,iVar3);
      uStack_4 = 0;
      FUN_00459040(auStack_2c,param_1 + 0x34,uVar2);
      uStack_4 = CONCAT31(uStack_4._1_3_,2);
      if (iStack_18 != 0) {
        cVar1 = *(char *)(iStack_18 + -1);
        if ((cVar1 == '\0') || (cVar1 == -1)) {
          FUN_004bc150((char *)(iStack_18 + -1));
        }
        else {
          *(char *)(iStack_18 + -1) = cVar1 + -1;
        }
      }
      iStack_18 = 0;
      uStack_14 = 0;
      uStack_10 = 0;
      uVar2 = FUN_00460970(param_1,auStack_2c);
      FUN_00458460(1);
      uStack_30 = uVar2;
      FUN_00459170(*(undefined4 *)(*(int *)(param_1 + 0x88) + 8),1,&uStack_30);
      uStack_4 = 0xffffffff;
      if (iStack_28 != 0) {
        cVar1 = *(char *)(iStack_28 + -1);
        if ((cVar1 == '\0') || (cVar1 == -1)) {
          FUN_004bc150(iStack_28 + -1);
        }
        else {
          *(char *)(iStack_28 + -1) = cVar1 + -1;
        }
      }
      iVar3 = iVar3 + 1;
      iStack_28 = 0;
      uStack_24 = 0;
      uStack_20 = 0;
    } while (iVar3 < *(int *)(param_1 + 0x98));
  }
  ExceptionList = pvStack_c;
  return;
}

