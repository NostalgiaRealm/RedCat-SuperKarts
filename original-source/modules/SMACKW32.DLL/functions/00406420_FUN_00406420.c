/*
 * FUN_00406420 at 00406420
 * undefined8 __fastcall FUN_00406420(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00406420-0040650e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined8 __fastcall FUN_00406420(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  uint in_EAX;
  undefined4 uVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  int extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  uint uVar6;
  undefined8 uVar7;
  
  if ((in_EAX != 0) && (in_EAX < 0xffffffd5)) {
    bVar1 = false;
    uVar6 = in_EAX + 3 & 0xfffffffc;
    (*(code *)PTR_FUN_0040ef60)();
    uVar2 = extraout_EDX;
LAB_00406459:
    do {
      uVar3 = uVar6;
      if (uVar6 < 0xc) {
        uVar3 = 0xc;
      }
      if ((uVar3 <= DAT_0040e86c) || (iVar5 = DAT_0040e868, DAT_0040e868 == 0)) {
        DAT_0040e86c = 0;
        iVar5 = DAT_0040e864;
      }
      while (iVar5 != 0) {
        DAT_0040e868 = iVar5;
        puVar4 = FUN_00407a1e();
        if (puVar4 != (uint *)0x0) goto LAB_004064f0;
        if (DAT_0040e86c < *(uint *)(extraout_ECX + 0x14)) {
          DAT_0040e86c = *(uint *)(extraout_ECX + 0x14);
        }
        uVar2 = 0;
        iVar5 = *(int *)(extraout_ECX + 8);
      }
      if (!bVar1) {
        uVar7 = FUN_00407cd5(0,uVar2);
        uVar2 = (undefined4)((ulonglong)uVar7 >> 0x20);
        if ((int)uVar7 != 0) {
          bVar1 = true;
          goto LAB_00406459;
        }
      }
      iVar5 = FUN_00407d30();
      if (iVar5 == 0) goto LAB_004064f0;
      bVar1 = false;
      uVar2 = extraout_EDX_00;
    } while( true );
  }
  uVar2 = 0;
LAB_00406500:
  return CONCAT44(param_2,uVar2);
LAB_004064f0:
  DAT_004104e8 = 0;
  (*(code *)PTR_FUN_0040ef68)();
  uVar2 = extraout_EDX_01;
  goto LAB_00406500;
}

