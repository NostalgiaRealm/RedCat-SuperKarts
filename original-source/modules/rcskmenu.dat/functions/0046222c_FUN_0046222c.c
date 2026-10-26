/*
 * FUN_0046222c at 0046222c
 * undefined __register FUN_0046222c(void)
 * Address ranges: 0046222c-0046228a;00462295-004622aa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046222c(void)

{
  int *piVar1;
  undefined4 extraout_ECX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_2c;
  undefined1 *puStack_28;
  undefined1 *puStack_24;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  
  puStack_18 = &stack0xfffffffc;
  puStack_24 = &stack0xfffffffc;
  puStack_1c = &LAB_004622ab;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  puStack_28 = &LAB_0046228b;
  uStack_2c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_2c;
  piVar1 = FUN_004615d8((int *)&PTR_FUN_00460fd0,'\x01',*(undefined4 *)PTR_DAT_0047c86c);
  if (piVar1 != (int *)0x0) {
    FUN_00461858((int)piVar1,'\0',extraout_ECX);
    (**(code **)(*piVar1 + 0xd8))();
  }
  *in_FS_OFFSET = uStack_2c;
  *in_FS_OFFSET = uStack_20;
  puStack_18 = &LAB_004622b2;
  puStack_1c = (undefined1 *)0x4622aa;
  FUN_00402eac(piVar1);
  return;
}

