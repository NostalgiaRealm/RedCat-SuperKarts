/*
 * FUN_00404260 at 00404260
 * undefined8 __fastcall FUN_00404260(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00404260-004042c7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined8 __fastcall FUN_00404260(undefined4 param_1,undefined4 param_2)

{
  uint in_EAX;
  uint uVar1;
  
  uVar1 = in_EAX;
  if ((*(int *)(in_EAX + 0x420) != -1) && (*(int *)(in_EAX + 0x428) == 0)) {
    if (*(int *)(in_EAX + 0x424) == 0) {
      uVar1 = CONCAT31((int3)(in_EAX >> 8),1);
      goto LAB_004042c2;
    }
    uVar1 = *(uint *)(in_EAX + 0x404 + *(int *)(in_EAX + 0x420) * 4);
    if (*(int *)(uVar1 + 0x44) == 0) {
      uVar1 = (*DAT_00410478)(uVar1);
      if (*(uint *)(*(int *)(in_EAX + 0x404 + *(int *)(in_EAX + 0x420) * 4) + 0x24) >> 7 <= uVar1) {
        uVar1 = CONCAT31((int3)(uVar1 >> 8),1);
        *(undefined4 *)(in_EAX + 0x424) = 0;
        goto LAB_004042c2;
      }
    }
  }
  uVar1 = uVar1 & 0xffffff00;
LAB_004042c2:
  return CONCAT44(param_2,uVar1);
}

