/*
 * FUN_00406c30 at 00406c30
 * undefined8 __fastcall FUN_00406c30(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00406c30-00406cdc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined8 __fastcall FUN_00406c30(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = DAT_0040e874;
  if (DAT_0040e874 == in_EAX) {
    DAT_0040e874 = *(int *)(DAT_0040e874 + 8);
  }
  else {
    do {
      iVar2 = iVar1;
      iVar1 = *(int *)(iVar2 + 8);
      if (iVar1 == 0) {
        uVar3 = 1;
        goto LAB_00406cd7;
      }
    } while (in_EAX != iVar1);
    *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar1 + 8);
  }
  if ((*(char *)(in_EAX + 0x28) != '\0') && (DAT_0040e878 = DAT_0040e878 + -1, DAT_0040e878 == 0)) {
    timeKillEvent(DAT_004104d8);
    timeEndPeriod(0x1f);
  }
  (**(code **)(**(int **)(in_EAX + 4) + 0x48))(*(int **)(in_EAX + 4));
  (**(code **)(**(int **)(in_EAX + 4) + 8))(*(int **)(in_EAX + 4));
  if ((DAT_0040e874 == 0) && (DAT_0040e880 != '\0')) {
    (**(code **)(*DAT_0040e87c + 8))(DAT_0040e87c);
    DAT_0040e87c = (int *)0x0;
  }
  FUN_00402c10();
  uVar3 = 0;
LAB_00406cd7:
  return CONCAT44(param_2,uVar3);
}

