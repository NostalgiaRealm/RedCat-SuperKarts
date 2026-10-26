/*
 * FUN_00407c45 at 00407c45
 * undefined8 __fastcall FUN_00407c45(undefined4 param_1, uint param_2)
 * Address ranges: 00407c45-00407cd4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined8 __fastcall FUN_00407c45(undefined4 param_1,uint param_2)

{
  uint in_EAX;
  undefined4 uVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 extraout_ECX;
  int iVar4;
  longlong lVar5;
  undefined8 uVar6;
  
  if ((DAT_0040f050 != 0) && (DAT_0040f00c != -2)) {
    lVar5 = FUN_00407ce6(param_1,param_2);
    uVar1 = 0;
    if ((int)lVar5 == 0) goto LAB_00407ccc;
    puVar2 = VirtualAlloc((LPVOID)0x0,in_EAX,0x1000,0x40);
    uVar1 = 0;
    if (puVar2 == (uint *)0x0) goto LAB_00407ccc;
    uVar3 = in_EAX - 4;
    if ((uVar3 <= in_EAX) && (0x37 < uVar3)) {
      *puVar2 = uVar3;
      uVar6 = FUN_00407bd1(extraout_ECX,puVar2);
      iVar4 = (int)((ulonglong)uVar6 >> 0x20);
      *(uint *)uVar6 = *(uint *)uVar6 | 1;
      *(undefined4 *)(iVar4 + 0x14) = 0xffffffff;
      *(int *)(iVar4 + 0x18) = *(int *)(iVar4 + 0x18) + 1;
      FUN_0040650f();
      uVar1 = 1;
      goto LAB_00407ccc;
    }
  }
  uVar1 = 0;
LAB_00407ccc:
  return CONCAT44(param_2,uVar1);
}

