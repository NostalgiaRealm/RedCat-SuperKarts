/*
 * FUN_00483280 at 00483280
 * undefined FUN_00483280(void)
 * Address ranges: 00483280-004832f4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __thiscall FUN_00483280(undefined4 *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  char cVar2;
  uint in_EAX;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  uVar3 = in_EAX & 0xffffff00;
  iVar4 = 0;
  uVar1 = 0;
  if (0 < (int)param_1[0x28]) {
    iVar5 = 0;
    do {
      if (*(char *)(iVar5 + 8 + param_1[0x27]) != '\0') {
        cVar2 = (*(code *)**(undefined4 **)(iVar5 + param_1[0x27]))(param_2);
        if (cVar2 == '\0') {
          *(undefined1 *)(iVar5 + 8 + param_1[0x27]) = 0;
          if ((param_1[1] == 2) || (param_1[1] == 0)) {
            (**(code **)*param_1)(iVar4);
          }
        }
        else {
          uVar1 = 1;
        }
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x5c;
    } while (iVar4 < (int)param_1[0x28]);
    uVar3 = CONCAT31((int3)((uint)param_1[0x28] >> 8),uVar1);
  }
  return uVar3;
}

