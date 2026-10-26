/*
 * FUN_0041e734 at 0041e734
 * int * __register FUN_0041e734(undefined4 param_1, undefined4 param_2, uint param_3)
 * Address ranges: 0041e734-0041e812;0041e82a-0041e833
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0041e734(undefined4 param_1,undefined4 param_2,uint param_3)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *in_FS_OFFSET;
  RECT *pRVar8;
  undefined4 uStack_34;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  RECT local_1c;
  int *local_c;
  uint local_8;
  
  puStack_2c = (undefined1 *)0x41e74e;
  local_8 = param_3;
  local_c = FUN_0041c7f0((int *)&PTR_FUN_00416860,'\x01',param_3);
  puStack_30 = &LAB_0041e813;
  uStack_34 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_34;
  puStack_2c = &stack0xfffffffc;
  (**(code **)(*local_c + 0x40))(local_c,8);
  (**(code **)(*local_c + 0x34))(local_c,8);
  piVar1 = (int *)FUN_0041cd5c(local_c);
  FUN_00417fbc((int *)piVar1[5],'\0');
  FUN_00417ea0((int *)piVar1[5],param_2);
  uVar2 = (**(code **)(*local_c + 0x20))();
  pRVar8 = &local_1c;
  uVar3 = (**(code **)(*local_c + 0x2c))();
  FUN_0040ebe8(0,0,uVar3,&pRVar8->left,uVar2);
  FUN_00418538(piVar1,&local_1c);
  uVar7 = 0;
  do {
    uVar6 = 0;
    do {
      uVar4 = uVar7 & 0x80000001;
      if ((int)uVar4 < 0) {
        uVar4 = (uVar4 - 1 | 0xfffffffe) + 1;
      }
      uVar5 = uVar6 & 0x80000001;
      if ((int)uVar5 < 0) {
        uVar5 = (uVar5 - 1 | 0xfffffffe) + 1;
      }
      if (uVar4 == uVar5) {
        FUN_0041894c(piVar1,uVar6,uVar7,local_8);
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 != 9);
    uVar7 = uVar7 + 1;
  } while (uVar7 != 9);
  FUN_0041ca74((int)local_c);
  *in_FS_OFFSET = uStack_34;
  return local_c;
}

