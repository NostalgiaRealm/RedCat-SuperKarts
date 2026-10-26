/*
 * FUN_00408ff5 at 00408ff5
 * undefined4 * __fastcall FUN_00408ff5(undefined4 param_1, int param_2)
 * Address ranges: 00408ff5-0040906e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __fastcall FUN_00408ff5(undefined4 param_1,int param_2)

{
  undefined4 *in_EAX;
  undefined4 *puVar1;
  uint uVar2;
  undefined4 extraout_ECX;
  uint uVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  
  if (in_EAX == (undefined4 *)0x0) {
    uVar5 = FUN_00406420(param_2,param_2);
    puVar1 = (undefined4 *)uVar5;
  }
  else if (param_2 == 0) {
    FUN_0040650f();
    puVar1 = (undefined4 *)0x0;
  }
  else {
    uVar2 = FUN_00409213();
    uVar5 = FUN_0040921c();
    puVar1 = (undefined4 *)uVar5;
    if (puVar1 == (undefined4 *)0x0) {
      uVar5 = FUN_00406420(extraout_ECX,(int)((ulonglong)uVar5 >> 0x20));
      puVar1 = (undefined4 *)uVar5;
      if (puVar1 == (undefined4 *)0x0) {
        FUN_0040921c();
      }
      else {
        puVar4 = puVar1;
        for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar4 = *in_EAX;
          in_EAX = in_EAX + 1;
          puVar4 = puVar4 + 1;
        }
        for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
          *(undefined1 *)puVar4 = *(undefined1 *)in_EAX;
          in_EAX = (undefined4 *)((int)in_EAX + 1);
          puVar4 = (undefined4 *)((int)puVar4 + 1);
        }
        FUN_0040650f();
      }
    }
  }
  return puVar1;
}

