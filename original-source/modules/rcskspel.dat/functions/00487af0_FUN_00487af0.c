/*
 * FUN_00487af0 at 00487af0
 * undefined FUN_00487af0(void)
 * Address ranges: 00487af0-00487bf4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall
FUN_00487af0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined1 auStack_794 [1940];
  
  bVar1 = false;
  if (((DAT_0053ba78 != 0) && (DAT_0053ba60 != 0)) && (DAT_0053b9b0 == 0)) {
    uVar3 = FUN_00456370();
    cVar2 = FUN_00417e90(uVar3);
    iVar4 = DAT_0053be28;
    if (cVar2 == '\0') {
      iVar4 = FUN_00456370();
      iVar4 = (&DAT_005081bc)[iVar4 * 0x1c];
    }
    iVar5 = (**(code **)*param_1)();
    if (iVar5 < 0x14) {
      iVar7 = 0;
      if (0 < iVar5) {
        do {
          iVar6 = FUN_00486cb0();
          if (iVar6 == iVar4) {
            bVar1 = true;
            iVar7 = iVar5;
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < iVar5);
        if (bVar1) {
          return;
        }
      }
      FUN_00486ac0();
      FUN_00487dc0(*(undefined4 *)(param_1[1] + 4),1,auStack_794);
      FUN_00486b20(param_2,param_3,param_4);
    }
  }
  return;
}

